// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xeucdis32_float.h"

extern XEucdis32_float_Config XEucdis32_float_ConfigTable[];

XEucdis32_float_Config *XEucdis32_float_LookupConfig(u16 DeviceId) {
	XEucdis32_float_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XEUCDIS32_FLOAT_NUM_INSTANCES; Index++) {
		if (XEucdis32_float_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XEucdis32_float_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XEucdis32_float_Initialize(XEucdis32_float *InstancePtr, u16 DeviceId) {
	XEucdis32_float_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XEucdis32_float_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XEucdis32_float_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

