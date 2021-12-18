
// Import required libraries
#include <ArducamSSD1306.h>    // Modification of Adafruit_SSD1306 for ESP8266 compatibility
#include <Adafruit_GFX.h>   // Needs a little change in original Adafruit library (See README.txt file)
#include <Wire.h>           // For I2C comm, but needed for not getting compile error

/*
HardWare I2C pins
A4   SDA
A5   SCL
*/

// Pin definitions
#define OLED_RESET  16  // Pin 15 -RESET digital signal

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
int r =0;
ArducamSSD1306 display(OLED_RESET); // FOR I2C


void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // SSD1306 Init
  display.begin();  // Switch OLED
  // Clear the buffer.



}


void loop() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(5,0);
  display.println("BACK|RIGHT");
  display.setCursor(5,15);
  display.println("    |     ");
  display.setCursor(5,30);
  display.println("    |     ");
  display.setCursor(5,45);
  display.println("    |     ");
  display.setCursor(5,60);
  display.println("    |     ");
  display.setCursor(5,30);
  display.println("STOP");
  display.setCursor(64,30);
  display.println(r);
  display.setCursor(84, 30);
  display.println(" cm");
  r += 1;
  display.display();
}
