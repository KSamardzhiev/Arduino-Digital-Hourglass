const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;

long interval = 6000;

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
    if(led == 8) {
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
    for(int x = 2; x < 8; x++){
      digitalWrite(x,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
