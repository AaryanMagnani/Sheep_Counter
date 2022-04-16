int trigPin1 = 4;
int echoPin1 = 6; 
int trigPin2 = 5;
int echoPin2 = 7;
int count = 0;

void setup()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float time1, time2, dist1, dist2, gateWidth = 100;
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  //to get rid of any junk waves in the trig pins
  
  //for sheeps entering
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);  
  time1 = pulseIn(echoPin1, HIGH);  
  dist1 = 0.034*(time1/2);
  
  //for sheeps leaving
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);  
  time2 = pulseIn(echoPin2, HIGH);  
  dist2 = 0.034*(time2/2);
  
  if(dist1<gateWidth){
    count+=1;
    delay(1000); 
    //assuming this as the avg time a sheep takes to pass the gate
  }
  
  if(dist2<gateWidth){
    if(count>0){
      count-=1;
      delay(1000);
    }  	
  }
  
  Serial.print("\nNumber of sheeps inside = ");
  Serial.println(count);
  delay(500);
}