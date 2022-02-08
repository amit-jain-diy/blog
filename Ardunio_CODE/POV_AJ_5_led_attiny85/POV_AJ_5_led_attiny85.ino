//-------------------------------------------------------------------------------------- 
// Simple POV with 5 leds
// Code will display my Son's name "Gautam"
// Author Amit Jain 
// Version 1.0 
// Date : 3rd Jun 2015

// Define characters to be displayed 
// 5 columbs and no small letters, Not good for 5x5 display
// Added Heart, Smile, Alien etc


//-------------------------------------------------------------------------------------- 
// Capital Letters  // Changed
        int C_G[] = {0,1,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,0,1,1,1,0};
        int C_A[] = {0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1};
	int C_U[] = {1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0};
	int C_T[] = {1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0};
	int C_M[] = {1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1};

	//int C_B[] = {1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0};
	//int C_C[] = {0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1};
	//int C_D[] = {1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0};
	//int C_E[] = {1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1};
	//int C_F[] = {1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0};
//	int C_H[] = {1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1};
//	int C_I[] = {1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1};
	//int C_J[] = {1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,1,0};
	//int C_K[] = {1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1};
	//int C_L[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1};
	//int C_N[] = {1,0,0,0,1,1,1,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1};
	//int C_O[] = {0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0};
	//int C_P[] = {1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0};
	//int C_Q[] = {0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,0,0,1,1,0,1};
//	int C_R[] = {1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1};
//	int C_S[] = {0,1,1,1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,1,0};
	//int C_V[] = {1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0};
	//int C_W[] = {1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1};
	//int C_X[] = {1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1};
	//int C_Y[] = {1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0};
	//int C_Z[] = {1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};



//-------------------------------------------------------------------------------------- 
/* not needed for test my goal
// Numbers
	int ONE[] = {1,0,0,0,1, 1,1,1,1,1, 0,0,0,0,1};
	int TWO[] = {0,1,0,1,1, 1,0,1,0,1, 0,1,0,0,1};
	int THREE[] = {1,0,1,0,1, 1,0,1,0,1, 1,1,1,1,1};
	int FOUR[] = {1,1,1,0,0, 0,0,1,0,0, 1,1,1,1,1};
	int FIVE[] = {1,0,1,0,1, 1,0,1,0,1, 1,0,1,1,1};
	int SIX[] = {1,0,1,1,1, 1,0,1,0,1, 1,0,1,1,1};
	int SEVEN[] = {1,0,0,0,0, 1,0,0,0,0, 1,1,1,1,1};
	int EIGHT[] = {1,1,1,1,1, 1,0,1,0,1, 1,1,1,1,1};
	int NINE[] = {1,1,1,0,0, 1,0,1,0,0, 1,1,1,1,1};
	int ZERO[] = {1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1};
*/

//-------------------------------------------------------------------------------------- 

// Special characters
	int ZSPACE[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}; // changed
	int Smile[] = {0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,}; // changed
        int PacPac[] = {0,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1};
        int Alien[] = {0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0};
        int Heart[] = {0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0};
        int GSign[] = {1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0};
        int Partern1[] = {1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1};
        //int Partern2[] = {1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1};
        int Partern3[] = {0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,1};
//	int C_Star[] = {0,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,,1,1,0,0,1,0,0,1};
//-------------------------------------------------------------------------------------- 

// Define variables
	int letterSpace;
	int dotTime;
//-------------------------------------------------------------------------------------- 
	void setup() //Changed
	{
		  // setting the ports of the leds to OUTPUT
		  pinMode(0, OUTPUT);
		  pinMode(1, OUTPUT);
		  pinMode(2, OUTPUT);
		  pinMode(3, OUTPUT);
		  pinMode(4, OUTPUT);
		 
		  // defining the space between the letters (ms)
		  letterSpace = 2;
		  // defining the time dots appear (ms)
		  dotTime = 1;
		  // testing all 5 leds are working, they will glow from top to buttom 
		  int counter;
		  for (counter=0; counter < 6; counter++)
		  {
				digitalWrite(counter, HIGH);
				// delay for 300 ms
				delay (300);
				digitalWrite(counter, LOW);
		  }
	}
//-------------------------------------------------------------------------------------- 
// Print letters with 5 columns // Changed 
	void printLetter(int letter[])
	{
		  int y;
		  int x;
		  // Printing x columns and y rows 
		  for (x=0; x<5; x++)
		  {
				for (y=0; y<5; y++)
				{
					digitalWrite(y, letter[x+(y*5)]);
				}
			delay(dotTime);
		  }
		 // printing the space between the letters
		  for (y=0; y<5; y++)
		  {
				digitalWrite(y, 0);
		  }
		  delay(letterSpace);
	}
//-------------------------------------------------------------------------------------- 

/*void AMIT(){
    // Printing Amit  
  printLetter(C_A);
  printLetter(C_M);
  printLetter(C_I);
  printLetter(C_T);
  printLetter(ZSPACE);
}

void SURBHI(){
    // Printing Amit  
  printLetter(C_S);
  printLetter(C_U);
  printLetter(C_R);
  printLetter(C_B);
  printLetter(C_H);
  printLetter(C_I);
  printLetter(ZSPACE);
}
*/
void GAUTAM(){
    // Printing Amit  
  printLetter(C_G);
  printLetter(C_A);
  printLetter(C_U);
  printLetter(C_T);
  printLetter(C_A);
  printLetter(C_M);
  printLetter(ZSPACE);
}

//--------------------------------------------------------------------------------------
// This makes it go in loop
void loop(){

  
  int i = 0;
  //for (i = 0; i < 30; i++) { AMIT();}
  //for (i = 0; i < 30; i++) { SURBHI();}
  for (i = 0; i < 30; i++) { GAUTAM();}
  for (i = 0; i < 60; i++) { printLetter(PacPac);}
  for (i = 0; i < 60; i++) { printLetter(Heart);}
  for (i = 0; i < 60; i++) { printLetter(Partern1);}
  for (i = 0; i < 60; i++) { printLetter(Alien);}
  for (i = 0; i < 60; i++) { printLetter(Partern3);}
//  for (i = 0; i < 60; i++) { printLetter(Smile);}
}


