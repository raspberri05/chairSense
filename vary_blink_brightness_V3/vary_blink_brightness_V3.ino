const int trigPin = 9; 
const int echoPin = 10;
const int ledPin = 11;
const int buzzer = 3;

int brightness = 0;
int wait = 0;

float duration, distance; 

void setup() { 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 pinMode(ledPin, OUTPUT);
 pinMode(buzzer, OUTPUT);
 Serial.begin(9600); 
} 

void loop(){
 noTone(buzzer);
 analogWrite(ledPin, brightness); 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
 distance = (duration*.0343)/2; 
 if (distance <= 28) {
    brightness = 255 - 10*distance;
    if (distance > 15) {
      wait = sqrt(distance*2000);
    } else {
      wait = sqrt(distance*500);
    }
 } else {
  brightness = 0;
  wait = 0;
 }

 analogWrite(ledPin, brightness);
 while (distance <= 9) {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration*.0343)/2; 
  
  tone(buzzer, 1000);
  
 }
 delay(wait);
 analogWrite(ledPin, 0);
 delay(wait);
 analogWrite(ledPin, brightness);


}
