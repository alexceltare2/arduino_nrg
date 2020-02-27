# include <HardwareSerial.h>

void setup() {
  randomSeed(analogRead(A0));
  uint8_t randByte1 = random(127);
  uint8_t randByte2 = random(127);
  uint8_t randByte3 = random(127);
  Serial.begin(9600);
  Serial.print("My random bytes are: ");
  Serial.print(randByte1);Serial.print(" ");
  Serial.print(randByte2);Serial.print(" ");
  Serial.println(randByte3);
}

void loop() {
 

}
