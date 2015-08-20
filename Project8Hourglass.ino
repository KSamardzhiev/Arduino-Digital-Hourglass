/**
 * The pin on which the tilt sensor is attached
 */
const int switchPin = 8;
/**
 * Variable that help calculating the passed time
 */
unsigned long previousTime = 0;
/**
 * Variable that stores the current state of the tilt switch
 */
int switchState = 0;
/**
 * Variable that stores the previous state of the tilt switch
 */
int prevSwitchState = 0;
/**
 * Variable that stores the first pin with attached LED
 */
int led = 2;
/**
 * Time needed by hourglass to be restarted
 */
long interval = 600000;

void setup() {
  // put your setup code here, to run once:
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }

  pinMode(8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  if(currentTime-previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led,HIGH);
    led++;
    if(led == 8) { //When all the six LED are turned on this code will be executed.
      //This will make signal which points that hourglass have to be restarted.
      
      while(switchState==prevSwitchState){
        
        for(int i = 2; i < 8; i++){
          digitalWrite(i,LOW);
          delay(200);
          digitalWrite(i,HIGH);  
        }
    
        for(int i = 7; i > 1; i--){
          digitalWrite(i,LOW); 
          delay(200);
          digitalWrite(i,HIGH);  
        }
        
      switchState = digitalRead(switchPin);
      }
    }
  }
 
  switchState = digitalRead(switchPin);
  
  if(switchState != prevSwitchState){
    //This code restart the hourglass
    for(int x = 2; x < 8; x++){
      digitalWrite(x,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
