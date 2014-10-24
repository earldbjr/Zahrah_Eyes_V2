int redLed1 = 3;
int greenLed1 = 5;
int blueLed1 = 6;
int redLed2 = 9;
int greenLed2 = 10;
int blueLed2 = 11;
int isInterrupted = 0;
boolean mode = 0;

int bounceThreshold = 500;

void setup(){
  attachInterrupt(0, interruptHandler, RISING);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  pinMode(greenLed2, OUTPUT);
  pinMode(blueLed1, OUTPUT);
  pinMode(blueLed2, OUTPUT);
}

void loop(){
  isInterrupted = 0;
  mode = !mode;
  switch(mode){
  case 0:
    rotateEyesFast();
    break;
  case 1:
    orangeBlue();
    break;
  }

}

void interruptHandler(){
  static unsigned long lastpress;
  static unsigned long thispress;
  thispress = millis();
  if(thispress - lastpress > bounceThreshold){
    lastpress = thispress;
    isInterrupted = 1;
  }
}

void off(){
  digitalWrite(redLed1, LOW);
  digitalWrite(redLed2, LOW);
  digitalWrite(greenLed1, LOW);
  digitalWrite(greenLed2, LOW);
  digitalWrite(blueLed1, LOW);
  digitalWrite(blueLed2, LOW);
}
void orangeBlue(){
  while(isInterrupted == 0){
    digitalWrite(redLed1, HIGH);
    analogWrite(greenLed1, 40);
    digitalWrite(blueLed1, LOW);
    digitalWrite(redLed2, LOW);
    digitalWrite(greenLed2, HIGH);
    analogWrite(blueLed2, 25);
    if(isInterrupted == 1){
      continue;
    }
  }
}

void rotateEyesFast(){

  off();
  while(isInterrupted == 0){
    int timer1 = 0;
    int timer2 = 255;

    while(timer1 <255){
      timer1+=5;
      timer2-=5;
      if(isInterrupted == 1){
        continue;
      }
      analogWrite(redLed1, timer1);
      analogWrite(blueLed2, timer1);
      analogWrite(blueLed1, timer2);
      analogWrite(greenLed2, timer2);

      delay(20);
    }
    if(isInterrupted == 0){
    //delay(300);
    }

    timer1 = 0;
    timer2 = 255;

    while(timer1 <255){
      timer1+=5;
      timer2-=5;
      if(isInterrupted == 1){
        continue;
      }
      analogWrite(greenLed1, timer1);
      analogWrite(redLed2, timer1);
      analogWrite(redLed1, timer2);
      analogWrite(blueLed2, timer2);

      delay(20);
    }
    if(isInterrupted == 0){
    //delay(300);
    }
    timer1 = 0;
    timer2 = 255;

    while(timer1<255){
      timer1+=5;
      timer2-=5;
      if(isInterrupted == 1){
        continue;
      }
      analogWrite(blueLed1, timer1);
      analogWrite(greenLed2, timer1);
      analogWrite(greenLed1, timer2);
      analogWrite(redLed2, timer2);

      delay(20);
    }
    if(isInterrupted == 0){
    //delay(300);
    }
  }
}



