/*
 ESP32 Bluetooth RC Mobile Base
 Uses Bluetooth Serial commands:
 F = Forward
 B = Backward
 L = Left
 R = Right
 S = Stop
*/

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int IN1 = 25;
const int IN2 = 26;
const int IN3 = 27;
const int IN4 = 14;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Hospitality_Robot");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      default: stopRobot(); break;
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
