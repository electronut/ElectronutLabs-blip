![blip](blip.jpg)

## Overview and features

Blip is a development board for Bluetooth Low Energy (BLE) and 802.15.4 based wireless applications, based on the Nordic Semiconductor nRF52840 SoC. It has a Black Magic Probe compatible programmer and debugger built-in along with temperature/humidity sensor, ambient light intensity sensor, and a 3-axis accelerometer. It is usable to prototype for very low power applications, and debugger and regulator can be disconnected when only SoC needs to be powered.

## Features 

* Raytac [MDBT50](https://www.raytac.com/product/ins.php?index_id=24) module based on [Nordic Semiconductor's nRF52840](https://www.nordicsemi.com/Products/Low-power-short-range-wireless/nRF52840)
* nRF52840 advanced single chip 2.4GHz multiprotocol SoC
* 32-bit ARM Cortex-M4F processor, 1MB flash + 256 kB RAM
* external crystal oscillator 32.768MHZ, on-chip 32MHz
* Power Supply: USB, JST connector for Li-ion/Li-po, Vext 1.8V - 3.3V
* BQ24079 battery charging and power management IC
* Built in 3.3V LDO for USB and Lipo
* MicroSD slot
* Bluetooth 5 support for long range and high throughput
* 802.15.2 radio support
* LIS2DDH12 High-performance 3-axis "femto" accelerometer 
* Optical Sensor LTR-329ALS-01
* Si7006-A20 I2C humidity and temperature sensor
* On board STM32F103CBT6 as Black magic probe debugger


## Operating conditions

**Maximum Input Voltage**

* USB powered : 5V
* Vext = 1.8V to 3.3V
* Vbat = Lithium ion/polymer 3.7/4.2V battery

**Power Ratings**

* Max current through USB: 150mA (for charging and/or system power)
* When powering with Vext, the debugger, charging IC, and LDO are bypassed for low current consumption

[Note: battery is not required for powering blip]
