#include <RCSwitch.h>
#define INTERVAL 5000

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  Serial.println("start");
  mySwitch.enableReceive(22);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
    Serial.println("DOORBELL!!! Ada tamu nih! Nyalakan suara");
  }
}
