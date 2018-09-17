const byte interruptPin1 = 2;
const byte interruptPin2 = 3;
long int n1 = 0;
long int n2 = 0;
long int time1;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), increase1, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), increase2, RISING);
}

void loop() {
   delay(1000);
   
   Serial.print((float)n1/(micros()-time1)*1000000);
   Serial.print(" ");
   Serial.print((float)n2/(micros()-time1)*1000000);
   Serial.print("\n");
   n1 = 0;
   n2 = 0;
   time1 = micros();
}

void increase1() {
  n1++;
}


void increase2() {
  n2++;
}
