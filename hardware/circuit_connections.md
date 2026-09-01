# Circuit Connections

## Arduino UNO - LCD Display (I2C)

| LCD | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## Arduino UNO - Servo Motors

| Servo | Arduino UNO |
|---|---|
| Hand Servo Signal | D9 |
| Arm/Presentation Servo Signal | D10 |
| VCC | External regulated 5V supply |
| GND | Common Ground |

> Use an adequate external supply for motors/servos. Do not power high-load motors directly from an Arduino pin.

## ESP32 - Motor Driver

The exact GPIO pins depend on the motor driver and chassis wiring. The sample code uses:

| Motor Driver Input | ESP32 |
|---|---|
| IN1 | GPIO 25 |
| IN2 | GPIO 26 |
| IN3 | GPIO 27 |
| IN4 | GPIO 14 |

## System Architecture

```
Bluetooth Phone Controller
          |
          v
        ESP32
          |
     Motor Driver
          |
       DC Motors
          |
      Mobile Base

Arduino UNO
   |       |
   v       v
 LCD     Servo Motors
          |
     Rose Presentation
```

The Arduino and ESP32 can operate as separate controllers. Ensure all modules share an appropriate common ground when required by the hardware design.
