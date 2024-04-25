#ifndef LT2485_H
#define LT2485_H

#include <Arduino.h>
#include<Wire.h>

#define LT2485_I2C_GlOBAL_ADDRESS 0b1110111

#define LT2485_SPEED_1X 0x00
#define LT2485_SPEED_2X 0x01
#define LTC2845_INTERNAL_TEMP 0x08

#define LT2485_R50 0x02
#define LT2485_R60 0x04
#define LT2485_R50_R60 0x00

struct _fourbytes {
    int8_t d1;
    int8_t d2;
    int8_t d3;
    int8_t d4;
};

union {
    int32_t result;
    struct _fourbytes by;

} adc_code;
class LT2485 {
    public:
        LT2485(uint8_t deviceAddress = LT2485_I2C_GlOBAL_ADDRESS, TwoWire &wirePort = Wire);
        bool setup();
        int32_t readData(char address, char config);

    private:
        uint8_t _deviceAddress;
        TwoWire *_i2cPort;

};
#endif