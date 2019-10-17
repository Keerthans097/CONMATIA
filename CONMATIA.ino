#define in 11
#define out 10
int n=0;
int i;

String voice;
int
led1 = 2, //Connect LED 1 To Pin #2
led2 = 3, //Connect LED 2 To Pin #3
led3 = 4, //Connect LED 3 To Pin #4
led4 = 5; //Connect LED 4 To Pin #5

//--------------------------Call A Function------------------// 
void allon(){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
}
void alloff(){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
}
void IN()
{
  n++;
  delay(1000);
  Serial.print(n);
}
void OUT()
{
  n--;
  delay(1000);
  Serial.print(n);
  // Serial.print("hi");
  
}


//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(in,INPUT);
  pinMode(out,INPUT);
  Serial.print(n);
}
//-----------------------------------------------------------------------// 
void loop()
{
  if(digitalRead(in))
IN();
if(digitalRead(out))
OUT();

if(n>0)
{
  while (Serial.available())
  { 
    //Check if there is an available byte to read
  delay(10);               //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c;           //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   

  //----------Control Multiple Pins/ LEDs----------// 
       if((voice == "*full on")|(voice == "*all on")) {allon();}  //Turn Off All Pins 
  else if((voice == "*full off")|(voice == "*full of")|(voice == "*all of")){alloff();} //Turn On  All Pins
 
  //----------Turn On One-By-One----------//
  else if(voice == "*TV on") {digitalWrite(led1, HIGH);}
  else if(voice == "*fan on") {digitalWrite(led2, HIGH);}
  else if(voice == "*buzzer on") {digitalWrite(led4, HIGH);}
  else if(voice == "*lights on") {digitalWrite(led3, HIGH);}
 
  //----------Turn Off One-By-One----------//
  else if(voice == "*TV off") {digitalWrite(led1, LOW);}
  else if(voice == "*fan off") {digitalWrite(led2, LOW);}
  else if((voice == "*buzzer off")|(voice == "*bazzar of")) {digitalWrite(led4, LOW);}
  else if(voice == "*lights off") {digitalWrite(led3, LOW);}
  

voice="";
}
}

else
alloff();
}



