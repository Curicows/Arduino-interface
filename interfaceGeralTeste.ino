#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <IRremote.h>
#include <EEPROM.h>
#include <virtuabotixRTC.h>

#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

int RECV_PIN = 11;
String recebido;
// asm volatile ("  jmp 0"); <---- reinicia o arduino

//#define MA 0

// Inicializa o display no endereco 0x38
LiquidCrystal_I2C lcd(0x38,2,1,0,4,5,6,7,3, POSITIVE);
IRrecv irrecv(RECV_PIN);
decode_results results;
DHT dht(DHTPIN, DHTTYPE);
virtuabotixRTC myRTC(6, 7, 8);

short LEITURASERIAL;
int MA = 0; //Menu atual
int IA = 0; //Interface atual
int MT = 5; //Menu total
int RM; //Reles Menu
int CM = 1; //Config menu
int TM = 1; //Temperatura menu
int tempMin = 100; //Temperatura minima
int tempMax = 0; //Temperatura maxima
int umidMin = 100; //Humidade minima
int umidMax = 0; //Humidade maxima
int PS = 1; //Posição senha
int S1 = 0; //Senha 1
int S2 = 0; //Senha 2
int S3 = 0; //Senha 3
int S4 = 0; //Senha 4
int S5 = 0; //Senha 5
int S6 = 0; //Senha 6
int S7 = 0; //Senha 7
int S8 = 0; //Senha 8
int S9 = 0; //Senha 9
int S10 = 0; //Senha 10
int S11 = 0; //Senha 11
int S12 = 0; //Senha 12
int S13 = 0; //Senha 13
int S14 = 0; //Senha 14
int S15 = 0; //Senha 15
int S16 = 0; //Senha 16
int SI1 = 0; //Senha inserida 1
int SI2 = 0; //Senha inserida 2
int SI3 = 0; //Senha inserida 3
int SI4 = 0; //Senha inserida 4
int SI5 = 0; //Senha inserida 5
int SI6 = 0; //Senha inserida 6
int SI7 = 0; //Senha inserida 7
int SI8 = 0; //Senha inserida 8
int SI9 = 0; //Senha inserida 9
int SI10 = 0; //Senha inserida 10
int SI11 = 0; //Senha inserida 11
int SI12 = 0; //Senha inserida 12
int SI13 = 0; //Senha inserida 13
int SI14 = 0; //Senha inserida 14
int SI15 = 0; //Senha inserida 15
int SI16 = 0; //Senha inserida 16
int SIT; //Senha inserida temporaria
//time integer
int TCP = 1; //Time config position
int DWI = 1; //Day of week inserted
int DI1 = ""; //Day 1 inserted
int DI2 = ""; //Day 2 inserted
int MI1 = ""; //Month 1 inserted
int MI2 = ""; //Month 2 inserted
int YI1 = ""; //Year 1 inserted
int YI2 = ""; //Year 2 inserted
int YI3 = ""; //Year 3 inserted
int YI4 = ""; //Year 4 inserted
int HI1 = ""; //Hour 1 inserted
int HI2 = ""; //Hour 2 inserted
int MiI1 = ""; //Minute 1 inserted
int MiI2 = ""; //Minute 2 inserted
int SeI1 = ""; //Second 1 inserted
int SeI2 = ""; //Second 2 inserted
int DI;
int MI;
int YI;
int HI;
int MiI;
int SeI;
int estadoBotao = 0;
int numeroRecebido;
String RS1 = "OFF"; //Rele Status 1
String RS2 = "OFF"; //Rele Status 2
String TTP1; //Time to print 1
String TTP2; //Time to print 2
String C1 = "ON"; //Config 1 LCD backlight
boolean SI = false; //Senha inserida
boolean TC = false; //Time config boolean
const int ledAzul = 8;
const int ledVerde = 9;
const int ledVermelho = 10;

void setup()
{
  lcd.begin (16,2);
  dht.begin();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Insira a senha:");
  lcd.setCursor(0,1);
  lcd.print("");
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT); 
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);  
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
//  leituraEEPROMSenha();
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop()
{
  if (SI == false) //senha
  {
    if (irrecv.decode(&results)) {
    recebido = results.value;
    if (recebido == "16712445") //OK
    {
      recebido = "";
      senhaEntrar();
    }
    else if (recebido == "16738455") //1
    {
      SIT = 1;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16750695") //2
    {
      SIT = 2;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16756815") //3
    {
      SIT = 3;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16724175") //4
    {
      SIT = 4;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16718055") //5
    {
      SIT = 5;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16743045") //6
    {
      SIT = 6;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16716015") //7
    {
      SIT = 7;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16726215") //8
    {
      SIT = 8;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16734885") //9
    {
      SIT = 9;
      recebido = "";
      senhaInserir();
    }
    else if (recebido == "16730805") //0
    {
      SIT = 0;
      recebido = "";
      senhaInserir();
    }
    irrecv.resume(); // Receive the next value
  }
  }
  else
  {
  if (IA == 1)
  {
    if (TM == 1)
    tempMenu1();
  }
  else if (TM == 2)
  {
    tempMenu2();
  }
  if (MA == 2)
  {
    menu2();
  }
  if (MA == 5)
  {
    menu5();
  }
  estadoBotao = digitalRead(7);
  if (irrecv.decode(&results)) 
  {
    recebido = results.value;
    if (recebido == "16736925") //UP
    {
      recebido = "";
      up();
    }
    else if (recebido == "16754775") //DOWN
    {
      recebido = "";
      down();
    }
    else if (recebido == "16720605") //LEFT
    {
      recebido = "";
      left();
    }
    else if (recebido == "16761405") //RIGHT
    {
      recebido = "";
      right();
    }
    else if (recebido == "16712445") //OK
    {
      recebido = "";
      down();
    }
    else if (recebido == "16738455") //1
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 1;
        timeConfig(); 
      }
    }
    else if (recebido == "16750695") //2
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 2;
        timeConfig(); 
      }
    }
    else if (recebido == "16756815") //3
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 3;
        timeConfig(); 
      }
    }
    else if (recebido == "16724175") //4
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 4;
        timeConfig(); 
      }
    }
    else if (recebido == "16718055") //5
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 5;
        timeConfig(); 
      }
    }
    else if (recebido == "16743045") //6
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 6;
        timeConfig(); 
      }
    }
    else if (recebido == "16716015") //7
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 7;
        timeConfig(); 
      }
    }
    else if (recebido == "16726215") //8
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 8;
        timeConfig(); 
      }
    }
    else if (recebido == "16734885") //9
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 9;
        timeConfig(); 
      }
    }
    else if (recebido == "16730805") //0
    {
      recebido = "";
      if (TC == true)
      {
        numeroRecebido = 0;
        timeConfig(); 
      }
    }
    irrecv.resume(); // Receive the next value
   if (estadoBotao == 1)
   {
    
   }
  }
}
}

void senhaInserir()
{
  if (PS == 1)
  {
    SI1 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  }
  else if (PS == 2)
  {
    SI2 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  }
  else if (PS == 3)
  {
    SI3 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  }
  else if (PS == 4)
  {
    SI4 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 5)
  {
    SI5 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 6)
  {
    SI6 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 7)
  {
    SI7 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 8)
  {
    SI8 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 9)
  {
    SI9 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 10)
  {
    SI10 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 11)
  {
    SI11 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 12)
  {
    SI12 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 13)
  {
    SI13 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 14)
  {
    SI14 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 15)
  {
    SI15 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
  else if (PS == 16)
  {
    SI16 = SIT;
    PS = PS + 1;
    lcd.setCursor(PS - 2,1);
    lcd.print("*");
  } 
}

void senhaApagar()
{
  SIT = 0;
  PS = 1;
  SI1 = 0;
  SI2 = 0;
  SI3 = 0;
  SI4 = 0;
  SI5 = 0;
  SI6 = 0;
  SI7 = 0;
  SI8 = 0;
  SI9 = 0;
  SI10 = 0;
  SI11 = 0;
  SI12 = 0;
  SI13 = 0;
  SI14 = 0;
  SI15 = 0;
  SI16 = 0;
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void senhaEntrar()
{
  if (SI1 == S1 and SI2 == S2 and SI3 == S3 and SI4 == S4 and SI5 == S5 and SI6 == S6 and SI7 == S7 and SI8 == S8 and SI9 == S9 and SI10 == S10 and SI11 == S11 and SI12 == S12 and SI13 == S13 and SI14 == S14 and SI15 == S15 and SI16 == S16)
  {
    SI = true;
    lcdClear();
    menu1();
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("WRONG PASSWORD  ");
    delay(3000);
    senhaApagar();
  }
}


void right()
{
  if (IA == 1)
  {
    if (TM == 1)
    {
      lcdClear();
      tempMenu2();
    }
  }
  else if (IA == 3)
  {
    if (RM == 1)
    {
      lcdClear();
      rele2();
    }
  }
  else if (IA == 4)
  {
    if (CM == 1)
    {
      CM = 2;
      lcdClear();
      config2();
    }
    else if (CM == 2)
    {
      CM = 3;
      lcdClear();
      config3();
    }
  }
  else
  {
  MA = MA + 1;
  if (MA > MT)
  {
    MA = MA - 1;
  }
  else
  {
    if (MA == 1)
    {
      lcdClear();
      menu1();
    }
    else if (MA == 2)
    {
      lcdClear();
      menu2();
    }
    else if (MA == 3)
    {
      lcdClear();
      menu3();
    }
    else if (MA == 4)
    {
      lcdClear();
      menu4();
    }
    else if (MA == 5)
    {
      lcdClear();
      menu5();
    }
  }
 }
}

void left()
{
  if (IA == 3)
  {
    if (RM == 2)
    {
      lcdClear();
      rele1();
    }
  }
  else if (IA == 4)
  {
    if (CM == 1)
    {
            
    }
    else if (CM == 2)
    {
      CM = 1;
      lcdClear();
      config1();
    }
    else if (CM == 3)
    {
      CM = 2;
      lcdClear();
      config2();
    }
  }
  else
  {
  MA = MA - 1;
  if (MA < 1)
  {
    MA = MA + 1;
  }
  else
  {
    if (MA == 1)
    {
      lcdClear();
      menu1();
    }
    else if (MA == 2)
    {
      lcdClear();
      menu2();
    }
    else if (MA == 3)
    {
      lcdClear();
      menu3();
    }
    else if (MA == 4)
    {
      lcdClear();
      menu4();
    }
  }
 }
}

void up()
{
  if (IA == 1)
  {
    IA = 0;
    lcdClear();
    menu1();
  }
  else if (IA == 3)
  {
    IA = 0;
    lcdClear();
    menu3();
  }
  else if (IA == 4)
  {
    IA = 0;
    lcdClear();
    menu4();
  }
}

void down()
{
  if (IA == 3)
  {
    if (RM == 1)
    {
      if (RS1 == "OFF")
      {
        digitalWrite(12,LOW);
        RS1 = "ON";
        lcdClear();
        rele1();
      }
      else if (RS1 == "ON")
      {
        digitalWrite(12,HIGH);
        RS1 = "OFF"; 
        lcdClear();
        rele1();
      }
    }
    else if (RM == 2)
    {
      if (RS2 == "OFF")
      {
        digitalWrite(13,LOW);
        RS2 = "ON";
        lcdClear();
        rele2();
      }
      else if (RS2 == "ON")
      {
        digitalWrite(13,HIGH);
        RS2 = "OFF"; 
        lcdClear();
        rele2();
      }
    }
  }
  else if (IA == 4)
  {
    if (CM == 1)
    {
      if (C1 == "ON")
      {
        lcd.setBacklight(LOW);
        C1 = "OFF";
        lcdClear();
        config1();
      }
      else
      {
        lcd.setBacklight(HIGH);
        C1 = "ON";
        lcdClear();
        config1();
      }      
    }
    else if (CM == 2)
    {
      asm volatile ("  jmp 0");
    }
    else if (CM == 3)
    {
      if (TC == false)
      {
        lcdClear();
        timeConfigInicial();
         
      }
      else
      {
        setTimeConfig();
      }
      }
  }
  else
  {
    if (MA == 1)
    {
      lcdClear();
      IA = 1;
      tempMenu1();
    }
    else if (MA == 3)
    {
      lcdClear();
      IA = 3;
      rele1();
    }
    else if (MA == 4)
    {
      lcdClear();
      IA = 4;
      config1();
    }
  }
}


void ok()
{
  if (IA == 3)
  {
    if (RM == 1)
    {
      if (RS1 == "OFF")
      {
        digitalWrite(12,LOW);
        RS1 = "ON";
        lcdClear();
        rele1();
      }
      else if (RS1 == "ON")
      {
        digitalWrite(12,HIGH);
        RS1 = "OFF"; 
        lcdClear();
        rele1();
      }
    }
    else if (RM == 2)
    {
      if (RS2 == "OFF")
      {
        digitalWrite(13,LOW);
        RS2 = "ON";
        lcdClear();
        rele2();
      }
      else if (RS2 == "ON")
      {
        digitalWrite(13,HIGH);
        RS2 = "OFF"; 
        lcdClear();
        rele2();
      }
    }
  }
  else if (IA == 4)
  {
    if (CM == 1)
    {
      if (C1 == "ON")
      {
        lcd.setBacklight(LOW);
        C1 = "OFF";
        lcdClear();
        config1();
      }
      else
      {
        lcd.setBacklight(HIGH);
        C1 = "ON";
        lcdClear();
        config1();
      }      
    }
    else if (CM == 2)
    {
      asm volatile ("  jmp 0");
    }    
    }
  else
  {
    if (MA == 1)
    {
      lcdClear();
      IA = 1;
      tempMenu1();
    }
    else if (MA == 3)
    {
      lcdClear();
      IA = 3;
      rele1();
    }
    else if (MA == 4)
    {
      lcdClear();
      IA = 4;
      config1();
    }
  }
}

 void menu1()
{
  MA = 1; // menu atual
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURA");
  lcd.setCursor(0,1);
  lcd.print("Entrar?");
}

void menu2()
{
  MA = 2; // menu atual
  lcd.setCursor(0,0);
  lcd.print("Tempo ligado:");
  lcd.setCursor(0,1);
  lcd.print(millis() / 1000);
}

void menu3()
{
  MA = 3; // menu atual
  lcd.setCursor(0,0);
  lcd.print("RELES");
  lcd.setCursor(0,1);
  lcd.print("");
}

void menu4()
{
  MA = 4;
  lcd.setCursor(0,0);
  lcd.print("Configuracoes");
  lcd.setCursor(0,1);
  lcd.print("");
}

void menu5()
{
  MA = 5;
  prepararHorario();
  lcd.setCursor(0,0);
  lcd.print(TTP1);
  lcd.setCursor(0,1);
  lcd.print(TTP2);
}

void lcdClear()
{
     lcd.setCursor(0,0);
     lcd.print("                ");
     lcd.setCursor(0,1);
     lcd.print("                ");
}

void rele1()
{
  RM = 1;
  lcd.setCursor(0,0);
  lcd.print("RELE 1");
  lcd.setCursor(0,1);
  lcd.print(RS1);
}

void rele2()
{
  RM = 2;
  lcd.setCursor(0,0);
  lcd.print("RELE 2");
  lcd.setCursor(0,1);
  lcd.print(RS2);
}

void config1()
{
  CM = 1;
  lcd.setCursor(0,0);
  lcd.print("Backlight LCD");
  lcd.setCursor(0,1);
  lcd.print(C1);
}

void config2()
{
  CM = 2;
  lcd.setCursor(0,0);
  lcd.print("Reboot");
  lcd.setCursor(0,1);
  lcd.print("");
}

void config3()
{
  CM = 3;
  lcd.setCursor(0,0);
  lcd.print("Horario");
  lcd.setCursor(0,1);
  lcd.print("");
}

void tempMenu1() //mede temperatura e umidade
{
  TM = 1;
  int h = dht.readHumidity();
  int t = dht.readTemperature();

if (isnan(t) || isnan(h)) 
  {
    lcd.setCursor(0,0);
    lcd.print("Erro de");
    lcd.setCursor(0,1);
    lcd.print("leitura");
  } 
  else 
  {
    lcd.setCursor(0,0);
    lcd.print("Temp:");
    lcd.setCursor(5,0);
    lcd.print(t);
    lcd.setCursor(7,0);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Umid:");
    lcd.setCursor(5,1);
    lcd.print(h);
    lcd.setCursor(7,1);
    lcd.print("%");
    if (h > umidMax)
    {
      umidMax = h;
    }
    if (h < umidMin)
    {
      umidMin = h;
    }
    if (t > tempMax)
    {
      tempMax = t;
    }
    if (t < tempMin)
    {
      tempMin = t;
    }
  }
  
}

void tempMenu2()
{
  TM = 2;
  lcd.setCursor(0,0);
  lcd.print("TEMP:MIN" and tempMin and " MAX" and tempMax);
 // lcd.setCursor(8,0);
  lcd.setCursor(0,1);
  lcd.print("UMID:MIN" and umidMin and " MAX" and umidMax);
}

void timeConfigInicial()
{
  lcdClear();
  lcd.setCursor(0,0);
  lcd.print(" /  /  /    ");
  lcd.setCursor(0,1);
  lcd.print("  :  :  ");
  TC = true;
}

void timeConfig()
{
  if (TCP == 1)
  {
    DWI = numeroRecebido;
    lcd.setCursor(0,0);
    lcd.print(numeroRecebido);
    TCP = 2;
    numeroRecebido = "";
  }
  else if (TCP == 2)
  {
    DI1 = numeroRecebido;
    lcd.setCursor(2,0);
    lcd.print(numeroRecebido);
    TCP = 3;
    numeroRecebido = "";
  }
  else if (TCP == 3)
  {
    DI2 = numeroRecebido;
    lcd.setCursor(3,0);
    lcd.print(numeroRecebido);
    TCP = 4;
    numeroRecebido = "";
  }
  else if (TCP == 4)
  {
    MI1 = numeroRecebido;
    lcd.setCursor(5,0);
    lcd.print(numeroRecebido);
    TCP = 5;
    numeroRecebido = "";
  }
  else if (TCP == 5)
  {
    MI2 = numeroRecebido;
    lcd.setCursor(6,0);
    lcd.print(numeroRecebido);
    TCP = 6;
    numeroRecebido = "";
  }
  else if (TCP == 6)
  {
    YI1 = numeroRecebido;
    lcd.setCursor(8,0);
    lcd.print(numeroRecebido);
    TCP = 7;
    numeroRecebido = "";
  }
  else if (TCP == 7)
  {
    YI2 = numeroRecebido;
    lcd.setCursor(9,0);
    lcd.print(numeroRecebido);
    TCP = 8;
    numeroRecebido = "";
  }
  else if (TCP == 8)
  {
    YI3 = numeroRecebido;
    lcd.setCursor(10,0);
    lcd.print(numeroRecebido);
    TCP = 9;
    numeroRecebido = "";
  }
  else if (TCP == 9)
  {
    YI4 = numeroRecebido;
    lcd.setCursor(11,0);
    lcd.print(numeroRecebido);
    TCP = 10;
    numeroRecebido = "";
  }
  else if (TCP == 10)
  {
    HI1 = numeroRecebido;
    lcd.setCursor(0,1);
    lcd.print(numeroRecebido);
    TCP = 11;
    numeroRecebido = "";
  }
  else if (TCP == 11)
  {
    HI2 = numeroRecebido;
    lcd.setCursor(1,1);
    lcd.print(numeroRecebido);
    TCP = 12;
    numeroRecebido = "";
  }
  else if (TCP == 12)
  {
    MiI1 = numeroRecebido;
    lcd.setCursor(3,1);
    lcd.print(numeroRecebido);
    TCP = 13;
    numeroRecebido = "";
  }
  else if (TCP == 13)
  {
    MiI2 = numeroRecebido;
    lcd.setCursor(4,1);
    lcd.print(numeroRecebido);
    TCP = 14;
    numeroRecebido = "";
  }
  else if (TCP == 14)
  {
    SeI1 = numeroRecebido;
    lcd.setCursor(6,1);
    lcd.print(numeroRecebido);
    TCP = 15;
    numeroRecebido = "";
  }
  else if (TCP == 15)
  {
    SeI1 = numeroRecebido;
    lcd.setCursor(7,1);
    lcd.print(numeroRecebido);
    TCP = 16;
    numeroRecebido = "";
  }
  else if (TCP == 16)
  {
    
  }
}

void setTimeConfig()
{
  SeI1 = SeI1 * 10;
  SeI = SeI1 + SeI2;
  MiI1 = MiI1 * 10;
  MiI = MiI1 + MiI2;
  HI1 = HI1 * 10;
  HI = HI1 + HI2;
  DI1 = DI1 * 10;
  DI = DI1 + DI2;
  MI1 = MI1 * 10;
  MI = MI1 + MI2;
  YI1 = YI1 * 1000;
  YI2 = YI2 * 100;
  YI3 = YI3 * 10;
  YI = YI1 + YI2 + YI3 + YI4;
  Serial.println(SI1);
  Serial.println(SI2);
  Serial.println(MiI1);
  Serial.println(MiI2);
  Serial.println(HI1);
  Serial.println(HI2);
  //Serial.println(YI);
 // SI = SI1 + SI2  
  //myRTC.setDS1302Time(SI1 and SI2, MiI1 and MiI2, HI1 and HI2, DWI, DI1 and DI2, MI1 and MI2, YI1 and YI2 and YI3 and YI4);
  myRTC.setDS1302Time(SeI, MiI, HI, DWI, DI, MI, YI);
  
  TC = false;
  TCP = 1;
  lcdClear();
  config3();
}

void prepararHorario()//MD = menos que dez  ZAM = Zero a mais
{
  String horaZAM; 
  String minutoZAM;
  String segundoZAM;
  String dia;
  String mes;
  String ano;
  String hora;
  String minuto;
  String segundo;
  boolean horaMD = false;
  boolean minutoMD = false;
  boolean segundoMD = false;
  myRTC.updateTime();
  int diaDaSemanaa = myRTC.dayofweek;
  String diaDaSemana;
  int diaint = myRTC.dayofmonth;
  int mesint = myRTC.month;
  int anoint = myRTC.year;
  if (myRTC.hours < 10)
  {
    horaMD = true;
  }
  if (myRTC.minutes < 10)
  {
    minutoMD = true;
  }
  if (myRTC.seconds < 10)
  {
    segundoMD = true;
  }
  int horaint = myRTC.hours;
  int minutoint = myRTC.minutes;
  int segundoint = myRTC.seconds;
  switch (diaDaSemanaa)
  {
    case 1:
    diaDaSemana = "Dom";
    break;
    case 2:
    diaDaSemana = "Seg";
    break;
    case 3:
    diaDaSemana = "Ter";
    break;
    case 4:
    diaDaSemana = "Qua";
    break;
    case 5:
    diaDaSemana = "Qui";
    break;
    case 6:
    diaDaSemana = "Sex";
    break;
    case 7:
    diaDaSemana = "Sab";
    break;    
  }
  if (horaMD == true)
  {
    horaZAM = "0";
  }
  else
  {
    horaZAM = "";
  }
  if (minutoMD == true)
  {
    minutoZAM = "0";
  }
  else
  {
    minutoZAM = "";
  }
  if (segundoMD == true)
  {
    segundoZAM = "0";
  }
  else
  {
    segundoZAM = "";
  }
  dia = diaint;
  mes = mesint;
  ano = anoint;
  hora = horaint;
  minuto = minutoint;
  segundo = segundoint;  
  
  TTP1 = horaZAM + hora + ":" + minutoZAM + minuto + ":" + segundoZAM + segundo;
  TTP2 = dia + "/" + mes + "/" + ano + "   " + diaDaSemana;
}

/*void leituraEEPROMSenha()
{
  S1 = EEPROM.read(0);
  S2 = EEPROM.read(1);
  S3 = EEPROM.read(2);
  S4 = EEPROM.read(3);
  S5 = EEPROM.read(4);
  S6 = EEPROM.read(5);
  S7 = EEPROM.read(6);
  S8 = EEPROM.read(7);
  S9 = EEPROM.read(8);
  S10 = EEPROM.read(9);
  S11 = EEPROM.read(10);
  S12 = EEPROM.read(11);
  S13 = EEPROM.read(12);
  S14 = EEPROM.read(13);
  S15 = EEPROM.read(14);
  S16 = EEPROM.read(15);
}

void gravacaoEEPROMSenha()
{
  
}*/

