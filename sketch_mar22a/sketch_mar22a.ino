#include <IRremote.h>  // include the IRremote library

const int RECV_PIN = 11;  // define the input pin for the IR receiver


IRrecv irrecv(RECV_PIN);  // create an instance of the IRrecv class
decode_results results;   // create a variable to hold the decoded IR signal

void setup() {
  Serial.begin(9600);   // initialize serial communication at 9600 baud
  irrecv.enableIRIn();  // start the IR receiver

}

void loop() {
  if (irrecv.decode()) {  // if an IR signal is received
    Serial.print("IR Code: ");
    Serial.println(irrecv.decodedIRData.decodedRawData);  // print the value of the signal in hexadecimal format
    irrecv.resume();  // continue receiving IR signals
  }
}
