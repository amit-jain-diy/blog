/*// Arduino Nano pins
const int buttonPin = 2;    // the number of the pushbutton pin
const int LED_1 = 13;     //LED row 1
const int LED_2 = 12;     //LED row 2    
const int LED_3 = 11;     //LED row 3
const int Relay_out = 4; // relay on pinn 4
*/
// ATTINY85 pins
const int buttonPin = 4;    // the number of the pushbutton pin
const int LED_1 = 0;     //LED row 1
const int LED_2 = 1;     //LED row 2    
const int LED_3 = 2;     //LED row 3
const int Relay_out = 3; // relay on pinn 4


const int one_hour = 3600; // one hr counter
// Variables will change:
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int Flag =0; // set to 0 hours
int select_hrs_flag=0;
int hr_count=0;

void LED_ALL_OFF(){
  pinMode(LED_1, INPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);    //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);    //row 3
  digitalWrite(LED_3, LOW);
         
}
void LED1_ON()  {   //turn on LED L1
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, INPUT);      //row 3
  digitalWrite(LED_3, LOW);
}
  
void LED2_ON()  {  //turn on LED L2
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);   
  pinMode(LED_3, INPUT);      //row 3
  digitalWrite(LED_3, LOW);
}
void LED3_ON()  {  //turn on LED L3
  pinMode(LED_1, INPUT);      //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, OUTPUT);     //row 3
  digitalWrite(LED_3, HIGH);
} 

void LED4_ON()  {  //turn on LED L4
  pinMode(LED_1, INPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);    //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, OUTPUT);    //row 3
  digitalWrite(LED_3, LOW);
}

void case_Led_ON() {
    switch (Flag) {
      case 1:    
        LED1_ON();
        break;
      case 2:   
        LED2_ON();
        break;
      case 3:    
        LED3_ON();
        break;
      case 4:    
        LED4_ON();
        break;
      default:
        LED_ALL_OFF();
        break;
    }
}

void select_hrs(){
    // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        Flag=Flag+1;
      }
      if (Flag>4){
        Flag=0;
      }
    }
  }
 // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
  // switch on LED based on flag
  case_Led_ON();
 // Come out of loop if the key is not pressed for 5 secs
 if(Flag > 0){
   if ((millis() - lastDebounceTime) > 5000){
 // Serial.println("Deafult timeout ");
  select_hrs_flag = 1;
   }
  }

  //Serial.println("Inside Select Hr Loop");
}

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(Relay_out, OUTPUT);
  // initialize serial communication:
//  Serial.begin(9600);
  
}

void loop() {
while (select_hrs_flag == 0) {
    select_hrs();
  }
//Serial.println("Outside Select Hr loop");
//Serial.println(select_hrs_flag);
if (Flag > 0) {
    digitalWrite(Relay_out, HIGH);  
  }
while (hr_count < one_hour) {
  case_Led_ON();
  delay(500);
  LED_ALL_OFF();
  delay(500);
  hr_count=hr_count + 1;
  }
  if (Flag > 0) {
  Flag = Flag - 1 ;
 // Serial.println("reducing 1 Hr");
  hr_count=0;
}
if (Flag ==0){
  digitalWrite(Relay_out, LOW); 
  select_hrs_flag = 0;
}
}
