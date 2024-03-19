#define PRIMER_PULSADOR 2
#define SEGUNDO_PULSADOR 3
volatile int contador = 0;

void setup() {
  pinMode(PRIMER_PULSADOR, INPUT_PULLUP);
  pinMode(SEGUNDO_PULSADOR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PRIMER_PULSADOR), incrementarContador, FALLING);
  attachInterrupt(digitalPinToInterrupt(SEGUNDO_PULSADOR), reiniciarContador, FALLING);
  Serial.begin(9600);
}

void loop() {
  // No es necesario hacer nada en el bucle principal
}

void incrementarContador() {
  contador++;
  Serial.print("Contador: ");
  Serial.println(contador);
}

void reiniciarContador() {
  contador = 0;
  Serial.println("Contador reiniciado");
}