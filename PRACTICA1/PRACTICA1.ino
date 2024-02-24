#define LED1 1 
#define LED2 2
#define LED3 3
#define tiempo 1000

void setup() {
 pinMode (LED1,OUTPUT);
 pinMode (LED2,OUTPUT);
 pinMode (LED3,OUTPUT);
}

void loop() {
  digitalWrite(LED1,HIGH);
  delay(tiempo);
  digitalWrite(LED1,LOW);
  delay(tiempo);
  digitalWrite(LED2,HIGH);
  delay(tiempo);
  digitalWrite(LED2,LOW);
  delay(tiempo);
  digitalWrite(LED3,HIGH);
  delay(tiempo);
  digitalWrite(LED3,LOW);
  delay(tiempo);
}
