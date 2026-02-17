# Smart-Waste-Bin-Monitoring-with-QAM-Inspired-Complex-Representation-for-Scalar-Sensor-Data

This project presents a novel QAM-inspired complex-domain analytical framework for interpreting scalar IoT sensor data from a Smart Waste Bin prototype.

Traditional IoT systems process sensor data using thresholding, averaging, or basic time-domain techniques. These scalar-only approaches fail to capture the relationship between instantaneous sensor value and its temporal variation.
Inspired by Quadrature Amplitude Modulation (QAM) in communication systems, this work maps scalar sensor readings into the complex plane, enabling hybrid signal-processing analysis combining magnitude and rate-of-change information.

### System Workflow

The Smart Waste Bin operates through a continuous sensing–processing–response cycle controlled by the ESP32 microcontroller.

#### Step 1: Continuous Sensing

•	Ultrasonic Sensor (HC-SR04) continuously measures the distance between the sensor and the garbage surface using time-of-flight echo measurement.

•	IR Sensor (LM393) monitors hand proximity for automatic lid operation.

•	Gas Sensor detects harmful or toxic gas concentration inside the bin.

•	All sensor readings are periodically acquired by the ESP32.

#### Step 2: Local Processing (ESP32)

The ESP32 performs real-time processing:

•	Converts ultrasonic echo time into distance (fill level).

•	Compares fill level with a predefined threshold.

•	Reads IR sensor state for proximity detection.

•	Monitors gas sensor value against safety limits.

•	Generates PWM signals to control the servo motor.

#### Step 3: Lid Automation

When the IR sensor detects a hand:

•	The ESP32 drives the servo motor.

•	The lid opens automatically.

•	After a fixed delay (e.g., 3 seconds):

•	The lid closes automatically.

This ensures touch-free operation.

#### Step 4: Event Detection

The system detects key operational events:

•	Bin Full Condition:
Triggered when measured distance falls below a defined threshold.

•	Toxic Gas Alert:
Triggered when gas sensor reading exceeds the safety limit.

#### Step 5: Communication & Alerts

When critical conditions occur:

•	The ESP32 uses its in-built WiFi module.

•	A Telegram notification is sent to the registered user.

•	LCD display updates current bin status.

#### Step 6: Data Logging & Analytical Processing

Sensor data is stored and later processed in MATLAB using a QAM-inspired complex mapping:

Zn = Xn  + j(Xn  - Xn-1 )

This allows:

•	Magnitude-based activity monitoring

•	Phase-based dynamic behavior analysis

•	Complex-plane trajectory visualization

The analytical layer provides deeper insight into bin usage patterns beyond simple threshold detection.

