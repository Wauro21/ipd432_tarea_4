// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XEUCDIS32_INT_H
#define XEUCDIS32_INT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xeucdis32_int_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XEucdis32_int_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XEucdis32_int;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XEucdis32_int_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XEucdis32_int_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XEucdis32_int_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XEucdis32_int_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XEucdis32_int_Initialize(XEucdis32_int *InstancePtr, u16 DeviceId);
XEucdis32_int_Config* XEucdis32_int_LookupConfig(u16 DeviceId);
int XEucdis32_int_CfgInitialize(XEucdis32_int *InstancePtr, XEucdis32_int_Config *ConfigPtr);
#else
int XEucdis32_int_Initialize(XEucdis32_int *InstancePtr, const char* InstanceName);
int XEucdis32_int_Release(XEucdis32_int *InstancePtr);
#endif

void XEucdis32_int_Start(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_IsDone(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_IsIdle(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_IsReady(XEucdis32_int *InstancePtr);
void XEucdis32_int_EnableAutoRestart(XEucdis32_int *InstancePtr);
void XEucdis32_int_DisableAutoRestart(XEucdis32_int *InstancePtr);

u32 XEucdis32_int_Get_C(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_C_vld(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_0_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_0_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_0_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_0_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_0_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_1_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_1_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_1_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_1_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_1_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_2_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_2_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_2_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_2_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_2_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_3_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_3_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_3_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_3_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_3_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_4_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_4_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_4_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_4_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_4_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_5_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_5_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_5_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_5_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_5_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_6_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_6_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_6_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_6_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_6_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_7_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_7_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_7_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_7_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_7_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_8_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_8_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_8_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_8_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_8_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_9_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_9_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_9_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_9_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_9_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_10_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_10_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_10_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_10_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_10_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_11_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_11_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_11_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_11_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_11_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_12_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_12_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_12_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_12_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_12_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_13_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_13_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_13_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_13_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_13_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_14_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_14_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_14_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_14_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_14_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_A_15_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_15_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_15_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_15_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_A_15_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_A_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_A_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_A_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_A_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_0_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_0_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_0_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_0_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_0_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_1_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_1_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_1_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_1_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_1_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_2_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_2_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_2_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_2_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_2_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_3_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_3_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_3_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_3_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_3_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_4_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_4_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_4_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_4_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_4_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_5_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_5_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_5_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_5_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_5_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_6_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_6_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_6_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_6_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_6_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_7_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_7_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_7_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_7_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_7_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_8_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_8_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_8_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_8_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_8_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_9_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_9_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_9_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_9_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_9_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_10_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_10_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_10_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_10_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_10_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_11_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_11_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_11_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_11_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_11_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_12_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_12_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_12_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_12_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_12_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_13_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_13_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_13_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_13_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_13_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_14_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_14_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_14_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_14_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_14_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Get_B_15_BaseAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_15_HighAddress(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_15_TotalBytes(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_15_BitWidth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Get_B_15_Depth(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_Write_B_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Read_B_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_int_Write_B_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_int_Read_B_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length);

void XEucdis32_int_InterruptGlobalEnable(XEucdis32_int *InstancePtr);
void XEucdis32_int_InterruptGlobalDisable(XEucdis32_int *InstancePtr);
void XEucdis32_int_InterruptEnable(XEucdis32_int *InstancePtr, u32 Mask);
void XEucdis32_int_InterruptDisable(XEucdis32_int *InstancePtr, u32 Mask);
void XEucdis32_int_InterruptClear(XEucdis32_int *InstancePtr, u32 Mask);
u32 XEucdis32_int_InterruptGetEnabled(XEucdis32_int *InstancePtr);
u32 XEucdis32_int_InterruptGetStatus(XEucdis32_int *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
