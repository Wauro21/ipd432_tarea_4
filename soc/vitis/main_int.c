#include "xparameters.h"
#include "xgpiops.h"
#include "xplatform_info.h"
#include "xeucdis32_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "math.h"
#include <xscugic.h>
#include <xil_printf.h>

#define INTC_DEVICE_ID			XPAR_PS7_SCUGIC_0_DEVICE_ID
#define EXTP_DEVICE_ID			XPAR_AXI_GPIO_0_DEVICE_ID

#define XHLS_DEVICE_ID			XPAR_XSDPS_0_DEVICE_ID
#define INTC_EUCDIS_INT_ID	XPAR_FABRIC_EUCDIS32_INT_0_INTERRUPT_INTR

#define GPIO_DEVICE_ID      XPAR_XGPIOPS_0_DEVICE_ID

#define EUC_RAND_FACTOR     ((double)0x800 / (double)RAND_MAX)

#define VECTOR_SIZE				  1024
#define BUFFER_SIZE				  64
#define BRAMS               16

// #define DEBUG_VECTORS

static u32 out_pin, hw_pin;
XGpioPs gpio;
XEucdis32_int eucdis_ip;
XScuGic intc;

void (*XEucdis32_int_Write_A[])() = {XEucdis32_int_Write_A_0_Words,
                               XEucdis32_int_Write_A_1_Words,
                               XEucdis32_int_Write_A_2_Words,
                               XEucdis32_int_Write_A_3_Words,
                               XEucdis32_int_Write_A_4_Words,
                               XEucdis32_int_Write_A_5_Words,
                               XEucdis32_int_Write_A_6_Words,
                               XEucdis32_int_Write_A_7_Words,
                               XEucdis32_int_Write_A_8_Words,
                               XEucdis32_int_Write_A_9_Words,
                               XEucdis32_int_Write_A_10_Words,
                               XEucdis32_int_Write_A_11_Words,
                               XEucdis32_int_Write_A_12_Words,
                               XEucdis32_int_Write_A_13_Words,
                               XEucdis32_int_Write_A_14_Words,
                               XEucdis32_int_Write_A_15_Words};

void (*XEucdis32_int_Write_B[])() = {XEucdis32_int_Write_B_0_Words,
                               XEucdis32_int_Write_B_1_Words,
                               XEucdis32_int_Write_B_2_Words,
                               XEucdis32_int_Write_B_3_Words,
                               XEucdis32_int_Write_B_4_Words,
                               XEucdis32_int_Write_B_5_Words,
                               XEucdis32_int_Write_B_6_Words,
                               XEucdis32_int_Write_B_7_Words,
                               XEucdis32_int_Write_B_8_Words,
                               XEucdis32_int_Write_B_9_Words,
                               XEucdis32_int_Write_B_10_Words,
                               XEucdis32_int_Write_B_11_Words,
                               XEucdis32_int_Write_B_12_Words,
                               XEucdis32_int_Write_B_13_Words,
                               XEucdis32_int_Write_B_14_Words,
                               XEucdis32_int_Write_B_15_Words};


u32 tx_A_data[BUFFER_SIZE];
u32 tx_B_data[BUFFER_SIZE];
u32 rx_data[2];

int A_data[VECTOR_SIZE], B_data[VECTOR_SIZE];
volatile int ip_status;

u16 Get_16bitData(void);
void TxVectors(XEucdis32_int *instance_ptr, int vec_a[VECTOR_SIZE], int vec_b[VECTOR_SIZE]);
int Intc_InitFunction(u16 device_id);
void EucDis_ReceiveHandler(void *instance_ptr);
void GenVectors(int vec_a[VECTOR_SIZE], int vec_b[VECTOR_SIZE]);

int main(void) {
  int status;

  XGpioPs_Config *config_ptr;

  config_ptr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);
	out_pin = 13;
  hw_pin = 10;

  status = XGpioPs_CfgInitialize(&gpio, config_ptr, config_ptr->BaseAddr);
	if (status != XST_SUCCESS) {
    printf("GPIO Polled Mode Example Test Failed\r\n");
		return XST_FAILURE;
	}

  XGpioPs_SetDirectionPin(&gpio, out_pin, 1);
	XGpioPs_SetOutputEnablePin(&gpio, out_pin, 1);
	XGpioPs_WritePin(&gpio, out_pin, 0x0);
  XGpioPs_SetDirectionPin(&gpio, hw_pin, 1);
	XGpioPs_SetOutputEnablePin(&gpio, hw_pin, 1);
	XGpioPs_WritePin(&gpio, hw_pin, 0x0);

  status = XEucdis32_int_Initialize(&eucdis_ip, XHLS_DEVICE_ID);
  if (status != XST_SUCCESS) {
    printf("Error while initializing Eucdis\r\n");
		return XST_FAILURE;
	}

  status = Intc_InitFunction(INTC_DEVICE_ID);
  if (status != XST_SUCCESS) {
    printf("Error while initializing interruptions\r\n");
		return XST_FAILURE;
	}

  while (1) {
    u16 n_trials = Get_16bitData();
    u16 seed = Get_16bitData();

    srand(seed);

    for (int i = 0; i < n_trials; i++)
    {
      double sum = 0;
      u32 result_sw;
      GenVectors(A_data, B_data);

      // PS processing
      XGpioPs_WritePin(&gpio, out_pin, 0x1);
      for (int i = 0; i < VECTOR_SIZE; i++) {
        sum += (double)((A_data[i] - B_data[i]) * (A_data[i] - B_data[i]));
      }
      result_sw = (u32)sqrt(sum);
      XGpioPs_WritePin(&gpio, out_pin, 0x0);
      printf("%lu,", result_sw);

      // Delay
      for (int i = 0; i < 10000; i++);

      // PL processing
      XGpioPs_WritePin(&gpio, hw_pin, 0x1);
      ip_status = 0x01;
      TxVectors(&eucdis_ip, A_data, B_data);

      XEucdis32_int_Start(&eucdis_ip);
      while (ip_status);
      XGpioPs_WritePin(&gpio, hw_pin, 0x0);
      printf("%lu\n", rx_data[0]);

      // Delay
      for (int i = 0; i < 10000; i++);
    }
  }

  return 0;
}

u16 Get_16bitData() {
  u16 data = ((u16)inbyte() << 8);
  data |= (u16)inbyte();

  return data;
}

void EucDis_ReceiveHandler(void *instance_ptr) {
  //u32 result;
  XEucdis32_int_InterruptDisable(instance_ptr, 1);

  rx_data[0] = XEucdis32_int_Get_C(instance_ptr);

  ip_status = 0x00;
  XEucdis32_int_InterruptClear(instance_ptr, 1);
  XEucdis32_int_InterruptEnable(instance_ptr, 1);
}

void TxVectors(XEucdis32_int *instance_ptr, int vec_a[VECTOR_SIZE], int vec_b[VECTOR_SIZE]) {
  for (int bram = 0; bram < BRAMS; bram++) {
    for (int buf_pos = 0; buf_pos < BUFFER_SIZE; buf_pos++) {
      u16 t_pos = buf_pos * BRAMS + bram;
      tx_A_data[buf_pos] = t_pos < VECTOR_SIZE ? ((u32)vec_a[t_pos]): 0;
      tx_B_data[buf_pos] = t_pos < VECTOR_SIZE ? ((u32)vec_b[t_pos]): 0;
    }
    XEucdis32_int_Write_A[bram](instance_ptr, 0, tx_A_data, BUFFER_SIZE);
    XEucdis32_int_Write_B[bram](instance_ptr, 0, tx_B_data, BUFFER_SIZE);
  }
}

void GenVectors(int vec_a[VECTOR_SIZE], int vec_b[VECTOR_SIZE]) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    vec_a[i] = (int) (((double)(rand() - (RAND_MAX/2))) * EUC_RAND_FACTOR);
    vec_b[i] = (int)(((double)(rand() - (RAND_MAX/2))) * EUC_RAND_FACTOR);

#ifdef DEBUG_VECTORS
    printf("%d) A : %d\tB : %d \n", i, vec_a[i], vec_b[i]);
#endif
  }
}

int Intc_InitFunction(u16 device_id) {
  XScuGic_Config *intc_config;
  int status;

  intc_config = XScuGic_LookupConfig(device_id);
  status = XScuGic_CfgInitialize(&intc, intc_config, intc_config->CpuBaseAddress);
  if (status != XST_SUCCESS) return status;

  Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
                              (Xil_ExceptionHandler) XScuGic_InterruptHandler,
                              &intc);
	Xil_ExceptionEnable();

  status = XScuGic_Connect(&intc,
                   INTC_EUCDIS_INT_ID,
                   (Xil_InterruptHandler) EucDis_ReceiveHandler,
                   (void *) (&eucdis_ip));

  XEucdis32_int_InterruptEnable(&eucdis_ip, 1);
  XEucdis32_int_InterruptGlobalEnable(&eucdis_ip);
  XScuGic_Enable(&intc, INTC_EUCDIS_INT_ID);

  return XST_SUCCESS;
}
