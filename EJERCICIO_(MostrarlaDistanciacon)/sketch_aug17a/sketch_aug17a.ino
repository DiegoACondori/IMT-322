const int trigPin = 9;
const int echoPin = 10;

const int pinPulsador = 2;
const int pinSalida = 13;  
volatile bool pulActivado = false;

void manejarInterrupcion() {
  pulActivado = !pulActivado; // Cambia el estado del pulsador
  digitalWrite(pinSalida, pulActivado); // Actualiza el estado del pulsador
}
void setup() {
  pinMode(pinPulsador, INPUT_PULLUP); // Configura el pulsador con resistencia interna
  pinMode(pinSalida, OUTPUT);            // Configura el pin como salida
  attachInterrupt(digitalPinToInterrupt(pinPulsador), manejarInterrupcion, FALLING); // Configura la interrupción

Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {

if (pulActivado==1) {
digitalWrite(trigPin, LOW);
delayMicroseconds(2) ;
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
long duration = pulseIn(echoPin, HIGH);
float distance_cm = duration * 0.034 / 2;
Serial.println(distance_cm);
delay(2000);
}
}
