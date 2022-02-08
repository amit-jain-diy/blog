#include <avr/pgmspace.h>//need to store letter arrays in flash memory- or else we run out of space, more info here: http://arduino.cc/en/Reference/PROGMEM

// Display Names 
String povtext1 = " GAUTAM ";//PUT YOUR MESSAGE HERE!!- must be in all caps, spaces are fine, no punctuation
String povtext2 = " AMIT ";
String povtext3 = " SURBHI ";

byte refreshrate = 1;//delay time for pixels to refresh in milliseconds- experiment with different values

 //get length of string povtext
int dimtext1 = povtext1.length();
int dimtext2 = povtext2.length();
int dimtext3 = povtext3.length();
int z;
int randomNo;

//letterArray to make sure firmware is loaded correctly- each led should light up in order upon turning on
boolean load[]= {
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
};


//incoming data storage
byte data1 = 0;//for portB
byte data2 = 0;//for portC
byte data3 = 0;//for portD

//variables
byte n; //variable for loops
byte t; //variable for loops
byte l; //variable for loops

//The letters of the alphabet- edit the look of these if you want, just make sure the letters m and w are 15 pixels wide and the rest are 12 pixels
boolean letterA[] PROGMEM = {
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,1,1,1,1,1,1,1,1,0,0,
0,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterB[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterC[] PROGMEM = {
0,0,0,0,1,1,1,1,1,1,1,0,
0,0,1,1,1,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,0,0,0,0,1,1,
1,1,1,1,1,0,0,0,0,0,0,0,
1,1,1,1,1,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,1,0,0,0,0,0,0,0,
0,1,1,1,1,1,0,0,0,0,1,1,
0,1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,1,1,1,1,1,1,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterD[] PROGMEM = {
1,1,1,1,1,1,1,1,1,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterE[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterF[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterG[] PROGMEM = {
0,0,0,0,1,1,1,1,1,0,0,0,
0,0,1,1,1,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,1,1,1,1,1,
0,1,1,1,1,1,0,0,1,1,1,1,
1,1,1,1,1,0,0,0,0,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,1,1,1,1,1,1,
1,1,1,1,0,0,1,1,1,1,1,1,
1,1,1,1,0,0,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,0,1,1,1,
1,1,1,1,1,0,0,0,0,1,1,1,
1,1,1,1,1,1,0,0,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,0,
0,0,1,1,1,1,1,1,1,1,0,0,
0,0,0,0,1,1,1,1,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterH[] PROGMEM = {
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterI[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterJ[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
1,1,1,0,1,1,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,0,0,0,0,
0,1,1,1,1,1,1,0,0,0,0,0,
0,0,1,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterK[] PROGMEM = {
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,0,
1,1,1,1,0,0,0,1,1,1,1,0,
1,1,1,1,0,0,1,1,1,1,0,0,
1,1,1,1,0,0,1,1,1,1,0,0,
1,1,1,1,0,1,1,1,1,1,0,0,
1,1,1,1,1,1,1,1,1,0,0,0,
1,1,1,1,1,1,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,0,0,0,0,
1,1,1,1,0,1,1,1,1,0,0,0,
1,1,1,1,0,1,1,1,1,1,0,0,
1,1,1,1,0,0,1,1,1,1,0,0,
1,1,1,1,0,0,0,1,1,1,1,0,
1,1,1,1,0,0,0,1,1,1,1,0,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterL[] PROGMEM = {
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterM[] PROGMEM = {
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,
1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,
1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,
1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,
1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,
1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterN[] PROGMEM = {
1,1,1,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,1,0,0,0,1,1,1,1,
1,1,1,1,1,0,0,0,1,1,1,1,
1,1,1,1,1,1,0,0,1,1,1,1,
1,1,1,1,1,1,0,0,1,1,1,1,
1,1,1,1,1,1,1,0,1,1,1,1,
1,1,1,1,1,1,1,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,1,1,1,1,1,1,1,
1,1,1,1,0,1,1,1,1,1,1,1,
1,1,1,1,0,0,1,1,1,1,1,1,
1,1,1,1,0,0,1,1,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterO[] PROGMEM = {
0,0,0,1,1,1,1,1,1,0,0,0,
0,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,1,0,0,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterP[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterQ[] PROGMEM = {
0,0,0,1,1,1,1,1,1,0,0,0,
0,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,0,0,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,1,1,1,1,
1,1,1,1,1,0,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,1,1,1,1,1,0,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,

};

boolean letterR[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,0,0,
1,1,1,1,0,0,1,1,1,1,1,0,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterS[] PROGMEM = {
0,0,1,1,1,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,0,0,0,0,
1,1,1,1,1,0,0,0,0,0,0,0,
0,1,1,1,1,1,0,0,0,0,0,0,
0,0,1,1,1,1,1,0,0,0,0,0,
0,0,0,1,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,1,0,0,0,
0,0,0,0,0,1,1,1,1,1,0,0,
0,0,0,0,0,0,1,1,1,1,0,0,
0,0,0,0,0,0,0,1,1,1,1,0,
0,0,0,0,0,0,0,1,1,1,1,1,
0,0,0,0,0,0,0,1,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,0,
1,1,1,1,1,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,1,1,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterT[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterU[] PROGMEM = {
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,1,0,0,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterV[] PROGMEM = {
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,1,1,1,0,0,0,0,1,1,1,0,
0,1,1,1,1,0,0,1,1,1,1,0,
0,1,1,1,1,0,0,1,1,1,1,0,
0,0,1,1,1,0,0,1,1,1,0,0,
0,0,1,1,1,1,1,1,1,1,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterW[] PROGMEM = {
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,
1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,
1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,
1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,
1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,
0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,
0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterX[] PROGMEM = {
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,1,1,1,0,0,0,0,1,1,1,0,
0,1,1,1,1,0,0,1,1,1,1,0,
0,0,1,1,1,0,0,1,1,1,0,0,
0,0,1,1,1,1,1,1,1,1,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,1,1,1,1,1,1,1,1,0,0,
0,0,1,1,1,0,0,1,1,1,0,0,
0,1,1,1,1,0,0,1,1,1,1,0,
0,1,1,1,0,0,0,0,1,1,1,0,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterY[] PROGMEM = {
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,0,0,0,0,1,1,1,1,
0,1,1,1,0,0,0,0,1,1,1,0,
0,1,1,1,1,0,0,1,1,1,1,0,
0,0,1,1,1,0,0,1,1,1,0,0,
0,0,1,1,1,1,1,1,1,1,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,1,1,1,1,1,1,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
};

boolean letterZ[] PROGMEM = {
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,1,1,1,1,
0,0,0,0,0,0,0,1,1,1,1,0,
0,0,0,0,0,0,1,1,1,1,0,0,
0,0,0,0,0,0,1,1,1,1,0,0,
0,0,0,0,0,1,1,1,1,0,0,0,
0,0,0,0,0,1,1,1,1,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,1,1,1,1,0,0,0,0,0,
0,0,1,1,1,1,1,0,0,0,0,0,
0,0,1,1,1,1,0,0,0,0,0,0,
0,1,1,1,1,0,0,0,0,0,0,0,
1,1,1,1,1,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,
};
//-------------------------------------------------------------------------------

boolean Zufo30[] PROGMEM = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

boolean Zalien17[] PROGMEM = {
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0,
0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0,
1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

boolean Zsmile21[] PROGMEM = {
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0,
0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0,
0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};


boolean Zstar21[] PROGMEM = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1,
0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

};


boolean Zheart21[] PROGMEM = {
0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

// ------------------------------------------------------------------------------
  void sendToWand(boolean letterArray[]){//function to get array data
    
  for (t=0; t<12; t++){ //for each time step

  for (l=0; l<6; l++){ //for first six rows of data
    data1 = data1 << 1;//bitwise shift left
    data1 |= pgm_read_byte_near(letterArray + (l*12+t));//add next value from dataset
  }
  for (l=6; l<14; l++){ //for next eight rows of data
    data2 = data2 << 1;//bitwise shift left
    data2 |= pgm_read_byte_near(letterArray + (l*12+t));//add next value from dataset
  }
  for (l=14; l<20; l++){ //for next six rows of data
    data3 = data3 << 1;//bitwise shift left
    data3 |= pgm_read_byte_near(letterArray + (l*12+t));//add next value from dataset
  }
  //SET PINS:
  PORTB = data1;
  PORTD = data2;
  PORTC = data3;
  delay(refreshrate);
  //clear data storage
  data1=0;
  data2=0;
  data3=0;
  }
  }
// ------------------------------------------------------------------------------
  
  void sendToWandMW(boolean letterArray[]){//M and W are extra wide- they have a special function to get array data (with 15 time steps instead of 12)
    
  //send data to leds via port/pin manipulation
  for (t=0; t<15; t++){ //for each time step

  for (l=0; l<6; l++){ //for first six rows of data
    data1 = data1 << 1;//bitwise shift left
    data1 |= pgm_read_byte_near(letterArray + (l*15+t));//add next value from dataset
  }
  for (l=6; l<14; l++){ //for next eight rows of data
    data2 = data2 << 1;//bitwise shift left
    data2 |= pgm_read_byte_near(letterArray + (l*15+t));//add next value from dataset
  }
  for (l=14; l<20; l++){ //for next six rows of data
    data3 = data3 << 1;//bitwise shift left
    data3 |= pgm_read_byte_near(letterArray + (l*15+t));//add next value from dataset
  }
  //SET PINS:
  PORTB = data1;
  PORTD = data2;
  PORTC = data3;
  delay(refreshrate);
  //clear data storage
  data1=0;
  data2=0;
  data3=0;
  }
  }
// ------------------------------------------------------------------------------
  void sendToWandSpecial(boolean letterArray[], int zchar)
  {//function to get array data
  for (t=0; t<zchar; t++){ //for each time step

  for (l=0; l<6; l++){ //for first six rows of data
    data1 = data1 << 1;//bitwise shift left
    data1 |= pgm_read_byte_near(letterArray + (l*zchar+t));//add next value from dataset
  }
  for (l=6; l<14; l++){ //for next eight rows of data
    data2 = data2 << 1;//bitwise shift left
    data2 |= pgm_read_byte_near(letterArray + (l*zchar+t));//add next value from dataset
  }
  for (l=14; l<20; l++){ //for next six rows of data
    data3 = data3 << 1;//bitwise shift left
    data3 |= pgm_read_byte_near(letterArray + (l*zchar+t));//add next value from dataset
  }
  //SET PINS:
  PORTB = data1;
  PORTD = data2;
  PORTC = data3;
  delay(refreshrate);
  //clear data storage
  data1=0;
  data2=0;
  data3=0;
  }
}
  

  
 



// ------------------------------------------------------------------------------

void setup() {
 //port/pin assignments- set all pins to output- more info here: http://www.arduino.cc/en/Reference/PortManipulation
  DDRB = 0xFF;//port b- digital pins 8-13
  DDRC = 0xFF;//port c- anlog pins 0-5
  DDRD = 0xFF;//port d- digital pins 0-7
  
 //run intialization so we know device is working- leds should light up in order from top of wand to bottom
 for (byte j=0; j<20; j++){ //for each time step
  for (byte i=0; i<6; i++){ //for first six rows of data
    data1 = data1 << 1;//bitwise shift left
    data1 |= load[(i*20+j)];//add next value from dataset
  }
  for (byte i=6; i<14; i++){ //for next eight rows of data
    data2 = data2 << 1;//bitwise shift left
    data2 |= load[(i*20+j)];//add next value from dataset
  }
  for (byte i=14; i<20; i++){ //for next six rows of data
    data3 = data3 << 1;//bitwise shift left
    data3 |= load[(i*20+j)];//add next value from dataset
  }
  PORTB = data1;
  PORTD = data2;
  PORTC = data3;
  delay(100);
 }
 //clear data storage
 data1 = 0;
 data2 = 0;
 data3 = 0;
 //clear ports- set all arduino pins to 0Volts
 PORTB = data1;
 PORTD = data2;
 PORTC = data3;
}
// ------------------------------------------------------------------------------


void drawtextmsg( String povtext, int dimtext ) 
{
  //go through each character of povtext and call function sendToWand to display letter
  for (n=0; n<dimtext; n++) { 
    if (povtext.charAt(n)=='A') {
      sendToWand(letterA);
      }
    else if (povtext.charAt(n)=='B') {
      sendToWand(letterB);
    }
    else if (povtext.charAt(n)=='C') {
      sendToWand(letterC);
    }
    else if (povtext.charAt(n)=='D') {
      sendToWand(letterD);
    }
    else if (povtext.charAt(n)=='E') {
      sendToWand(letterE);
    }
    else if (povtext.charAt(n)=='F') {
      sendToWand(letterF);
    }
    else if (povtext.charAt(n)=='G') {
      sendToWand(letterG);
    }
    else if (povtext.charAt(n)=='H') {
      sendToWand(letterH);
    }
    else if (povtext.charAt(n)=='I') {
      sendToWand(letterI);
    }
    else if (povtext.charAt(n)=='J') {
      sendToWand(letterJ);
    }
    else if (povtext.charAt(n)=='K') {
      sendToWand(letterK);
    }
    else if (povtext.charAt(n)=='L') {
      sendToWand(letterL);
    }
    else if (povtext.charAt(n)=='M') {
      sendToWandMW(letterM);
    }
    else if (povtext.charAt(n)=='N') {
      sendToWand(letterN);
    }
    else if (povtext.charAt(n)=='O') {
      sendToWand(letterO);
    }
    else if (povtext.charAt(n)=='P') {
      sendToWand(letterP);
    }
    else if (povtext.charAt(n)=='Q') {
      sendToWand(letterQ);
    }
    else if (povtext.charAt(n)=='R') {
      sendToWand(letterR);
    }
    else if (povtext.charAt(n)=='S') {
      sendToWand(letterS);
    }
    else if (povtext.charAt(n)=='T') {
      sendToWand(letterT);
    }
    else if (povtext.charAt(n)=='U') {
      sendToWand(letterU);
    }
    else if (povtext.charAt(n)=='V') {
      sendToWand(letterV);
    }
    else if (povtext.charAt(n)=='W') {
      sendToWandMW(letterW);
    }
    else if (povtext.charAt(n)=='X') {
      sendToWand(letterX);
    }
    else if (povtext.charAt(n)=='Y') {
      sendToWand(letterY);
    }
    else if (povtext.charAt(n)=='Z') {
      sendToWand(letterZ);
    }
    else if (povtext.charAt(n)==' ') {
      PORTB = 0;
      PORTD = 0;
      PORTC = 0;
   delay(refreshrate*3);//off for 3 pixels
    }
    //space between each character
    PORTB = 0;
    PORTD = 0;
    PORTC = 0;
   delay(refreshrate);
  }
  
  //space at end of text
   PORTB = 0;
   PORTD = 0;
   PORTC = 0;
   delay(refreshrate*3);
}
// -----------------------------------------------------


void loop() {
  
  //space at beginning of text
   PORTB = 0;
   PORTD = 0;
   PORTC = 0;
   delay(refreshrate*3);
  
   randomNo = random(1, 9);
   
   for (z=0; z<50; z++) {
   
	if (randomNo == 1) {
		drawtextmsg(povtext1,dimtext1);
                z++;
	}
	else if (randomNo == 2) {
		drawtextmsg(povtext2,dimtext2);
                z++;
	}
	else if (randomNo == 3) {
		drawtextmsg(povtext3,dimtext3);
                z++;
	}
	else if (randomNo == 4) {
		sendToWandSpecial(Zufo30,30) ;
	}
	else if (randomNo == 5) {
		sendToWandSpecial(Zsmile21,21) ;
	}
	else if (randomNo == 6) {
		sendToWandSpecial(Zstar21,21) ;
	}
	else if (randomNo == 7) {
		sendToWandSpecial(Zalien17,17) ;
	}
	else  {
		sendToWandSpecial(Zheart21,21) ;
	}
   // Blank space between 
   
   PORTB = 0;
   PORTD = 0;
   PORTC = 0;
   delay(refreshrate*3);
 
   }
   
   // for debug // sendToWandSpecial(Zalien17,17) ;
   
 }
