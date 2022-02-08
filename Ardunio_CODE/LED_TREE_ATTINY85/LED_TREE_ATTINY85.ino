// LED Tree fading using ATTINY85
// Effect 1 : All ON 
// Effect 2 : All Fade (delay 30 ms for each step)
// Effect 3 : Two line Flikering gap 300 ms  
// Effect 4 : Alternate Fading
// Effect 5 : Random
// Select by button

int led0 = 0;  // the pin that the LED is attached to
int led1 = 1;  // the pin that the LED is attached to
int led4 = 4; // Pin 4 is PWM as well For apples
int button = 2; // Pin for input : digital 
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int Flag = 1; // Flag to control which effect is called

// For debounce button
boolean lastButton = LOW;
boolean currentButton = LOW;
//----------------------------------------------------------------
// the setup routine runs once when you press reset:
// 100% Done
//----------------------------------------------------------------
void setup()  { 
  // declare pin 0 and 1 to be an output:
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(button, INPUT);
  
  // Hardware Interrupt on Physical pin 7, logical pin 2)
  attachInterrupt(0, flag_interrupt, CHANGE); 
  } 

boolean debounce(boolean last)
{
  boolean current = digitalRead(button);
  if (last != current)
  {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}


//----------------------------------------------------------------
// 100% Done
//----------------------------------------------------------------
void fade_led(int LED){
   // change the brightness for next time through the loop:
  for (brightness = 0; brightness <255; brightness++) {
    analogWrite(LED, brightness);
    brightness = brightness + fadeAmount -1 ;
    delay(50);  
  }
  for (brightness = 255; brightness >=0; brightness--) {
    analogWrite(LED, brightness);
    brightness = brightness - fadeAmount + 1 ;
    delay(50);  
  }
}

//----------------------------------------------------------------
// Yellow led = On , Red = Fading
//----------------------------------------------------------------
void All_ON(){
  digitalWrite(led0 , HIGH);
  digitalWrite(led1, HIGH);
  fade_led(led4);
  }

//----------------------------------------------------------------
// Fade all LED : 100% Done
//----------------------------------------------------------------
void FADE_ALL() {
 analogWrite(led4, 225);
  for (brightness = 255; brightness >0; brightness--) {
    analogWrite(led0, brightness);
    analogWrite(led1, brightness);
    brightness = brightness - fadeAmount +1 ;
    delay(100);  
  }
 for (brightness = 0; brightness <=255; brightness++) {
    analogWrite(led0, brightness);
    analogWrite(led1, brightness);
    brightness = brightness + fadeAmount -1 ;
    delay(100);  
  } 
}

//----------------------------------------------------------------
// Alternative flickering for LEDS. Not Apples 100% Done
//----------------------------------------------------------------
void alternate_flickering(){
  digitalWrite(led4, HIGH);
  digitalWrite(led0 , HIGH);
  digitalWrite(led1, LOW);
  delay(200);
  digitalWrite(led0 , LOW);
  digitalWrite(led1, HIGH);
  delay(200);

}
//----------------------------------------------------------------
// Alternate fading for yellow Leds and not for Apples : 100% Done
//----------------------------------------------------------------
void alternate_fading(){
    analogWrite(led4, 225);
   // analogWrite(led0, 0);
    analogWrite(led1, 0);    
    fade_led(led0);
    fade_led(led1);
}
//----------------------------------------------------------------

void ALL_LOOP() {
 int i;// below is set for 30 secs
 for (i = 0; i < 6; i++) { All_ON(); } 
 for (i = 0; i < 3; i++)  {  FADE_ALL();   }
 for (i = 0; i < 75; i++)  {  alternate_flickering(); }
 for (i = 0; i < 3; i++)  {  alternate_fading(); }  
}


void flag_interrupt()
{
   // read button, pressed set Flag++
 currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    Flag = Flag + 1;
  }
  lastButton = currentButton;
}
//----------------------------------------------------------------
// the loop routine runs over and over again forever:
void loop()  { 

if (Flag ==1) {  
  All_ON();  
}
if (Flag==2) {   
  FADE_ALL(); 
}
if (Flag==3) {  
  alternate_flickering();  
}
if (Flag==4) {   
  alternate_fading();   
}
if (Flag==5) {
  ALL_LOOP();  
}
if (Flag > 4)  { 
  Flag = 1;
}
 
}
