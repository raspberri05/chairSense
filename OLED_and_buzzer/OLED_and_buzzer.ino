#include <ArducamSSD1306.h>    // Modification of Adafruit_SSD1306 for ESP8266 compatibility
#include <Adafruit_GFX.h>   // Needs a little change in original Adafruit library (See README.txt file)
#include <Wire.h>           // For I2C comm, but needed for not getting compile error

/*
HardWare I2C pins
20   SDA
21   SCL
*/

// Pin definitions
#define OLED_RESET  16  // Pin 15 -RESET digital signal
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

const int echoB = 2;
const int trigB = 3; 
const int echoS = 4;
const int trigS = 5;
const int buzzer = 6;
float durationB, durationS, distanceB, distanceS; 

ArducamSSD1306 display(OLED_RESET); // FOR I2C

void setup(void)
{
  // Start Serial
  Serial.begin(115200);
  pinMode(echoB, INPUT); 
  pinMode(trigB, OUTPUT); 
  pinMode(echoS, INPUT);
  pinMode(trigS, OUTPUT); 
  pinMode(buzzer, OUTPUT);
  // SSD1306 Init
  display.begin();  // Switch OLED
  // Clear the buffer.
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void displaySetup() {
  display.clearDisplay();
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
}

int calculateDistance(int duration, int distance, int trig, int echo) {
  digitalWrite(trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  duration = pulseIn(echo, HIGH); 
  distance = (duration*.0343)/2 - 5;
  return distance;
  }

void detectObstacle(int duration, int distance, int trig, int echo, int start) {
  distance = calculateDistance(duration, distance, trig, echo);
  if (distance < 0) {
    distance = 0;
  }
  if (distance <= 30 && distance > 5) {
    display.setCursor(start+15, 30);
    display.println(" cm");
    display.setCursor(start, 30);
    display.println(distance);
  } 
  else if (distance <= 5) {
    display.setCursor(start,30);
    display.println("STOP!   ");
    tone(buzzer,1000);
  }
}

void loop() {
  noTone(buzzer);
  displaySetup();
  detectObstacle(durationB, distanceB, trigB, echoB, 0);
  detectObstacle(durationS, distanceS, trigS, echoS, 64);
  display.display();
  //5 or 64
  // +15 px to get from num to cm
}
