/*
 * This example shows how to read the Internal Temperature of the MCU.
 */
#include<HardwareSerial.h>
#define CAL_ADC_15T30   *((uint16_t *)0x1A1A)
#define CAL_ADC_15T85   *((uint16_t *)0x1A1C)
#define CAL_ADC_20T30   *((uint16_t *)0x1A1E)
#define CAL_ADC_20T85   *((uint16_t *)0x1A20)
#define CAL_ADC_25T30   *((uint16_t *)0x1A22)
#define CAL_ADC_25T85   *((uint16_t *)0x1A24)


float cal_temp_15, cal_temp_20, cal_temp_25, temp_vcc;


void setup() {
  pinMode(A10,INPUT);

}

void loop() {
  
//   analogReference(INTERNAL1V5);
//   int DegC = ((analogRead(A10) - 673) * 423) / 1024; //Celsius
//   int DecC = ((analogRead(A10) - 673) * 423) % 1024;
//   int DegF = ((analogRead(A10) - 630) * 761) / 1024; //Fahrenheit
//   int DecF = ((analogRead(A10) - 630) * 761) % 1024;
//   Serial.print("Internal MCU Temperature: ");
//   Serial.print(DegC);Serial.print(".");Serial.print(DecC);Serial.println(" *C");
//   delay(200);
  

  
//   //Legacy:
//   Serial.print("Internal MCU Temperature: ");
//   Serial.print(panstamp.core.getTemp());Serial.println("*C");
//   delay(200);


//   //Debug:
//   analogReference(INTERNAL1V5);//(REFVSEL_0/1/2/3 to 0 ->1.5/2/2.5/2.5 to 3.3, default is 0)
//   cal_temp_15 = (analogRead(A10) - CAL_ADC_15T30)*((85.00 - 30.00)/(CAL_ADC_15T85 - CAL_ADC_15T30))+30.0;
//   delay(50);

   //The most reliable result with -13*C offset added 
   analogReference(INTERNAL2V0);
   cal_temp_20 = (analogRead(A10) - CAL_ADC_20T30)*((85.00 - 30.00)/(CAL_ADC_20T85 - CAL_ADC_20T30))+30.0-13.0;
   delay(50);
   
//   analogReference(INTERNAL2V5);
//   cal_temp_25 = (analogRead(A10) - CAL_ADC_25T30)*((85.00 - 30.00)/(CAL_ADC_25T85 - CAL_ADC_25T30))+30.0;
//   delay(50);
//   
//   analogReference(DEFAULT);
//   temp_vcc = analogRead(A10);
//   delay(50);


   Serial.begin(9600);
   //Serial.print(cal_temp_15);Serial.println(" *C Calibrated for 1.5Vref");
   Serial.print(cal_temp_20);Serial.println(" *C Calibrated for 2.0Vref");
   //Serial.print(cal_temp_25);Serial.println(" *C Calibrated for 2.5Vref");
   //Serial.print(temp_vcc);Serial.println(" *C for VCCref\n");
   Serial.end();
   //Serial.print(DegC);Serial.print(".");
   //Serial.print(DecC);Serial.println(" *C");
   delay(500);
}
