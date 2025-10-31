📱 Smart Phone–Based Home Automation Using Bluetooth (HC-05)
Mini Project – LPC2129 (ARM7)

This mini-project demonstrates a Bluetooth-based home automation system built using the LPC2129 ARM7 microcontroller and the HC-05 Bluetooth module.
The system allows a user to control devices like a bulb and fan via:

✅ Bluetooth mode (mobile app / Bluetooth terminal)

✅ Manual mode (hardware switches)

A mode switch allows toggling between Bluetooth and Manual operation at any time.

✅ Features

Control devices using HC-05 Bluetooth module

Manual mode using push buttons

Smooth mode switching

UART communication at 9600 baud

LCD support for displaying messages

Clean modular code (main + UART driver)

📂 Project Structure
/HomeAutomation_BT/
│
├── main.c        # Application code (Bluetooth + Manual mode)
├── uart.c        # UART0 driver (init, TX, RX, string, float, hex print)
├── header.h      # Header file containing function prototypes
├── lcd.c         # (optional) LCD driver if used in project
└── README.md     # Documentation file

🔧 Hardware Requirements

LPC2129 ARM7 Microcontroller

HC-05 Bluetooth Module

16x2 LCD (optional for debug output)

3 Push Buttons

SW1 → Bulb ON/OFF

SW2 → Fan ON/OFF

SW3 → Mode Change

LEDs for load simulation

Connecting wires, resistors, power supply

🔌 Pin Configuration
Pin	Function
P0.17	Bulb (LED1)
P0.18	Fan (LED2)
P0.19	Status LED
P0.14	SW1 – Bulb ON/OFF
P0.15	SW2 – Fan ON/OFF
P0.16	SW3 – Mode Toggle
UART0 (P0.0, P0.1)	Bluetooth HC-05
📡 Bluetooth Controls
Command	Action
a	Bulb ON
b	Bulb OFF
c	Fan ON
d	Fan OFF
e	Bulb + Fan ON
f	Bulb + Fan OFF
g	Switch mode (Bluetooth ↔ Manual)

Invalid commands show "Invalid input" on the LCD.

🧠 How the System Works
✅ Bluetooth Mode

Continuously waits for a character from HC-05

Takes action based on received command

Can switch to manual mode anytime using command 'g'

✅ Manual Mode

SW1 toggles Bulb

SW2 toggles Fan

SW3 switches back to Bluetooth mode

Uses counters for toggle states (f1, f2)

🛠 UART Driver (uart.c)

Provides UART functionalities:

uart0_init() – Initializes UART at given baud rate

uart0_tx() – Transmits one byte

uart0_rx() – Receives one byte

uart0_tx_string() – Sends string

uart0_rx_string() – Reads string

uart0_tx_float() – Transmits float

uart0_tx_integer() – Transmits integer

uart0_hex() – Sends byte in hex format

Configured for 9600 baud using VPBDIV clock.

⚙️ Compilation & Flashing

Open project in Keil uVision or LPCXpresso

Add: main.c, uart.c, header.h (+LCD files if used)

Select device: NXP LPC2129

Build the project → Generate HEX file

Flash using:

Flash Magic or

JTAG Programmer

Reset the controller

Connect HC-05 → Open Bluetooth terminal → Send commands

📲 Testing With Phone

Power the system

Pair phone with HC-05 (Default password: 1234)

Open any Bluetooth Terminal app

Send characters (a, b, c, … g)

See LEDs / loads respond instantly

🚀 Future Enhancements

Add relay driver to control AC appliances

Add timer-based automation

Add Wi-Fi + MQTT control

Add OLED/LCD for richer UI

Add voice-control (Google Assistant/Alexa)

If you want, I can also generate:

✅ Circuit Diagram
✅ Block Diagram
✅ Flowchart
✅ PDF Documentation
✅ PowerPoint for presentation
✅ GitHub-friendly version with images & badges
