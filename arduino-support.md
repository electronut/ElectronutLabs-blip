## Using Blip with Arduino

Blip can be used with [Arduino](http://arduino.cc/)! The Arduino core is 
based on Adafruit's [nRF52 core](https://github.com/adafruit/Adafruit_nRF52_Arduino),
which is forked from [Sandeep Mistry's](https://github.com/sandeepmistry/arduino-nRF5)
Arduino core for Nordic Semiconductor chips.

### Installation

1. Download and install Arduino IDE (at least v1.6.12) from [Arduino website](https://www.arduino.cc/en/Main/Software).
2. Start the IDE
3. Go into preferences
4. Add `https://gitlab.com/electronutlabs-public/ElectronutLabs-blip/raw/master/package_electronutlabs_boards_index.json` as an "Additional Board Manager URL"
5. Open the Boards Manager from the Tools -> Board menu and search/install "Electronut labs nRF52840 Boards"
6. Select 'Electronut labs Blip' from the `Tools -> Board menu`
7. Select 'Black Magic Probe (GDB)' from the `Tools -> Programmer` menu

### Usage

The main USB port of Blip is connected to the on-board Blackmagicprobe 
debugger, and to your computer it will show up as two serial ports.

Thw first one of these is the GDB serial port, and is used for 
programming only. The second one is connected to UART pins of
nRF52840 (pins are reconfigurable on the chip).

Any code compiled right now requires [Nordic Semiconductor's](http://nordicsemi.com/) BLE stack binary, called the [Softdevice](https://www.nordicsemi.com/eng/Products/S140-SoftDevice) to be present on the 
nRF52840 chip. This needs to be programmed only once while using arduino.
To do this, click on `Tools -> Burn bootloader` menu option.

Note about serial ports: In this arduino core, `Serial` is the
serial port that comes up when you plug in the secondary USB port of
blip to your computer. This one is USB device peripheral of the nRF52840
chip. `Serial1` is the actual UART peripheral of nRF52840 SoC, and it is
connected to the Debugger's serial port (which comes up as the second 
serial port on your computer). In Arduino IDE, you have to select the 
first port for programming; this means serial montor will not work with 
that one. To use serial monitor, you can switch to the second port
temporarily.

### Pin mapping

Pin mumbers are directly connected to the nRF52840 port/pin numbers. Pin numbers 0-31 are on the chip's Port0. Pin numbers above 32 are on Port1. For example, pin 16 corresponds to Port0, pin 16; pin 40 correseponds to Port1 pin 8 (i.e. 40-32).

You can use the following symbols in your code:

#### LEDs

    PIN_LED1             pin 13
    PIN_LED2             pin 14
    PIN_LED3             pin 15

    LED_BUILTIN          PIN_LED1
    LED_CONN             PIN_LED2

    LED_GREEN            PIN_LED1
    LED_RED              PIN_LED2
    LED_BLUE             PIN_LED3

#### Buttons

    PIN_BUTTON           pin 38

#### UART

This serial port is connected to the Black Magic Probe debugger's USB to serial pins.

    PIN_SERIAL_RX       8
    PIN_SERIAL_TX       6

#### SPI

The SPI pins are connected to the microSD card slot. The pin mapping is as follows:

    MISO         pin 25
    MOSI         pin 34
    SCK          pin 24
    SS           pin 17

To use another SPI device, second SPI is available to use as `SPI1`, with 
the pin mapping:

    MISO         pin 26
    MOSI         pin 23
    SCK          pin 27

### Troubleshooting

A known issue with blip is that sometimes the debugger is not able to detect the 
nRF52840 chip when it scans. This happens rarely, and there is a manual fix for
that. 

**Option 1**: One can either repeatedly try uploading (which takes time if
compiling), or by trying 'Burn bootloader' (Alt+T, then Up, then enter). If you
can run `arm-none-eabi-gdb` directly, you can run it like in the following 
terminal capture. First we specify the GDB serial port (which is the first port
detected when Blip is connected to your computer) using `tar ext <GDB port>`.
Next, try scanning using the command `mon swdp_scan`. Keep on pressing enter
till the chip is detected:

Following is output when chip is not detected:
```bash
$ arm-none-eabi-gdb
GNU gdb (GNU Tools for Arm Embedded Processors 7-2018-q3-update) 8.1.0.20180315-git
...
...
>>> tar ext /dev/ttyACM0
Remote debugging using /dev/ttyACM0
>>> mon swdp_scan
Target voltage: unknown
SW-DP scan failed!
```

Following is output when it gets detected:
```bash
