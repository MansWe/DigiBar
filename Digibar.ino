
//Notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempo = 140;

// change this to whichever pin you want to use
int buzzer = 2; //Speaker pin


#include <DFRobot_HX711.h> //Load cell amplifier
#include <LiquidCrystal.h> //LCD display library
#include <Wire.h>          


LiquidCrystal lcd(A7,A6,A5,A4,A3,A2); //Creating object for lcd screen.

/*!
 * @fn DFRobot_HX711
 * @brief Constructor 
 * @param pin_din  Analog data pins
 * @param pin_slk  Analog data pins
 */


DFRobot_HX711 MyScale(A0, A1);	      //Creating object for amplifier

//Creates variables for the glasses weight
float smallGlass = 80;	              
float sailGlass = 133;		      
float swirlGlass = 186;
float bigGlass = 499;


//Array containing the four different glasses
float glasses[4] = {smallGlass,sailGlass,swirlGlass,bigGlass};


//PUMPSTYRNING
int In1 = 5;  //Relay 1
int In2 = 7;  //Relay 1 Pump 3/ Orange Juice
int In3 = 23; //Relay 2
int In4 = 22; //Relay 2 Pump 4/Cola
int In5 = 8;  //Relay 3
int In6 = 9;  //Relay 3 Pump 1/Vodka
int In7 = 3;  //Relay 4
int In8 = 4;  //Relay 4 Pump 2/White rum




//A circular buffer = A "circular" array, that will start over from the beginning if the code has reached the last element and takes another step. 
#define LEN 3 		//Längd
int circBuffer[LEN];	//Definerar arrayen
int idx=-1;		//Startindex
float weight;		//Defines weightvariable
bool drinkMade = false;	//Has the machine already made a drink?

							//Function, to decide what glass is placed on the sensor by mapping weight put on sensor with the glasses coded into the program. 
float nearestGlass(float currRead){	
  int idx = 0; 						//Startindex
  float closestGlass = glasses[0];			//Default value for closest glass is set to the first glass in the array 
  float distance = abs(glasses[idx]-currRead);		//Weight difference "distance" is the weight difference between the glass we are on subtracted by the weight on the sensor. 

  for (int i = 1; i<4; i++){				//Looping through the glasses
   float d = abs(glasses[i]-currRead);			//Measured weight difference (distance)
    if(d<distance){					//IS the weight difference (Distance) smaller than the distance variable?
      distance = d; 					//Smallest weight difference is to the glass we are on right now
      closestGlass = glasses[i];			//Closest glass is set to the glass we are on
    }
  }

  return closestGlass; 					//Returns the glass that corresponds to the closest in weight to what is placed on the sensor
}



//supermario song from https://github.com/robsoncouto/arduino-songs
void playSuperMario(){	

//TONER
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

//Melodyarray 
int melody[] = {
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  
  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2, 

};


int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

//Loop through melody and play song
 for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
  }


}


//Tetris song from https://github.com/robsoncouto/arduino-songs
void playTetris(){
//Tones
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Melodyarray
int melody[] = {
  NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, 
  NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5,
  NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, 
  NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, 
  NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, 
  NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0, 
  NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, 
  NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5,
  NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, 
  NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, 
  NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, 
  NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0,
};



int noteDurations[] = {
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};

//Loop through melody and play song
 for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++){

    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzzer, melody[thisNote],noteDuration);
    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
   
    noTone(buzzer); //stop the tone playing:
  }
}


//Rick Astley's Never gonna give you up from https://github.com/robsoncouto/arduino-songs
void playNeverGonna(){
//Notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int tempo = 114;

//Melodyarray
int melody[] = {
  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
  NOTE_E5,4, NOTE_D5,2, REST,4,
};


int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;


//Loop through the melody and play the song
for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    }n else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
}

//Star wars Cantina band from https://github.com/robsoncouto/arduino-songs
void playCantinaBand(){
  int melody[] = {
    NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
    NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8, 
    NOTE_B4,8,  NOTE_AS4,8, NOTE_B4,8, NOTE_A4,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_G4,8,
    NOTE_G4,4,  NOTE_E4,-2, 
    NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
    NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,

    NOTE_A4,-4, NOTE_A4,-4, NOTE_GS4,8, NOTE_A4,-4,
    NOTE_D5,8,  NOTE_C5,-4, NOTE_B4,-4, NOTE_A4,-4,
    NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
    NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,
    NOTE_D5,4, NOTE_D5,-4, NOTE_B4,8, NOTE_A4,-4,
    NOTE_G4,-4, NOTE_E4,-2,
    NOTE_E4, 2, NOTE_G4,2,
    NOTE_B4, 2, NOTE_D5,2,

    NOTE_F5, -4, NOTE_E5,-4, NOTE_AS4,8, NOTE_AS4,8, NOTE_B4,4, NOTE_G4,4, 
};


int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 2) / tempo;
int divider = 0, noteDuration = 0;

//Loopa igenom melodin och spela
 for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    tone(buzzer, melody[thisNote], noteDuration*0.9);
    delay(noteDuration);
    noTone(buzzer);

};
}


//Setup
void setup() {
  Serial.begin(9600);				//Start serial monitor
  lcd.begin(16,2);				//Start LCD display

  //Setting all relaypins to output. 
  pinMode(In1,OUTPUT);				
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);  
  pinMode(In5,OUTPUT);
  pinMode(In6,OUTPUT);
  pinMode(In7,OUTPUT);
  pinMode(In8,OUTPUT);


  //Setting all relaypins to low, to prevent malfunction
  digitalWrite(In1,LOW);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,LOW);
  digitalWrite(In5,LOW);
  digitalWrite(In6,LOW);
  digitalWrite(In7,LOW);
  digitalWrite(In8,LOW);
}



//Loop
void loop() {

  if(drinkMade == 1){	//Has the machine just made a drink? 

    //Prints "please take your drink" on the display.
    lcd.clear();	
    lcd.setCursor(0,0);	
    lcd.print("Please");	
    lcd.setCursor(0,1);
    lcd.print("Take your drink!");
  
  }
  else{    //Not made a drink
    lcd.setCursor(0,0);
    weight = 5*MyScale.readWeight();	//Reads weight (The 5 is the coefficient)
    Serial.println(weight);		//Prints to serial
    Serial.println("--------");

    //Prints to the user.
    lcd.print("    Digibar");		
    lcd.setCursor(1,0);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Place your glass");	
  }

  if(5*MyScale.readWeight()>40) { //If the weight is more than 40 grams.
      if(drinkMade == 0){	  //Not just made a drink
      Serial.println(weight);	

      //Prints to the screen "Processing"	
      lcd.setCursor(0,1);
      lcd.print("Processing");
      float closestWeight = nearestGlass(weight); //Get the closest glass via the nearestGlass function.

      if(closestWeight == smallGlass){ //If the closest glass is the smallest, 80 gram glass.
        circBuffer[idx++] = 80;		//Add the value to the circular buffer at index idx++
      }

      else if (closestWeight == sailGlass){ 	//if the closest glass is the sailor glass, 133gram. 
        circBuffer[idx++] = 133;	    	//Add the value to the circular buffer at index idx++
      }

    
      else if (closestWeight == swirlGlass){    //if the closest glass is the swirl glass, 186gram
        circBuffer[idx++] = 186;		//Add the value to the circular buffer at index idx++
      }

      else if (closestWeight == bigGlass){ //if the closest glass is the biggest glass, 499gram
        circBuffer[idx++] = 499;	  //Add the value to the circular buffer at index idx++	
      }

}

    }

    else{				//Value on sensor less than 40 grams?
      drinkMade = false; 		//Set drinkmade to false.

      //Loop through circular buffer and set every value to 0.
      for (int i=0; i<3; i++){
        circBuffer[i]=0;
      }


      //print to serial monitor
      for(int i=0; i<3; i++){
      Serial.println(circBuffer[i]);}
      }
  

    if(circBuffer[0]==80 && circBuffer[1]==80 && circBuffer[2]==80){	//If every measurement of the glass is 80 grams (or closest to)

      //Print what kind of drink is being mixed for the user. 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Machine Cocktail");
      lcd.setCursor(0,1);
      lcd.print("Mixing!          ");
     
      //Machine cocktail
      digitalWrite(In6,HIGH); //Activate pump 1 (Vodka)
      delay(1030);	      //Wait 1030ms
      digitalWrite(In6,LOW);  //De-activate pump 1 (Vodka)	
      delay(2000);	      //wait 2000ms for liquid to simmer down
      digitalWrite(In2,HIGH); //Activate Pump 3 (Orange juice)
      delay(1470);	      //Wait 1470ms	
      digitalWrite(In2,LOW);  //Deactivate pump 3(Orange Juice) 
	

      //Print to the user
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("Finished!");
      lcd.setCursor(0,1);
      lcd.print("Take your drink!");
      delay(3000);
      lcd.clear();
      playCantinaBand(); //Play music (Cantina Band)

      drinkMade = true; //Set drinkmade to true (just made a drink)
     
      for (int i=0; i<3; i++){	//Set all the values of the circular buffer to 0.
      circBuffer[i]=0;
    }
    }

    if(circBuffer[0]==133 && circBuffer[1]==133 && circBuffer[2]==133){ //If every measurement of the glass is 133 grams (or closest to)

      //Print what kind of drink is being mixed for the user. 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Thames Water");
      lcd.setCursor(0,1);
      lcd.print("Mixing!          ");

      //Themes water
      digitalWrite(In2, HIGH); //Activate pump 3 (Orange Juice)
      delay(3718);	       //Wait 3718ms
      digitalWrite(In2, LOW);  //Deactivate pump 3 (Orange Juice)	
      delay(2000);	       //wait 2000ms for liquid to simmer down		
      digitalWrite(In4,HIGH);  // Activate pump 4 (Cola)
      delay(1252);	       //Wait 1252ms
      digitalWrite(In4,LOW);   //Deactivate pump 4 (Cola)

	
      //Print to the user
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("Finished!");
      lcd.setCursor(0,1);
      lcd.print("Take your drink!");
      delay(3000);
      lcd.clear();

      drinkMade = true; //Set drinkmade to true
      playSuperMario();	//Play super mario song

      for (int i=0; i<3; i++){ //Set all values of the circularbuffer to 0
      	circBuffer[i]=0;
      }
    }

    if(circBuffer[0]==186 && circBuffer[1]==186 && circBuffer[2]==186){ //If every measurement of the glass is 186 grams (or closest to)

      //Print to the user
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Rum and Coke");
      lcd.setCursor(0,1);
      lcd.print("Mixing!          ");

      //rum n coke
      digitalWrite(In8, HIGH); //Activate Pump 2 (white rum)
      delay(1900);	       //Wait 1900ms
      digitalWrite(In8, LOW);  //Deactivate Pump 2 (white rum)
      delay(2000);	       //wait 2000ms for liquid to simmer down		
      digitalWrite(In4,HIGH);  //Activate pump 4 (Cola)
      delay(4193);	       //Wait 4193ms	
      digitalWrite(In4,LOW);   //Deactivate pump 4 (Cola)

      //Print to the user
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("Finished!");
      lcd.setCursor(0,1);
      lcd.print("Take your drink!");
      delay(3000);
      lcd.clear();

      drinkMade = true;	//Set drinkmade to true
      playTetris();	//Play tetris song

      for (int i=0; i<3; i++){ //Set all values of the circularbuffer to 0
      circBuffer[i]=0;
    }
    }

    if(circBuffer[0]==499 && circBuffer[1]==499 && circBuffer[2]==499){ //If every measurement of the glass is 186 grams (or closest to)

      //Print to the user
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Brass Monkey");
      lcd.setCursor(0,1);
      lcd.print("Mixing!          ");

      //brass monkey
      digitalWrite(In6, HIGH); //Activate pump 1 (Vodka)
      delay(1252);	       //wait 1252ms
      digitalWrite(In6, LOW);  //Deactivate pump 1 (Vodka)
      delay(2000);	       //wait 2000ms for liquid to simmer down
      digitalWrite(In8,HIGH);  //Activate Pump 2 (white rum)
      delay(1252);	       //Wait 1252ms	
      digitalWrite(In8,LOW);   //Deactivate Pump 2 (white rum)
      delay(2000);	       //Wait 2000ms for liquid to simmer down
      digitalWrite(In2,HIGH);  //Activate pump 3 (Orange Juice)
      delay(4287);	       //Wait 4287ms
      digitalWrite(In2,LOW);   //Deactivate pump 3 (Orange Juice)	
      
      //Print to the user
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("Finished!");
      lcd.setCursor(0,1);
      lcd.print("Take your drink!");
      delay(3000);
      lcd.clear();

      drinkMade = true;   //Drinkmade is set to true
      playNeverGonna();  //Play Never Gonna give you up song for the user. 

      for (int i=0; i<3; i++){   //Set all of the values of the buffer to 0 
      circBuffer[i]=0;
    }
    }
    

if (idx >= LEN) idx = 0; //If circular buffer has reached its end, continue from the front again.

 delay(1000); //Delay 1000ms between glass measurements.
  
}
