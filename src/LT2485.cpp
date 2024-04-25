#include <LT2485.h>

LT2485::LT2485(void) {
   
}

// bool LT2485::setup(TwoWire &wirePort, uint8_t deviceAddress = LT2485_I2C_GlOBAL_ADDRESS) {
//     _i2cPort = &wirePort;
//     _deviceAddress = deviceAddress;
    
//     _i2cPort->beginTransmission(_deviceAddress);
//     uint8_t error = _i2cPort->endTransmission();
    
//     if(error == 0)  return true;
//     else            return false;
// }

bool LT2485::setup(TwoWire &wirePort, uint8_t deviceAddress) {
    _i2cPort = &wirePort;
    _deviceAddress = deviceAddress;

    _i2cPort->beginTransmission(_deviceAddress);
    uint8_t error = _i2cPort->endTransmission();

    return error == 0;
}


int32_t LT2485::readData(uint8_t address, uint8_t config) {
    _i2cPort->beginTransmission(_deviceAddress);
    _i2cPort->write(config);
    _i2cPort->endTransmission();

    _i2cPort->requestFrom(static_cast<uint8_t>(address), static_cast<uint8_t>(4));
    adc_code.by.d4 = _i2cPort->read();
    adc_code.by.d3 = _i2cPort->read();
    adc_code.by.d2 = _i2cPort->read();
    adc_code.by.d1 = _i2cPort->read();

    return adc_code.result;

}