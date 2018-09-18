const byte interruptPin = 2;
volatile long int n = 0;
long int timestamp;
long int now;
long int diff;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), increase, RISING);
}

void loop() {
   delay(10000);

   now = micros();
   diff = (now - timestamp) / 1000000;
  
   Serial.println(float(n)/diff);

   n = 0;
   timestamp = now;
}

void increase() {
  n++;
}
