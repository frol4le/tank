const int trigPin = 15;  //D4
const int echoPin = 0;  //D3


long duration;
int distance=0;
int distance1=0;

void setup() {
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    Serial.begin(115200);
}

void loop() {
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
    delay(100);
}
