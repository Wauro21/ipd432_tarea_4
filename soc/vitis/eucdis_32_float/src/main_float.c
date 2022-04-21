#include "xparameters.h"
#include "xgpiops.h"
#include "xplatform_info.h"
#include "xeucdis32_float.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "math.h"
#include <xscugic.h>
#include <xil_printf.h>

#define INTC_DEVICE_ID			XPAR_PS7_SCUGIC_0_DEVICE_ID
#define EXTP_DEVICE_ID			XPAR_AXI_GPIO_0_DEVICE_ID

#define XHLS_DEVICE_ID			XPAR_XSDPS_0_DEVICE_ID
#define INTC_EUCDIS_FLOAT_ID	XPAR_FABRIC_EUCDIS32_FLOAT_0_INTERRUPT_INTR

#define GPIO_DEVICE_ID      XPAR_XGPIOPS_0_DEVICE_ID

#define EUC_RAND_FACTOR     ((float)1 / (float)RAND_MAX)

#define VECTOR_SIZE				  1024
#define BUFFER_SIZE				  64
#define BRAMS               16

// #define DEBUG_VECTORS

static u32 out_pin;
XGpioPs gpio;
XEucdis32_float eucdis_ip;
XScuGic intc;

void (*XEucdis32_float_Write_A[])() = {XEucdis32_float_Write_A_0_Words,
                               XEucdis32_float_Write_A_1_Words,
                               XEucdis32_float_Write_A_2_Words,
                               XEucdis32_float_Write_A_3_Words,
                               XEucdis32_float_Write_A_4_Words,
                               XEucdis32_float_Write_A_5_Words,
                               XEucdis32_float_Write_A_6_Words,
                               XEucdis32_float_Write_A_7_Words,
                               XEucdis32_float_Write_A_8_Words,
                               XEucdis32_float_Write_A_9_Words,
                               XEucdis32_float_Write_A_10_Words,
                               XEucdis32_float_Write_A_11_Words,
                               XEucdis32_float_Write_A_12_Words,
                               XEucdis32_float_Write_A_13_Words,
                               XEucdis32_float_Write_A_14_Words,
                               XEucdis32_float_Write_A_15_Words};

void (*XEucdis32_float_Write_B[])() = {XEucdis32_float_Write_B_0_Words,
                               XEucdis32_float_Write_B_1_Words,
                               XEucdis32_float_Write_B_2_Words,
                               XEucdis32_float_Write_B_3_Words,
                               XEucdis32_float_Write_B_4_Words,
                               XEucdis32_float_Write_B_5_Words,
                               XEucdis32_float_Write_B_6_Words,
                               XEucdis32_float_Write_B_7_Words,
                               XEucdis32_float_Write_B_8_Words,
                               XEucdis32_float_Write_B_9_Words,
                               XEucdis32_float_Write_B_10_Words,
                               XEucdis32_float_Write_B_11_Words,
                               XEucdis32_float_Write_B_12_Words,
                               XEucdis32_float_Write_B_13_Words,
                               XEucdis32_float_Write_B_14_Words,
                               XEucdis32_float_Write_B_15_Words};


u32 tx_A_data[BUFFER_SIZE];
u32 tx_B_data[BUFFER_SIZE];
float rx_data[2];

u32 tx_DEBUG_data[BUFFER_SIZE];

float A_data[VECTOR_SIZE], B_data[VECTOR_SIZE];
volatile int ip_status;

u16 Get_16bitData(void);
void TxVectors(XEucdis32_float *instance_ptr, float vec_a[VECTOR_SIZE], float vec_b[VECTOR_SIZE]);
int Intc_InitFunction(u16 device_id);
void EucDis_ReceiveHandler(void *instance_ptr);
void GenVectors(float vec_a[VECTOR_SIZE], float vec_b[VECTOR_SIZE]);

int main(void) {
  int status;

  XGpioPs_Config *config_ptr;

  config_ptr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);
	out_pin = 7;

  status = XGpioPs_CfgInitialize(&gpio, config_ptr, config_ptr->BaseAddr);
	if (status != XST_SUCCESS) {
    printf("GPIO Polled Mode Example Test Failed\r\n");
		return XST_FAILURE;
	}

  XGpioPs_SetDirectionPin(&gpio, out_pin, 1);
	XGpioPs_SetOutputEnablePin(&gpio, out_pin, 1);
	XGpioPs_WritePin(&gpio, out_pin, 0x0);

  status = XEucdis32_float_Initialize(&eucdis_ip, XHLS_DEVICE_ID);
  if (status != XST_SUCCESS) {
    printf("Error while initializing Eucdis\r\n");
		return XST_FAILURE;
	}

  status = Intc_InitFunction(INTC_DEVICE_ID);
  if (status != XST_SUCCESS) {
    printf("Error while initializing interruptions\r\n");
		return XST_FAILURE;
	}

  //printf((char *)"Started...\n");
  u16 n_trials = Get_16bitData();
  u16 seed = Get_16bitData();

  srand(seed);

  for (int i = 0; i < n_trials; i++)
  {
    GenVectors(A_data, B_data);

    XGpioPs_WritePin(&gpio, out_pin, 0x1);
    // PS processing
    double sum = 0;
    float result_sw;
    for (int i = 0; i < VECTOR_SIZE; i++) {
      sum += (double)((A_data[i] - B_data[i]) * (A_data[i] - B_data[i]));
    }
    result_sw = (float)sqrt(sum);
    XGpioPs_WritePin(&gpio, out_pin, 0x0);
    printf("%f,", result_sw);

    // Delay
    for (int i = 0; i < 10000; i++);

    // PL processing
    XGpioPs_WritePin(&gpio, out_pin, 0x1);
    ip_status = 0x01;
    TxVectors(&eucdis_ip, A_data, B_data);

    XEucdis32_float_Read_A_15_Words(&eucdis_ip, 0, tx_DEBUG_data, BUFFER_SIZE);

    XEucdis32_float_Start(&eucdis_ip);
    while (ip_status);
    XGpioPs_WritePin(&gpio, out_pin, 0x0);
    printf("%f\n", rx_data[0]);

    // Delay
    for (int i = 0; i < 10000; i++);
  }

  while(1);
  return 0;
}

// just 1 byte for now
u16 Get_16bitData() {
  u16 data = (u16)inbyte();

  return data;
}

u32 result;
void EucDis_ReceiveHandler(void *instance_ptr) {

  XEucdis32_float_InterruptDisable(instance_ptr, 1);

  result = XEucdis32_float_Get_C(instance_ptr);
  //rx_data[0] = XEucdis32_float_Get_C(instance_ptr);
  rx_data[0] = *((float *) &result);

  ip_status = 0x00;
  XEucdis32_float_InterruptClear(instance_ptr, 1);
  XEucdis32_float_InterruptEnable(instance_ptr, 1);
}

void TxVectors(XEucdis32_float *instance_ptr, float vec_a[VECTOR_SIZE], float vec_b[VECTOR_SIZE]) {
  for (int bram = 0; bram < BRAMS; bram++) {
    for (int buf_pos = 0; buf_pos < BUFFER_SIZE; buf_pos++) {
      u16 t_pos = buf_pos * BRAMS + bram;
      tx_A_data[buf_pos] = t_pos < VECTOR_SIZE ? *((u32 *) &vec_a[t_pos]): 0;
      tx_B_data[buf_pos] = t_pos < VECTOR_SIZE ? *((u32 *) &vec_b[t_pos]): 0;
    }
    XEucdis32_float_Write_A[bram](instance_ptr, 0, tx_A_data, BUFFER_SIZE);
    XEucdis32_float_Write_B[bram](instance_ptr, 0, tx_B_data, BUFFER_SIZE);
  }
}

void GenVectors(float vec_a[VECTOR_SIZE], float vec_b[VECTOR_SIZE]) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    vec_a[i] = ((float)(rand() - (RAND_MAX/2))) * EUC_RAND_FACTOR;
    vec_b[i] = ((float)(rand() - (RAND_MAX/2))) * EUC_RAND_FACTOR;

#ifdef DEBUG_VECTORS
    printf("%f) A : %d\tB : %f \n", i, vec_a[i], vec_b[i]);
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
                   INTC_EUCDIS_FLOAT_ID,
                   (Xil_InterruptHandler) EucDis_ReceiveHandler,
                   (void *) (&eucdis_ip));

  XEucdis32_float_InterruptEnable(&eucdis_ip, 1);
  XEucdis32_float_InterruptGlobalEnable(&eucdis_ip);
  XScuGic_Enable(&intc, INTC_EUCDIS_FLOAT_ID);

  return XST_SUCCESS;
}
