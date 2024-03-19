//definiremos nuestras variables usando #define para evitar consumo innecesari de almacenamiento.
#define LEDPIN 3
#define BOTONPIN 2
// Contador  
volatile unsigned int contador = 0; //creamos una variable volatil osea cambiable que no podra tener valores negativos.

void setup() {
  // Configuración de pines
  pinMode(LEDPIN, OUTPUT);
  pinMode(BOTONPIN, INPUT_PULLUP);
  
  // Interrumpiremos en flanco de subida
  attachInterrupt(digitalPinToInterrupt(BOTONPIN), handleButton, CHANGE);  //RISING 0v a 5v //FALLING de 5v a 0v //CHANGE en ambos casos
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LEDPIN, 1);
  delay(300);
  digitalWrite(LEDPIN, 0);
  delay(300);
  Serial.println(contador); 
  
}

void handleButton() 
{
  // Incrementa el contador al presionar 
  contador++;
}