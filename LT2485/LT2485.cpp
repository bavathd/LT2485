#include <LT2485.h>

LT2485::LT248(uint8_t deviceAddress = LT2845_I2C_GlOBAL_ADDRESS, TwoWire &wirePort = Wire) {
    _deviceAddress = deviceAddress;
    _i2cPort = &wirePort;
}

bool LT2485::setup() {

    
    _i2cPort->beginTransmission(_deviceAddress);
    uint8_t error = _i2cPort->endTransmission();
    
    if(error == 0)  return true;
    else            return false;
}

int32_t readData(uint8_t address, uint8_t config) {
    _i2cPort->beginTransmission(_deviceAddress);
    _i2cPort->write(config);
    _i2cPort->endTransmission();

    _i2cPort->requestFrom(_deviceAddress, 4)
    adc_code.by.d4 = _i2cPort->read();
    adc_code.by.d3 = _i2cPort->read();
    adc_code.by.d2 = _i2cPort->read();
    adc_code.by.d1 = _i2cPort->read();

    return adc_code.result;

}