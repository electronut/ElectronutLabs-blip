![blip](blip.jpg)

## Overview and Features

Blip is a development board for Bluetooth Low Energy (BLE) and 802.15.4 based wireless applications, based on the Nordic Semiconductor nRF52840 SoC. It has a Black Magic Probe compatible programmer and debugger built in, along with temperature/humidity sensor, ambient light intensity sensor, and a 3-axis accelerometer. It is usable to prototype for very low power applications. It also provides provision for SD card, which makes it a complete and versatile device.

## Features 

* Raytac MDBT50Q-1M based on Nordic Semiconductor's nRF52840
* Power Supply: USB, JST connector for Li-ion/Li-po
* BQ24079 battery charging and power management IC
* MicroSD slot
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

