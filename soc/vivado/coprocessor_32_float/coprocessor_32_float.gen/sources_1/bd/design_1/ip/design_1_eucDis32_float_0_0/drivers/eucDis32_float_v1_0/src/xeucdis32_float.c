// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xeucdis32_float.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XEucdis32_float_CfgInitialize(XEucdis32_float *InstancePtr, XEucdis32_float_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XEucdis32_float_Start(XEucdis32_float *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL) & 0x80;
    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XEucdis32_float_IsDone(XEucdis32_float *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XEucdis32_float_IsIdle(XEucdis32_float *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XEucdis32_float_IsReady(XEucdis32_float *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XEucdis32_float_EnableAutoRestart(XEucdis32_float *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XEucdis32_float_DisableAutoRestart(XEucdis32_float *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL, 0);
}

u32 XEucdis32_float_Get_C(XEucdis32_float *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_C_DATA);
    return Data;
}

u32 XEucdis32_float_Get_C_vld(XEucdis32_float *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_C_CTRL);
    return Data & 0x1;
}

u32 XEucdis32_float_Get_A_0_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE);
}

u32 XEucdis32_float_Get_A_0_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_HIGH);
}

u32 XEucdis32_float_Get_A_0_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + 1);
}

u32 XEucdis32_float_Get_A_0_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_0;
}

u32 XEucdis32_float_Get_A_0_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_0;
}

u32 XEucdis32_float_Write_A_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_1_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE);
}

u32 XEucdis32_float_Get_A_1_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_HIGH);
}

u32 XEucdis32_float_Get_A_1_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + 1);
}

u32 XEucdis32_float_Get_A_1_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_1;
}

u32 XEucdis32_float_Get_A_1_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_1;
}

u32 XEucdis32_float_Write_A_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_2_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE);
}

u32 XEucdis32_float_Get_A_2_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_HIGH);
}

u32 XEucdis32_float_Get_A_2_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + 1);
}

u32 XEucdis32_float_Get_A_2_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_2;
}

u32 XEucdis32_float_Get_A_2_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_2;
}

u32 XEucdis32_float_Write_A_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_3_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE);
}

u32 XEucdis32_float_Get_A_3_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_HIGH);
}

u32 XEucdis32_float_Get_A_3_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + 1);
}

u32 XEucdis32_float_Get_A_3_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_3;
}

u32 XEucdis32_float_Get_A_3_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_3;
}

u32 XEucdis32_float_Write_A_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_4_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE);
}

u32 XEucdis32_float_Get_A_4_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_HIGH);
}

u32 XEucdis32_float_Get_A_4_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + 1);
}

u32 XEucdis32_float_Get_A_4_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_4;
}

u32 XEucdis32_float_Get_A_4_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_4;
}

u32 XEucdis32_float_Write_A_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_5_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE);
}

u32 XEucdis32_float_Get_A_5_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_HIGH);
}

u32 XEucdis32_float_Get_A_5_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + 1);
}

u32 XEucdis32_float_Get_A_5_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_5;
}

u32 XEucdis32_float_Get_A_5_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_5;
}

u32 XEucdis32_float_Write_A_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_6_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE);
}

u32 XEucdis32_float_Get_A_6_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_HIGH);
}

u32 XEucdis32_float_Get_A_6_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + 1);
}

u32 XEucdis32_float_Get_A_6_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_6;
}

u32 XEucdis32_float_Get_A_6_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_6;
}

u32 XEucdis32_float_Write_A_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_7_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE);
}

u32 XEucdis32_float_Get_A_7_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_HIGH);
}

u32 XEucdis32_float_Get_A_7_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + 1);
}

u32 XEucdis32_float_Get_A_7_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_7;
}

u32 XEucdis32_float_Get_A_7_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_7;
}

u32 XEucdis32_float_Write_A_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_8_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE);
}

u32 XEucdis32_float_Get_A_8_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_HIGH);
}

u32 XEucdis32_float_Get_A_8_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + 1);
}

u32 XEucdis32_float_Get_A_8_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_8;
}

u32 XEucdis32_float_Get_A_8_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_8;
}

u32 XEucdis32_float_Write_A_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_9_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE);
}

u32 XEucdis32_float_Get_A_9_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_HIGH);
}

u32 XEucdis32_float_Get_A_9_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + 1);
}

u32 XEucdis32_float_Get_A_9_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_9;
}

u32 XEucdis32_float_Get_A_9_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_9;
}

u32 XEucdis32_float_Write_A_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_10_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE);
}

u32 XEucdis32_float_Get_A_10_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_HIGH);
}

u32 XEucdis32_float_Get_A_10_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + 1);
}

u32 XEucdis32_float_Get_A_10_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_10;
}

u32 XEucdis32_float_Get_A_10_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_10;
}

u32 XEucdis32_float_Write_A_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_11_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE);
}

u32 XEucdis32_float_Get_A_11_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_HIGH);
}

u32 XEucdis32_float_Get_A_11_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + 1);
}

u32 XEucdis32_float_Get_A_11_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_11;
}

u32 XEucdis32_float_Get_A_11_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_11;
}

u32 XEucdis32_float_Write_A_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_12_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE);
}

u32 XEucdis32_float_Get_A_12_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_HIGH);
}

u32 XEucdis32_float_Get_A_12_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + 1);
}

u32 XEucdis32_float_Get_A_12_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_12;
}

u32 XEucdis32_float_Get_A_12_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_12;
}

u32 XEucdis32_float_Write_A_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_13_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE);
}

u32 XEucdis32_float_Get_A_13_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_HIGH);
}

u32 XEucdis32_float_Get_A_13_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + 1);
}

u32 XEucdis32_float_Get_A_13_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_13;
}

u32 XEucdis32_float_Get_A_13_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_13;
}

u32 XEucdis32_float_Write_A_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_14_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE);
}

u32 XEucdis32_float_Get_A_14_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_HIGH);
}

u32 XEucdis32_float_Get_A_14_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + 1);
}

u32 XEucdis32_float_Get_A_14_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_14;
}

u32 XEucdis32_float_Get_A_14_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_14;
}

u32 XEucdis32_float_Write_A_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_15_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE);
}

u32 XEucdis32_float_Get_A_15_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_HIGH);
}

u32 XEucdis32_float_Get_A_15_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + 1);
}

u32 XEucdis32_float_Get_A_15_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_15;
}

u32 XEucdis32_float_Get_A_15_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_15;
}

u32 XEucdis32_float_Write_A_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_16_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE);
}

u32 XEucdis32_float_Get_A_16_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_HIGH);
}

u32 XEucdis32_float_Get_A_16_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + 1);
}

u32 XEucdis32_float_Get_A_16_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_16;
}

u32 XEucdis32_float_Get_A_16_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_16;
}

u32 XEucdis32_float_Write_A_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_17_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE);
}

u32 XEucdis32_float_Get_A_17_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_HIGH);
}

u32 XEucdis32_float_Get_A_17_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + 1);
}

u32 XEucdis32_float_Get_A_17_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_17;
}

u32 XEucdis32_float_Get_A_17_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_17;
}

u32 XEucdis32_float_Write_A_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_18_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE);
}

u32 XEucdis32_float_Get_A_18_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_HIGH);
}

u32 XEucdis32_float_Get_A_18_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + 1);
}

u32 XEucdis32_float_Get_A_18_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_18;
}

u32 XEucdis32_float_Get_A_18_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_18;
}

u32 XEucdis32_float_Write_A_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_19_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE);
}

u32 XEucdis32_float_Get_A_19_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_HIGH);
}

u32 XEucdis32_float_Get_A_19_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + 1);
}

u32 XEucdis32_float_Get_A_19_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_19;
}

u32 XEucdis32_float_Get_A_19_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_19;
}

u32 XEucdis32_float_Write_A_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_20_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE);
}

u32 XEucdis32_float_Get_A_20_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_HIGH);
}

u32 XEucdis32_float_Get_A_20_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + 1);
}

u32 XEucdis32_float_Get_A_20_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_20;
}

u32 XEucdis32_float_Get_A_20_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_20;
}

u32 XEucdis32_float_Write_A_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_21_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE);
}

u32 XEucdis32_float_Get_A_21_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_HIGH);
}

u32 XEucdis32_float_Get_A_21_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + 1);
}

u32 XEucdis32_float_Get_A_21_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_21;
}

u32 XEucdis32_float_Get_A_21_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_21;
}

u32 XEucdis32_float_Write_A_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_22_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE);
}

u32 XEucdis32_float_Get_A_22_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_HIGH);
}

u32 XEucdis32_float_Get_A_22_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + 1);
}

u32 XEucdis32_float_Get_A_22_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_22;
}

u32 XEucdis32_float_Get_A_22_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_22;
}

u32 XEucdis32_float_Write_A_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_23_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE);
}

u32 XEucdis32_float_Get_A_23_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_HIGH);
}

u32 XEucdis32_float_Get_A_23_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + 1);
}

u32 XEucdis32_float_Get_A_23_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_23;
}

u32 XEucdis32_float_Get_A_23_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_23;
}

u32 XEucdis32_float_Write_A_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_24_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE);
}

u32 XEucdis32_float_Get_A_24_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_HIGH);
}

u32 XEucdis32_float_Get_A_24_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + 1);
}

u32 XEucdis32_float_Get_A_24_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_24;
}

u32 XEucdis32_float_Get_A_24_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_24;
}

u32 XEucdis32_float_Write_A_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_25_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE);
}

u32 XEucdis32_float_Get_A_25_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_HIGH);
}

u32 XEucdis32_float_Get_A_25_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + 1);
}

u32 XEucdis32_float_Get_A_25_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_25;
}

u32 XEucdis32_float_Get_A_25_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_25;
}

u32 XEucdis32_float_Write_A_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_26_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE);
}

u32 XEucdis32_float_Get_A_26_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_HIGH);
}

u32 XEucdis32_float_Get_A_26_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + 1);
}

u32 XEucdis32_float_Get_A_26_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_26;
}

u32 XEucdis32_float_Get_A_26_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_26;
}

u32 XEucdis32_float_Write_A_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_27_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE);
}

u32 XEucdis32_float_Get_A_27_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_HIGH);
}

u32 XEucdis32_float_Get_A_27_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + 1);
}

u32 XEucdis32_float_Get_A_27_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_27;
}

u32 XEucdis32_float_Get_A_27_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_27;
}

u32 XEucdis32_float_Write_A_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_28_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE);
}

u32 XEucdis32_float_Get_A_28_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_HIGH);
}

u32 XEucdis32_float_Get_A_28_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + 1);
}

u32 XEucdis32_float_Get_A_28_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_28;
}

u32 XEucdis32_float_Get_A_28_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_28;
}

u32 XEucdis32_float_Write_A_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_29_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE);
}

u32 XEucdis32_float_Get_A_29_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_HIGH);
}

u32 XEucdis32_float_Get_A_29_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + 1);
}

u32 XEucdis32_float_Get_A_29_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_29;
}

u32 XEucdis32_float_Get_A_29_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_29;
}

u32 XEucdis32_float_Write_A_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_30_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE);
}

u32 XEucdis32_float_Get_A_30_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_HIGH);
}

u32 XEucdis32_float_Get_A_30_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + 1);
}

u32 XEucdis32_float_Get_A_30_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_30;
}

u32 XEucdis32_float_Get_A_30_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_30;
}

u32 XEucdis32_float_Write_A_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_A_31_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE);
}

u32 XEucdis32_float_Get_A_31_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_HIGH);
}

u32 XEucdis32_float_Get_A_31_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + 1);
}

u32 XEucdis32_float_Get_A_31_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_A_31;
}

u32 XEucdis32_float_Get_A_31_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_A_31;
}

u32 XEucdis32_float_Write_A_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_A_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_A_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_0_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE);
}

u32 XEucdis32_float_Get_B_0_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_HIGH);
}

u32 XEucdis32_float_Get_B_0_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + 1);
}

u32 XEucdis32_float_Get_B_0_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_0;
}

u32 XEucdis32_float_Get_B_0_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_0;
}

u32 XEucdis32_float_Write_B_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_0_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_0_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_1_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE);
}

u32 XEucdis32_float_Get_B_1_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_HIGH);
}

u32 XEucdis32_float_Get_B_1_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + 1);
}

u32 XEucdis32_float_Get_B_1_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_1;
}

u32 XEucdis32_float_Get_B_1_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_1;
}

u32 XEucdis32_float_Write_B_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_1_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_1_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_2_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE);
}

u32 XEucdis32_float_Get_B_2_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_HIGH);
}

u32 XEucdis32_float_Get_B_2_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + 1);
}

u32 XEucdis32_float_Get_B_2_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_2;
}

u32 XEucdis32_float_Get_B_2_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_2;
}

u32 XEucdis32_float_Write_B_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_2_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_2_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_3_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE);
}

u32 XEucdis32_float_Get_B_3_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_HIGH);
}

u32 XEucdis32_float_Get_B_3_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + 1);
}

u32 XEucdis32_float_Get_B_3_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_3;
}

u32 XEucdis32_float_Get_B_3_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_3;
}

u32 XEucdis32_float_Write_B_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_3_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_3_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_4_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE);
}

u32 XEucdis32_float_Get_B_4_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_HIGH);
}

u32 XEucdis32_float_Get_B_4_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + 1);
}

u32 XEucdis32_float_Get_B_4_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_4;
}

u32 XEucdis32_float_Get_B_4_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_4;
}

u32 XEucdis32_float_Write_B_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_4_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_4_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_5_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE);
}

u32 XEucdis32_float_Get_B_5_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_HIGH);
}

u32 XEucdis32_float_Get_B_5_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + 1);
}

u32 XEucdis32_float_Get_B_5_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_5;
}

u32 XEucdis32_float_Get_B_5_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_5;
}

u32 XEucdis32_float_Write_B_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_5_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_5_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_6_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE);
}

u32 XEucdis32_float_Get_B_6_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_HIGH);
}

u32 XEucdis32_float_Get_B_6_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + 1);
}

u32 XEucdis32_float_Get_B_6_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_6;
}

u32 XEucdis32_float_Get_B_6_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_6;
}

u32 XEucdis32_float_Write_B_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_6_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_6_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_7_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE);
}

u32 XEucdis32_float_Get_B_7_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_HIGH);
}

u32 XEucdis32_float_Get_B_7_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + 1);
}

u32 XEucdis32_float_Get_B_7_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_7;
}

u32 XEucdis32_float_Get_B_7_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_7;
}

u32 XEucdis32_float_Write_B_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_7_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_7_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_8_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE);
}

u32 XEucdis32_float_Get_B_8_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_HIGH);
}

u32 XEucdis32_float_Get_B_8_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + 1);
}

u32 XEucdis32_float_Get_B_8_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_8;
}

u32 XEucdis32_float_Get_B_8_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_8;
}

u32 XEucdis32_float_Write_B_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_8_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_8_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_9_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE);
}

u32 XEucdis32_float_Get_B_9_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_HIGH);
}

u32 XEucdis32_float_Get_B_9_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + 1);
}

u32 XEucdis32_float_Get_B_9_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_9;
}

u32 XEucdis32_float_Get_B_9_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_9;
}

u32 XEucdis32_float_Write_B_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_9_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_9_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_10_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE);
}

u32 XEucdis32_float_Get_B_10_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_HIGH);
}

u32 XEucdis32_float_Get_B_10_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + 1);
}

u32 XEucdis32_float_Get_B_10_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_10;
}

u32 XEucdis32_float_Get_B_10_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_10;
}

u32 XEucdis32_float_Write_B_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_10_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_10_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_11_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE);
}

u32 XEucdis32_float_Get_B_11_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_HIGH);
}

u32 XEucdis32_float_Get_B_11_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + 1);
}

u32 XEucdis32_float_Get_B_11_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_11;
}

u32 XEucdis32_float_Get_B_11_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_11;
}

u32 XEucdis32_float_Write_B_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_11_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_11_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_12_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE);
}

u32 XEucdis32_float_Get_B_12_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_HIGH);
}

u32 XEucdis32_float_Get_B_12_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + 1);
}

u32 XEucdis32_float_Get_B_12_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_12;
}

u32 XEucdis32_float_Get_B_12_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_12;
}

u32 XEucdis32_float_Write_B_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_12_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_12_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_13_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE);
}

u32 XEucdis32_float_Get_B_13_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_HIGH);
}

u32 XEucdis32_float_Get_B_13_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + 1);
}

u32 XEucdis32_float_Get_B_13_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_13;
}

u32 XEucdis32_float_Get_B_13_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_13;
}

u32 XEucdis32_float_Write_B_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_13_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_13_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_14_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE);
}

u32 XEucdis32_float_Get_B_14_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_HIGH);
}

u32 XEucdis32_float_Get_B_14_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + 1);
}

u32 XEucdis32_float_Get_B_14_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_14;
}

u32 XEucdis32_float_Get_B_14_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_14;
}

u32 XEucdis32_float_Write_B_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_14_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_14_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_15_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE);
}

u32 XEucdis32_float_Get_B_15_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_HIGH);
}

u32 XEucdis32_float_Get_B_15_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + 1);
}

u32 XEucdis32_float_Get_B_15_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_15;
}

u32 XEucdis32_float_Get_B_15_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_15;
}

u32 XEucdis32_float_Write_B_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_15_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_15_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_16_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE);
}

u32 XEucdis32_float_Get_B_16_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_HIGH);
}

u32 XEucdis32_float_Get_B_16_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + 1);
}

u32 XEucdis32_float_Get_B_16_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_16;
}

u32 XEucdis32_float_Get_B_16_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_16;
}

u32 XEucdis32_float_Write_B_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_16_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_16_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_17_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE);
}

u32 XEucdis32_float_Get_B_17_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_HIGH);
}

u32 XEucdis32_float_Get_B_17_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + 1);
}

u32 XEucdis32_float_Get_B_17_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_17;
}

u32 XEucdis32_float_Get_B_17_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_17;
}

u32 XEucdis32_float_Write_B_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_17_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_17_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_18_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE);
}

u32 XEucdis32_float_Get_B_18_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_HIGH);
}

u32 XEucdis32_float_Get_B_18_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + 1);
}

u32 XEucdis32_float_Get_B_18_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_18;
}

u32 XEucdis32_float_Get_B_18_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_18;
}

u32 XEucdis32_float_Write_B_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_18_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_18_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_19_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE);
}

u32 XEucdis32_float_Get_B_19_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_HIGH);
}

u32 XEucdis32_float_Get_B_19_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + 1);
}

u32 XEucdis32_float_Get_B_19_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_19;
}

u32 XEucdis32_float_Get_B_19_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_19;
}

u32 XEucdis32_float_Write_B_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_19_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_19_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_20_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE);
}

u32 XEucdis32_float_Get_B_20_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_HIGH);
}

u32 XEucdis32_float_Get_B_20_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + 1);
}

u32 XEucdis32_float_Get_B_20_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_20;
}

u32 XEucdis32_float_Get_B_20_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_20;
}

u32 XEucdis32_float_Write_B_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_20_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_20_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_21_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE);
}

u32 XEucdis32_float_Get_B_21_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_HIGH);
}

u32 XEucdis32_float_Get_B_21_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + 1);
}

u32 XEucdis32_float_Get_B_21_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_21;
}

u32 XEucdis32_float_Get_B_21_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_21;
}

u32 XEucdis32_float_Write_B_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_21_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_21_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_22_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE);
}

u32 XEucdis32_float_Get_B_22_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_HIGH);
}

u32 XEucdis32_float_Get_B_22_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + 1);
}

u32 XEucdis32_float_Get_B_22_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_22;
}

u32 XEucdis32_float_Get_B_22_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_22;
}

u32 XEucdis32_float_Write_B_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_22_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_22_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_23_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE);
}

u32 XEucdis32_float_Get_B_23_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_HIGH);
}

u32 XEucdis32_float_Get_B_23_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + 1);
}

u32 XEucdis32_float_Get_B_23_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_23;
}

u32 XEucdis32_float_Get_B_23_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_23;
}

u32 XEucdis32_float_Write_B_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_23_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_23_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_24_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE);
}

u32 XEucdis32_float_Get_B_24_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_HIGH);
}

u32 XEucdis32_float_Get_B_24_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + 1);
}

u32 XEucdis32_float_Get_B_24_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_24;
}

u32 XEucdis32_float_Get_B_24_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_24;
}

u32 XEucdis32_float_Write_B_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_24_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_24_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_25_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE);
}

u32 XEucdis32_float_Get_B_25_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_HIGH);
}

u32 XEucdis32_float_Get_B_25_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + 1);
}

u32 XEucdis32_float_Get_B_25_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_25;
}

u32 XEucdis32_float_Get_B_25_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_25;
}

u32 XEucdis32_float_Write_B_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_25_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_25_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_26_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE);
}

u32 XEucdis32_float_Get_B_26_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_HIGH);
}

u32 XEucdis32_float_Get_B_26_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + 1);
}

u32 XEucdis32_float_Get_B_26_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_26;
}

u32 XEucdis32_float_Get_B_26_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_26;
}

u32 XEucdis32_float_Write_B_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_26_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_26_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_27_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE);
}

u32 XEucdis32_float_Get_B_27_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_HIGH);
}

u32 XEucdis32_float_Get_B_27_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + 1);
}

u32 XEucdis32_float_Get_B_27_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_27;
}

u32 XEucdis32_float_Get_B_27_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_27;
}

u32 XEucdis32_float_Write_B_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_27_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_27_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_28_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE);
}

u32 XEucdis32_float_Get_B_28_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_HIGH);
}

u32 XEucdis32_float_Get_B_28_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + 1);
}

u32 XEucdis32_float_Get_B_28_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_28;
}

u32 XEucdis32_float_Get_B_28_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_28;
}

u32 XEucdis32_float_Write_B_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_28_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_28_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_29_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE);
}

u32 XEucdis32_float_Get_B_29_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_HIGH);
}

u32 XEucdis32_float_Get_B_29_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + 1);
}

u32 XEucdis32_float_Get_B_29_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_29;
}

u32 XEucdis32_float_Get_B_29_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_29;
}

u32 XEucdis32_float_Write_B_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_29_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_29_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_30_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE);
}

u32 XEucdis32_float_Get_B_30_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_HIGH);
}

u32 XEucdis32_float_Get_B_30_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + 1);
}

u32 XEucdis32_float_Get_B_30_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_30;
}

u32 XEucdis32_float_Get_B_30_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_30;
}

u32 XEucdis32_float_Write_B_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_30_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_30_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_float_Get_B_31_BaseAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE);
}

u32 XEucdis32_float_Get_B_31_HighAddress(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_HIGH);
}

u32 XEucdis32_float_Get_B_31_TotalBytes(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + 1);
}

u32 XEucdis32_float_Get_B_31_BitWidth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_WIDTH_B_31;
}

u32 XEucdis32_float_Get_B_31_Depth(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_FLOAT_CONTROL_DEPTH_B_31;
}

u32 XEucdis32_float_Write_B_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_31_Words(XEucdis32_float *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_float_Write_B_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_float_Read_B_31_Bytes(XEucdis32_float *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_HIGH - XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE + offset + i);
    }
    return length;
}

void XEucdis32_float_InterruptGlobalEnable(XEucdis32_float *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_GIE, 1);
}

void XEucdis32_float_InterruptGlobalDisable(XEucdis32_float *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_GIE, 0);
}

void XEucdis32_float_InterruptEnable(XEucdis32_float *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_IER);
    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_IER, Register | Mask);
}

void XEucdis32_float_InterruptDisable(XEucdis32_float *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_IER);
    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_IER, Register & (~Mask));
}

void XEucdis32_float_InterruptClear(XEucdis32_float *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_float_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_ISR, Mask);
}

u32 XEucdis32_float_InterruptGetEnabled(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_IER);
}

u32 XEucdis32_float_InterruptGetStatus(XEucdis32_float *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEucdis32_float_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_FLOAT_CONTROL_ADDR_ISR);
}

