// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xeucdis32_int.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XEucdis32_int_CfgInitialize(XEucdis32_int *InstancePtr, XEucdis32_int_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XEucdis32_int_Start(XEucdis32_int *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_AP_CTRL) & 0x80;
    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XEucdis32_int_IsDone(XEucdis32_int *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XEucdis32_int_IsIdle(XEucdis32_int *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XEucdis32_int_IsReady(XEucdis32_int *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XEucdis32_int_EnableAutoRestart(XEucdis32_int *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XEucdis32_int_DisableAutoRestart(XEucdis32_int *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_AP_CTRL, 0);
}

u32 XEucdis32_int_Get_C(XEucdis32_int *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_C_DATA);
    return Data;
}

u32 XEucdis32_int_Get_C_vld(XEucdis32_int *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_C_CTRL);
    return Data & 0x1;
}

u32 XEucdis32_int_Get_A_0_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE);
}

u32 XEucdis32_int_Get_A_0_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_0_HIGH);
}

u32 XEucdis32_int_Get_A_0_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + 1);
}

u32 XEucdis32_int_Get_A_0_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_0;
}

u32 XEucdis32_int_Get_A_0_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_0;
}

u32 XEucdis32_int_Write_A_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_0_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_1_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE);
}

u32 XEucdis32_int_Get_A_1_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_1_HIGH);
}

u32 XEucdis32_int_Get_A_1_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + 1);
}

u32 XEucdis32_int_Get_A_1_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_1;
}

u32 XEucdis32_int_Get_A_1_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_1;
}

u32 XEucdis32_int_Write_A_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_1_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_2_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE);
}

u32 XEucdis32_int_Get_A_2_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_2_HIGH);
}

u32 XEucdis32_int_Get_A_2_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + 1);
}

u32 XEucdis32_int_Get_A_2_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_2;
}

u32 XEucdis32_int_Get_A_2_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_2;
}

u32 XEucdis32_int_Write_A_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_2_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_3_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE);
}

u32 XEucdis32_int_Get_A_3_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_3_HIGH);
}

u32 XEucdis32_int_Get_A_3_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + 1);
}

u32 XEucdis32_int_Get_A_3_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_3;
}

u32 XEucdis32_int_Get_A_3_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_3;
}

u32 XEucdis32_int_Write_A_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_3_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_4_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE);
}

u32 XEucdis32_int_Get_A_4_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_4_HIGH);
}

u32 XEucdis32_int_Get_A_4_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + 1);
}

u32 XEucdis32_int_Get_A_4_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_4;
}

u32 XEucdis32_int_Get_A_4_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_4;
}

u32 XEucdis32_int_Write_A_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_4_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_5_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE);
}

u32 XEucdis32_int_Get_A_5_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_5_HIGH);
}

u32 XEucdis32_int_Get_A_5_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + 1);
}

u32 XEucdis32_int_Get_A_5_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_5;
}

u32 XEucdis32_int_Get_A_5_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_5;
}

u32 XEucdis32_int_Write_A_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_5_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_6_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE);
}

u32 XEucdis32_int_Get_A_6_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_6_HIGH);
}

u32 XEucdis32_int_Get_A_6_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + 1);
}

u32 XEucdis32_int_Get_A_6_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_6;
}

u32 XEucdis32_int_Get_A_6_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_6;
}

u32 XEucdis32_int_Write_A_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_6_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_7_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE);
}

u32 XEucdis32_int_Get_A_7_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_7_HIGH);
}

u32 XEucdis32_int_Get_A_7_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + 1);
}

u32 XEucdis32_int_Get_A_7_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_7;
}

u32 XEucdis32_int_Get_A_7_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_7;
}

u32 XEucdis32_int_Write_A_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_7_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_8_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE);
}

u32 XEucdis32_int_Get_A_8_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_8_HIGH);
}

u32 XEucdis32_int_Get_A_8_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + 1);
}

u32 XEucdis32_int_Get_A_8_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_8;
}

u32 XEucdis32_int_Get_A_8_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_8;
}

u32 XEucdis32_int_Write_A_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_8_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_9_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE);
}

u32 XEucdis32_int_Get_A_9_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_9_HIGH);
}

u32 XEucdis32_int_Get_A_9_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + 1);
}

u32 XEucdis32_int_Get_A_9_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_9;
}

u32 XEucdis32_int_Get_A_9_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_9;
}

u32 XEucdis32_int_Write_A_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_9_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_10_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE);
}

u32 XEucdis32_int_Get_A_10_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_10_HIGH);
}

u32 XEucdis32_int_Get_A_10_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + 1);
}

u32 XEucdis32_int_Get_A_10_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_10;
}

u32 XEucdis32_int_Get_A_10_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_10;
}

u32 XEucdis32_int_Write_A_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_10_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_11_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE);
}

u32 XEucdis32_int_Get_A_11_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_11_HIGH);
}

u32 XEucdis32_int_Get_A_11_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + 1);
}

u32 XEucdis32_int_Get_A_11_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_11;
}

u32 XEucdis32_int_Get_A_11_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_11;
}

u32 XEucdis32_int_Write_A_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_11_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_12_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE);
}

u32 XEucdis32_int_Get_A_12_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_12_HIGH);
}

u32 XEucdis32_int_Get_A_12_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + 1);
}

u32 XEucdis32_int_Get_A_12_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_12;
}

u32 XEucdis32_int_Get_A_12_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_12;
}

u32 XEucdis32_int_Write_A_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_12_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_13_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE);
}

u32 XEucdis32_int_Get_A_13_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_13_HIGH);
}

u32 XEucdis32_int_Get_A_13_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + 1);
}

u32 XEucdis32_int_Get_A_13_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_13;
}

u32 XEucdis32_int_Get_A_13_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_13;
}

u32 XEucdis32_int_Write_A_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_13_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_14_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE);
}

u32 XEucdis32_int_Get_A_14_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_14_HIGH);
}

u32 XEucdis32_int_Get_A_14_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + 1);
}

u32 XEucdis32_int_Get_A_14_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_14;
}

u32 XEucdis32_int_Get_A_14_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_14;
}

u32 XEucdis32_int_Write_A_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_14_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_A_15_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE);
}

u32 XEucdis32_int_Get_A_15_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_15_HIGH);
}

u32 XEucdis32_int_Get_A_15_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + 1);
}

u32 XEucdis32_int_Get_A_15_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_A_15;
}

u32 XEucdis32_int_Get_A_15_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_A_15;
}

u32 XEucdis32_int_Write_A_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_A_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_A_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_A_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_A_15_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_0_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE);
}

u32 XEucdis32_int_Get_B_0_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_0_HIGH);
}

u32 XEucdis32_int_Get_B_0_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + 1);
}

u32 XEucdis32_int_Get_B_0_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_0;
}

u32 XEucdis32_int_Get_B_0_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_0;
}

u32 XEucdis32_int_Write_B_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_0_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_0_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_0_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_0_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_1_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE);
}

u32 XEucdis32_int_Get_B_1_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_1_HIGH);
}

u32 XEucdis32_int_Get_B_1_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + 1);
}

u32 XEucdis32_int_Get_B_1_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_1;
}

u32 XEucdis32_int_Get_B_1_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_1;
}

u32 XEucdis32_int_Write_B_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_1_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_1_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_1_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_1_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_2_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE);
}

u32 XEucdis32_int_Get_B_2_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_2_HIGH);
}

u32 XEucdis32_int_Get_B_2_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + 1);
}

u32 XEucdis32_int_Get_B_2_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_2;
}

u32 XEucdis32_int_Get_B_2_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_2;
}

u32 XEucdis32_int_Write_B_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_2_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_2_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_2_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_2_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_3_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE);
}

u32 XEucdis32_int_Get_B_3_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_3_HIGH);
}

u32 XEucdis32_int_Get_B_3_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + 1);
}

u32 XEucdis32_int_Get_B_3_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_3;
}

u32 XEucdis32_int_Get_B_3_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_3;
}

u32 XEucdis32_int_Write_B_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_3_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_3_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_3_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_3_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_4_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE);
}

u32 XEucdis32_int_Get_B_4_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_4_HIGH);
}

u32 XEucdis32_int_Get_B_4_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + 1);
}

u32 XEucdis32_int_Get_B_4_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_4;
}

u32 XEucdis32_int_Get_B_4_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_4;
}

u32 XEucdis32_int_Write_B_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_4_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_4_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_4_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_4_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_5_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE);
}

u32 XEucdis32_int_Get_B_5_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_5_HIGH);
}

u32 XEucdis32_int_Get_B_5_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + 1);
}

u32 XEucdis32_int_Get_B_5_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_5;
}

u32 XEucdis32_int_Get_B_5_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_5;
}

u32 XEucdis32_int_Write_B_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_5_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_5_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_5_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_5_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_6_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE);
}

u32 XEucdis32_int_Get_B_6_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_6_HIGH);
}

u32 XEucdis32_int_Get_B_6_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + 1);
}

u32 XEucdis32_int_Get_B_6_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_6;
}

u32 XEucdis32_int_Get_B_6_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_6;
}

u32 XEucdis32_int_Write_B_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_6_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_6_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_6_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_6_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_7_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE);
}

u32 XEucdis32_int_Get_B_7_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_7_HIGH);
}

u32 XEucdis32_int_Get_B_7_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + 1);
}

u32 XEucdis32_int_Get_B_7_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_7;
}

u32 XEucdis32_int_Get_B_7_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_7;
}

u32 XEucdis32_int_Write_B_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_7_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_7_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_7_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_7_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_8_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE);
}

u32 XEucdis32_int_Get_B_8_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_8_HIGH);
}

u32 XEucdis32_int_Get_B_8_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + 1);
}

u32 XEucdis32_int_Get_B_8_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_8;
}

u32 XEucdis32_int_Get_B_8_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_8;
}

u32 XEucdis32_int_Write_B_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_8_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_8_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_8_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_8_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_9_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE);
}

u32 XEucdis32_int_Get_B_9_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_9_HIGH);
}

u32 XEucdis32_int_Get_B_9_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + 1);
}

u32 XEucdis32_int_Get_B_9_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_9;
}

u32 XEucdis32_int_Get_B_9_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_9;
}

u32 XEucdis32_int_Write_B_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_9_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_9_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_9_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_9_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_10_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE);
}

u32 XEucdis32_int_Get_B_10_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_10_HIGH);
}

u32 XEucdis32_int_Get_B_10_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + 1);
}

u32 XEucdis32_int_Get_B_10_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_10;
}

u32 XEucdis32_int_Get_B_10_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_10;
}

u32 XEucdis32_int_Write_B_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_10_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_10_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_10_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_10_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_11_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE);
}

u32 XEucdis32_int_Get_B_11_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_11_HIGH);
}

u32 XEucdis32_int_Get_B_11_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + 1);
}

u32 XEucdis32_int_Get_B_11_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_11;
}

u32 XEucdis32_int_Get_B_11_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_11;
}

u32 XEucdis32_int_Write_B_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_11_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_11_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_11_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_11_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_12_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE);
}

u32 XEucdis32_int_Get_B_12_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_12_HIGH);
}

u32 XEucdis32_int_Get_B_12_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + 1);
}

u32 XEucdis32_int_Get_B_12_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_12;
}

u32 XEucdis32_int_Get_B_12_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_12;
}

u32 XEucdis32_int_Write_B_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_12_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_12_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_12_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_12_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_13_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE);
}

u32 XEucdis32_int_Get_B_13_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_13_HIGH);
}

u32 XEucdis32_int_Get_B_13_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + 1);
}

u32 XEucdis32_int_Get_B_13_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_13;
}

u32 XEucdis32_int_Get_B_13_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_13;
}

u32 XEucdis32_int_Write_B_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_13_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_13_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_13_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_13_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_14_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE);
}

u32 XEucdis32_int_Get_B_14_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_14_HIGH);
}

u32 XEucdis32_int_Get_B_14_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + 1);
}

u32 XEucdis32_int_Get_B_14_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_14;
}

u32 XEucdis32_int_Get_B_14_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_14;
}

u32 XEucdis32_int_Write_B_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_14_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_14_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_14_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_14_BASE + offset + i);
    }
    return length;
}

u32 XEucdis32_int_Get_B_15_BaseAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE);
}

u32 XEucdis32_int_Get_B_15_HighAddress(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_15_HIGH);
}

u32 XEucdis32_int_Get_B_15_TotalBytes(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XEUCDIS32_INT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + 1);
}

u32 XEucdis32_int_Get_B_15_BitWidth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_WIDTH_B_15;
}

u32 XEucdis32_int_Get_B_15_Depth(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEUCDIS32_INT_CONTROL_DEPTH_B_15;
}

u32 XEucdis32_int_Write_B_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_15_Words(XEucdis32_int *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XEUCDIS32_INT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + (offset + i)*4);
    }
    return length;
}

u32 XEucdis32_int_Write_B_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XEucdis32_int_Read_B_15_Bytes(XEucdis32_int *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XEUCDIS32_INT_CONTROL_ADDR_B_15_HIGH - XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XEUCDIS32_INT_CONTROL_ADDR_B_15_BASE + offset + i);
    }
    return length;
}

void XEucdis32_int_InterruptGlobalEnable(XEucdis32_int *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_GIE, 1);
}

void XEucdis32_int_InterruptGlobalDisable(XEucdis32_int *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_GIE, 0);
}

void XEucdis32_int_InterruptEnable(XEucdis32_int *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_IER);
    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_IER, Register | Mask);
}

void XEucdis32_int_InterruptDisable(XEucdis32_int *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_IER);
    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_IER, Register & (~Mask));
}

void XEucdis32_int_InterruptClear(XEucdis32_int *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEucdis32_int_WriteReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_ISR, Mask);
}

u32 XEucdis32_int_InterruptGetEnabled(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_IER);
}

u32 XEucdis32_int_InterruptGetStatus(XEucdis32_int *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEucdis32_int_ReadReg(InstancePtr->Control_BaseAddress, XEUCDIS32_INT_CONTROL_ADDR_ISR);
}

