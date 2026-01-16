# Smart-Accident-and-Intruson-Detection-System

## Project Overview
This project implements a **dual ESP8266–based smart vehicle safety system** that combines:

- Accident Detection & Alerting  
- Intrusion Detection & Prevention (IDPS)  
- Spoofed CAN Message Simulation  
- Real-time GPS Location Tracking  
- Email Alert System  

The system uses **two ESP8266 nodes**:
- **ESP1 (Defender / IDPS Node)** – Detects spoofed CAN messages and triggers alerts  
- **ESP2 (Vehicle / Attacker Simulation Node)** – Detects accidents, sends alerts, and simulates spoofed CAN packets  

---

## Hardware Components Used

| Component | Purpose |
|---------|--------|
| ESP8266 | Main microcontroller (ESP1 & ESP2) |
| MPU6050 | Accident detection using acceleration |
| NEO-6M GPS | Location tracking |
| CAN Module | CAN message spoofing simulation |
| SW-420 | Vibration / shock detection |
| LED | Visual alert |
| Buzzer | Audible alert |

---

## Software & Libraries Used

- ESP8266WiFi  
- WiFiUDP  
- Wire  
- MPU6050  
- TinyGPS++  
- ESP Mail Client  
- SoftwareSerial  

---

## System Working

### ESP2 – Accident Detection & Spoofing Node
- Reads acceleration data from **MPU6050**
- Detects accidents using a **G-force threshold**
- Determines **impact direction**
- Fetches **GPS coordinates**
- Sends an **email alert** with accident & location details
- Periodically sends **spoofed CAN messages via UDP** to ESP1

### ESP1 – Intrusion Detection (IDPS) Node
- Acts as a **UDP server**
- Listens for incoming CAN packets
- Detects **spoofed messages**
- Logs **attacker IP address**
- Triggers:
  - LED alert  
  - Buzzer warning  
- Simulates **blocking the attacker**

---

## File Structure

Project/
├── esp1.ino # Intrusion Detection & Prevention (Defender Node)
├── esp2.ino # Accident Detection & Spoofing (Vehicle Node)
└── README.md


---

## Key Features

- Accident detection using accelerometer  
- Impact direction analysis  
- Real-time GPS tracking  
- Email alerts with Google Maps link  
- CAN spoofing attack simulation  
- Intrusion detection with IP tracking  
- LED & buzzer alerts  
- Dual-node ESP8266 architecture  

---

## Email Alert Includes

- Accident notification  
- G-force values  
- Impact direction  
- Latitude & Longitude  
- Google Maps navigation link  

---

## Applications

- Smart vehicle safety systems  
- Automotive cybersecurity research  
- CAN bus attack simulation  
- IoT-based emergency response  
- Academic projects & hackathons  

---

## Security Note

Sensitive information such as **Wi-Fi credentials and email passwords** should be secured before real-world deployment.

---

## Developed By

**Cheran V**  
2nd Year – Artificial Intelligence & Machine Learning  

---

## License

This project is developed for **educational and research purposes only**.
