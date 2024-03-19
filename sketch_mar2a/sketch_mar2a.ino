//EJERCICIO 2 

#define LED1 1 
#define PULS 8
#define BAUDRATE 9600
int valpul;
int dtled=200;
volatile int cont =0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN ,OUTPUT);
  pinMode(PULS,INPUT_PULLUP);
  attachInterrup (digitalPinToInterrupt(PULS),counter,RISING);
  
  Serial.begin(BAUDRATE);

}

void loop() {
  // put your main code here, to run repeatedly:
valpul=digitalRead(PULS);
Serial.println(100);
Serial.print("CONTADOR:     ");
Serial.println(cont);

digitalWrite(LED1,HIGH);
  delay(100);
  digitalWrite(LED1,LOW);
}
