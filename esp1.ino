#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "iPhone";
const char* password = "Cherancheran";

WiFiUDP udp;
const int localPort = 4210;

const int alertLed = D4;   // LED for intrusion alert
const int buzzerPin = D3;  // Optional buzzer

IPAddress attackerIP;      // Store attacker's IP

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(alertLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(alertLed, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.println("\nConnecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ ESP1 connected to WiFi");
  Serial.print("📡 ESP1 IP Address: ");
  Serial.println(WiFi.localIP());

  udp.begin(localPort);
  Serial.print("✅ UDP server started at port: ");
  Serial.println(localPort);
  Serial.println("📥 Waiting for spoofed attacker messages...");
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    byte buf[255];
    int len = udp.read(buf, 255);

    // Store attacker IP
    attackerIP = udp.remoteIP();

    Serial.print("⚠️ Spoofed message received from ");
    Serial.print(attackerIP);
    Serial.print(": ");

    for (int i = 0; i < len; i++) {
      Serial.print(buf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();

    // ==== Trigger IDPS Response ====
    digitalWrite(alertLed, HIGH); // Turn on LED
    digitalWrite(buzzerPin, HIGH); // Start buzzer
    delay(1000);
    digitalWrite(buzzerPin, LOW);

    // Show warning
    Serial.println("🚨 ALERT: Spoofed CAN message detected!");
    Serial.println("⚠️ Taking defensive action...");

    // ==== Block Attacker IP (basic simulation) ====
    Serial.print("⛔ Blocking attacker: ");
    Serial.println(attackerIP);
    delay(3000);
    digitalWrite(alertLed, LOW);
  }
}
