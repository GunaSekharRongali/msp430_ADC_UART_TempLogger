#ifndef LOCKER_H
#define LOCKER_H

#include "eeprom.h"
#include "keypad.h"
#include "uart.h"

class Locker {
    EEPROM &eeprom;
    Keypad &keypad;
    UART &uart;
    char enteredPin[5];
    const int pinAddr = 0x00;

public:
    Locker(EEPROM &e, Keypad &k, UART &u);
    void init();
    void loop();
    void checkPin();
    void changePin();
};

#endif