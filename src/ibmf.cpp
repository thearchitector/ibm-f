#include <BleKeyboard.h>

#define TX_CLOCK 2
#define TX_DATA 3

BleKeyboard bleKeyboard("IBM F-BLE", "Elias Gabriel", 100);

bool isReading = false;
byte keystroke = 0;
int bitPos = 0;

void capture() {
  if(bleKeyboard.isConnected()) {
    // initial "start" bit, should be 1
    if(!isReading) {
      keystroke = 0;
      bitPos = 0;
      isReading = true;
    }
    else {
      if(bitPos == 8) {
        // final "end" bit, should be 0
        Serial.println(String(keystroke, BIN));
        Serial.println(String(keystroke, DEC));
        isReading = false;
      }
      else {
        bool rx_bit = digitalRead(TX_DATA);
        if(rx_bit) keystroke |= (1 << bitPos);
        bitPos += 1;
      }
    }
  } 
  else {
    isReading = false;
    keystroke = 0;
    bitPos = 0;
  }
}

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();

  pinMode(TX_CLOCK, INPUT);
  pinMode(TX_DATA, INPUT);

  attachInterrupt(digitalPinToInterrupt(TX_CLOCK), capture, RISING);
}

void loop() {
  
}
