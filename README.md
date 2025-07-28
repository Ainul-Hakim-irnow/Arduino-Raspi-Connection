# Arduino to Raspberry Pi Direct Ethernet Communication 🚀

This project demonstrates a direct TCP/IP communication link between an Arduino (with an Ethernet shield) and a Raspberry Pi using a single Ethernet cable. No router or switch is needed.
In this setup, the Raspberry Pi acts as a TCP server, and the Arduino acts as a TCP client. The Arduino connects to the Pi, sends a "Hello" message, and the Pi sends a confirmation message back.

## Hardware Requirements 🛠️
* Arduino board (e.g., Uno, Mega)
* Arduino Ethernet Shield (W5100 or similar)
* Raspberry Pi (any model with an Ethernet port)
* A standard Ethernet cable

