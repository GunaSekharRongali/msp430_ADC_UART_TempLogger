#ifndef UART_H
#define UART_H

class UART {
public:
    void init();
    void send(const char *msg);
    void sendChar(char c);
    char receive();
};