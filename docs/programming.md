# Programming the ATtiny861 MCU
Once the [prerequisites](/docs/prerequisites.md) have been installed, the MCCU can be programmed as follows:

## Preparing the ISP
In order to program the MCU, an ISP programmer is needed. For this an arduino board will be used with the `Arduino as ISP` sketch.

### Uploading the `ArduinoISP` sketch
Connect the arduino board to the computer and select it in the Arduino IDE.
Next, open the `ArduinoISP` sketch from `File -> Examples -> 11. ArduinoISP -> ArduinoISP`.

![How to open the Arduino as ISP sketch](/docs/open-arduinoisp.png)

Once the sketch is open, upload it to the arduino being used as a programmer.

### Connecting the programmer and ATtiny IC
First disconnect the arduino from the computer, then wire up the ATtiny IC as follows:

`Arduino Uno  ->  ATtiny x61`
- Pin 10      ->  Reset   (PB7)
- Pin 11      ->  MOSI    (PB0)
- Pin 12      ->  MISO    (PB1)
- Pin 13      ->  SCK     (PB2)
- 5V          ->  VCC, AVCC
- GND         ->  GND, AGND

When wiring, the following image should be used as the ATtiny's pinout diagram:

![ATtiny x61 pinout](/docs/Pinout_x61.jpg)

When finished, the wiring should look something like this:

![Picture of programmer wiring](/docs/wiring.JPG)

Now you can reconnect the arduino to the computer and proceed with programming.

## Programming the ATtiny IC

### Uploading a bootloader
Before the main program can be uploaded to the ATtiny, a bootloader must be written to it first.
Start by setting the board to `ATtiny261/461/861(a)` from `Tools -> Board: -> ATTinyCore`.

![How to select the correct board](/docs/select-x61.png)

Next, select the `ATtiny861(a)` chip from `Tools -> Chip:`.

![How to select the correct chip](/docs/chip-settings.png)


Additionally the settings should be set to those shown in the previous image, **except** for `Pin Mapping`, which should be set to `Legacy`.
Once the settings are correct, select `Arduino as ISP` as the programmer from `Tools -> Programmer:` and burn the bootloader from `Tools`.

![How to burn the bootloader](/docs/burn-bootloader.png)

After the bootloader has finished uploading, the message `Done burning bootloader.` should be show near the bottom of the IDE window.

![Bootloader success message](/docs/bootloader-burning-message.png)

You can now upload your own sketches to the ATtiny861 IC.
