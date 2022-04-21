// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XEUCDIS32_FLOAT_H
#define XEUCDIS32_FLOAT_H

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
#include "xeucdis32_float_hw.h"

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
} XEucdis32_float_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XEucdis32_float;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XEucdis32_float_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XEucdis32_float_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XEucdis32_float_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XEucdis32_float_ReadReg(BaseAddress, RegOffset) \
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
int XEucdis32_float_Initialize(XEucdis32_float *InstancePtr, u16 DeviceId);
XEucdis32_float_Config* XEucdis32_float_LookupConfig(u16 DeviceId);
int XEucdis32_float_CfgInitialize(XEucdis32_float *InstancePtr, XEucdis32_float_Config *ConfigPtr);
#else
int XEucdis32_float_Initialize(XEucdis32_float *InstancePtr, const char* InstanceName);
int XEucdis32_float_Release(XEucdis32_float *InstancePtr);
#endif

void XEucdis32_float_Start(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_IsDone(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_IsIdle(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_IsReady(XEucdis32_float *InstancePtr);
void XEucdis32_float_EnableAutoRestart(XEucdis32_float *InstancePtr);
void XEucdis32_float_DisableAutoRestart(XEucdis32_float *InstancePtr);

u32 XEucdis32_float_Get_C(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_C_vld(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_0_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_0_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_0_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_0_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_0_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_1_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_1_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_1_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_1_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_1_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_2_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_2_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_2_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_2_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_2_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_3_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_3_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_3_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_3_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_3_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_4_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_4_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_4_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_4_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_4_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_5_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_5_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_5_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_5_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_5_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_6_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_6_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_6_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_6_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_6_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_7_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_7_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_7_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_7_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_7_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_8_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_8_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_8_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_8_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_8_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_9_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_9_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_9_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_9_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_9_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_10_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_10_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_10_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_10_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_10_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_11_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_11_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_11_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_11_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_11_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_12_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_12_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_12_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_12_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_12_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_13_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_13_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_13_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_13_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_13_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_14_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_14_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_14_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_14_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_14_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_15_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_15_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_15_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_15_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_15_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_16_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_16_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_16_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_16_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_16_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_17_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_17_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_17_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_17_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_17_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_18_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_18_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_18_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_18_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_18_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_19_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_19_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_19_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_19_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_19_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_20_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_20_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_20_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_20_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_20_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_21_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_21_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_21_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_21_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_21_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_22_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_22_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_22_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_22_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_22_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_23_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_23_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_23_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_23_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_23_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_24_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_24_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_24_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_24_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_24_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_25_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_25_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_25_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_25_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_25_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_26_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_26_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_26_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_26_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_26_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_27_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_27_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_27_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_27_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_27_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_28_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_28_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_28_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_28_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_28_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_29_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_29_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_29_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_29_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_29_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_30_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_30_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_30_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_30_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_30_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_A_31_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_31_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_31_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_31_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_A_31_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_A_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_A_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_A_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_A_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_0_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_0_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_0_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_0_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_0_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_1_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_1_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_1_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_1_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_1_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_2_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_2_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_2_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_2_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_2_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_3_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_3_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_3_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_3_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_3_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_4_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_4_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_4_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_4_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_4_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_5_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_5_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_5_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_5_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_5_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_6_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_6_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_6_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_6_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_6_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_7_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_7_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_7_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_7_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_7_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_8_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_8_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_8_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_8_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_8_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_9_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_9_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_9_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_9_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_9_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_10_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_10_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_10_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_10_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_10_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_11_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_11_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_11_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_11_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_11_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_12_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_12_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_12_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_12_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_12_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_13_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_13_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_13_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_13_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_13_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_14_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_14_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_14_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_14_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_14_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_15_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_15_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_15_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_15_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_15_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_16_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_16_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_16_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_16_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_16_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_17_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_17_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_17_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_17_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_17_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_18_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_18_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_18_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_18_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_18_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_19_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_19_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_19_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_19_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_19_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_20_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_20_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_20_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_20_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_20_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_21_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_21_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_21_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_21_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_21_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_22_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_22_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_22_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_22_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_22_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_23_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_23_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_23_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_23_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_23_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_24_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_24_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_24_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_24_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_24_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_25_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_25_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_25_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_25_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_25_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_26_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_26_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_26_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_26_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_26_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_27_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_27_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_27_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_27_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_27_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_28_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_28_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_28_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_28_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_28_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_29_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_29_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_29_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_29_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_29_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_30_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_30_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_30_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_30_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_30_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Get_B_31_BaseAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_31_HighAddress(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_31_TotalBytes(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_31_BitWidth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Get_B_31_Depth(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_Write_B_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Read_B_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length);
u32 XEucdis32_float_Write_B_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);
u32 XEucdis32_float_Read_B_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length);

void XEucdis32_float_InterruptGlobalEnable(XEucdis32_float *InstancePtr);
void XEucdis32_float_InterruptGlobalDisable(XEucdis32_float *InstancePtr);
void XEucdis32_float_InterruptEnable(XEucdis32_float *InstancePtr, u32 Mask);
void XEucdis32_float_InterruptDisable(XEucdis32_float *InstancePtr, u32 Mask);
void XEucdis32_float_InterruptClear(XEucdis32_float *InstancePtr, u32 Mask);
u32 XEucdis32_float_InterruptGetEnabled(XEucdis32_float *InstancePtr);
u32 XEucdis32_float_InterruptGetStatus(XEucdis32_float *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
