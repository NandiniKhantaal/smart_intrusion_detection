
# 🔐 Smart Intrusion Detection System using ESP32 (IoT Project)

> Simulated using Wokwi | Cloud Alert via Discord Webhook using Postman

---

## 📌 Aim

To design and simulate a smart intrusion detection system that continuously monitors a restricted area using a PIR sensor and alerts security personnel through cloud-based notifications simulated via Discord webhook.

---

## 🧠 Problem Statement

Security systems in sensitive areas like labs, homes, and offices require real-time alert mechanisms. This project implements an intrusion detection system that:
- Detects motion using a PIR sensor.
- Activates visual (LED) and audible (buzzer) alerts.
- Simulates cloud notifications using Postman and Discord webhook.

---

## 🔍 Scope of the Solution

- Detects unauthorized motion in real-time.
- Provides local alerts (LED + buzzer).
- Sends (simulated) cloud notifications using Discord webhook via Postman.
- Fully simulated environment using **Wokwi**, ideal for demonstration without physical hardware.
- Easily extendable to real-world ESP32 + Wi-Fi + HTTP integration.

---

## 🧰 Required Components

### 🛠️ Hardware (Simulated on Wokwi)
| Component       | Description                       |
|----------------|-----------------------------------|
| ESP32           | Microcontroller unit              |
| PIR Sensor      | Detects human motion              |
| Red LED         | Motion detected indicator         |
| Green LED       | System ON indicator               |
| Buzzer          | Audible alert on motion detection |
| 220Ω Resistors  | For current limiting on LEDs      |
| Jumper Wires    | For circuit connections           |
| Breadboard      | Circuit prototyping               |

### 💻 Software
- [Wokwi Simulator](https://wokwi.com/)
- [Arduino IDE (internal in Wokwi)](https://www.arduino.cc/en/software)
- [Postman](https://www.postman.com/)
- [Discord](https://discord.com/) (for webhook notifications)

---

## 🗺️ System Flowchart

```
Start
  ↓
Initialize system
  ↓
Turn ON green LED (System ON)
  ↓
Loop: Check PIR sensor
  ↓
If motion detected:
    → Turn ON red LED
    → Activate buzzer
    → Simulate cloud alert (Serial)
    → Trigger Discord webhook (via Postman)
    → Wait 3 seconds
    → Reset system
Else:
    → Continue monitoring
```

---

## 🧪 Circuit Diagram (Wokwi)

👉 [Live Circuit on Wokwi](https://wokwi.com/projects/435388129210793985)

### 🔌 GPIO Pin Mapping

| Component         | ESP32 GPIO |
|------------------|------------|
| PIR Sensor OUT   | 13         |
| Red LED          | 12         |
| Green LED        | 14         |
| Buzzer (+)       | 27         |
| GND (all)        | GND        |
| Power            | 3.3V       |

*Note: LEDs are connected via 220Ω resistors.*

---

## 🧾 Code

The complete source code is available in `SmartIntrusion.ino` (Arduino compatible).  
Key logic includes:
- Reading motion from PIR
- Activating alert mechanisms
- Printing simulated cloud alerts to Serial Monitor

```
#define PIR_PIN 13
#define MOTION_LED 12
#define POWER_LED 14
#define BUZZER_PIN 27

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(MOTION_LED, OUTPUT);
  pinMode(POWER_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(POWER_LED, HIGH);  // Keep system ON LED always on

  Serial.begin(115200);
  Serial.println("🔒 System Initialized. Monitoring...");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    digitalWrite(MOTION_LED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("🚨 Motion Detected! Sending alert to cloud (simulated)...");
    delay(3000);
    digitalWrite(MOTION_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("✅ Alert sent. System monitoring...");
  }
  delay(500);
}
```

---

## 🌐 Cloud Notification Simulation (Postman + Discord)

Since Wokwi doesn’t support actual HTTP requests:

1. Motion is detected → Serial prints alert message.
2. You manually trigger a Discord webhook using **Postman**.

### ➕ Setup Discord Webhook:
- Create a Discord server → Go to any channel → ⚙️ → **Integrations > Webhooks**
- Copy the webhook URL.

### 🔁 Send POST Request via Postman:
- Method: `POST`
- URL: Your Discord Webhook URL
- Headers: `Content-Type: application/json`
- Body (raw, JSON):

```
{
  "content": "🚨 Motion detected from Smart Intrusion Detection System!"
}
```

- Hit **Send** → Message appears in Discord.

---

## 🎥 Demo Video Plan (To Record)

1. Start Wokwi simulation
2. Show Serial Monitor: “System Initialized”
3. Move mouse over PIR sensor → Show LED and buzzer reaction
4. Show Serial Monitor: “Motion Detected!”
5. Switch to Postman → Send Discord webhook → Show alert in Discord
6. Close by saying, "This demonstrates cloud alert simulation."

---

## ✅ Project Outcomes

- Motion detection logic fully simulated
- Local alerts implemented via LEDs and buzzer
- Cloud alert mechanism simulated via Postman
- Hardware + software + cloud concepts integrated

---

## 👤 Developed By

**Nandini Khantaal**    
B.Tech EEE  
VIT Vellore

---

## 📎 Attachments
- `SmartIntrusion.ino` – Arduino source code
- `Flowchart.png` – System flowchart
- `Wokwi-Link.txt` – Direct circuit link
- `Demo.mp4` – Demo video (if submitted)

---
