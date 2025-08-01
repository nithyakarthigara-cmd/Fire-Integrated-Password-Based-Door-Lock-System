#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Servo setup
Servo servo;

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Fire sensor and buzzer setup
const int fireSensorPin = A0;
const int flamePin = 12;
const int buzzerPin = 11;

// Servo position
const int lockedPosition = 0;
const int unlockedPosition = 90;

// Password setup
String password = "1234";  // Set password
String inputPassword = "";

void setup() {
  pinMode(fireSensorPin, INPUT);
  pinMode(flamePin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2); // Initialize LCD
  lcd.backlight();  // Turn on LCD backlight
  servo.attach(10);
  servo.write(lockedPosition);

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  int fireValue = analogRead(fireSensorPin);
  int flameStatus = digitalRead(flamePin);

  // Check for fire emergency
  if (flameStatus == LOW) { // Flame or fire detected
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("FIRE EMERGENCY!");
    servo.write(unlockedPosition);
    digitalWrite(buzzerPin, HIGH);
    delay(10000); // Keep the door open for 10 seconds
    digitalWrite(buzzerPin, LOW);
    servo.write(lockedPosition);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Password:");
  } else {
    char key = keypad.getKey();
    if (key) {
      if (key == '#') {  // Submit password with '#'
        if (inputPassword == password) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Access Granted");
          servo.write(unlockedPosition);
          delay(5000); // Keep the door open for 5 seconds
          servo.write(lockedPosition);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Enter Password:");
        } else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Access Denied");
          delay(2000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Enter Password:");
        }
        inputPassword = "";
      } else if (key == '*') {  // Clear input with '*'
        inputPassword = "";
        lcd.setCursor(0, 1);
        lcd.print("                "); // Clear the line
      } else {
        inputPassword += key;
        lcd.setCursor(0, 1);
        for (int i = 0; i < inputPassword.length(); i++) {
          lcd.setCursor(i, 1);
          lcd.print("*");
        }
      }
    }
  }
}

