# Wheelchair Object Detection

## Introduction
For wheelchair users, especially power wheelchair users, it can be hard to see what's behind the chair, especially when backing up or turning, and since a power wheelchair can weigh upwards of 350 lbs, getting run over by a power wheelchair is very painful. The aim of this project is to solve that problem by creating a low-cost device that can detect obstacles and warn the wheelchair user so they don't hit objects or people, similar to how a car has object detection when backing up. 

## Materials

### Microcontroller
[Arduino MEGA 2560 Rev3](https://store.arduino.cc/products/arduino-mega-2560-rev3): Arduino boards are low cost and are programmed in C++, which makes it easy to use for this project. 

### Sensors
2 ultrasonic sensors: ultrasonic sensors are pretty accurate and have a large range. 1 of the sensors is used to detect objects when backing up, and the other one is to detect objects while turning.

### LEDs 
2 red LEDS: These LEDS are programmed to blink at different speeds and brightnesses based on the distance from the object. Each of the LEDs corresponds with a ultrasonic sensor 
