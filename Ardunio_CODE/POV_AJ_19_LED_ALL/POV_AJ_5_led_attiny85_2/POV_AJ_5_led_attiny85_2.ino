//-------------------------------------------------------------------------------------- 
// Simple POV with 5 leds
// Code will display my Son's name "Gautam"
// Author Amit Jain 
// Version 1.0 
// Original date : 3rd Nov 2014

// Define characters to be displayed 
// Character data stored in integer type array - 1 dimensional array
// using 4 columns to display characters, W and M characters needs 5 columns
// Small characters missing below : g, p, q, s, v, 

//Reveision 1. Changing to 5 columbs and no small letters, Not good for 5x5 display
// Added Heart, Smile, Alien etc
//-------------------------------------------------------------------------------------- 
// Capital Letters  // Changed
	int C_A[] = {0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1};
	int C_B[] = {1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0};
	int C_C[] = {0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1};
	int C_D[] = {1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0};
	int C_E[] = {1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1};
	int C_F[] = {1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0};
	int C_G[] = {0,1,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,0,1,1,1,0};
	int C_H[] = {1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1};
	int C_I[] = {1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1};
	int C_J[] = {1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,1,0};
	int C_K[] = {1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1};
	int C_L[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1};
	int C_M[] = {1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1};
	int C_N[] = {1,0,0,0,1,1,1,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1};
	int C_O[] = {0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0};
	int C_P[] = {1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0};
	int C_Q[] = {0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,0,0,1,1,0,1};
	int C_R[] = {1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1};
	int C_S[] = {0,1,1,1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,1,0};
	int C_T[] = {1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0};
	int C_U[] = {1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0};
	int C_V[] = {1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0};
	int C_W[] = {1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1};
	int C_X[] = {1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1};
	int C_Y[] = {1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0};
	int C_Z[] = {1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};



//-------------------------------------------------------------------------------------- 

// Special characters
	int ZSPACE[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}; // changed
	int Smile[] = {0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,}; // changed
        int PacPac[] = {0,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1};
        int Alien[] = {0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0};
        int Heart[] = {0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0};
        int GSign[] = {1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0};
        int Partern1[] = {1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1};
        int Partern2[] = {1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1};
        int Partern3[] = {0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0};
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
		  letterSpace = 5;
		  // defining the time dots appear (ms)
		  dotTime = 3;
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


//--------------------------------------------------------------------------------------
// This makes it go in loop
void loop(){
    // Printing Amit  
/*  printLetter(C_G);
  printLetter(C_A);
  printLetter(C_U);
  printLetter(C_T);
  printLetter(C_A);
  printLetter(C_M);
  printLetter(ZSPACE);
 
  */
  
  int i = 0;
  
  for (i = 0; i < 50; i++) { printLetter(Smile); }
  for (i = 0; i < 50; i++) {printLetter(Heart);}
  for (i = 0; i < 50; i++) {printLetter(Partern1);}
  for (i = 0; i < 50; i++) {printLetter(PacPac); }
  for (i = 0; i < 50; i++) {printLetter(Partern2);}
  for (i = 0; i < 50; i++) {printLetter(Partern3);}
  //printLetter(C_M);


}


