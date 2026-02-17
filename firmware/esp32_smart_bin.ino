#include <ESP32Servo.h>
#include <LiquidCrystal.h>

// ---------- Pin Definitions ----------
const int IR_PIN = 34;              // IR sensor output pin
const bool IR_ACTIVE_STATE = LOW;   // set LOW if IR outputs LOW when object detected
const int SERVO_PIN = 13;           // Servo signal pin

// Ultrasonic sensor pins
const int TRIG_PIN = 25;
const int ECHO_PIN = 33;

// LED pins
const int GREEN_LED = 26;
const int RED_LED   = 27;

// Gas sensor pin
const int GAS_PIN = 32;             // MQ sensor AO pin
const int GAS_THRESHOLD = 1800;     // tune this as per your sensor output

// LCD connections
const int RS = 23;
const int EN = 22;
const int D4 = 18;
const int D5 = 19;
const int D6 = 21;
const int D7 = 5;

// ---------- Parameters ----------
const unsigned long openDuration = 3000UL;
const int binFullDistance = 4;  // cm threshold for "bin full"

// ---------- Globals ----------
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
Servo servo;

bool lidOpen = false;
unsigned long lidOpenedAt = 0;
bool binWasFull = false; // <--- NEW flag to detect state change

void setup() {
  Serial.begin(115200);

  pinMode(IR_PIN, INPUT);
  pinMode(GAS_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  servo.attach(SERVO_PIN);
  servo.write(0);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart Bin Ready");
  lcd.setCursor(0, 1);
  lcd.print("LID: CLOSED");

  Serial.println("System initialized. Waiting for IR detection...");
}

void loop() {
  long distance = getDistance();
  int irVal = digitalRead(IR_PIN);
  int gasValue = analogRead(GAS_PIN);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | IR: ");
  Serial.print(irVal == IR_ACTIVE_STATE ? "DETECTED" : "CLEAR");
  Serial.print(" | Gas: ");
  Serial.println(gasValue);

  // ----- BIN FULL -----
  if (distance > 0 && distance <= binFullDistance) {
    servo.write(0);
    lidOpen = false;
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    if (!binWasFull) {  // <--- only refresh LCD once when state changes
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Bin is Full!");
      lcd.setCursor(0, 1);
      lcd.print("Please empty bin");
      Serial.println("Bin full! Lid locked.");
      binWasFull = true;
    }

    delay(300);
    return;
  }

  // ----- BIN NOT FULL -----
  else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    // when bin transitions from full → not full
    if (binWasFull) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Bin Cleared :)");
      lcd.setCursor(0, 1);
      lcd.print("LID: CLOSED");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ready for Use");
      lcd.setCursor(0, 1);
      lcd.print("LID: CLOSED");
      binWasFull = false;
    }

    // normal IR-based opening
    if (irVal == IR_ACTIVE_STATE && !lidOpen) {
      openLid();
    }

    if (lidOpen && (millis() - lidOpenedAt >= openDuration)) {
      closeLid();
    }
  }

  // ----- GAS SENSOR STATUS -----
  lcd.setCursor(0, 1);
  if (gasValue < GAS_THRESHOLD) {
    lcd.print("Gas: Normal   ");
  } else {
    lcd.print("Gas: Abnormal ");
    Serial.println("⚠ WARNING: Gas Level HIGH!");
  }

  delay(200);
}

void openLid() {
  servo.write(90);
  lidOpen = true;
  lidOpenedAt = millis();

  Serial.println("Lid opened");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LID: OPEN");
}

void closeLid() {
  servo.write(0);
  lidOpen = false;

  Serial.println("Lid closed after timeout");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Thank you :)");
  lcd.setCursor(0, 1);
  lcd.print("Have a great day!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LID: CLOSED");
}

// ---------- Ultrasonic Helper ----------
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;

  long distance = (duration * 0.0343) / 2.0;
  return distance;}
