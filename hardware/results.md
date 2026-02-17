# Hardware Design
### Block Diagram

The block diagram illustrates the overall architecture of the Smart Waste Bin system.
The ESP32 acts as the central controller interfacing with:

•	Ultrasonic sensor (fill-level measurement)

•	IR sensor (proximity detection)

•	Gas sensor (toxic gas monitoring)

•	Servo motor (lid actuation)

•	LCD display (status output)

•	WiFi module (alert transmission)

All sensor inputs are processed locally before triggering actuation or communication events.
<img width="1061" height="1441" alt="Block diagram" src="https://github.com/user-attachments/assets/c1e1984a-bbb4-4485-b55e-9edbfbd366dd" />
