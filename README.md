# 📱 Smart Phone–Based Home Automation Using Bluetooth (HC-05)
### Mini Project – LPC2129 (ARM7)

This mini-project demonstrates a **Bluetooth-based home automation system** built using the **LPC2129 ARM7 microcontroller** and the **HC-05 Bluetooth module**.  
The system allows controlling devices like a **bulb** and **fan** using:

- Bluetooth mode (via HC-05)
- Manual mode (via switches)
- Mode switching using SW3

---

## ✅ Features
- Control loads using Bluetooth HC-05 module  
- Manual control with physical switches  
- Real-time mode switching  
- UART 9600 baud communication  
- LCD output for invalid input  
- Modular code (main + UART driver)

---

## 📂 Project Structure
/HomeAutomation_BT/
│
├── main.c # Main program (Bluetooth + Manual mode)
├── uart.c # UART driver (init, TX, RX, string, float, integer, hex)
├── header.h # Function prototypes and macros
└── README.md # Project documentation


---

## 🔧 Hardware Requirements
- LPC2129 Microcontroller  
- HC-05 Bluetooth Module  
- Switches: SW1, SW2, SW3  
- LEDs for load simulation  
- Power supply + wires  

---

## 🔌 Pin Configuration
| LPC2129 Pin | Description        |
|-------------|--------------------|
| P0.17       | LED1 (Bulb)        |
| P0.18       | LED2 (Fan)         |
| P0.19       | Status LED         |
| P0.14       | SW1 – Bulb control |
| P0.15       | SW2 – Fan control  |
| P0.16       | SW3 – Mode switch  |
| P0.0        | UART0 TX for HC-05 |
|  P0.1       | UART0 RX for HC-05 |

---

## 📡 Bluetooth Commands
| Command | Function |
|---------|----------|
| a | Turn ON Bulb |
| b | Turn OFF Bulb |
| c | Turn ON Fan |
| d | Turn OFF Fan |
| e | Turn ON both Bulb & Fan |
| f | Turn OFF both Bulb & Fan |
| g | Toggle Mode (Bluetooth ↔ Manual) |

Invalid input is displayed on the LCD.

---

## 🧠 Code Workflow

### 🔵 Bluetooth Mode (`bluetooth()`)
- Receives characters from HC-05  
- Controls LEDs based on command  
- Can switch to Manual mode using `'g'`

### 🟢 Manual Mode (`manual()`)
- SW1 toggles Bulb  
- SW2 toggles Fan  
- SW3 switches to Bluetooth mode  
- Toggle states stored using counters

---

## ⚙️ How to Compile & Upload

1. Open Keil uVision / LPCXpresso  
2. Add all files (`main.c`, `uart.c`, `header.h`)  
3. Select device: **LPC2129**  
4. Build the project  
5. Flash the HEX file using Flash Magic  
6. Reset the board  
7. Connect Bluetooth → Send commands via app

---

## 📲 Testing with Smartphone
1. Power the system  
2. Pair phone with **HC-05** (Password: 1234)  
3. Open Bluetooth Terminal App  
4. Send commands (`a`, `b`, `c`, etc.)  
5. Observe the LEDs controlling Bulb/Fan

---

