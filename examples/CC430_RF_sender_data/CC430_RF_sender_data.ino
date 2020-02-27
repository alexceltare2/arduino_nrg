
#define RFCHANNEL        0       // Let's use channel 0
#define SYNCWORD1        0xB5    // Synchronization word, high byte
#define SYNCWORD0        0x47    // Synchronization word, low byte
//#define SOURCE_ADDR      5       // Device address
//#define DESTINATION_ADDR 254
#define PACKET_SIZE      11       // Packet length in bytes (ADDR + DATA1)

CCPACKET txPacket;
const int buttonPin = BUTTON;
const int ledPin = LED_RED;
uint8_t main_addr = panstamp.core.getShortUID();
uint8_t dev_addr = 254;
int i, j, voltage = 0;
uint8_t uid[8];

void setup()
{

  // Setup LED output pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(buttonPin, INPUT_PULLUP);

  //panstamp.init(CFREQ_868); //obsolete, change panstamp.h
  //panstamp.radio.setCarrierFreq(CFREQ_868);
  panstamp.radio.setChannel(RFCHANNEL);
  panstamp.radio.setSyncWord(SYNCWORD1, SYNCWORD0);
  panstamp.radio.setDevAddress(main_addr);
  panstamp.radio.setCCregs();
  //panstamp.setHighTxPower();
  //panstamp.rxOff();
  attachInterrupt(buttonPin, myISR, FALLING);
  
}

void loop(){
  panstamp.sleep();
if (digitalRead(buttonPin) == LOW){
  digitalWrite(ledPin, HIGH);
  //for (i = 1; i <= 100; i++){
  voltage = analogRead(A11);
  panstamp.core.getUID(uid);

  for (i = 1; i <= 100; i++){
  txPacket.length = PACKET_SIZE;
  txPacket.data[0] = dev_addr;
  for (j = 0; j <= 7; j++){
  txPacket.data[j+1] = uid[j];
  }
  txPacket.data[9] = voltage/100;
  txPacket.data[10] = voltage%100;
  panstamp.radio.sendData(txPacket);
  delay(100);
  }
  voltage = 0;
  //panstamp.sleepSec(1);
  //}
  digitalWrite(ledPin, LOW);
  } else {
  digitalWrite(ledPin, LOW);}
}

void myISR(){
  
}
