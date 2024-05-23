int LedRojo = 4;
int LedVerde =5;

const int PulsadorInterrupcionReset =2;
volatile bool PulState2 = LOW;
int Estado3 =0;
int Estado4 =0;

const int PulsadorInterrupcion =3;
volatile bool PulState = LOW;
int Estado1 =0;
int Estado2 =0;

#include <Password.h>
#include <Keypad.h>
Password password = Password( "1234" );
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3',},
  {'4','5','6',},
  {'7','8','9',},
  {'*','0','#',}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 2, 3, 4, 5, };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 6, 7, 8 };

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
#define ledPin 13

void setup() {
  pinMode(LedRojo,OUTPUT);
  pinMode(LedVerde,OUTPUT);

  pinMode(PulsadorInterrupcionReset, INPUT_PULLUP);
  pinMode(PulsadorInterrupcion, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PulsadorInterrupcion), myISR, RISING); 
  attachInterrupt(digitalPinToInterrupt(PulsadorInterrupcionReset), myISR2, RISING); 


  digitalWrite(ledPin, LOW);   // sets the LED on
  
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  keypad.setDebounceTime(250);

  Serial.begin(9600);

}
void loop(){
  keypad.getKey();
}
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println(eKey);
	switch (eKey){
	  case '#': guessPassword(); break;
	   default:
		   password.append(eKey);
  }
}}
void loop() {

 

Estado3 =PulState2;
if (Estado3==LOW){

  Estado1=PulState;
   if(Estado1==LOW){
 Serial.println("Puerta cerrada");
 Serial.println("Coloque la contraseña si quiere Entrar");
 delay(500);

 //Estado1 =digitalRead(Pulsador1);
  digitalWrite(LedRojo,HIGH);
  delay(500);
 }

   Estado2=PulState;
 if(Estado2==HIGH){
  digitalWrite(LedRojo,LOW);
 Serial.println("La puerta esta Abierta");
 digitalWrite(LedVerde,HIGH);
 delay(500);
 digitalWrite(LedVerde,HIGH);
 
 }
  
}

Estado4 =PulState2;
if (Estado4==HIGH){
Serial.println("Sitema Reiniciado");
delay(10000);

Estado1=PulState;
   if(Estado1==LOW){
 Serial.println("Puerta cerrada");
 Serial.println("Coloque la contraseña si quiere Entrar");
 delay(500);

 //Estado1 =digitalRead(Pulsador1);
  digitalWrite(LedRojo,HIGH);
  delay(500);
 }

   Estado2=PulState;
 if(Estado2==HIGH){
  digitalWrite(LedRojo,LOW);
 Serial.println("La puerta esta Abierta");
 digitalWrite(LedVerde,HIGH);
 delay(500);
 digitalWrite(LedVerde,HIGH);
 
 }


}









}
void myISR() {
    PulState = !PulState; // Invierte el estado del LED (alternando entre encendido y apagado)
        //Podemos colocar cualquier codigo basico que queramos hacer solo lo basico nomas pero si no posiblemente falle.
}
void myISR2() {
    PulState2 = !PulState2; // Invierte el estado del LED (alternando entre encendido y apagado)
        //Podemos colocar cualquier codigo basico que queramos hacer solo lo basico nomas pero si no posiblemente falle.
}

void guessPassword(){
     Serial.print("Guessing password... ");
     if (password.evaluate()){
	     digitalWrite(ledPin,HIGH); //activates garaged door relay
             delay(500);                
             digitalWrite(ledPin,LOW); //turns off door relay after .5 sec
	     Serial.println("VALID PASSWORD "); //
              password.reset(); //resets password after correct entry
     }else{
	     digitalWrite(ledPin,LOW);
	     Serial.println("INVALID PASSWORD ");
              password.reset(); //resets password after INCORRECT entry
     }
}
