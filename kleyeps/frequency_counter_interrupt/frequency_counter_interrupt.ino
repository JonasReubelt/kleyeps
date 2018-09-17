const byte interruptPin1 = 2;
const byte interruptPin2 = 3;
long int n1 = 0;
long int n2 = 0;
long int timestamp;
long int now;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), increase1, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), increase2, RISING);
}

void loop() {
   delay(1000);
   elapsed_time = (micros() - start_time) * 1000000;
   Serial.print((float)n1/elapsed_time);
   Serial.print(" ");
   Serial.print((float)n2/elapsed_time);
   Serial.print("\n");
   n1 = 0;
   n2 = 0;
   start_time = micros();

   now = micros();
   div = (now - timestamp) * 1000000;
   
   Serial.print((float)n1/div);
   Serial.print(" ");
   Serial.println((float)n2/div);

   n1 = 0;
   n2 = 0;
   timestamp = now;
}

void increase1() {
  n1++;
}


void increase2() {
  n2++;
}
