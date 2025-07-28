#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress arduino_ip(0, 0, 1, 2);

IPAddress server_ip(0, 0, 1, 1);
int server_port = 8888;

EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }

  Ethernet.begin(mac, arduino_ip);
  Serial.print("Arduino Client is at: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  if (client.connect(server_ip, server_port)) {
    Serial.println("Connected to server!");

    client.println("Hello from Arduino!");
    Serial.println("Sent message to Pi.");

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
      }
    }

    Serial.println();
    Serial.println("Server disconnected.");
    client.stop();

  } else {
    Serial.println("Connection failed!");
  }

  delay(5000);
}
