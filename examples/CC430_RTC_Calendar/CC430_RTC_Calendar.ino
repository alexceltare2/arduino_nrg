/*
*Welcome to the CC430 Serial Monitor program. To make the program display your results
*on the serial monitor you need to ground DTR when you've oppened the Serial Monitor
*applet. Ground the RTS pin to reset the MCU (applies to the WCH CH430 UART families).
*/

#include <HardwareSerial.h>
RTCDATA rtcData;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
rtcData.year = 2019;
rtcData.mon = 1;
rtcData.day = 10;
rtcData.wday = 3;
rtcData.hour = 11;
rtcData.min = 25;
rtcData.sec = 30;
panstamp.rtc.startCalendar(&rtcData);
  Serial.println("Calendar Started");
}

void loop() {
  
  if (digitalRead(BUTTON)==LOW){
    Serial.print("Time: ");Serial.print(RTC_GET_HOUR());Serial.print(":");Serial.print(RTC_GET_MIN());Serial.print(":");Serial.println(RTC_GET_SEC());
    delay(1000);
  }
}
