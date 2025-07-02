//Wokwi code
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


