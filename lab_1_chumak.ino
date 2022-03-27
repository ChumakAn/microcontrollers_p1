boolean buttonFlag = 0;
boolean button;
int LEDnumber = 42;

void setup() {
  pinMode(26, INPUT_PULLUP);
  Serial.begin(9600);
  for(int i=42;i<50;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,0);
    }
}

void loop() {
  button = !digitalRead(26);
  if (button == 1 && buttonFlag == 0) {
    for (LEDnumber; LEDnumber <= 45; LEDnumber++) {
      digitalWrite(LEDnumber, 1);
      digitalWrite(91 - LEDnumber, 1);
      delay(650);
      digitalWrite(LEDnumber, 0);
      digitalWrite(91 - LEDnumber, 0);
      delay(650);
    }
   
    buttonFlag = 1;
  }

  if (button == 0 && buttonFlag == 1) {
    LEDnumber = 42;
    buttonFlag = 0;
  }
}
