#include <LiquidCrystal.h>
#include <Servo.h>

const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN  = 6; // Arduino pin connected to servo motor's pin

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo;

// variables:
bool gateOpen = false;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void updateGate();

void setup() {
  lcd.begin(16, 2);
  lcd.print("Estado:");
  servo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  updateGate();
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed and button is pressed
    if (lastButtonState == HIGH && reading == LOW) {
      gateOpen = !gateOpen;
      updateGate();
    }
  }
  lastButtonState = reading;
}

void updateGate() {
  lcd.setCursor(0, 1);
  if (gateOpen) {
    servo.write(90); // adjust angle for open position
    lcd.print("Aberta        "); // clear with spaces
  } else {
    servo.write(0); // closed position
    lcd.print("Fechada       "); // clear with spaces
  }
}
