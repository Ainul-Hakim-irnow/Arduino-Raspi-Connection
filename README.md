# Arduino to Raspberry Pi Direct Ethernet Communication 🚀

This project demonstrates a direct TCP/IP communication link between an Arduino (with an Ethernet shield) and a Raspberry Pi using a single Ethernet cable. No router or switch is needed.
In this setup, the Raspberry Pi acts as a TCP server, and the Arduino acts as a TCP client. The Arduino connects to the Pi, sends a "Hello" message, and the Pi sends a confirmation message back.

## Hardware Requirements 🛠️
* Arduino board (e.g., Uno, Mega)
* Arduino Ethernet Shield (W5100 or similar)
* Raspberry Pi (any model with an Ethernet port)
* A standard Ethernet cable

## Software Requirements 💻
* Arduino IDE
* Python 3 installed on the Raspberry Pi
* Arduino Libraries: SPI.h and Ethernet.h (included with the Arduino IDE)

## Setup and Configuration ⚙️
### IP Address Configuration
This project uses static IP addresses for the direct connection:
* Raspberry Pi (Server) IP: 0.0.1.1
* Arduino (Client) IP: 0.0.1.2
* Subnet Mask: 255.255.255.0 (or /24)
* Port: 8888
### Find Your Raspberry Pi's Network Interface
The Python script needs to know the name of the Ethernet interface on your Raspberry Pi. The provided script uses eno1, but yours might be different (e.g., eth0).
Find your interface name by running this command in the Raspberry Pi terminal:

<code>ip a</code>

Look for the entry corresponding to your wired Ethernet port and note its name. You must update the INTERFACE variable in the raspi.py script if your name is different.
### Hardware Connection
* Stack the Ethernet Shield onto your Arduino board.
* Connect the Arduino to the Raspberry Pi using the Ethernet cable.
* Power both the Arduino (e.g., via USB) and the Raspberry Pi.

## How to Run 🚦
You must start the server on the Raspberry Pi before running the Arduino client.
### Start the Server on the Raspberry Pi
* Open a terminal on your Raspberry Pi.
* Navigate to the directory containing the raspi.py file.
* Run the script with sudo to allow it to configure the network interface:

<code>sudo python3 raspi.py</code>


The terminal will display Server starting... and then Waiting for a connection....
2. Run the Client on the Arduino
Open the arduino.ino sketch in the Arduino IDE.
Upload the sketch to your Arduino board.
Open the Serial Monitor (set the baud rate to 9600).
The Arduino will attempt to connect to the Raspberry Pi server. Once connected, you will see the messages exchanged in both the Arduino Serial Monitor and the Raspberry Pi terminal.
