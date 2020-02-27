/**
 * Basic radio example
 *
 * Each node acts simultaneously as sender and receiver. Each node sends a packet
 * every five senconds and toggles a LED each time a packet is received
 */
#include<HardwareSerial.h>

#define RFCHANNEL        0       // Let's use channel 0
#define SYNCWORD1        0xB5    // Synchronization word, high byte
#define SYNCWORD0        0x47    // Synchronization word, low byte
#define SOURCE_ADDR      7       // Sender address
#define PACKET_SIZE      2       // Size of packet in bytes (ADDR + DATA1 +...)

CCPACKET txPacket;  // packet object

/**
 * This function is called whenever a wireless packet is received
 */
void rfPacketReceived(CCPACKET *packet)
{   
  // The LED will toggle when a new packet is received
  if (packet->length > 1){
  digitalWrite(LED, HIGH);
  delay(1);
  //Serial.println("Packet Received.");
  Serial.print("DataID: ");
  if (packet->data[1]<=15){Serial.print("0");}
  Serial.print(packet->data[1],HEX);
  Serial.print(" ");
  if (packet->data[2]<=15){Serial.print("0");}
  Serial.print(packet->data[2],HEX);
  Serial.print(" ");
  if (packet->data[3]<=15){Serial.print("0");}
  Serial.print(packet->data[3],HEX);
  Serial.print(" ");
  if (packet->data[4]<=15){Serial.print("0");}
  Serial.print(packet->data[4],HEX);
  Serial.print(" ");
  if (packet->data[5]<=15){Serial.print("0");}
  Serial.print(packet->data[5],HEX);
  Serial.print(" ");
  if (packet->data[6]<=15){Serial.print("0");}
  Serial.print(packet->data[6],HEX);
  Serial.print(" ");
  if (packet->data[7]<=15){Serial.print("0");}
  Serial.print(packet->data[7],HEX);
  Serial.print(" ");
  if (packet->data[8]<=15){Serial.print("0");}
  Serial.println(packet->data[8],HEX);
  Serial.print("DataV: ");
  if (packet->data[9]<=15){Serial.print("0");}
  Serial.print(packet->data[9]);
  if (packet->data[10]<=15){Serial.print("0");}
  Serial.println(packet->data[10]);
  //Serial.print("Length:");Serial.println(packet->length);
  //Serial.print("CRC:");Serial.println(packet->crc_ok);
  Serial.print("RSSI/Signal Strength: ");Serial.println(packet->rssi);
  Serial.print("LQI/Link Quality: ");Serial.println(packet->lqi);
  digitalWrite(LED, LOW);
  }

}
  
void setup()
{
  // Setup LED output pin
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  //panstamp.init(CFREQ_868); //obsolete, change panstamp.h
  panstamp.radio.setChannel(RFCHANNEL);
  panstamp.radio.setSyncWord(SYNCWORD1, SYNCWORD0);
  panstamp.radio.setDevAddress(SOURCE_ADDR);
  panstamp.radio.setCCregs();
  //panstamp.setLowTxPower();

  // Let's disable address check for the current project so that our device
  // will receive packets even not addressed to it.
  panstamp.radio.disableAddressCheck();

  // Declare RF callback function
  panstamp.setPacketRxCallback(rfPacketReceived);
  send_dummy_packet(); //Necessarily dummy send packet
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED, LOW);
}

void send_dummy_packet() {
  txPacket.length = PACKET_SIZE;
  txPacket.data[0] = 0b11111110; //dummy address
  txPacket.data[1] = 0; //learn this please
  txPacket.data[2] = 0;
  txPacket.data[3] = 0;
  panstamp.radio.sendData(txPacket);
}
