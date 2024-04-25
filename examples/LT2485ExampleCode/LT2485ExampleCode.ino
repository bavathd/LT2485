#include <LT2485.h>
#define GAIN1  0b00000000   // G = 1   (SPD = 0), G = 1   (SPD = 1)
 #define GAIN2  0b00100000   // G = 4   (SPD = 0), G = 2   (SPD = 1)
 #define GAIN3  0b01000000   // G = 8   (SPD = 0), G = 4   (SPD = 1)
 #define GAIN4  0b01100000   // G = 16  (SPD = 0), G = 8   (SPD = 1)
 #define GAIN5  0b10000000   // G = 32  (SPD = 0), G = 16  (SPD = 1)
 #define GAIN6  0b10100000   // G = 64  (SPD = 0), G = 32  (SPD = 1)
 #define GAIN7  0b11000000   // G = 128 (SPD = 0), G = 64  (SPD = 1)
 #define GAIN8  0b11100000   // G = 256 (SPD = 0), G = 128 (SPD = 1)
 // Select ADC source - differential input or PTAT circuit
 #define VIN    0b00000000
 #define PTAT   0b00001000
 // Select rejection frequency - 50, 55, or 60Hz
 #define R50    0b00000010
 #define R55    0b00000000
 #define R60    0b00000100
 // Select speed mode
 #define SLOW   0b00000000 // slow output rate with autozero
 #define FAST   0b00000001 // fast output rate with no autozero


LT2485 s1;
void setup() {
  s1.setup();
  // put your setup code here, to run once:

}

void loop() {
int32_t x, y;
  // put your main code here, to run repeatedly:
  x = s1.readData(0x15,  VIN | R50 |SLOW );
}
