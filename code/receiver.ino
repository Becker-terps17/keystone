//receives 4 int array of pot values and writes them to servo pins 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8); // CNS, CE
const byte address[6] = "00001";
Servo a;
Servo b;
Servo c;
Servo d;

void setup() {
//  Serial.begin(9600);
  a.attach(5);
  b.attach(6);
  c.attach(9);
  d.attach(10);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  delay(5);
  radio.startListening();
  int i, j;
  if ( radio.available()) {
    while (radio.available()) {
      int angle[4] = {0,0,0,0};
      radio.read(&angle, sizeof(angle));
//      for (i=0; i<4; i++){
//        Serial.println(angle[i]);
//      }
      a.write(angle[0]);
      b.write(angle[1]);
      c.write(angle[2]);
      d.write(angle[3]);
    }
    delay(5);
    radio.stopListening();
  }
}

