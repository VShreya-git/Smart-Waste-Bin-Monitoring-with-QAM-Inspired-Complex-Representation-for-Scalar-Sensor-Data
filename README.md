# Smart Waste Bin Monitoring 

Rapid urbanization and population growth have led to a significant increase in daily waste generation, putting immense pressure on existing waste management systems. 
Traditional waste bins rely heavily on manual monitoring and collection, which often results in delayed responses and inefficient resource utilization.
Overflowing bins are a common issue in public spaces, leading to unhygienic conditions, foul odors, and potential environmental contamination. These conditions not only degrade the surroundings but also pose serious health risks.
Additionally, conventional systems lack real-time monitoring capabilities, making it difficult to track bin status and optimize waste collection routes. This leads to unnecessary fuel consumption, increased operational costs, and poor management efficiency.
Another critical limitation is the absence of safety monitoring. Harmful gases produced from decomposing waste often go undetected, posing risks to both the environment and human health.

## Requirements

Hardware:
- ESP32-WROOM-32E
- HC-SR04 Ultrasonic Sensor
- LM393 IR Sensor
- Gas Sensor
- Servo Motor
- LCD Display
- Keypad

Software:
- Arduino IDE

## System Architecture
<img width="675" height="662" alt="Screenshot 2026-03-31 183204" src="https://github.com/user-attachments/assets/1d820f42-d536-4649-a758-b0cb64ebec14" />


## System Workflow

The Smart Waste Bin operates through a continuous sensing–processing–response cycle controlled by the ESP32 microcontroller.

•	Ultrasonic sensing for fill-level measurement by calculating the distance between the waste and the lid

•	IR-based sensor detects user proximity, enabling automatic lid opening without physical contact

•	Gas sensing is integrated to detect harmful gases generated from waste decomposition

•	Servo motor is used to control the opening and closing of the lid based on sensor inputs

•	LCD display provides real-time status updates to users

•	WiFi-enabled alert communication to the registered mobile number

•	A Keypad-based PIN authentication system is implemented to provide secure access when the bin is locked due to full capacity or toxic gas detection, preventing misuse and enabling controlled operation

The system ensures hygienic operation, intelligent monitoring, and real-time response using an embedded hardware architecture.




