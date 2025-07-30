#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress arduino_ip(0, 0, 1, 2);
IPAddress server_ip(0, 0, 1, 1);
int server_port = 8888;

EthernetClient client;

const int sensorPin = I2;
int lastSensorState = HIGH;

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, arduino_ip);
  pinMode(sensorPin, INPUT);

  Serial.print("Arduino Client is at: ");
  Serial.println(Ethernet.localIP());
  delay(1000);
}

void loop() {
  if (!client.connected()) {
    Serial.println("Disconnected. Attempting to connect...");
    client.stop();
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected to server!");
    } else {
      delay(5000);
      return;
    }
  }

  int currentSensorState = digitalRead(sensorPin);

  if (currentSensorState == LOW && lastSensorState == HIGH) {
    Serial.println("Object detected! Sending data to Pi...");
    client.println("DETECT"); 
  }

  lastSensorState = currentSensorState;

  delay(50);
}
