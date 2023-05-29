#include <LiquidCrystal.h> // Biblioteca do codigo
#include <VNH3SP30.h> // Biblioteca do codigo
#include <Keypad.h> // Biblioteca do codigo

VNH3SP30 Motor1;    // defina o objeto de controle para 1 motor

// Pinos do Motor
#define M1_PWM 3    // Pino PWM
#define M1_INA 1    // Controle Pino INA
#define M1_INB 2    // Controle Pino INB
#define M1_DIAG 6   // pinos de diagnóstico (DIAGA / ENA combinado e DIAGB / ENB)
#define M1_CS A2    // Pino Sensor de Corrente (CS)

// Pinos do LCD
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // Variaveis para manter números de pinos
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Cria um objeto LCD para controlar o monitor LCD

// Variaveis do KeyPad
const byte LINHAS = 4; // Linhas do teclado
const byte COLUNAS = 4; // Colunas do teclado

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { // Matriz de caracteres (mapeamento do teclado)
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte PINOS_LINHAS[LINHAS] = {14, 15, 16, 17}; // Pinos de conexao com as linhas do teclado
const byte PINOS_COLUNAS[COLUNAS] = {18, 19, 20, 21}; // Pinos de conexao com as colunas do teclado

Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS); // Inicia teclado
//Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
  lcd.setCursor (0, 0);
  lcd.print("Buenas LAPMEC!"); //Mostra Mostra mensagem no LCD
  delay (2500);
  lcd.setCursor (0, 1);
  lcd.print ("Debulhador v1");
  delay (2500);
  lcd.clear();

  Motor1.begin(M1_PWM, M1_INA, M1_INB, M1_DIAG, M1_CS);

  }

void loop() {

  bool loop = false; // Variavel para loop
  char leitura_teclas = teclado_personalizado.getKey(); // Atribui a variavel a leitura do teclado

  // MOTOR
  switch (leitura_teclas) {
  case '0': // 48 é 0

    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);  // Define o cursor para a Coluna 1, linha 1
    lcd.print ("Motor Parado");
    delay(500);
    Motor1.setSpeed (0); // Motor Parado

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

    
  break;

  case '1': //49 é 1
    
    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("4/4 da Velocidade");
    Motor1.setSpeed (400); // 4/4 da Velocidade
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  case '2': //50 é 2

    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("3/4 da Velocidade");
    Motor1.setSpeed (300); // 3/4 da Velocidade
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  case '3': // 51 é 3

    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("2/4 da Velocidade");
    Motor1.setSpeed (200); // 2/4 para trás
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  case '4': // 52 é 4

    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("1/4 da Velocidade");
    Motor1.setSpeed (100); // 1/4 da Velocidade
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  case '5': // 53 é 5
    
    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("4/4 para trás");
    Motor1.setSpeed (-400); // 4/4 para trás
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  case '6': // 54 é 6

    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("3/4 para trás");
    Motor1.setSpeed (-300); // 3/4 para trás
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  case '7': // 55 é 7

    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("1/4 para trás");
    Motor1.setSpeed (-200); // 2/4 para trás
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  case '8': // 56 é 8

    lcd.begin(16, 2); // Define o numero de colunas e linhas do LCD
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print ("1/4 para trás");
    Motor1.setSpeed (-100); // 1/4 para trás
    delay (500);

    while(!loop) {

      lcd.setCursor (0, 1);
      lcd.print ("Corrente="); lcd.print (Motor1.motorCurrent());
      
      if ( !(leitura_teclas == 1) ){
        loop = true;
      }
    }

  break;

  }

}
