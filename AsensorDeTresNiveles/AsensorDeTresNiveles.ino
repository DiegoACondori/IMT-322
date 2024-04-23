//VARIABLES Y ENUMERACIONES..........................................
#define PrimerBot 2
#define SegundoBot 3
#define TercerBot 4
int Estado =0;
typedef enum{
  PISO1,PISO2,PISO3
}piso;
piso NumeroDePiso=PISO1;

//DECLARACION DE ENTRADAS Y SALIDAS....................................
void setup() 
{
  // put your setup code here, to run once:
 pinMode(PrimerBot,INPUT_PULLUP);
 pinMode(SegundoBot,INPUT_PULLUP);
 pinMode(TercerBot,INPUT_PULLUP);
Serial.begin(9600);
}

//..............................................................................................
void loop() {
  // put your main code here, to run repeatedly:
switch(NumeroDePiso)
  {
    //CASO NUMERO UNO....................................
  case PISO1:
  Serial.println("Llegaste al piso 1");
  
  delay(2000);

  Estado=digitalRead(PrimerBot);
  Serial.println("VALOR");
  Serial.println(Estado);
  
  if(digitalRead(SegundoBot)==1)
    {
      Serial.println("Estas yendo al piso2");
      delay(3000);
      NumeroDePiso=PISO2;
      break;
    }
     if(digitalRead(TercerBot)==1)
    {
      Serial.println("Estas yendo al piso3");
      delay(3000);
      NumeroDePiso=PISO3;
      break;
    }



  break;

  //CASO NUMERO DOS...........................
  case PISO2:
  Serial.println("Llegaste al piso2");
  delay(2000);
    Estado=digitalRead(TercerBot);
    Serial.println("VALOR");
    Serial.println(Estado);

    if(digitalRead(TercerBot)==1)
    {
      Serial.println("Estas yendo al piso 3");
      delay(3000);
      NumeroDePiso=PISO3;
      break;
    }
    if(digitalRead(PrimerBot)==1)
    {
      Serial.println("Estas yendo al piso 1");
      delay(3000);
      NumeroDePiso=PISO1;
      break;
    }
  break;

  //CASO NUMERO TRES...........................
  case PISO3:
  Serial.println("Llegaste al piso 3");
  delay(3000);
  Estado=digitalRead(TercerBot);
    Serial.println("VALOR");
    Serial.println(Estado);
    
    if(digitalRead(PrimerBot)==1)
    {
      Serial.println("Estas yendo al piso 1");
      delay(3000);
      NumeroDePiso=PISO1;
      break;
    }
     if(digitalRead(SegundoBot)==1)
    {
      Serial.println("Estas yendo al piso 2");
      delay(3000);
      NumeroDePiso=PISO2;
      break;
    }


   break;
    }
}
