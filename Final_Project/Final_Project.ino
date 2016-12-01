#define LEFTPHOTO  A5  //These analog input ports need to be defined!
#define RIGHTPHOTO A3
#define CENTERPHOTO A4
#define LEFTDISTANCE A2
#define RIGHTDISTANCE A0
#define CENTERDISTANCE A1
#define LEFTOUTPUTA 5
#define LEFTOUTPUTB 6
#define RIGHTOUTPUTA 9
#define RIGHTOUTPUTB 10

int differenceThreshold = 0;

int distanceThreshold = 625;
int whiteThreshold = 500;
int REDLINE_THRESHOLD = 200;

int stepDelay = 200;
int movementDelay = 100;

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
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 // delay(1.4);
  int leftPhoto = analogRead(LEFTPHOTO);
  int rightPhoto = analogRead(RIGHTPHOTO);
  int centerPhoto = analogRead(CENTERPHOTO);
  int leftDistance = analogRead(LEFTDISTANCE);
  int rightDistance = analogRead(RIGHTDISTANCE);
  int centerDistance = analogRead(CENTERDISTANCE);


  Serial.println(" ");
  Serial.print(leftPhoto);
  Serial.print("\t");
  Serial.print(rightPhoto);
  Serial.print("\t");
  Serial.print(centerPhoto);
  Serial.print("\t");
  Serial.print(centerDistance);
  
 if (centerDistance > distanceThreshold) {
   stopMotion();
   
 } else {
        if (leftPhoto <= rightPhoto && centerPhoto <= leftPhoto && (max (rightPhoto, leftPhoto) - centerPhoto) > differenceThreshold) {
          forward();
          
          /* delay(stepDelay);
          stopMotion();
          delay(movementDelay); */
          
        } else if (rightPhoto <= centerPhoto && rightPhoto <= leftPhoto && (max (centerPhoto, leftPhoto) - rightPhoto) > differenceThreshold) {
          turnRight();
          
          /* delay(stepDelay);
          stopMotion();
          delay(movementDelay); */
          
        } else if (leftPhoto <= centerPhoto || leftPhoto <= rightPhoto && (max (centerPhoto, rightPhoto) - leftPhoto) > differenceThreshold) {
          turnLeft();
          
                    /* delay(stepDelay);
          stopMotion();
          delay(movementDelay); */
        }
    }
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
void turnRight () {
    digitalWrite(LEFTOUTPUTA, HIGH);
    digitalWrite(RIGHTOUTPUTA, LOW);
    digitalWrite(LEFTOUTPUTB, LOW);
    digitalWrite(RIGHTOUTPUTB, HIGH);
}
void stopMotion () {
    digitalWrite(LEFTOUTPUTA, LOW);
    digitalWrite(RIGHTOUTPUTA, LOW);
    digitalWrite(LEFTOUTPUTB, LOW);
    digitalWrite(RIGHTOUTPUTB, LOW);
}
