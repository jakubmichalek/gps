#include <SoftwareSerial.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiAvrI2c.h>
#include <TinyGPS++.h>

#define I2C_ADDRESS 0x3C

SSD1306AsciiAvrI2c oled;

SoftwareSerial gpsModul(2, 3);
TinyGPSPlus gps;

void setup(){
  gpsModul.begin(9600);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(TimesNewRoman13);

  uint32_t m = micros();
  oled.clear();
  oled.setCursor(25,0);
  oled.set1X();
  oled.println("MopsikoGPSka");
}

void loop(){
  if (gpsModul.available()){
    gps.encode(gpsModul.read());
  }

oled.print("ZS: ");
oled.println(gps.location.lat(), 6);
oled.print("ZD: ");
oled.println(gps.location.lng(), 6);
  }

