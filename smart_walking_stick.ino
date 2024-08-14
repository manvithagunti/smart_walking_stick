//DEFINING PIN NUMBERS
const int MOTOR_PIN =10;
const int TRIG_PIN=6;
const int ECHO_PIN=9;
const int buzzer = 11;
const int flamePin=8;
//DEFINING VARIABLES
long time;
float distance;
float vibrating_distance;
const int startfreq=523;

void setup(){
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(MOTOR_PIN,OUTPUT);
  pinMode(buzzer, OUTPUT);
   pinMode(flamePin, INPUT);
 
}
void loop(){
  int fireValue=digitalRead(flamePin);
  // CLEARING THE TRIG PIN
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(1);
  digitalWrite(TRIG_PIN,LOW);
  
  //SENDS A TRIGGER SIGNAL
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);
  
  // MEASURES THE DURATION AT ECHO PIN USING PULSEIN FUNCTION
  Serial.println("firevalue");
    Serial.println(fireValue);
if(fireValue==0){
  for(int freq=startfreq ; freq<=(startfreq*2) ; ++freq)
  {
    tone(buzzer,freq,10);
    delay(3);
  }
}
  time=pulseIn(ECHO_PIN,HIGH);
  distance= time*0.034/2 ;
  vibrating_distance=distance;
  if(vibrating_distance<=30)
  {
    digitalWrite(MOTOR_PIN,HIGH);
    delay(300);
    digitalWrite(MOTOR_PIN,LOW);

    tone(buzzer,450);
    delay(174);
    noTone(buzzer);
    
    /*digitalWrite(MOTOR_PIN,HIGH);
    delay(1000);
    digitalWrite(MOTOR_PIN,LOW);
    */
  }
  else if(vibrating_distance>=45 && vibrating_distance<=100){
    digitalWrite(MOTOR_PIN,HIGH);
    delay(600);
    digitalWrite(MOTOR_PIN,LOW);


        tone(buzzer,450);
    delay(250);
    noTone(buzzer);
    
    /*digitalWrite(MOTOR_PIN,HIGH);
    delay(1000);
    digitalWrite(MOTOR_PIN,LOW);
*/
  }
  
  Serial.print("Distance: ");
Serial.println(distance);
}
  