//Hardware arduino code
#include <WiFi.h>
#include <HTTPClient.h>

#define PIR_PIN 13
#define MOTION_LED 12
#define POWER_LED 14
#define BUZZER_PIN 27

// ✅ Your Wi-Fi Credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ✅ Replace with your Discord Webhook URL
const char* webhook_url = "https://discord.com/api/webhooks/XXXX/XXXXXXXXXX";

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(MOTION_LED, OUTPUT);
  pinMode(POWER_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(POWER_LED, HIGH);

  Serial.println("🔌 Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ Wi-Fi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("🔒 System Initialized. Monitoring for motion...");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    Serial.println("🚨 Motion Detected!");

    // Turn on alert
    digitalWrite(MOTION_LED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    // Send alert to Discord
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(webhook_url);
      http.addHeader("Content-Type", "application/json");

      String message = "{\"content\": \"🚨 Motion Detected from ESP32 Intrusion System!\"}";
      int httpResponseCode = http.POST(message);

      if (httpResponseCode == 204) {
        Serial.println("✅ Alert sent to Discord.");
      } else {
        Serial.print("❌ Failed to send alert. HTTP Code: ");
        Serial.println(httpResponseCode);
      }

      http.end();
    } else {
      Serial.println("❌ Wi-Fi disconnected. Cannot send alert.");
    }

    delay(3000); // Alert duration

    // Turn off alert
    digitalWrite(MOTION_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("✅ System reset. Monitoring again...");
  }

  delay(500); // Sensor polling interval
}

