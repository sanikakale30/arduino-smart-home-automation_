# Arduino Smart Home Automation with Motion and Light Control

## Overview
This project automates a home light using a **PIR Motion Sensor** and **LDR** with Arduino.  
It turns the light ON when motion is detected **and** the ambient light is low, and automatically turns it OFF after a set delay.

## Components
- Arduino Uno / Nano
- PIR Motion Sensor
- LDR (Light Dependent Resistor)
- 10kΩ Resistor
- Relay Module (to control AC light)
- Jumper Wires
- Breadboard

## Circuit Connection
| Component        | Arduino Pin | Notes |
|------------------|-------------|-------|
| PIR Sensor OUT   | D2          | Motion detect karega |
| LDR              | A0          | Ambient light measure karega |
| Relay IN         | D3          | Light ko ON/OFF karega |
| LDR Resistor     | 10kΩ to GND | Voltage divider banane ke liye |
| PIR VCC          | 5V          | Power |
| PIR GND          | GND         | Ground |
| Relay VCC        | 5V          | Power |
| Relay GND        | GND         | Ground |

## How it Works
1. The LDR continuously measures ambient light.
2. If ambient light is low **and** motion is detected → relay ON (light ON).
3. If no motion is detected for a few seconds → relay OFF (light OFF).

## Usage
1. Upload the code from `Arduino_Sketch/smart_home.ino` to your Arduino.
2. Connect the circuit as per diagram.
3. Test by moving in front of the PIR sensor in low light.

---
© 2025 YourName
