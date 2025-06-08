#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

class TempSensor {
public:
    TempSensor();
    void initADC();
    unsigned int readADC();      // Raw ADC value
    float convertToCelsius(unsigned int raw);  // Returns temperature in °C
};

#endif

