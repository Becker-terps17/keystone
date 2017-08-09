//transmits a 4 int array over RF, {x1, y1, x2, y2}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CNS, CE
const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  int i;
  int Values[4] = {analogRead(A0), analogRead(A1), analogRead(A2), analogRead(A3)};
  int angleValue[4];
  for (i=0; i<4; i++){
    angleValue[i] = map(Values[i], 0, 1023, 0, 180);
  }
  
  radio.write(&angleValue, sizeof(angleValue));
  delay(10);
}
