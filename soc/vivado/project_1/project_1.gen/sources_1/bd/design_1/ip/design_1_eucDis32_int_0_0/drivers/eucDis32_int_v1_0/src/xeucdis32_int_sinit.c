// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xeucdis32_int.h"

extern XEucdis32_int_Config XEucdis32_int_ConfigTable[];

XEucdis32_int_Config *XEucdis32_int_LookupConfig(u16 DeviceId) {
	XEucdis32_int_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XEUCDIS32_INT_NUM_INSTANCES; Index++) {
		if (XEucdis32_int_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XEucdis32_int_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XEucdis32_int_Initialize(XEucdis32_int *InstancePtr, u16 DeviceId) {
	XEucdis32_int_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XEucdis32_int_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XEucdis32_int_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

