#include "locker.h"
#include <string.h>

Locker::Locker(EEPROM &e, Keypad &k, UART &u) : eeprom(e), keypad(k), uart(u) {
    memset(enteredPin, 0, sizeof(enteredPin));
}

void Locker::init() {
    uart.send("[Locker Init]\r\n");
}

void Locker::loop() {
    uart.send("Enter 4-digit PIN:\r\n");
    for (int i = 0; i < 4; ++i) {
        enteredPin[i] = keypad.getKey();
        uart.sendChar('*');
    }
    enteredPin[4] = '\0';
    checkPin();
}

void Locker::checkPin() {
    bool match = true;
    for (int i = 0; i < 4; ++i) {
        if (enteredPin[i] != eeprom.readByte(pinAddr + i)) {
            match = false;
            break;
        }
    }
    if (match) {
        uart.send("\r\nAccess Granted\r\n");
    } else {
        uart.send("\r\nAccess Denied\r\n");
    }
}

void Locker::changePin() {
    uart.send("Enter new 4-digit PIN:\r\n");
    for (int i = 0; i < 4; ++i) {
        char key = keypad.getKey();
        eeprom.writeByte(pinAddr + i, key);
        uart.sendChar('*');
    }
    uart.send("\r\nPIN Updated\r\n");
}
