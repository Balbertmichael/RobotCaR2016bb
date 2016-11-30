#define LEFTPHOTO	A5	//These analog input ports need to be defined!
#define RIGHTPHOTO A3
#define CENTERPHOTO A4
#define LEFTDISTANCE A2
#define RIGHTDISTANCE A0
#define CENTERDISTANCE A1
#define LEFTOUTPUTA 5
#define LEFTOUTPUTB 6
#define RIGHTOUTPUTA 9
#define RIGHTOUTPUTB 10

int LEFTPHOTOREADINGP = 0; //Needs to be defined to white value
int RIGHTPHOTOREADINGP = 0; //Needs to be defined to white value
int CENTERPHOTOREADINGP = 0; //Needs to be defined to black value
int PHOTORESISTOR_THRESHOLD = 370;
int DISTANCESENSOR_THRESHOLD = 500;

void setup() {
  // put your setup code here, to run once:
  /*pinMode(LEFTPHOTO, INPUT);
  pinMode(RIGHTPHOTO, INPUT);
  pinMode(CENTERPHOTO, INPUT);
  pinMode(LEFTDISTANCE, INPUT);
  pinMode(RIGHTDISTANCE, INPUT);
  pinMode(CENTERDISTANCE, INPUT);*/
  pinMode(LEFTOUTPUTA, OUTPUT);
  pinMode(LEFTOUTPUTB, OUTPUT);
  pinMode(RIGHTOUTPUTA, OUTPUT);
  pinMode(RIGHTOUTPUTB, OUTPUT);
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
  Serial.println(" ");
  Serial.print(LEFTPHOTOREADING);
  Serial.print("\t");
  Serial.print(CENTERPHOTOREADING);
  Serial.print("\t");
  Serial.print(RIGHTPHOTOREADING);
  /*int LEFTPHOTODIGITAL = 0;							//Default value for all digital readings is 0
  if (LEFTPHOTOREADING - LEFTPHOTOREADINGP > PHOTORESISTOR_THRESHOLD) { LEFTPHOTODIGITAL = 1; }		//but if analog value > threshold, change to 1
  int RIGHTPHOTODIGITAL = 0;									
  if (RIGHTPHOTOREADING - RIGHTPHOTOREADINGP > PHOTORESISTOR_THRESHOLD) { RIGHTPHOTODIGITAL = 1; }	// Do they revert back to 0 if < threshold ? - John L
  int CENTERPHOTODIGITAL = 0;
  if (CENTERPHOTOREADING - CENTERPHOTOREADINGP > PHOTORESISTOR_THRESHOLD) { CENTERPHOTODIGITAL = 1; }*/
  int LEFTPHOTODIGITAL = 0;              //Default value for all digital readings is 0
  if (LEFTPHOTOREADING > PHOTORESISTOR_THRESHOLD) { LEFTPHOTODIGITAL = 1; }   //but if analog value > threshold, change to 1
  int RIGHTPHOTODIGITAL = 0;                  
  if (RIGHTPHOTOREADING > PHOTORESISTOR_THRESHOLD) { RIGHTPHOTODIGITAL = 1; }  // Do they revert back to 0 if < threshold ? - John L
  int CENTERPHOTODIGITAL = 0;
  if (CENTERPHOTOREADING > PHOTORESISTOR_THRESHOLD) { CENTERPHOTODIGITAL = 1; }

  Serial.println(" ");
  Serial.print(LEFTPHOTODIGITAL);
  Serial.print(" ");
  Serial.print(CENTERPHOTODIGITAL);
  Serial.print(" ");
  Serial.print(RIGHTPHOTODIGITAL);
  Serial.print(" ");

  int LEFTDISTANCEDIGITAL = 0;							//Same process for distance sensor readings
  if (LEFTDISTANCEREADING > DISTANCESENSOR_THRESHOLD) { LEFTDISTANCEDIGITAL = 1; }
  int RIGHTDISTANCEDIGITAL = 0;
  if (RIGHTDISTANCEREADING > DISTANCESENSOR_THRESHOLD) { RIGHTDISTANCEDIGITAL = 1; }
  int CENTERDISTANCEDIGITAL = 0;
  if (CENTERDISTANCEREADING > DISTANCESENSOR_THRESHOLD) { CENTERDISTANCEDIGITAL = 1; }

  if (LEFTDISTANCEDIGITAL == 1 ||
	RIGHTDISTANCEDIGITAL == 1 ||
	CENTERDISTANCEDIGITAL == 1) {		//This checks for a reading from any of the distance sensors
	//Place code for distance-sensor-based behavior here
  } else {
	if (LEFTPHOTODIGITAL == 0) {
		turnLeft();
	} else if (RIGHTPHOTODIGITAL == 0) {
		turnRight();
	} else {
		forward();
	}
  }
  LEFTPHOTOREADINGP = LEFTPHOTOREADING;
  RIGHTPHOTOREADINGP = RIGHTPHOTOREADING;
  CENTERPHOTOREADINGP = CENTERPHOTOREADING;

  //delay(1);
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


