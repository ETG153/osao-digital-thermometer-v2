# Digital thermometer V2
An educational project for use by students of the [OSAO Educational Consortium](https://www.osao.fi/en/).
Other uses are under the GPLv3 license.

The aim of this project is to  build a digital thermometer based on the ATtiny861 MCU from Atmel Corporation.

## Prerequisite software
### PCB design
- `PADS` from Siemens EDA

As the students this is written for should have this software already installed, instructions for its installation will be excluded for brevity.

### Embedded programming
- [`Arduino IDE`](https://github.com/arduino/Arduino/), version 1.8.13 recommended

Additionally, the following libraries will be needed. For full instructions on their installation, see [`prerequisites.md`](/docs/prerequisites.md).
- [`ATTinyCore`](https://github.com/SpenceKonde/ATTinyCore) for using the ATtiny861 MCU
- A OneWire library for interfacing with the DS18B20 digital temperature sensors. If using the TMP3x sensors instead, this is not needed.
- The [`DallasTemperature`](https://github.com/milesburton/Arduino-Temperature-Control-Library/) library for easier interfacing with the DS18B20 sensors. If using the TMP3x sensors instead, this is not needed.

## Assembly
At this point the students may be instructed to design their own PCBs, which falls outside the scope of this guide.
If the example layout is used, the following parts will be needed for assembly:
- 3x 100nF capacitors
- 1x 7805 regulator (Preferrably in a TO-220 package)
- 1x DIP-20 socket (Optional but highly recommended)
- 1x ATtiny861 MCU in a DIP-20 package

Additionally, depending on which sensors you intend to use, you will need one of the following component sets.
**For DS18B20:**
- 2x DS18B20 temperature sensors
- 1x 4.7 kOhm resistor

**For TMP3x:**
- 2x 10nF capacitors (Optional but recommended for noise reduction)
  - If the sensors are not mounted onto the board, the capacitors should be mounted as close to the sensors as possible.
- 2x TMP3x temperature sensors (Project developed for and tested with TMP36 sensors)

Assemble the board by soldering the components into their places on the PCB. If you are not using a DIP socket, do not solder the MCU onto the board yet.

## Programming
At this point the students may be either instructed to use the [`example code`](/arduino-code/thermometer_x61/thermometer_x61.ino), or to write their own code. If this is the case when using the example PCB, refer to the schematic for which pins to use.
For detailed instructions on how to upload programs to the ATtiny861, see [`programming.md`](/docs/programming.md).
Once the MCU has been programmed it may be socketed (or soldered if no socket was used) onto the PCB, finishing the project.
