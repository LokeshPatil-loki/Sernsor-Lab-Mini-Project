#include <IRremote.h>

IRsend irsend;
IRrecv irrecv(11);  // Define the IR receiver pin

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
  // Check if we received an IR signal
  if (irrecv.decode(&results)) {
    // Print the protocol, address, and command of the received signal
    Serial.print("Protocol: ");
    Serial.print(results.decode_type);
    Serial.print("  Address: ");
    Serial.print(results.address);
//    Serial.print("  Command: ");
//    Serial.println(results.command);

    irrecv.resume();  // Resume the IR receiver
  }

  // Send an IR signal using the NEC protocol
  irsend.sendNEC(0x20DF10EF, 32);  // Send a "power" command to a TV
  delay(1000);  // Wait 1 second before sending the next signal
}
