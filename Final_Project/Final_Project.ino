#define LEFTPHOTO
#define RIGHTPHOTO
#define CENTERPHOTO
#define LEFTDISTANCE
#define RIGHTDISTANCE
#define CENTERDISTANCE 
#define LEFTOUTPUTA 5
#define LEFTOUTPUTB 6
#define RIGHTOUTPUTA 9
#define RIGHTOUTPUTB 10
int LEFTPHOTOREADING;
int RIGHTPHOTOREADING;
int CENTERPHOTOREADING;
int LEFTDISTANCEREADING;
int RIGHTDISTANCEREADING;
int CENTERDISTANCEREADING;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEFTPHOTO, INPUT);
  pinMode(RIGHTPHOTO, INPUT);
  pinMode(CENTERPHOTO, INPUT);
  pinMode(LEFTDISTANCE, INPUT);
  pinMode(RIGHTDISTANCE, INPUT);
  pinMode(CENTERDISTANCE, INPUT);
  pinMode(LEFTOUTPUTA, OUTPUT);
  pinMode(LEFTOUTPUTB, OUTPUT);
  pinMode(RIGHTOUTPUTA, OUTPUT);
  pinMode(RIGHTOUTPUTB, OUTPUT);
  digitalWrite(ENABLELEFT, HIGH);
  digitalWrite(ENABLERIGHT, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int LEFTPHOTOREADING = analogRead(LEFTPHOTO);
  int RIGHTPHOTOREADING = analogRead(RIGHTPHOTO);
  int CENTERPHOTOREADING = analogRead(CENTERPHOTO);
  int LEFTDISTANCEREADING = analogRead(LEFTDISTANCE);
  int RIGHTDISTANCEREADING = analogRead(RIGHTDISTANCE);
  int CENTERDISTANCEREADING = analogRead(CENTERDISTANCE);
  
  forward();
  delay (1200);
  turnLeft();
  delay(1200);
}

void forward () {
    digitalWrite(LEFTOUTPUTA, HIGH);
    digitalWrite(RIGHTOUTPUTA, HIGH);
    digitalWrite(LEFTOUTPUTB, LOW);
    digitalWrite(RIGHTOUTPUTB, LOW);
}
void turnLeft () {
    digitalWrite(LEFTOUTPUTA, LOW);
    digitalWrite(RIGHTOUTPUTA, HIGH);
    digitalWrite(LEFTOUTPUTB, HIGH);
    digitalWrite(RIGHTOUTPUTB, LOW);
}
}

