# Smart-Waste-Bin-Monitoring-with-QAM-Inspired-Complex-Representation-for-Scalar-Sensor-Data

This project presents a novel QAM-inspired complex-domain analytical framework for interpreting scalar IoT sensor data from a Smart Waste Bin prototype.

Traditional IoT systems process sensor data using thresholding, averaging, or basic time-domain techniques. These scalar-only approaches fail to capture the relationship between instantaneous sensor value and its temporal variation.
Inspired by Quadrature Amplitude Modulation (QAM) in communication systems, this work maps scalar sensor readings into the complex plane, enabling hybrid signal-processing analysis combining magnitude and rate-of-change information.

### Core Concept
Each scalar sensor sample is transformed into a complex representation:

Where:  Zn = Xn  + j(Xn  - Xn-1 )
Real part (I) → Normalized sensor value
Imaginary part (Q) → Discrete derivative (rate of change)
Magnitude |zₙ| → Activity intensity
Phase θₙ → Direction of temporal behavior

This enables:
Complex-plane trajectory visualization
Phase-based event detection
Dynamic feature extraction
Modulation-style sensor analytics

### System Architecture
Hardware Components:
ESP32-WROOM-32E microcontroller
HC-SR04 Ultrasonic Sensor (fill level detection)
LM393 IR Sensor (proximity detection)
Servo Motor (automatic lid control)
Gas Sensor (toxic gas monitoring)
16x2 LCD Display
In-built WiFi module (Telegram alerts)

