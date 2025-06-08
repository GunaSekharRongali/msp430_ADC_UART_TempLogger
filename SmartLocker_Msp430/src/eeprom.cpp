#include "eeprom.h"

EEPROM::EEPROM(I2CInterface &interface) : i2c(interface) {}

void EEPROM::init() {
    // Assume I2C already initialized
}

void EEPROM::writeByte(unsigned int address, unsigned char data) {
    i2c.start();
    i2c.sendByte(0xA0);
    i2c.sendByte(address);
    i2c.sendByte(data);
    i2c.stop();
}

unsigned char EEPROM::readByte(unsigned int address) {
    i2c.start();
    i2c.sendByte(0xA0);
    i2c.sendByte(address);
    i2c.start();
    i2c.sendByte(0xA1);
    unsigned char data = i2c.readByte(false);
    i2c.stop();
    return data;
}