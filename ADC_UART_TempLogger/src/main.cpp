#include <msp430.h>
#include "TempSensor.hpp"
#include "UARTDriver.hpp"

TempSensor tempSensor;
UARTDriver uart;

void delayMs(unsigned int ms) {
    while (ms--) {
        __delay_cycles(1000);
    }
}

int main() {
    WDTCTL = WDTPW | WDTHOLD;
    uart.initUART();
    tempSensor.initADC();

    char buffer[32];

    while (1) {
        unsigned int raw = tempSensor.readADC();
        float temp = tempSensor.convertToCelsius(raw);

        // Convert float to string (basic)
        int intTemp = (int)temp;
        buffer[0] = '\0';
        sprintf(buffer, "Temp: %d C\r\n", intTemp);
        uart.sendString(buffer);

        delayMs(1000); // Delay 1s
    }
}

