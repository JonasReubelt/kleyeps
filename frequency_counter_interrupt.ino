const byte ledPin = 13;
const byte interruptPin = 2;
long int n = 0;
long int time1;

void setup() {
  Serial.begin(9600);
  Serial.print("Hallo");
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop() {
   delay(1000);
   Serial.println((float)n/(micros()-time1)*1000000);
   n = 0;
   time1 = micros();
}

void blink() {
  n++;
}
