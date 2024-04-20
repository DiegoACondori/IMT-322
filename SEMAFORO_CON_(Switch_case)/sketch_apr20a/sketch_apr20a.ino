
#define Rojo 5
#define Amarillo 6
#define Verde 7
int estadoSemaforo = 0;
typedef enum {
ROJO,
AMARILLO,
VERDE
} semaforo;  // coloque como nombre a mi enum se llamara semaforo. 

semaforo FSM = ROJO;           //cree una variable de tipo semaforo y lo llame FSM.
semaforo Invertido = VERDE;    //cree una variable extra "solo para practicar" de tipo semaforo y lo llame Invertido.
void setup() {
  // put your setup code here, to run once:
pinMode (Rojo, OUTPUT);
pinMode (Amarillo, OUTPUT);
pinMode (Verde, OUTPUT);

}
void
void loop() {
  // put your main code here, to run repeatedly:
switch (estadoSemaforo) {
case ROJO: //Estado del Rojo
digitalWrite(Rojo, HIGH);
digitalWrite(Amarillo, LOW);
digitalWrite(Verde, LOW);
delay(2000);
estadoSemaforo = 1; //Esto me ordena cambiar al estado 1 
break;
case AMARILLO: //Estado del Verde
digitalWrite(Rojo, LOW);
digitalWrite(Amarillo, LOW);
digitalWrite(Verde, HIGH);
delay(2000);
estadoSemaforo = 2; //Esto me ordena Cambiar al estado 2
break;
case VERDE:   //Estado Amarillo
digitalWrite(Rojo, LOW);
digitalWrite(Amarillo, HIGH);
digitalWrite(Verde, LOW);
delay(2000);
estadoSemaforo = 0;
break;

}
}