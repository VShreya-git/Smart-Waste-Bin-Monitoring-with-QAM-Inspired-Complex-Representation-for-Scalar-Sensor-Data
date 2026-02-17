# Hardware Design
### 1. Block Diagram

The block diagram illustrates the overall architecture of the Smart Waste Bin system.
The ESP32 acts as the central controller interfacing with:

•	Ultrasonic sensor (fill-level measurement)

•	IR sensor (proximity detection)

•	Gas sensor (toxic gas monitoring)

•	Servo motor (lid actuation)

•	LCD display (status output)

•	WiFi module (alert transmission)

All sensor inputs are processed locally before triggering actuation or communication events.

<img width="400" height="543" alt="Block diagram" src="https://github.com/user-attachments/assets/70197f70-08eb-4b5c-bc83-02f9e0ab8e7a" />

### 2. Hardware Setup

![Setup](https://github.com/user-attachments/assets/e0622999-5c1f-453a-9eab-01a2934e017b)

### 3. Demonstration Results
Bin Initialization

System powers on and initializes sensors and LCD display.

Automatic Lid Operation

When hand proximity is detected, the servo motor opens the lid automatically.

Bin Full Detection

When fill-level distance falls below threshold, a “Bin Full” message is displayed and a notification is sent.

Toxic Gas Alert

When gas concentration exceeds safety limits, a warning message is displayed and an alert is transmitted.
