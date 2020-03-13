#define L1 25 //3v3 Output
#define L0 26 //0V Output

#define PIN_PWM 27 //GPIO35
#define PIN_POT 34 //ADC6

#define PWM_CHAN 0 //PWM Channel (FreeRTOS Timer - based)
#define PWM_FREQ 5000 // PWM Frequency (Hz)
#define PWM_RES 12 //12 BIT PWM OUTPUT
#define MAX_PWM 4096 //12 BIT PWM OUTPUT

unsigned long potIn;

void setup() {
  pinMode(L1, OUTPUT);
  digitalWrite(L1, 1);
  
  pinMode(L0, OUTPUT);
  pinMode(L0, 0);
  
  
  pinMode(PIN_PWM, OUTPUT);
  digitalWrite(PIN_PWM, 0);
  ledcSetup(PWM_CHAN, PWM_FREQ, PWM_RES);
  ledcAttachPin(PIN_PWM, PWM_CHAN);

  pinMode(PIN_POT, INPUT);

  Serial.begin(115200);

  Serial.println("Initialization complete!");

}

void loop() {
  int i;
  int n = 10;
  for(i = 0; i < n; i++){
    potIn += (analogRead(PIN_POT));
    //Serial.print("Analog read: ");
    //Serial.println(analogRead(PIN_POT));
    delay(1);
  }
  potIn /= n;

  potIn = (potIn > MAX_PWM)?MAX_PWM:potIn;

  ledcWrite(PWM_CHAN, MAX_PWM-potIn);

  //Serial.print("New PWM set: ");
  //Serial.println(MAX_PWM-potIn);

  delay(1);


}
