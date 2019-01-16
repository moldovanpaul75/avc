
const int trigger = 4; //Trigger pin
const int echo = 2; //Echo pin

long time_taken;
int dist, dist1;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

//Function to calculate distance
void calculate_distance(int triggerPin, int echoPin){

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);


  time_taken = pulseIn(echoPin, HIGH);
  dist = time_taken * 0.034/2;
  if(dist>50) dist=50;
}

void loop() {
  // put your main code here, to run repeatedly:
  calculate_distance(trigger, echo);
  dist1 = dist;
  
    //for debug
    //Serial.print("Distance: ");
    //Serial.println(dist1);
    
    if(dist1>=10 && dist <= 40){
      delay(100);
      
      while(dist1 <= 40){
      
        calculate_distance(trigger, echo);
        dist1 = dist;
        
        //volume up range condition
        if(dist1 > 10 && dist1 < 20){
          calculate_distance(trigger, echo);
          dist1 = dist;
          Serial.println("VUp");
          delay(350);
        }
        
        //volume down range condition
        if(dist1 > 20 && dist1 < 30){
          calculate_distance(trigger, echo);
          dist1 = dist;
          Serial.println("VDown");
          delay(350);
        }
      }
    }
}
