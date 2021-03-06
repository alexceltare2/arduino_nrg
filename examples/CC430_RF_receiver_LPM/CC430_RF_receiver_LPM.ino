#include<HardwareSerial.h>
#define RFCHANNEL        0       // Let's use channel 0
#define SYNCWORD1        0xB5    // Synchronization word, high byte
#define SYNCWORD0        0x47    // Synchronization word, low byte
#define SOURCE_ADDR      11      // Sender address
#define PACKET_SIZE      3       // Size of packet in bytes (ADDR + DATA1 +...)


CCPACKET txPacket;  // packet object
const uint8_t alarmPin = PIN_RX;
uint8_t data_zero;
uint8_t data_one;
uint8_t data_two;
int n;
int i;

uint16_t x;

  
void setup()
{
  // Setup LED output pin
  pinMode(alarmPin, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  

  //panstamp.init(CFREQ_868); //obsolete, change panstamp.h
  //panstamp.radio.setCarrierFreq(CFREQ_868);
  panstamp.radio.setChannel(RFCHANNEL);
  panstamp.radio.setSyncWord(SYNCWORD1, SYNCWORD0);
  panstamp.radio.setDevAddress(SOURCE_ADDR);
  panstamp.radio.setCCregs();
  //panstamp.setLowTxPower();

  // Let's disable address check for the current project so that our device
  // will receive packets even not addressed to it.
  panstamp.radio.enableAddressCheck();

  // Declare RF interrupt function
  panstamp.setPacketRxCallback(rfPacketReceived);
  send_dummy_packet(); //Necessarily dummy send packet for good reception
    
}

void loop()
{
  //panstamp.radio.setWorState(100);
  //digitalWrite(LED_GREEN, LOW); 
  panstamp.sleepSec(2);
  panstamp.wakeUp();
  if (data_one == 0xFA){
    digitalWrite(LED_RED, HIGH);
    delay(200);
    sound_the_alarm_smoke_as_co();
    digitalWrite(LED_RED, LOW);
    delay(200);
    data_one=0;
  }
}

void rfPacketReceived(CCPACKET *packet)
{   
  if (packet->length > 1) { 
     
   // Our source address
     data_one = packet->data[1];   // Self-incrementing value generated by the sender
     data_two = packet->data[2];  
  }
}

void send_dummy_packet() {
  txPacket.length = PACKET_SIZE;
  txPacket.data[0] = 0b11111110; //dummy address
  txPacket.data[1] = 0; //learn this please
  txPacket.data[2] = 0; //learn this please
  panstamp.radio.sendData(txPacket);
}

void sound_the_alarm_smoke() {
  x = 0b0000101011101011; //String to be sent.
  for (n = 15; n >= 0; n--)
  {
    digitalWrite(alarmPin, bitRead(x, n));
    delay_precise();
  }
  digitalWrite(alarmPin, LOW);
}

void sound_the_alarm_smoke_as_co() {
  for (i = 1; i <= 4; i++) { //20 quick beeps
    x = 0b0000101010011010; //String to be sent.
    delay(200);
    for (n = 15; n >= 0; n--)
    {
      digitalWrite(alarmPin, bitRead(x, n));
      delay_precise();
    }
    digitalWrite(alarmPin, LOW);
}
}

void delay_precise() {
  delayMicroseconds(1010); //smoke-1ms
}

void delay_precise2() { //heat-30ms
  delay(30);
}

void delay_precise3(){ //CO-500ms
  delay(500);
}
