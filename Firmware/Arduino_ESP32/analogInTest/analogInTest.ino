#define PIN_PWM 17 //GPIO17
#define PIN_POT 34 //ADC6

#define PWM_CHAN 0 //PWM Channel (FreeRTOS Timer - based)
#define PWM_FREQ 5000 // PWM Frequency (Hz)
#define PWM_RES 12 //12 BIT PWM OUTPUT

unsigned int potIn;

void setup() {
  pinMode(PIN_PWM, OUTPUT);
  digitalWrite(PIN_PWM, 0);
  ledcSetup(PWM_CHAN, PWM_FREQ, PWM_RES);
  ledcAttachPin(PIN_PWM, PWM_CHAN);

  pinMode(PIN_POT, INPUT);

}

void loop() {
  int i;
  int n = 100;
  for(i = 0; i < n; i++){
    potIn += (analogRead(potIn));
    delay(1);
  }
  potIn /= n;

  ledcWrite(PWM_CHAN, potIn);

}
