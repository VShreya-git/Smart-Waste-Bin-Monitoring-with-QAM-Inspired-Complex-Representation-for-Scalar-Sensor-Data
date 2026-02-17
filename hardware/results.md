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

<img width="234" height="106" alt="Picture4" src="https://github.com/user-attachments/assets/9801987f-fb15-487c-bc0d-bfbd98622cd7" />

System powers on and initializes sensors and LCD display.

Automatic Lid Operation

<img width="234" height="119" alt="Picture5" src="https://github.com/user-attachments/assets/f00476de-5f4c-46fc-9f85-8fc6b67883c2" />

When hand proximity is detected, the servo motor opens the lid automatically.

Bin Full Detection

<img width="241" height="109" alt="Picture6" src="https://github.com/user-attachments/assets/038376d4-ad0b-4928-89e0-072ec67a5743" />

When fill-level distance falls below threshold, a “Bin Full” message is displayed and a notification is sent.

Toxic Gas Alert

<img width="242" height="93" alt="Picture7" src="https://github.com/user-attachments/assets/243a82d4-4ab8-4b93-bf60-762b17f58243" />

When gas concentration exceeds safety limits, a warning message is displayed and an alert is transmitted.

Telegram message sent to registered no. for bin full and toxic gas alert

<img width="242" height="93" alt="Picture7" src="https://github.com/user-attachments/assets/a0d36035-fbaf-46e0-ae6c-2e558d4eefdd" />


