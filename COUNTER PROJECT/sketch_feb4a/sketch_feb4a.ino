const int A = 2, B = 3, C = 4, D = 5, E = 6, F = 7, G = 8;
const int buttonPin = 9;
int currentNumber = 0;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 200;  
void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  displayNumber(currentNumber);
}
void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis(); 
    currentNumber++; 
    if (currentNumber > 9) currentNumber = 0;
    displayNumber(currentNumber);
  }
  lastButtonState = buttonState;
}
void displayNumber(int number) {
  const bool digits[10][7] = {
    {LOW,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
	  {LOW,LOW,LOW,LOW,HIGH,LOW,HIGH},
    {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,LOW},
    {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH},
    {HIGH,HIGH,LOW,LOW,HIGH,LOW,HIGH},
    {HIGH,HIGH,LOW,HIGH,LOW,HIGH,HIGH},
    {HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH},
    {LOW,LOW,LOW,HIGH,HIGH,LOW,HIGH},
    {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
    {HIGH,HIGH,LOW,HIGH,HIGH,HIGH,HIGH},

  };
  digitalWrite(A, digits[number][0]);
  digitalWrite(B, digits[number][1]);
  digitalWrite(C, digits[number][2]);
  digitalWrite(D, digits[number][3]);
  digitalWrite(E, digits[number][4]);
  digitalWrite(F, digits[number][5]);
  digitalWrite(G, digits[number][6]);
}
