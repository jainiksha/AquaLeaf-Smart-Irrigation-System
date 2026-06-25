# 🌱 AquaLeaf - Smart Irrigation System using ESP32

<p align="center">
  <img src="Images/prototype.jpg" width="700">
</p>

<p align="center">

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![ESP32](https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge)
![Blynk](https://img.shields.io/badge/Blynk-IoT-blue?style=for-the-badge)
![IoT](https://img.shields.io/badge/IoT-Smart%20Agriculture-green?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

</p>

---

# 📖 About Project

AquaLeaf is an IoT-based Smart Irrigation System developed using ESP32, soil moisture sensing, weather prediction, and the Blynk IoT platform. It automates irrigation based on real-time environmental conditions, helping reduce water waste and improve crop health.

---

# ✨ Features

- 🌱 Automatic Irrigation
- 🌧 Weather Prediction
- 💧 Soil Moisture Monitoring
- 🌡 Temperature Monitoring
- 💦 Humidity Monitoring
- 📱 Blynk Mobile Dashboard
- 🚿 Automatic Pump Control
- 📟 LCD Display
- 📊 Real-time Sensor Monitoring

---

# 🛠 Hardware Used

| Component | Quantity |
|-----------|---------:|
| ESP32 | 1 |
| Soil Moisture Sensor | 1 |
| DHT11 Sensor | 1 |
| Relay Module | 1 |
| Water Pump | 1 |
| LCD 16x2 I2C | 1 |
| Jumper Wires | Several |
| Breadboard | 1 |

---

# 💻 Software Used

- Arduino IDE
- Blynk IoT
- ESP32 Board Package
- OpenWeatherMap API
- Git
- GitHub

---

# ⚙ Working

1. ESP32 reads soil moisture.
2. Temperature and humidity are measured.
3. Weather forecast is checked.
4. If soil moisture is low and rain is not expected:
   - Pump turns ON.
5. When the moisture threshold is reached:
   - Pump turns OFF.
6. Data is updated to the Blynk dashboard.

---

# 🔌 ESP32 Connections

| Component | ESP32 Pin |
|-----------|-----------|
| DHT11 | GPIO26 |
| Relay | GPIO27 |
| Rain Sensor | GPIO25 |
| Soil Moisture | GPIO34 |
| LCD SDA | GPIO33 |
| LCD SCL | GPIO32 |

---

# 📂 Project Structure

```text
AquaLeaf-Smart-Irrigation-System
│
├── Arduino_Code
├── Hardware
├── Images
├── Docs
├── data
├── README.md
├── LICENSE
└── .gitignore
```

---

# 📸 Project Images

## Prototype

<img src="Images/prototype.jpg" width="700">

## Circuit

<img src="Images/circuit.png" width="700">

## Dashboard

<img src="Images/dashboard.png" width="700">

---

# 🚀 Installation

```bash
git clone https://github.com/jainiksha/AquaLeaf-Smart-Irrigation-System.git
```

Open the project in Arduino IDE.

Install all required libraries.

Upload the code to ESP32.

Open the Blynk App.

Monitor the system.

---

# 📈 Future Enhancements

- 🤖 AI Plant Disease Detection
- ☀ Solar Powered System
- 📸 Camera Monitoring
- 📱 SMS Alerts
- ☁ Cloud Analytics
- 🌾 Crop Recommendation

---

# 👩‍💻 Author

**Jainiksha Patel**

Computer Science Engineering (AI & DS)

Marwadi University

GitHub:
https://github.com/jainiksha

---

# ⭐ Support

If you like this project,

⭐ Star this repository.

🍴 Fork it.

😊 Share it.

---

# 📄 License

This project is licensed under the MIT License.