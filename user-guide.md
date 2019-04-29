Blip User Guide
===============

## Powering Blip

Blip can be powered in three ways:

* Either USB port - the power switch should be in REG position.
* Vext pin on header - the power switch should be in VEXT position
* Battery connector - the power switch should be in REG position

Blip can be programmed via the BMP USB port. This USB port comes up on your
computer like as a composite USB device with two serial ports. The first one
is the GDB server port from the Blackmagic probe debugger, and the second one is
connected to the serial port on nRF52840 (the pins from nRF52840 have to be
configured as serial in/out correctly in the firmware as any pin can be RX/TX
on it).

The label on the board for `system power` is `VDD`, it can either come from
onboard voltage regulator, or from external power pin. Further details follow.

When the power switch position is REG, the system is powered at VDD=3.3V from
the LDO; it's input can be either the battery connector, or either of the USB
ports. A battery and USB can be connected together, and the onboard Li-ion/Lipo
battery charging IC will recharge the battery (at a max current of 150mA).

When the switch position is VEXT, the nRF52840 chip is directly powered using
the VEXT pin. `WARNING!!`: maximum `VEXT` pin input is 3.3V; higher voltages
may damage the SoC or the sensors.

Note: Do not flip the switch's position while it is powered, it will not
function correctly otherwise, i.e., always put switch in correct position before
powering it on.

## Using SWD debugger for external chips

The onboard blackmagic probe is able to program and debug other supported ARM
chips. We generally test Nordic Semiconductor's NRF52 series chips with Bumpy
firmware, which is running on Blip's STM32 chip.

First (while Blip is powered off), put the power switch in VEXT position. Do not
connect any input voltage to `VEXT` pin, this copletely turns off and isolates
the SoC from the debugger. In this configuration, only the debugger is getting
any power.

Next, connect the pins `T_SWDIO`, `T_SWDCLK` to the target. Also make sure there
is common ground between Blip and target. The supported target voltage is 3.3V.

Now you can run gdb and scan for devices like:

```bash
tavish@computer:~/repos/el/public/ElectronutLabs-blip (master)*$ arm-none-eabi-gdb
GNU gdb (GNU Tools for Arm Embedded Processors 7-2018-q3-update) 8.1.0.20180315-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
(gdb) tar ext /dev/ttyACM0
Remote debugging using /dev/ttyACM0
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
0x0000384c in ?? ()
(gdb) mon swdp_scan
Target voltage: unknown
Available Targets:
No. Att Driver
 1      Nordic nRF52
 2      Nordic nRF52 Access Port
(gdb) att 1
A program is being debugged already.  Kill it? (y or n) y
Attaching to Remote target
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
0x0000384c in ?? ()
```

## Current measurement

To measure your firmware's current consumption, for example with Nordic
semiconductor's [power profiler kit](https://www.nordicsemi.com/Software-and-Tools/Development-Kits/Power-Profiler-Kit)
, first put the power selection switch to `VEXT` position. Now you must power
the board via only `VEXT` pin on the header. In this configuration debugger is
completely isolated from the nRF52840 chip using an onboard analog switch; you
should not connect either of the USB ports also.
