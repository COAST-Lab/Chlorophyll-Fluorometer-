/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jessiewynne/Chl_SD_RTC_AS7341_1/src/Chl_SD_RTC_AS7341_1.ino"
//This program monitors light while giving a time stamp and recording both
//basic counts and raw values to an SD card

#include <Adafruit_AS7341.h>
#include <Adafruit_AW9523.h>
#include "RTClibrary.h"
#include <SdFat.h>
#include <limits.h>
#include <numeric>

double calculateAverage(double sum, int count);
void setup();
void loop();
void serialprintresults();
void fileprintresults();
#line 11 "/Users/jessiewynne/Chl_SD_RTC_AS7341_1/src/Chl_SD_RTC_AS7341_1.ino"
Adafruit_AS7341 as7341;
Adafruit_AW9523 aw;
RTC_PCF8523 rtc;
File myFile;
SdFat SD;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const int SD_CHIP_SELECT = D5;
uint8_t LedPin = 0;
int LEDbright = 250;  // adjust this number as needed
int LEDdim = 1;       // adjust this number as needed

double calculateAverage(double sum, int count) {
    if (count == 0) {
        return 0.0; // or any other value to indicate an error or no data
    }
    return sum / static_cast<double>(count);
}

bool startLogging = false;

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {
    delay(1);
  }
  
  if (!as7341.begin()){
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }
  
  // use ATIME of 103, ASTEP of 3457, and GAIN of 512x for dark counts during optical calibration
  as7341.setATIME(59);      
  as7341.setASTEP(599);
  as7341.setGain(AS7341_GAIN_4X);

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
    file.print("ASTEP:");
    file.print(',');
    file.println(as7341.getASTEP());
    file.print("ATIME:");
    file.print(',');
    file.println(as7341.getATIME());
    file.print("GAIN (check table):");
    file.print(',');
    file.println(as7341.getGain());
    // 0.5x records as 0, 1x records as 1, 2x records as 2, 4x records as 3, 
    // 8x records as 4, 16x records as 5, 32x records as 6, 64x records as 7,
    // 128x records as 8, 256x records as 9, 512x records as 10.
    file.println(" ");
    file.println("LED Intensity,Date,Time,Type,F1 (Basic),F2 (Basic),F3 (Basic),F4 (Basic),F5 (Basic),F6 (Basic),F7 (Basic),F8 (Basic),Clear (Basic),NIR (Basic),Type,F1 (Raw),F2 (Raw),F3 (Raw),F4 (Raw),F5 (Raw),F6 (Raw),F7 (Raw),F8 (Raw),Clear (Raw),NIR (Raw)"); // Headers
    file.close();
  } else {
    Serial.println(F("Error opening file!"));
  }
}

void loop() {


  // put your main code here, to run repeatedly:

  //File file = SD.open("data.csv", FILE_WRITE);
  //DateTime now = rtc.now();

  // Switch LED intensity to bright.

  unsigned long currentTime = millis();  // Current time in milliseconds
  unsigned long onTime = 500;  // 1 second on time
  unsigned long offTime = 500;  // 1 second off time

  // Calculate the time elapsed since the start of the loop
  unsigned long elapsedTime = currentTime % (onTime + offTime);



  bool isLedOn = (elapsedTime < onTime);
  aw.analogWrite(LedPin, isLedOn ? LEDbright : LEDdim); // Turn LED on or off
  // aw.analogWrite(LedPin, 250);

  //delay(100);

  serialprintresults();
  
  //save data to SD card

  // if (file) {

    //  print readings
     
    // file.print("LED BRIGHT");
  
    
    fileprintresults();
  // }

  // else {
  //  Serial.println(F("Error opening file!"));
  //}

  //delay(250);

//  Switch LED intensity to dim.



  bool isLedOff = (elapsedTime < offTime);
  aw.analogWrite(LedPin, isLedOff ? LEDdim : LEDbright);
  // aw.analogWrite(LedPin, 1);

  //delay(100);

  serialprintresults();
  
  //save data to SD card
  
  //if (file) {

    //  print readings
     
    //file.print("LED DIM");

  fileprintresults();



//else {
  //  Serial.println(F("Error opening file!"));
 // }

 // delay(250);

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
unsigned long decimalseconds_to_record = (millis() % 1000)/1; //the divided by 1 has to stay, otherwise the program gets stuck during serial monitor!

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
  unsigned long onTime = 500;  // 1 second on time
  unsigned long offTime = 500;  // 1 second off time

  // Calculate the time elapsed since the start of the loop
  unsigned long elapsedTime = currentTime % (onTime + offTime);

  bool isLedOn = (elapsedTime < onTime);

  //delay(100);

  file.print(isLedOn ? LEDbright : LEDdim);
    file.print(',');
file.print(now.year(), DEC);
    file.print('/');
    file.print(now.month(), DEC);
    file.print('/');
    file.print(now.day(), DEC);
    file.print(" (");
    file.print(daysOfTheWeek[now.dayOfTheWeek()]);
    file.print(") ");
    file.print(',');
    file.print(now.hour(), DEC);
    file.print(':');
    file.print(now.minute(), DEC);
    file.print(':');
    file.print(now.second(), DEC);
    file.print(':');
    file.print(decimalseconds_to_record, DEC);
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