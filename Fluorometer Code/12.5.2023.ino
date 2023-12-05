//This program monitors light while giving a time stamp and recording both
//basic counts and raw values to an SD card

#include <Adafruit_AS7341.h>
#include <Adafruit_AW9523.h>
#include "RTClibrary.h"
#include <SdFat.h>

Adafruit_AS7341 as7341;
Adafruit_AW9523 aw;
RTC_PCF8523 rtc;
File myFile;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const int SD_CHIP_SELECT = D5;
uint8_t LedPin = 0;
int LEDbright = 255; 
 // adjust this number as needed
int LEDdim = 0;       // adjust this number as needed

SdFat SD;

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {
    delay(1);
  }
  
  if (!as7341.begin(0x39)){
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }
  
  // use ATIME of 103, ASTEP of 3457, and GAIN of 512x for dark counts during optical calibration
  as7341.setATIME(255);      
  as7341.setASTEP(1405);
  as7341.setGain(AS7341_GAIN_128X);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.initialized()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  if (! aw.begin(0x58)) {
    Serial.println("AW9523 not found? Check wiring!");
    while (1) delay(10);  // halt forever
  }

  Serial.println("AW9523 found!");
  aw.pinMode(LedPin, AW9523_LED_MODE);

  SD.begin(SD_CHIP_SELECT);
 
  File file = SD.open("data.csv", FILE_WRITE);

  if (file) {
    file.println("Date and Time,ASTEP,ATIME,GAIN,LED Status,LED Intensity,Test,Milliseconds,Seconds,Type,F1 (Basic),F2 (Basic),F3 (Basic),F4 (Basic),F5 (Basic),F6 (Basic),F7 (Basic),F8 (Basic),Clear (Basic),NIR (Basic),Type,F1 (Raw),F2 (Raw),F3 (Raw),F4 (Raw),F5 (Raw),F6 (Raw),F7 (Raw),F8 (Raw),Clear (Raw),NIR (Raw)"); // Headers
    file.close();
    } else {
    Serial.println(F("Error opening file!"));
  }
}


void loop() {
  serialprintresults();
  
  //save data to SD card

  // if (file) {

    //  print readings
     
    // file.print("LED BRIGHT");
  
    
  fileprintresults();


}

void serialprintresults() 
{

DateTime now = rtc.now();
unsigned long decimalseconds_to_record = (millis() % 1000)/1; //the divided by 1 has to stay, otherwise the program gets stuck during serial monitor!

Serial.print("LED INTENSITY:");
  Serial.print(" ");
  Serial.println(LEDbright);
  Serial.println();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print('.');
  Serial.print(decimalseconds_to_record, DEC);
  Serial.println();

  uint16_t readings[12];
  float counts[12];

    if (!as7341.readAllChannels(readings)){
    Serial.println("Error reading all channels!");
    return;
  }

  for(uint8_t i = 0; i < 12; i++) {
    if(i == 4 || i == 5) continue;
    // we skip the first set of duplicate clear/NIR readings
    // (indices 4 and 5)
    counts[i] = as7341.toBasicCounts(readings[i]);
  }
  Serial.print(',');
  Serial.println(millis() / 1000);
  Serial.print("F1 415nm : ");
  Serial.print(counts[0]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[0]);
  Serial.print("F2 445nm : ");
  Serial.print(counts[1]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[1]);
  Serial.print("F3 480nm : ");
  Serial.print(counts[2]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[2]);
  Serial.print("F4 515nm : ");
  Serial.print(counts[3]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[3]);
  Serial.print("F5 555nm : ");

  // again, we skip the duplicates  

  Serial.print(counts[6]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[6]);
  Serial.print("F6 590nm : ");
  Serial.print(counts[7]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[7]);
  Serial.print("F7 630nm : ");
  Serial.print(counts[8]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[8]);
  Serial.print("F8 680nm : ");
  Serial.print(counts[9]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[9]);
  Serial.print("Clear    : ");
  Serial.print(counts[10]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[10]);
  Serial.print("NIR      : ");
  Serial.print(counts[11]);
  Serial.print("  ");
  Serial.print("Raw Value : ");
  Serial.println(readings[11]);
  Serial.print("  ");
  Serial.println();
}

void fileprintresults() 
{

File file = SD.open("data.csv", FILE_WRITE);
DateTime now = rtc.now();
// unsigned long decimalseconds_to_record = (millis() % 1000)/1; //the divided by 1 has to stay, otherwise the program gets stuck during serial monitor!

 uint16_t readings[12];
  float counts[12];

    if (!as7341.readAllChannels(readings)){
    Serial.println("Error reading all channels!");
    return;
  }

  for(uint8_t i = 0; i < 12; i++) {
    if(i == 4 || i == 5) continue;
    // we skip the first set of duplicate clear/NIR readings
    // (indices 4 and 5)
    counts[i] = as7341.toBasicCounts(readings[i]);
  }

if (file) {

  unsigned long currentTime = millis();  // Current time in milliseconds
  unsigned long onTime = 60000;  // 1 second on time
  unsigned long offTime = 0;  // 1 second off time

  // Calculate the time elapsed since the start of the loop
  unsigned long elapsedTime = currentTime % (onTime + offTime);

  bool isLedOn = (elapsedTime < onTime);
  aw.analogWrite(LedPin, isLedOn ? 255 : 0); // Turn LED on or off
  delay(100); // Add a small delay to stabilize the LED current

  //delay(100);
    file.print(now.year(), DEC);
    file.print('/');
    file.print(now.month(), DEC);
    file.print('/');
    file.print(now.day(), DEC);
    file.print(" (");
    file.print(daysOfTheWeek[now.dayOfTheWeek()]);
    file.print(") ");
    file.print(now.hour(), DEC);
    file.print(':');
    file.print(now.minute(), DEC);
    file.print(':');
    file.print(now.second(), DEC);
    file.print(',');
    file.print(as7341.getASTEP());
    file.print(',');
    file.print(as7341.getATIME());
    file.print(',');
    file.print(as7341.getGain());
    file.print(',');
    file.print(isLedOn ? "LED ON" : "LED OFF");
    file.print(',');
    file.print(isLedOn ? "255" : "0"); // Record the LED intensity (100 when on, 0 when off)
    file.print(',');
    file.print("50.0");
    file.print(',');
    file.print(millis() / 1000);
    file.print(','); 
    file.print(millis());
    file.print(',');
    file.print("BASIC COUNTS");
    file.print(',');
    file.print(counts[0]);
    file.print(',');
    file.print(counts[1]);
    file.print(',');
    file.print(counts[2]);
    file.print(',');
    file.print(counts[3]);
    file.print(',');
    file.print(counts[6]);
    file.print(',');
    file.print(counts[7]);
    file.print(',');
    file.print(counts[8]);
    file.print(',');
    file.print(counts[9]);
    file.print(',');
    file.print(counts[10]);
    file.print(',');
    file.print(counts[11]);
    file.print(',');
    file.print("RAW VALUES");
    file.print(',');
    file.print(readings[0]);
    file.print(',');
    file.print(readings[1]);
    file.print(',');
    file.print(readings[2]);
    file.print(',');
    file.print(readings[3]);
    file.print(',');
    file.print(readings[6]);
    file.print(',');
    file.print(readings[7]);
    file.print(',');
    file.print(readings[8]);
    file.print(',');
    file.print(readings[9]);
    file.print(',');
    file.print(readings[10]);
    file.print(',');
    file.println(readings[11]);
    file.close();

}

else {
    Serial.println(F("Error opening file!"));
  }

}
