#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define AVERAGING_VALUES_COUNT 5

const byte rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define ONE_WIRE_BUS 3
#define TEMPERATURE_PRECISION 9

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress sensor0, sensor1;

bool useDigitalSensors = true;
const byte analogSensorPins[] = {0, 1};

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  sensors.begin();
  sensors.setResolution(sensor0, TEMPERATURE_PRECISION);
  sensors.setResolution(sensor1, TEMPERATURE_PRECISION);

  lcd.print("Digital T-meter");
  lcd.setCursor(0, 1);
  lcd.print("Found ");
  lcd.print(sensors.getDeviceCount());
  lcd.print(" sensor/s");
  delay(2500);

  if (sensors.getDeviceCount() == 0) {
    useDigitalSensors = false;
    analogReference(INTERNAL1V1);
    lcd.setCursor(0, 0);
    lcd.print("Defaulting to   ");
    lcd.setCursor(0, 1);
    lcd.print("analog sensors  ");
    delay(2500);

    for (byte i = 0; i < AVERAGING_VALUES_COUNT; i++) {
      readTemp(0);
      readTemp(1);
    }
  }
}

void loop() {
  updateLCD();
  delay(500);
}

void updateLCD() {
  char linebuffer[17];
  char tempbuffer[6];
  float sensor0temp = readTemp(0);
  float sensor1temp = readTemp(1);

  lcd.setCursor(0, 0);
  sprintf(linebuffer, "Interior: % 2d.%1dC", (int)sensor0temp, abs((int)(sensor0temp * 10) % 10));
  lcd.print(linebuffer);
  lcd.setCursor(0, 1);
  sprintf(linebuffer, "Exterior: % 2d.%1dC", (int)sensor1temp, abs((int)(sensor1temp * 10) % 10));
  lcd.print(linebuffer);
}

float readTemp(uint8_t index) {
  float temperature = 6.9;
  static byte averagingIteration;
  static float readings[2][AVERAGING_VALUES_COUNT];

  switch (useDigitalSensors) {
    case true:
      sensors.requestTemperatures();
      temperature = sensors.getTempCByIndex(index);
      if (temperature == DEVICE_DISCONNECTED_C) {
        return -99.9;
      }
      break;

    case false:
      // TMP36 formula:   temp(C) = (V - 0.5) / 0.01
      // Voltage formula: voltage = (adcValue * Vref) / adcMaxValue (1023)
      const float voltage = ((float)analogRead(analogSensorPins[index]) * 1.1) / 1023.0;
      temperature = (voltage - 0.5) / 0.01;
      break;
  }

  readings[index][averagingIteration] = temperature;

  averagingIteration++;
  if (averagingIteration >= AVERAGING_VALUES_COUNT)
    averagingIteration = 0;

  float avgTemperature = 0.0;
  for (byte i = 0; i < AVERAGING_VALUES_COUNT; i++) {
    avgTemperature += readings[index][i];
  }
  return avgTemperature / AVERAGING_VALUES_COUNT;
}
