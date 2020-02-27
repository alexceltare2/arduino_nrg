/**
 * RF Sender
 *
 * This program is meant to transmit a pulse with the following 
 * characteristics: to_Adress:7, from_Address: 5, data: 22, every time the button
 * is pressed. The red LED will also flash when data is sent, wait 300ms
 * and LED will go off if the button is not pressed again.
 */

#define RFCHANNEL        0       // Let's use channel 0
#define SYNCWORD1        0xB5    // Synchronization word, high byte
#define SYNCWORD0        0x47    // Synchronization word, low byte
#define SOURCE_ADDR      5       // Device address
#define DESTINATION_ADDR 7
#define PACKET_SIZE      4       // Packet length in bytes (ADDR + DATA1)
#define BUTTON BUTTON_TEST
#define LED_RED LED_RED1

CCPACKET txPacket;
byte data = 22;

void setup()
{

  // Setup LED output pin
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, LOW);
  pinMode(BUTTON, INPUT_PULLUP);

  //panstamp.init(CFREQ_868); //obsolete, change panstamp.h
  panstamp.radio.setChannel(RFCHANNEL);
  panstamp.radio.setSyncWord(SYNCWORD1, SYNCWORD0);
  panstamp.radio.setDevAddress(SOURCE_ADDR);
  panstamp.radio.setCCregs();
  //panstamp.setHighTxPower();
  //panstamp.rxOff();
  panstamp.radio.enableAddressCheck();
}

void loop()
{
   if (digitalRead(BUTTON) == LOW){
    
  digitalWrite(LED_RED, HIGH);
  txPacket.length = PACKET_SIZE;
  txPacket.data[0] = DESTINATION_ADDR;
  txPacket.data[1] = data;
  txPacket.data[2] = data;
  txPacket.data[3] = data;
  panstamp.radio.sendData(txPacket);
  delay(200);
  digitalWrite(LED_RED, LOW);
  } else {
  digitalWrite(LED_RED, LOW);}

}
