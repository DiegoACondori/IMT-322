//ELAVORADO POR DIEGO A CONDORI Y RICARDO VELASCO LOPEZ
#define LED1 5 
#define LED2 6
#define LED3 7
int pul=8;
int valpul;
int dtled=200;
int cont=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pul,INPUT_PULLUP);
  pinMode (LED1,OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (LED3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 // put your main code here, to run repeatedly:
valpul=digitalRead(pul);
Serial.println(100);
delay(100);

 if(valpul==1){
  digitalWrite(LED1,HIGH);
  delay(dtled);
  digitalWrite(LED1,LOW);
  delay(dtled);
  digitalWrite(LED2,HIGH);
  delay(dtled);
  digitalWrite(LED2,LOW);
  delay(dtled);
  digitalWrite(LED3,HIGH);
  delay(dtled);
  digitalWrite(LED3,LOW);
  delay(dtled);
  }
  else {  
  digitalWrite(LED3,HIGH);
  delay(dtled);
  digitalWrite(LED3,LOW);
  delay(dtled);
  digitalWrite(LED2,HIGH);
  delay(dtled);
  digitalWrite(LED2,LOW);
  delay(dtled);
  digitalWrite(LED1,HIGH);
  delay(dtled);
  digitalWrite(LED1,LOW);
  delay(dtled);
    }

}
