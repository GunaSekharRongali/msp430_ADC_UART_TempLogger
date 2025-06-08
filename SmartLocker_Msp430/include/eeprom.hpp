#ifndef EEPROM_H
#define EEPROM_H

#include "i2c.h"

class EEPROM {
    I2CInterface &i2c;
public:
    EEPROM(I2CInterface &interface);
    void init();
    void writeByte(unsigned int address, unsigned char data);
    unsigned char readByte(unsigned int address);
};

#endif