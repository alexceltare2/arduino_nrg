//#include<HardwareSerial.h>
STORAGE nvMem;
uint8_t dev_addr;
int i;


void setup() {
pinMode(LED_GREEN, OUTPUT);
pinMode(LED, OUTPUT);

digitalWrite(LED, HIGH);
//Serial.begin(9600);  

  for (i=0;i<=127;i++){
    dev_addr = 255;
    nvMem.write(&dev_addr, INFOMEM_SECTION_D, i, sizeof(dev_addr));
  }

  for (i=0;i<=127;i++){
    dev_addr = 255;
    nvMem.write(&dev_addr, INFOMEM_SECTION_C, i, sizeof(dev_addr));
  }

  for (i=0;i<=127;i++){
    dev_addr = 255;
    nvMem.write(&dev_addr, INFOMEM_SECTION_B, i, sizeof(dev_addr));
  }

  for (i=0;i<=127;i++){
    dev_addr = 255;
    nvMem.write(&dev_addr, INFOMEM_SECTION_A, i, sizeof(dev_addr));
  }
  
//Serial.println("Done clearing the list. All addresses are FF/255");
digitalWrite(LED, LOW);
digitalWrite(LED_GREEN, HIGH);
delay(100);
digitalWrite(LED_GREEN, LOW);
delay(100);
digitalWrite(LED_GREEN, HIGH);
delay(100);
digitalWrite(LED_GREEN, LOW);
delay(100);
digitalWrite(LED_GREEN, HIGH);
delay(100);
digitalWrite(LED_GREEN, LOW);
}

void loop() {
 

}
