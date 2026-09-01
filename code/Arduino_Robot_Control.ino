#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo handServo;
Servo presentationServo;

const int HAND_SERVO_PIN = 9;
const int PRESENTATION_SERVO_PIN = 10;

void setup() {
  lcd.init();
  lcd.backlight();

  handServo.attach(HAND_SERVO_PIN);
  presentationServo.attach(PRESENTATION_SERVO_PIN);

  handServo.write(90);
  presentationServo.write(20);

  showWelcome();
}

void loop() {
  // Demonstration sequence can be triggered here.
}

void showWelcome() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome Guest!");
  lcd.setCursor(0, 1);
  lcd.print("Have a Nice Day");
}

void presentRose() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("A Rose for You");

  presentationServo.write(90);
  delay(1500);

  handServo.write(130);
  delay(1000);

  handServo.write(90);
  presentationServo.write(20);
}
