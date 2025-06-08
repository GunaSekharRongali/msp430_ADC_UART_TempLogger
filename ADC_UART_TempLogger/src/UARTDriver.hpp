#ifndef UART_DRIVER_HPP
#define UART_DRIVER_HPP

class UARTDriver {
public:
    UARTDriver();
    void initUART();
    void sendChar(char c);
    void sendString(const char* str);
};

#endif
