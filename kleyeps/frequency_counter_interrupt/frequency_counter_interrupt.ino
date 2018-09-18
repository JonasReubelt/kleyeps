const byte interruptPin1 = 2;
const byte interruptPin2 = 3;
volatile long int n1 = 0;
volatile long int n2 = 0;
long int timestamp;
long int now;
long int diff;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), increase1, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), increase2, RISING);
}

void loop() {
   delay(1000);

   noInterrupts();
   now = micros();
   diff = (now - timestamp) / 1000000;
  
   Serial.print(float(n1)/diff);
   Serial.print(" ");
   Serial.println(float(n2)/diff);

   n1 = 0;
   n2 = 0;
   timestamp = now;
   interrupts();
}

void increase1() {
  n1++;
}


void increase2() {
  n2++;
}
