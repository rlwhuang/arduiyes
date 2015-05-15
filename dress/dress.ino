int led13 = 13;
int led12 = 12;
int led11 = 11;
int led10 = 10;

char state;

void setup() {

  pinMode(led13, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0) {
    state = Serial.read();
  }

  if (state == '1') { //1234
    OneTwoThreeFour();
  }  

  else if (state == '2') { //1243
    OneTwoFourThree();
  }

  else if (state == '3') { //1324
    OneThreeTwoFour();
  }  

  else if (state == '4') { //1342
    OneThreeFourTwo();
  }
  
  else if (state == '5') { //1423
    OneFourTwoThree();
  }
  
  else if (state == '6') { //1432
    OneFourThreeTwo();
  }

  else if (state == '7' ) { //2134
    TwoOneThreeFour(); 
  }
  
  else if (state == '8' ) { //2143
    TwoOneFourThree(); 
  }

  
  else if (state == '9' ) { //2314
    TwoThreeOneFour();
  }
  
  else if (state == '0' ) { //2341
    TwoThreeFourOne();
  }

  else if (state == 'a' ) { //2413
    TwoFourOneThree();
  }
  
  else if (state == 'b' ) { //2431
    TwoFourThreeOne(); 
  }
  
  else if (state == 'c' ) { //3124
    ThreeOneTwoFour();
  }
  
  else if (state == 'd' ) { //3142
    ThreeOneFourTwo();
  }
  
  else if (state == 'e') { //3214
    ThreeTwoOneFour(); 
  }

  else if (state == 'f') { //3241
    ThreeTwoFourOne();
  }
  
  else if (state == 'g') { //3412
    ThreeFourOneTwo();
  }
  
  else if (state == 'h') { //3421
    ThreeFourTwoOne();
  }
  
  else if (state == 'j') { //4123
    FourOneTwoThree();
  }
  
  else if (state == 'k') { //4132
    FourOneThreeTwo();
  }
  
  else if (state == 'l') { //4213
    FourTwoOneThree();
  }
  
  else if (state == 'm') { //4231
    FourTwoThreeOne();
  }
  
  else if (state == 'n') { //4321
    FourThreeTwoOne();
  }
  
  else if (state == 'o') { //4312
    FourThreeOneTwo();
  }
    
}





