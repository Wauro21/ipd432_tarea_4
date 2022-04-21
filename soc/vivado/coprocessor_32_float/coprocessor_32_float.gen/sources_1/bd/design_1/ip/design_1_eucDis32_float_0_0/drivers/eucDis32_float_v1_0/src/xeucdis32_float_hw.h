// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x0000 : Control signals
//          bit 0  - ap_start (Read/Write/COH)
//          bit 1  - ap_done (Read/COR)
//          bit 2  - ap_idle (Read)
//          bit 3  - ap_ready (Read/COR)
//          bit 7  - auto_restart (Read/Write)
//          others - reserved
// 0x0004 : Global Interrupt Enable Register
//          bit 0  - Global Interrupt Enable (Read/Write)
//          others - reserved
// 0x0008 : IP Interrupt Enable Register (Read/Write)
//          bit 0  - enable ap_done interrupt (Read/Write)
//          bit 1  - enable ap_ready interrupt (Read/Write)
//          others - reserved
// 0x000c : IP Interrupt Status Register (Read/TOW)
//          bit 0  - ap_done (COR/TOW)
//          bit 1  - ap_ready (COR/TOW)
//          others - reserved
// 0x0010 : Data signal of C
//          bit 31~0 - C[31:0] (Read)
// 0x0014 : Control signal of C
//          bit 0  - C_ap_vld (Read/COR)
//          others - reserved
// 0x0080 ~
// 0x00ff : Memory 'A_0' (32 * 32b)
//          Word n : bit [31:0] - A_0[n]
// 0x0100 ~
// 0x017f : Memory 'A_1' (32 * 32b)
//          Word n : bit [31:0] - A_1[n]
// 0x0180 ~
// 0x01ff : Memory 'A_2' (32 * 32b)
//          Word n : bit [31:0] - A_2[n]
// 0x0200 ~
// 0x027f : Memory 'A_3' (32 * 32b)
//          Word n : bit [31:0] - A_3[n]
// 0x0280 ~
// 0x02ff : Memory 'A_4' (32 * 32b)
//          Word n : bit [31:0] - A_4[n]
// 0x0300 ~
// 0x037f : Memory 'A_5' (32 * 32b)
//          Word n : bit [31:0] - A_5[n]
// 0x0380 ~
// 0x03ff : Memory 'A_6' (32 * 32b)
//          Word n : bit [31:0] - A_6[n]
// 0x0400 ~
// 0x047f : Memory 'A_7' (32 * 32b)
//          Word n : bit [31:0] - A_7[n]
// 0x0480 ~
// 0x04ff : Memory 'A_8' (32 * 32b)
//          Word n : bit [31:0] - A_8[n]
// 0x0500 ~
// 0x057f : Memory 'A_9' (32 * 32b)
//          Word n : bit [31:0] - A_9[n]
// 0x0580 ~
// 0x05ff : Memory 'A_10' (32 * 32b)
//          Word n : bit [31:0] - A_10[n]
// 0x0600 ~
// 0x067f : Memory 'A_11' (32 * 32b)
//          Word n : bit [31:0] - A_11[n]
// 0x0680 ~
// 0x06ff : Memory 'A_12' (32 * 32b)
//          Word n : bit [31:0] - A_12[n]
// 0x0700 ~
// 0x077f : Memory 'A_13' (32 * 32b)
//          Word n : bit [31:0] - A_13[n]
// 0x0780 ~
// 0x07ff : Memory 'A_14' (32 * 32b)
//          Word n : bit [31:0] - A_14[n]
// 0x0800 ~
// 0x087f : Memory 'A_15' (32 * 32b)
//          Word n : bit [31:0] - A_15[n]
// 0x0880 ~
// 0x08ff : Memory 'A_16' (32 * 32b)
//          Word n : bit [31:0] - A_16[n]
// 0x0900 ~
// 0x097f : Memory 'A_17' (32 * 32b)
//          Word n : bit [31:0] - A_17[n]
// 0x0980 ~
// 0x09ff : Memory 'A_18' (32 * 32b)
//          Word n : bit [31:0] - A_18[n]
// 0x0a00 ~
// 0x0a7f : Memory 'A_19' (32 * 32b)
//          Word n : bit [31:0] - A_19[n]
// 0x0a80 ~
// 0x0aff : Memory 'A_20' (32 * 32b)
//          Word n : bit [31:0] - A_20[n]
// 0x0b00 ~
// 0x0b7f : Memory 'A_21' (32 * 32b)
//          Word n : bit [31:0] - A_21[n]
// 0x0b80 ~
// 0x0bff : Memory 'A_22' (32 * 32b)
//          Word n : bit [31:0] - A_22[n]
// 0x0c00 ~
// 0x0c7f : Memory 'A_23' (32 * 32b)
//          Word n : bit [31:0] - A_23[n]
// 0x0c80 ~
// 0x0cff : Memory 'A_24' (32 * 32b)
//          Word n : bit [31:0] - A_24[n]
// 0x0d00 ~
// 0x0d7f : Memory 'A_25' (32 * 32b)
//          Word n : bit [31:0] - A_25[n]
// 0x0d80 ~
// 0x0dff : Memory 'A_26' (32 * 32b)
//          Word n : bit [31:0] - A_26[n]
// 0x0e00 ~
// 0x0e7f : Memory 'A_27' (32 * 32b)
//          Word n : bit [31:0] - A_27[n]
// 0x0e80 ~
// 0x0eff : Memory 'A_28' (32 * 32b)
//          Word n : bit [31:0] - A_28[n]
// 0x0f00 ~
// 0x0f7f : Memory 'A_29' (32 * 32b)
//          Word n : bit [31:0] - A_29[n]
// 0x0f80 ~
// 0x0fff : Memory 'A_30' (32 * 32b)
//          Word n : bit [31:0] - A_30[n]
// 0x1000 ~
// 0x107f : Memory 'A_31' (32 * 32b)
//          Word n : bit [31:0] - A_31[n]
// 0x1080 ~
// 0x10ff : Memory 'B_0' (32 * 32b)
//          Word n : bit [31:0] - B_0[n]
// 0x1100 ~
// 0x117f : Memory 'B_1' (32 * 32b)
//          Word n : bit [31:0] - B_1[n]
// 0x1180 ~
// 0x11ff : Memory 'B_2' (32 * 32b)
//          Word n : bit [31:0] - B_2[n]
// 0x1200 ~
// 0x127f : Memory 'B_3' (32 * 32b)
//          Word n : bit [31:0] - B_3[n]
// 0x1280 ~
// 0x12ff : Memory 'B_4' (32 * 32b)
//          Word n : bit [31:0] - B_4[n]
// 0x1300 ~
// 0x137f : Memory 'B_5' (32 * 32b)
//          Word n : bit [31:0] - B_5[n]
// 0x1380 ~
// 0x13ff : Memory 'B_6' (32 * 32b)
//          Word n : bit [31:0] - B_6[n]
// 0x1400 ~
// 0x147f : Memory 'B_7' (32 * 32b)
//          Word n : bit [31:0] - B_7[n]
// 0x1480 ~
// 0x14ff : Memory 'B_8' (32 * 32b)
//          Word n : bit [31:0] - B_8[n]
// 0x1500 ~
// 0x157f : Memory 'B_9' (32 * 32b)
//          Word n : bit [31:0] - B_9[n]
// 0x1580 ~
// 0x15ff : Memory 'B_10' (32 * 32b)
//          Word n : bit [31:0] - B_10[n]
// 0x1600 ~
// 0x167f : Memory 'B_11' (32 * 32b)
//          Word n : bit [31:0] - B_11[n]
// 0x1680 ~
// 0x16ff : Memory 'B_12' (32 * 32b)
//          Word n : bit [31:0] - B_12[n]
// 0x1700 ~
// 0x177f : Memory 'B_13' (32 * 32b)
//          Word n : bit [31:0] - B_13[n]
// 0x1780 ~
// 0x17ff : Memory 'B_14' (32 * 32b)
//          Word n : bit [31:0] - B_14[n]
// 0x1800 ~
// 0x187f : Memory 'B_15' (32 * 32b)
//          Word n : bit [31:0] - B_15[n]
// 0x1880 ~
// 0x18ff : Memory 'B_16' (32 * 32b)
//          Word n : bit [31:0] - B_16[n]
// 0x1900 ~
// 0x197f : Memory 'B_17' (32 * 32b)
//          Word n : bit [31:0] - B_17[n]
// 0x1980 ~
// 0x19ff : Memory 'B_18' (32 * 32b)
//          Word n : bit [31:0] - B_18[n]
// 0x1a00 ~
// 0x1a7f : Memory 'B_19' (32 * 32b)
//          Word n : bit [31:0] - B_19[n]
// 0x1a80 ~
// 0x1aff : Memory 'B_20' (32 * 32b)
//          Word n : bit [31:0] - B_20[n]
// 0x1b00 ~
// 0x1b7f : Memory 'B_21' (32 * 32b)
//          Word n : bit [31:0] - B_21[n]
// 0x1b80 ~
// 0x1bff : Memory 'B_22' (32 * 32b)
//          Word n : bit [31:0] - B_22[n]
// 0x1c00 ~
// 0x1c7f : Memory 'B_23' (32 * 32b)
//          Word n : bit [31:0] - B_23[n]
// 0x1c80 ~
// 0x1cff : Memory 'B_24' (32 * 32b)
//          Word n : bit [31:0] - B_24[n]
// 0x1d00 ~
// 0x1d7f : Memory 'B_25' (32 * 32b)
//          Word n : bit [31:0] - B_25[n]
// 0x1d80 ~
// 0x1dff : Memory 'B_26' (32 * 32b)
//          Word n : bit [31:0] - B_26[n]
// 0x1e00 ~
// 0x1e7f : Memory 'B_27' (32 * 32b)
//          Word n : bit [31:0] - B_27[n]
// 0x1e80 ~
// 0x1eff : Memory 'B_28' (32 * 32b)
//          Word n : bit [31:0] - B_28[n]
// 0x1f00 ~
// 0x1f7f : Memory 'B_29' (32 * 32b)
//          Word n : bit [31:0] - B_29[n]
// 0x1f80 ~
// 0x1fff : Memory 'B_30' (32 * 32b)
//          Word n : bit [31:0] - B_30[n]
// 0x2000 ~
// 0x207f : Memory 'B_31' (32 * 32b)
//          Word n : bit [31:0] - B_31[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XEUCDIS32_FLOAT_CONTROL_ADDR_AP_CTRL   0x0000
#define XEUCDIS32_FLOAT_CONTROL_ADDR_GIE       0x0004
#define XEUCDIS32_FLOAT_CONTROL_ADDR_IER       0x0008
#define XEUCDIS32_FLOAT_CONTROL_ADDR_ISR       0x000c
#define XEUCDIS32_FLOAT_CONTROL_ADDR_C_DATA    0x0010
#define XEUCDIS32_FLOAT_CONTROL_BITS_C_DATA    32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_C_CTRL    0x0014
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_BASE  0x0080
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_0_HIGH  0x00ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_0      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_0      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_BASE  0x0100
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_1_HIGH  0x017f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_1      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_1      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_BASE  0x0180
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_2_HIGH  0x01ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_2      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_2      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_BASE  0x0200
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_3_HIGH  0x027f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_3      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_3      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_BASE  0x0280
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_4_HIGH  0x02ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_4      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_4      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_BASE  0x0300
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_5_HIGH  0x037f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_5      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_5      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_BASE  0x0380
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_6_HIGH  0x03ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_6      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_6      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_BASE  0x0400
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_7_HIGH  0x047f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_7      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_7      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_BASE  0x0480
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_8_HIGH  0x04ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_8      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_8      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_BASE  0x0500
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_9_HIGH  0x057f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_9      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_9      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_BASE 0x0580
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_10_HIGH 0x05ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_10     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_10     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_BASE 0x0600
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_11_HIGH 0x067f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_11     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_11     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_BASE 0x0680
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_12_HIGH 0x06ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_12     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_12     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_BASE 0x0700
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_13_HIGH 0x077f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_13     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_13     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_BASE 0x0780
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_14_HIGH 0x07ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_14     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_14     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_BASE 0x0800
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_15_HIGH 0x087f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_15     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_15     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_BASE 0x0880
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_16_HIGH 0x08ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_16     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_16     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_BASE 0x0900
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_17_HIGH 0x097f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_17     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_17     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_BASE 0x0980
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_18_HIGH 0x09ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_18     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_18     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_BASE 0x0a00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_19_HIGH 0x0a7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_19     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_19     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_BASE 0x0a80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_20_HIGH 0x0aff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_20     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_20     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_BASE 0x0b00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_21_HIGH 0x0b7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_21     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_21     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_BASE 0x0b80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_22_HIGH 0x0bff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_22     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_22     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_BASE 0x0c00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_23_HIGH 0x0c7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_23     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_23     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_BASE 0x0c80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_24_HIGH 0x0cff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_24     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_24     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_BASE 0x0d00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_25_HIGH 0x0d7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_25     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_25     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_BASE 0x0d80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_26_HIGH 0x0dff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_26     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_26     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_BASE 0x0e00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_27_HIGH 0x0e7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_27     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_27     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_BASE 0x0e80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_28_HIGH 0x0eff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_28     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_28     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_BASE 0x0f00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_29_HIGH 0x0f7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_29     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_29     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_BASE 0x0f80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_30_HIGH 0x0fff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_30     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_30     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_BASE 0x1000
#define XEUCDIS32_FLOAT_CONTROL_ADDR_A_31_HIGH 0x107f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_A_31     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_A_31     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_BASE  0x1080
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_0_HIGH  0x10ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_0      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_0      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_BASE  0x1100
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_1_HIGH  0x117f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_1      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_1      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_BASE  0x1180
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_2_HIGH  0x11ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_2      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_2      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_BASE  0x1200
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_3_HIGH  0x127f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_3      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_3      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_BASE  0x1280
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_4_HIGH  0x12ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_4      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_4      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_BASE  0x1300
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_5_HIGH  0x137f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_5      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_5      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_BASE  0x1380
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_6_HIGH  0x13ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_6      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_6      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_BASE  0x1400
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_7_HIGH  0x147f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_7      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_7      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_BASE  0x1480
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_8_HIGH  0x14ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_8      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_8      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_BASE  0x1500
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_9_HIGH  0x157f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_9      32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_9      32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_BASE 0x1580
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_10_HIGH 0x15ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_10     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_10     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_BASE 0x1600
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_11_HIGH 0x167f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_11     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_11     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_BASE 0x1680
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_12_HIGH 0x16ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_12     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_12     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_BASE 0x1700
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_13_HIGH 0x177f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_13     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_13     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_BASE 0x1780
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_14_HIGH 0x17ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_14     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_14     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_BASE 0x1800
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_15_HIGH 0x187f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_15     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_15     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_BASE 0x1880
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_16_HIGH 0x18ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_16     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_16     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_BASE 0x1900
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_17_HIGH 0x197f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_17     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_17     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_BASE 0x1980
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_18_HIGH 0x19ff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_18     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_18     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_BASE 0x1a00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_19_HIGH 0x1a7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_19     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_19     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_BASE 0x1a80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_20_HIGH 0x1aff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_20     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_20     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_BASE 0x1b00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_21_HIGH 0x1b7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_21     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_21     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_BASE 0x1b80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_22_HIGH 0x1bff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_22     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_22     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_BASE 0x1c00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_23_HIGH 0x1c7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_23     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_23     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_BASE 0x1c80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_24_HIGH 0x1cff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_24     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_24     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_BASE 0x1d00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_25_HIGH 0x1d7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_25     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_25     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_BASE 0x1d80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_26_HIGH 0x1dff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_26     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_26     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_BASE 0x1e00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_27_HIGH 0x1e7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_27     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_27     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_BASE 0x1e80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_28_HIGH 0x1eff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_28     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_28     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_BASE 0x1f00
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_29_HIGH 0x1f7f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_29     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_29     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_BASE 0x1f80
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_30_HIGH 0x1fff
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_30     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_30     32
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_BASE 0x2000
#define XEUCDIS32_FLOAT_CONTROL_ADDR_B_31_HIGH 0x207f
#define XEUCDIS32_FLOAT_CONTROL_WIDTH_B_31     32
#define XEUCDIS32_FLOAT_CONTROL_DEPTH_B_31     32

