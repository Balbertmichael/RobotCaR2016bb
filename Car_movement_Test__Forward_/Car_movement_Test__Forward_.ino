int FLmotor = 5;
int BLmotor = 6;
int FRmotor = 9;
int BRmotor = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(FLmotor, OUTPUT);
  pinMode(BLmotor, OUTPUT);
  pinMode(FRmotor, OUTPUT);
  pinMode(BRmotor, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(FLmotor, HIGH);
  digitalWrite(FRmotor, HIGH);
}
