# Installation of prerequisite libraries
## Installing ATTinyCore to use the ATtiny861 MCU
To be able to use the ATtiny861 with Arduino IDE you must first install the ATTinyCore board library from SpenceKonde.
To  install the board library, open Arduino IDE and select `File -> Preferences`

![How to open Preferences](/docs/open-preferences.png)

In this menu, paste "`http://drazzy.com/package_drazzy.com_index.json`" without quotes into the `Additional Boards Manager URLs`

![Correct value of additional URLs](/docs/add-boards.png)

Next close the `Preferences` window, and select `Tools -> Board: -> Boards Manager...` from the IDE

![How to open boards manager](/docs/open-boardmanager.png)

In the manager window's search bar type "`attinycore`" without quotes and press enter. After the search completes, select `ATTinyCore` and press `Install`

![How to use the boards manager](/docs/install-attinycore.png)

After the installation finishes, it is recommended to close and reopen the IDE.


## Installing DS18B20 sensors' libraries
Installing these libraries is not mandatory when using analog temperature sensors, unless using the example code without modifications.
To install the code libraries, start by downloading the following files:
- [`OneWire`](http://www.pjrc.com/teensy/arduino_libraries/OneWire.zip)
- [`DallasTemperature`](https://github.com/milesburton/Arduino-Temperature-Control-Library/archive/refs/heads/master.zip)

Once the .zip files have been downloaded, open Arduino IDE and select `Sketch -> Include Library -> Add .ZIP Library...`

![How to add a .zip library](/docs/add-libraries.png)

From this menu, first select the `OneWire.zip` file from your downloads folder, then repeat the previous step and select `Arduino-Temperature-Control-Library-master.zip`.
Now all the prerequisites should be installed, and you can proceed to [programming](/docs/programming.md).
