//Include These Libraries
#include <SFE_MicroOLED.h>
#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>

//Screen Definitions: Change these based on what pins you use. 
#define PIN_RST 9 //RST
#define PIN_DC 8 //DC
#define PIN_CS 10 //CS
MicroOLED oled(PIN_RST, PIN_DC, PIN_CS);

//Bluetooth Declaration
SoftwareSerial BT(4,5);

void setup() {
  // put your setup code here, to run once:
  oled.begin(); //Starts up the display
  initBT();
  
}

void loop() {
  // put your main code here, to run repeatedly:


}

void initBT(){
  String setName = String("AT+NAME=OpenWear Glass\r\n");
  Serial.begin(9600);
  BT.begin(38400);
  BT.print("AT\r\n");
  delay(500);
  while (BT.available())
    Serial.write(BT.read());
  BT.print(setName);
  delay(500);
  while (BT.available())
    Serial.write(BT.read());
}

void batteryInfo(){
    int percent = 0;
    oled.setCursor(8, 40);
    oled.print(analogRead(percent));
    oled.print("%");
    //batteryIcon(percent);
}
/*
void batteryIcon(int percent){
  oled.line(2, 39, 4, 39);
  oled.line(1, 40, 2, 40); 
  oled.line(4, 40, 5, 40);
  oled.line(1, 40, 1, 46);
  oled.line(5, 40, 5, 46);
  oled.line(1, 46, 5, 46);
  if (percent > 90)
    oled.rectFill(2, 45, 3, 6);
  else if (percent > 75)
    oled.rectFill(2, 45, 3, 5);
  else if (percent > 50)
    oled.rectFill(2, 45, 3, 4);
  else if (percent > 25)
    oled.rectFill(2, 45, 3, 3);
  else if (percent > 5)
    oled.rectFill(2, 45, 3, 2);
  oled.display();
}
*/
