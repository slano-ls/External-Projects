#include <LiquidCrystal.h>
LiquidCrystal lcd (7, 8, 9, 10, 11, 12);
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

  double whiteTime = 600000;
  int whiteMinutes = 0;
  int whiteSeconds = 0;
  double whiteLastCheck = millis();
  double blackTime = 600000;
  int blackMinutes = 0;
  int blackSeconds = 0;
  double blackLastCheck = millis();
  bool isWhiteTurn = true;
  bool gameOver = false;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  UpdateWhiteTime();
  UpdateBlackTime();

  //int whiteButtonState = 0;
  //int blackButtonState = 0;
}
void loop() {
  int reading = digitalRead(buttonPin);
    Serial.println(ledState);

  if (reading != lastButtonState) {

    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }// set the LED:
  digitalWrite(ledPin, ledState);
  if(ledState==1){
    StartWhiteTurn ();
        Serial.println("White");
    UpdateWhiteTime();
  } else if(ledState==0){
    StartBlackTurn ();
        Serial.println("Black");
    UpdateBlackTime();
  }
lastButtonState = reading;
}
void UpdateWhiteTime() {
  lcd.setCursor(10,0);
  lcd.print("White");
  lcd.setCursor(12, 1);
      Serial.println("White");
  whiteTime -= ((millis() - whiteLastCheck));
  whiteLastCheck = millis();
  if (whiteTime <= 0) {
    gameOver = true;
    lcd.print("LOSE");
    return;
  }
  whiteMinutes = floor(whiteTime / 60000);
  whiteSeconds = floor(whiteTime / 1000) - whiteMinutes * 60;
  lcd.print(whiteMinutes);
  lcd.print(":");
  if (whiteSeconds < 10) {
    lcd.print(0);
  }
  lcd.print(whiteSeconds);
}// end printWait
void UpdateBlackTime() {
  lcd.setCursor(1,0);
  lcd.print("Black");
  lcd.setCursor(0, 1);
      Serial.println("Black");
  blackTime -= ((millis() - blackLastCheck));
  blackLastCheck = millis();
  if (blackTime <= 0) {
    gameOver = true;
    lcd.print("LOSE");
    return;
  }
  blackMinutes = floor(blackTime / 60000);
  blackSeconds = floor(blackTime / 1000) - blackMinutes * 60;
  lcd.print(blackMinutes);
  lcd.print(":");
  if (blackSeconds < 10) {
    lcd.print(0);
  }
  lcd.print(blackSeconds);
}// end printWait
void StartWhiteTurn () {
  if (isWhiteTurn) {
    return;
  }
  isWhiteTurn = true;
  whiteLastCheck = millis();
} // end StartWhiteTurn
void StartBlackTurn () {
  if (!isWhiteTurn) {
    return;
  }
  isWhiteTurn = false;
  blackLastCheck = millis();
} // end StartBlackTurn
