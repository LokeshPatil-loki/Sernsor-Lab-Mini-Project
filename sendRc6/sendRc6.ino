#include <IRremote.h>

const int SEND_PIN = 6;
IRsend irsend(SEND_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  irsend.sendNECMSB(12583004,24);
}
