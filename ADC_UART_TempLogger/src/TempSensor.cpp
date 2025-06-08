#include <msp430.h>
#include "TempSensor.hpp"

TempSensor::TempSensor() {}

void TempSensor::initADC() {
    ADC10CTL1 = INCH_0;                          // ADC input channel A0
    ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON;   // V+ = AVcc/V- = AVss, 64 cycles
}

unsigned int TempSensor::readADC() {
    ADC10CTL0 |= ENC + ADC10SC;  // Start sampling
    while (ADC10CTL1 & ADC10BUSY);
    return ADC10MEM;
}

float TempSensor::convertToCelsius(unsigned int raw) {
    return (raw * 3.3 / 1023.0) * 100.0; // LM35: 10mV/°C
}

