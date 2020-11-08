const int trigPin = 15;  //D10
const int echoPin = 0;  //D8
uint32_t myTimer1;
long duration;
int distance=0;
int distance1=0;

void setup() {
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    Serial.begin(115200);
}

void loop() {
  if (millis() - myTimer1 >= 50) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    if(distance-distance1<300 && distance!=distance1 && distance!=0){
      Serial.print("Distance: ");
      Serial.println(distance);
      distance1=distance;   
    }   
   }
}
