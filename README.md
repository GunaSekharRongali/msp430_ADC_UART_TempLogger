# 🌡️ MSP430 Temperature Logger using UART

A simple embedded C++ project for MSP430 that reads the internal temperature sensor and sends data via UART in a modular, object-oriented format.

---

## 📁 Project Structure

### Files Included

- `main.cpp` - Application logic
- `TempSensor.hpp/.cpp` - ADC-based temperature sensor driver
- `UARTDriver.hpp/.cpp` - UART communication driver
- `README.md` - Documentation

---

## 🔧 Features

- Uses MSP430 internal temperature sensor
- Sends temperature data over UART
- Modular C++ design for easy reusability
- 1-second delay between readings

---

## 🛠️ Requirements

- MSP430G2553 (or compatible with ADC + UART)
- Serial monitor software 
- MSP430 GCC toolchain
- VS Code or any preferred IDE

---

## ⚙️ How It Works

### Initialization

- Disables Watchdog Timer
- Initializes UART at 9600 baud
- Initializes ADC for internal temperature sensor

### Main Loop

- Reads raw ADC value from temperature sensor
- Converts to degrees Celsius
- Sends result over UART
- Waits 1 second (`__delay_cycles`)
