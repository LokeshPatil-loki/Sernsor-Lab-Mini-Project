#include <IRremote.h>

const int RECV_PIN = 11;
const int SEND_PIN = 6;

IRrecv irrecv(RECV_PIN);
IRsend irsend(SEND_PIN);

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode()) {
    Serial.print("Raw Data: ");
    Serial.println(irrecv.decodedIRData.decodedRawData);
    Serial.print("Raw Data Buff: ");
    Serial.println(irrecv.decodedIRData.rawDataPtr->rawlen);
    Serial.print("Protocol: ");
    Serial.println(irrecv.decodedIRData.protocol);
    Serial.print("Command: ");
    Serial.println(irrecv.decodedIRData.command);
    Serial.print("Address: ");
    Serial.println(irrecv.decodedIRData.address);
    Serial.print("Number of Bits: ");
    Serial.println(irrecv.decodedIRData.numberOfBits);
    printProtocol(irrecv.decodedIRData.protocol);
    delay(5000);
    for(int i = 0;i < 2;i++){
      irsend.sendRaw(irrecv.decodedIRData.rawDataPtr->rawbuf, irrecv.decodedIRData.rawDataPtr->rawlen, 36);
      Serial.print("sent: "); 
    }
    irrecv.resume();
  }

}

void printProtocol(int irProtocol) {
  switch (irProtocol) {
    case UNKNOWN:
      Serial.println("UNKNOWN");
      break;
    case PULSE_WIDTH:
      Serial.println("PULSE_WIDTH");
      break;
    case PULSE_DISTANCE:
      Serial.println("PULSE_DISTANCE");
      break;
    case APPLE:
      Serial.println("APPLE");
      break;

    case DENON:
      Serial.println("DENON");
      break;

    case JVC:
      Serial.println("JVC");
      break;

    case LG:
      Serial.println("LG");
      break;

    case LG2:
      Serial.println("LG2");
      break;

    case NEC:
      Serial.println("NEC");
      break;

    case NEC2:
      Serial.println("NEC2");
      break;

    case ONKYO:
      Serial.println("ONKYO");
      break;

    case PANASONIC:
      Serial.println("PANASONIC");
      break;

    case KASEIKYO:
      Serial.println("KASEIKYO");
      break;

    case KASEIKYO_DENON:
      Serial.println("KASEIKYO_DENON");
      break;

    case KASEIKYO_SHARP:
      Serial.println("KASEIKYO_SHARP");
      break;

    case KASEIKYO_JVC:
      Serial.println("KASEIKYO_JVC");
      break;

    case KASEIKYO_MITSUBISHI:
      Serial.println("KASEIKYO_MITSUBISHI");
      break;

    case RC5:
      Serial.println("RC5");
      break;

    case RC6:
      Serial.println("RC6");
      break;

    case SAMSUNG:
      Serial.println("SAMSUNG");
      break;

    case SAMSUNG48:
      Serial.println("SAMSUNG48");
      break;

    case SAMSUNG_LG:
      Serial.println("SAMSUNG_LG");
      break;

    case SHARP:
      Serial.println("SHARP");
      break;

    case SONY:
      Serial.println("SONY");
      break;

    case BANG_OLUFSEN:
      Serial.println("BANG_OLUFSEN");
      break;

    case BOSEWAVE:
      Serial.println("BOSEWAVE");
      break;

    case LEGO_PF:
      Serial.println("LEGO_PF");
      break;

    case MAGIQUEST:
      Serial.println("MAGIQUEST");
      break;

    case WHYNTER:
      Serial.println("WHYNTER");
      break;
  }
}
