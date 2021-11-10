const int echoB = 2;
const int trigB = 3; 
const int echoS = 4;
const int trigS = 5;
const int ledB = 10;
const int ledS = 11;
int brightB = 0;
int brightS = 0;
int waitB = 0;
int waitS = 0;

float durationB, durationS, distanceB, distanceS; 

void setup() { 
 pinMode(echoB, INPUT); 
 pinMode(trigB, OUTPUT); 
 pinMode(echoS, INPUT);
 pinMode(trigS, OUTPUT); 
 pinMode(ledB, OUTPUT);
 pinMode(ledS, OUTPUT);
 Serial.begin(9600); 
} 


int findDistance(int duration, int distance, int trig, int echo, int led, int brightness, int wait){
 digitalWrite(trig, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trig, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trig, LOW); 
 duration = pulseIn(echo, HIGH); 
 distance = (duration*.0343)/2;

 if (distance <= 5) {
  brightness = 255;
  wait = 0;
 } else if (distance <= 15) {
  wait = sqrt(distance*500);
  brightness = 255 - 10*distance;
 } else if (distance <= 25) {
  wait = sqrt(distance*2000);
  brightness = 255 - 10*distance;
 } else {
  brightness = 0;
  wait = 0;
 }

 analogWrite(led, brightness);
 delay(wait);
 if (distance > 5) analogWrite(led, 0);
 delay(wait);
 analogWrite(led, brightness);

}


void loop(){
 findDistance(durationB, distanceB, trigB, echoB, ledB, brightB, waitB);
 findDistance(durationS, distanceS, trigS, echoS, ledS, brightS, waitS);
}
