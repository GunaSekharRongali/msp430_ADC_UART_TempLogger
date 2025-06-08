#include "locker.h"
#include "uart.h"
#include "eeprom.h"
#include "keypad.h"

I2CInterface i2c;
UART uart;
EEPROM eeprom(i2c);
Keypad keypad;
Locker locker(eeprom, keypad, uart);

int main() {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    uart.init();
    i2c.init();
    eeprom.init();
    keypad.init();
    locker.init();

    while (1) {
        locker.loop();
    }
    return 0;
}