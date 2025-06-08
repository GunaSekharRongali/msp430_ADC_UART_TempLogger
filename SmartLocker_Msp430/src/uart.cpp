#include "uart.h"
#include <msp430.h>

void UART::init() {
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 = 104; 
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS0;
    UCA0CTL1 &= ~UCSWRST;
}

void UART::send(const char *msg) {
    while (*msg) sendChar(*msg++);
}

void UART::sendChar(char c) {
    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF = c;
}

char UART::receive() {
    while (!(IFG2 & UCA0RXIFG));
    return UCA0RXBUF;
}