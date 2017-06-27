#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LCD com comunicação l2C 0x3F

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE); // Inicia o LCD no endereço 0x3F fornecido pelo l2C e o nomeia com nome de "lcd"

int nivelHumidade;
int porcentagemHumidade;
int statusSistema = 0;
int statusIrrigacao = 0;

int contador = 1;

void setup() {
   lcd.begin (20,4); // Define o LCD e seu tamanho 20x4

   // Inicio: Inicialização em grande estilo 
   lcd.print("------- S.I.A ------");
   lcd.setCursor(0,2);
   lcd.print(" Iniciando sistema.");


   lcd.setCursor(0,1);
   lcd.print("|");
   
   while(contador < 19) {
       lcd.setCursor(contador,1);
       lcd.print("-");

       contador++;
       
       delay(250);
   }

   contador = 1;
   
   lcd.setCursor(19,1);
   lcd.print("|");
   delay(250);
   lcd.setCursor(0,2);
   lcd.print("|");
   delay(250);
   lcd.setCursor(19,2);
   lcd.print("|");
   delay(250);
   lcd.setCursor(0,3);
   lcd.print("|");
   delay(250);

   while(contador < 19) {
       lcd.setCursor(contador,3);
       lcd.print("-");

       contador++;
       
       delay(250);
   }

   delay(250);
   lcd.setCursor(19,4);
   lcd.print("|");
   // Fim; 

   // Inicio: Inicializando portas a serem usadas
   pinMode(9, OUTPUT); // Irrigador
   pinMode(10, OUTPUT); // LED AZUL: INFORMATIVO
   pinMode(11, OUTPUT); // LED VERDE: INFORMATIVO
   pinMode(12, OUTPUT); // LED VERMELHO: ALERTA
   pinMode(13, OUTPUT); // LED VERMELHO: INFORMATIVO
   // Fim;
}

void loop() {
  nivelHumidade = analogRead(0); // Recebe a informação do sensor de humidade e guarda
  porcentagemHumidade = (100 * nivelHumidade)/24; // Calcula porcentagem com base am analise

   // Inicio: Relatório do Sistema
   lcd.print("------- S.I.A ------");
   lcd.setCursor(0,2);


  if(porcentagemHumidade <= 60) { // Apenas irriga se a humidade for menor que 60%
    statusIrrigacao = 1;
    statusSistema = 1;
    
    digitalWrite(9, LOW); // Liga irrigador
    digitalWrite(11, LOW); // Desliga LED VERDE de informativo: PROBLEMAS ENCONTRADOS
    digitalWrite(10, HIGH); // Liga LED AZUL de informativo: Irrigador Ligada

    digitalWrite(12, LOW); // Desliga LED VERMELHO de alerta: para loops antecessores
    digitalWrite(12, HIGH); // Liga LED VERMELHO de alerta
    
    delay(500); // Aguarda meio segundo
    
    digitalWrite(12, LOW); // Desliga LED VERMELHO de alerta
   } else {
     statusIrrigacao = 0;
     statusSistema = 2;
    
    digitalWrite(12, LOW); // Desliga LED VERMELHO de alerta: para loops antecessores
    digitalWrite(9, HIGH); // Desliga irrigador: caso esteja ligado

    digitalWrite(11, HIGH); // Liga LED VERDE de informativo: TUDO OK
    digitalWrite(10, LOW); // DESLIGA LED AZUL de informativo: Irrigador desligado
   }

   lcd.print(" STS:" + String(statusSistema) + "|NHS:" + String(porcentagemHumidade) + "%|IR:" + String(statusIrrigacao));

   lcd.setCursor(0,1);
   lcd.print("|");
   
   while(contador < 19) {
       lcd.setCursor(contador,1);
       lcd.print("-");

       contador++;       
   }

   contador = 1;
   
   lcd.setCursor(19,1);
   lcd.print("|");
   lcd.setCursor(0,2);
   lcd.print("|");
   lcd.setCursor(19,2);
   lcd.print("|");
   lcd.setCursor(0,3);
   lcd.print("|");

   while(contador < 19) {
       lcd.setCursor(contador,3);
       lcd.print("-");

       contador++;
    }

   lcd.setCursor(19,4);
   lcd.print("|");
   // Fim; 

   // Inicio: Oscilador para mostrar status do sistema no LED

    digitalWrite(12, HIGH);

    if(statusSistema == 1) {
      delay(1000); // Espera 1/s para reavaliar dados
    } else {
      delay(350); // Espera 5/ms para reavaliar dados
    }

    digitalWrite(12, LOW);
    // Fim;
}
