/*
  DECLARANDO AS CONSTANTES DOS PINOS DE SAIDAS DIGITAIS E ENTRADAS ANALÓGICAS
*/

#define buzzer  6
#define motor  5
#define pot  A0
#define ldr  A1
#define led  4
#define rele 3

int valuePot = 0;
int valueLdr = 0;
int test = 0;
/*
  CONSTANTE DE CONTROLE DA VELOCIDADE DO MOTOR CC
*/ 
#define speedMotor 1000

/*
  INCIANDO MAPEAMENTO DE ENTRADA E SAIDA DOS PINOS 7, 5 E 3 DIGITAIS E SAIDAS A0 E A1 ANAÓGICAS
*/
void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(pot, INPUT);
  pinMode(rele, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Teste Projeto Ratoeira");
}

void loop()
{

  digitalWrite(led, HIGH);
  /*
    MAPEAMENTO DA LEITURA ANALÓGICA DO LDR E POTENCIOMETRO
  */
  valuePot = map(analogRead(pot), 0, 1023, 0, 255);
  valueLdr = map(analogRead(ldr), 0, 1023, 0, 255);
  
  Serial.print("Valor Lido pelo Ldr: ");
  Serial.print(valueLdr);
  Serial.print(" ");
  Serial.print("Valor Lido pelo Potenciometro: ");
  Serial.println(valuePot);

  /*
    VALUEPOT É USADA PARA AJUSTAR O CONDICIONAL DADO A ILUINAÇÃO DO AMBIENTE
      ONDE É REALIZADO TESTE
  */
  if(test == 0){
    if(valueLdr > valuePot){
      analogWrite(rele, HIGH);
      delay(400);
      digitalWrite(rele, LOW);
      tone(buzzer, 440);
      delay(3000);
      /*
          TEST INICIALMENTE 0, SERÁ ATIVADA APÓS O RATO ENTRAR NA RATOEIRA E SEJA CAPTURADO,
        BASICAMENTE NOS IMPEDIMOS QUE ELE ENCOSTE NOVAMENTE NO LDR, ASSIM, ACIONANDO NOVAMENTE
        O QUE PODERIA LEVAR A PORTA A SE ABRIR E O ANIMAL ESCAPAR DEVIDO A ESSA FALHA.
      */  
      test = 1;
    }
  }else{
    digitalWrite(rele, LOW);
    noTone(buzzer);
  }
  
}
