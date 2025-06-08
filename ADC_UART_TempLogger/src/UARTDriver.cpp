#include <msp430.h>
#include "UARTDriver.hpp"

UARTDriver::UARTDriver() {}

void UARTDriver::initUART() {
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 = 104;   // 9600 baud @1MHz
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS0;
    UCA0CTL1 &= ~UCSWRST;
}

void UARTDriver::sendChar(char c) {
    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF = c;
}

void UARTDriver::sendString(const char* str) {
    while (*str) {
        sendChar(*str++);
    }
}
