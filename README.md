# Smart-Bed-AI-Based-Bedsore-Prevention-for-ICU-Patients




# Smart Bed – AI-Based Bedsore Prevention for ICU Patients

An intelligent bed system using IoT and AI to detect and prevent pressure ulcers (bedsores) in immobile patients, improving care quality in hospitals and elder care.

## 🌟 Key Features
- Pressure mapping using resistor grid
- Real-time detection of high-risk zones
- Motion tracking using IMU
- AI prediction model for bedsore risk
- Alerts to caregivers and auto-adjustment triggers

## 🔧 Hardware Used
- ESP32 or STM32 MCU
- Force-sensitive resistor (FSR) matrix or pressure mat
- MPU6050 IMU sensor
- Wi-Fi module
- Optional: Pneumatic air cell control system

## 🔌 Pinout / Hardware Connections

| MCU Pin       | Connected Component         | Description                   |
| ------------- | --------------------------- | -----------------------------|
| GPIO 32-39    | FSR matrix rows/columns     | Pressure sensor matrix inputs |
| GPIO 4, 5     | MPU6050 SDA, SCL            | I2C communication for IMU     |
| 3.3V, GND     | Power to sensors             | Power supply                  |
| GPIO 12       | Pneumatic air cell control  | Control pneumatic pump (optional) |
| GPIO 2        | Wi-Fi Module Reset / Enable | Wi-Fi module control          |

*Note: Pin numbers are indicative; adapt according to your MCU and sensor specs.*

## 🧠 AI Model
- Inputs: Time, pressure, motion data
- Output: Risk prediction
- Model: Random Forest / SVM (Expandable to CNN if using pressure map images)

## 📊 Features
- Dashboard with patient posture history
- Configurable thresholds
- Secure cloud storage of logs

## 🔗 Future Scope
- Remote hospital integration
- Fall detection add-on
- Voice control or voice alert system

---

### Demo
Coming soon...

---

### License
MIT License © 2025 Your Name
