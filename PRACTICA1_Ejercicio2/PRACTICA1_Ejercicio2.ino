#define USER_BUTTON 2
#define LED1 9
#define LED2 10
#define LED3 11

int secuencia = 1; // 1 para secuencia 1, 2 para secuencia 2, 3 para secuencia 3, 4 para secuencia 4
int estadoAnterior = LOW;

void setup() {
  pinMode(USER_BUTTON, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  int estadoActual = digitalRead(USER_BUTTON);
  if (estadoAnterior == HIGH && estadoActual == LOW) {
    secuencia++;
    if (secuencia > 4) {
      secuencia = 1;
    }
    delay(50); // Debounce
  }
  estadoAnterior = estadoActual;

  switch (secuencia) {
    case 1:
    case 3:
      digitalWrite(LED1, HIGH);
      delay(1000);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(1000);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(1000);
      digitalWrite(LED3, LOW);
      break;
    case 2:
    case 4:
      digitalWrite(LED1, HIGH);
      delay(1000);
      digitalWrite(LED1, LOW);
      digitalWrite(LED3, HIGH);
      delay(1000);
      digitalWrite(LED3, LOW);
      digitalWrite(LED2, HIGH);
      delay(1000);
      digitalWrite(LED2, LOW);
      break;
  }
}