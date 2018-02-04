
/*s
 * morse code LED connected to 12(+) and GND(-)
 * reset LED connected to 10(+) and 8(-)
 * speakers connected to 2 and 4
 */



 #define UNIT 200 //Length of a time unit
 #define SPEAKER 2 //The PIN 2 will activate the Speaker
 #define SPEAKERGROUND 4 //The PIN 4 will act as GND for the Speaker
 
void litAf(char morseCode){
  switch(morseCode){

  case '.': 
  digitalWrite(12, HIGH);
  //speaker activation (DO[high])
  tone(SPEAKER, 523, UNIT);
  //
  delay(UNIT);
  digitalWrite(12, LOW);
  delay(UNIT);
  break;
  
  case '-':
   digitalWrite(12, HIGH);
   //speaker activation (DO[high])
   tone(SPEAKER, 523, 3*UNIT);
   //3 units
  delay(3*UNIT);
  digitalWrite(12, LOW);
  delay(UNIT);
  break;
  

//space between letters
  case 'l':
   digitalWrite(12, LOW);
  delay(3*UNIT);
  
  break;

//space between words
  case 'w':
   digitalWrite(12, LOW);
  delay(4*UNIT);
  break;
  }
}


String text; //variable to receive data from the port


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //reset LED
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  //pin 10 acts as GND for reset LED
  digitalWrite(10,LOW);
  //morse code LED
  pinMode(12, OUTPUT);
  //speaker
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  //pin 4 acts as GND for speaker
  digitalWrite(4, LOW);
  //Turn the Serial Protocol ON
  Serial.begin(9600);
  
  
}

// the loop function runs over and over again forever
void loop() {
//Takes the input from the serial monitor and puts it in the string variable "text"  
String text = Serial.readString() ;


String output = "";
for(unsigned int i=0; i < text.length(); i++){
  char c = text.charAt(i);
  //Respective morse code for every letter
  switch (c){
          case 'a': output.concat(".-l");
          break;
          case 'b': output.concat("-...l");
          break;
          case 'c': output.concat("-.-.l");
          break;
          case 'd': output.concat("-..l");
          break;
          case 'e': output.concat(".l");
          break;
          case 'f': output.concat("..-.l");
          break;
          case 'g': output.concat("--.l");
          break;
          case 'h': output.concat("....l");
          break;
          case 'i': output.concat("..l");
          break;
          case 'j': output.concat(".---l");
          break;
          case 'k': output.concat("-.-l");
          break;
          case 'l': output.concat(".-..l");
          break;
          case 'm': output.concat("--l");
          break;
          case 'n': output.concat("-.l");
          break;
          case 'o': output.concat("---l");
          break;
          case 'p': output.concat(".--.l");
          break;
          case 'q': output.concat("--.-l");
          break;
          case 'r': output.concat(".-.l");
          break;
          case 's': output.concat("...l");
          break;
          case 't': output.concat("-l");
          break;
          case 'u': output.concat("..--l");
          break;
          case 'v': output.concat("...-l");
          break;
          case 'w': output.concat(".--l");
          break;
          case 'x': output.concat("-..-l");
          break;
          case 'y': output.concat("-.--l");
          break;
          case 'z': output.concat("--..l");
          break;
          case '0': output.concat("-----l");
          break;
          case '1': output.concat(".----l");
          break;
          case '2': output.concat("..---l");
          break;
          case '3': output.concat("...--l");
          break;
          case '4': output.concat("....-l");
          break;
          case '5': output.concat(".....l");
          break;
          case '6': output.concat("-....l");
          break;
          case '7': output.concat("--...l");
          break;
          case '8': output.concat("---..l");
          break;
          case '9': output.concat("----.l");
          break;
          case ' ': output.concat("w");
          break;
          }
  }
  

    for (unsigned int i = 0; i < output.length(); i++){
    //activates message LED to indicate the reading of a message
    digitalWrite(8, HIGH);
    //translates the code into light/sound outpouts
     litAf(output.charAt(i)) ;
    }
 
  //deactivate message LED to indicate the end of the message
  digitalWrite(8,LOW);

}
