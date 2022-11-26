#include <Servo.h>
#include <arduino.h>

#define PINO1 2
#define PINO2 3
#define PINO3 4

Servo servo1;
Servo servo2;
Servo servo3;

int val;

int menuselect;
int zero[5][2] = {{0, 1}, {1, 1}, {1, -1}, {0, -1}, {0, 1}};
int one[2][2]= {{0, 1}, {0, -1}};
int two[6][2] = {{0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, -1}, {1, -1}};
int three[7][2] = {{0, 1}, {1, 1}, {1, 0}, {0, 0}, {1, 0}, {1, -1}, {0, -1}};
int four[5][2] = {{0, 1}, {0, 0}, {1, 0}, {1, 1}, {1, -1}};
int five[6][2] = {{1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, -1}, {0, -1}};
int six[7][2] = {{1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, -1}, {0, -1}, {0, 0}};
int seven[3][2] = {{0, 1}, {1, 1}, {1, -1}};
int eight[8][2] = {{0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, 1}, {0, -1}, {1, -1}, {1, 0}};
int nine[6][2] = {{1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, -1}, {0, -1}};

float deltax= 1, xf= .5, yf= .5;

void levantaLapis();
void moveTo(float offsetx, float xf, float yf, float x, float y);

void Menu(){
  Serial.println(F("Please select a number from the options available"));
  Serial.println(F(" "));
  Serial.println(F("Main Menu"));
  Serial.println(F("---------"));
  Serial.println(F("1. change x"));
  Serial.println(F("2. change y"));
  Serial.println(F("3. print go"));
  Serial.println(F("4. print angle"));
  Serial.println(F("5. go"));
  Serial.println(F("6. clock"));
  Serial.println(F("7. away"));
  Serial.println(F("8. near"));
}

void setup() {
  servo1.attach(PINO1);
  servo2.attach(PINO2);
  servo3.attach(PINO3);

  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);

  digitalWrite(22, LOW);
  digitalWrite(24, LOW);

  levantaLapis();
  moveTo(deltax, xf, yf, 0,0);
  //Inicializar monitor serial
  Serial.begin(9600);
  Menu();
  goAway();
}

float l1= 3;
float l2= 2;
float l1s = pow(l1,2);
float l2s = pow(l2,2);

int relogio[4] = {2, 1, 2, 9}; //Iniciando relógio (pq está inicializando com esses valores?

void incrementaHoraPorMinuto(){
  if(relogio[3] == 9){ //Se o ultimo digito for 9
    relogio[3]= 0; // ele volta pra 0
    if(relogio[2] == 5){ // e se o terceiro digito for 5
      relogio[2] = 0; // ele volta pro 0 
      //dessa forma ele está completando 60 minutos
      if(relogio[0]<2 && relogio[1]==9){ //se a hora for 09 ou 19
        relogio[1]= 0; // o segundo digito vai ser 0
        relogio[0]++; // e o primeiro vai aumentar mais 1
      }
      else if(relogio[0] == 2 && relogio[1] == 3){ // se for 23 horas
        relogio[0]= 0;
        relogio[1]= 0; // ele passa pras 00 horas
      }
      else{// se não for nenhum desses casos o segundo digito só aumenta mais um
        relogio[1]++;
      }
    }//segundo if
    else{ //se não for 5 ele só adiciona mais 1 (ex: 12:46) o 4 não é 5 então só incrementa 1
      relogio[2]++;
    }
  }//primeiro if
  else{ //Se o ultimo digito não for 9 então ele também só incrementa mais 1
    relogio[3]++; 
  }
}

void goAway(){
  digitalWrite(24, LOW);
  delay(100);
  digitalWrite(22, HIGH);
  delay(15000);
  digitalWrite(22, LOW);
}

void perto(){
  digitalWrite(22,LOW);
  delay(100);
  digitalWrite(24, HIGH);
  delay(15000);
  digitalWrite(24, LOW);
}

void levantaLapis(){
  servo3.write(0);
}

void abaixaLapis(){
  servo3.write(40);
}

void plotaSegmento(int steps, float offsetx, float xf, float yf, float x1, float y1, float x2, float y2){

    // Calculando a variação de x e y
    float deltax = x2 - x1;
    float deltay = y2 - y1;
    float nx, ny;

    deltax= deltax/ steps;
    deltay= deltay/ steps;
    for(int i=0; i<steps; i++){
        nx= x1 + (deltax * i);
        ny= y1 + (deltay * i);
        moveTo(offsetx, xf, yf, nx, ny); // movendo para as coordenadas passadas a cada 'steps'
    }
}

void printaRelogio(){
  perto();
  goAway();
  for(int i=0; i<4; i++){
    Serial.println("digito");
    int d= relogio[i];
    int (*n)[2]; //ponteiro
    int l;
    Serial.println(d);
    //O switch case é para atribuir a hora ao ponteiro e determinar o tamanho dele
    switch (d){
      case 0:
          n= zero;
          l = sizeof(zero) / sizeof(zero[0]);
          break;
      case 1:
          n= one;
          l = sizeof(one) / sizeof(one[0]);
          break;
      case 2:
          n= two;
          l = sizeof(two) / sizeof(two[0]);
          break;
      case 3:
          n= three;
          l = sizeof(three) / sizeof(three[0]);
          break;
      case 4:
          n= four;
          l = sizeof(four) / sizeof(four[0]);
          break;
      case 5:
          n= five;
          l = sizeof(five) / sizeof(five[0]);
          break;
      case 6:
          n= six;
          l = sizeof(six) / sizeof(six[0]);
          break;
      case 7:
          n= seven;
          l = sizeof(seven) / sizeof(seven[0]);
          break;
      case 8:
          n= eight;
          l = sizeof(eight) / sizeof(eight[0]);
          break;
      case 9:
          n= nine;
          l = sizeof(nine) / sizeof(nine[0]);
          break;
       }
       
     Serial.println(l);
     levantaLapis();
     delay(500);
     float ayf = yf * (1 + 0.1* i);
     for (int j=0; j < l; j++){
        Serial.print(" segment ");
        Serial.println(j);
        if(j==0){
            moveTo(deltax + (i+1), xf, ayf, n[j][0], n[j][1]);
            delay(500);
            abaixaLapis();
            delay(500);
        }
        else{
            plotaSegmento(30, deltax + (i+1), xf, ayf, n[j-1][0], n[j-1][1], n[j][0], n[j][1]);
        }
     }
     Serial.println("done");
  }
  levantaLapis();
  delay(500);
  moveTo(deltax, xf, yf, 0, 0);
}

void convertToAngle(float x, float y, float &a1, float &a2){
  float rs= pow(x,2) + pow(y,2); // r2 = a2 + b2 
  float gamma= atan(y/x); //arctangente de x e y
  float r = sqrt(rs);
  float sa1= acos((l2s - l1s - rs) / (-2* l1 * r));
  float sa2= acos((rs - l1s - l2s) / (-2* l1 * l2));
  a1= (sa1 + gamma) * RAD_TO_DEG;
  a2= sa2 * RAD_TO_DEG;
}

void go(float a1, float a2){ // Coloca os servos nas posições passadas
  servo1.write(a1); 
  servo2.write(180 - a2);
  delay(20);
}

void moveTo(float offsetx, float xf, float yf, float x, float y){
  float a1, a2;
  convertToAngle(offsetx + (x * xf), y * yf, a1, a2);
  Serial.println(a1);
  Serial.println(a2);
  go(a1, a2);
}

float gx = 0;
float gy = 0;
unsigned long long lastIncrement = millis();
unsigned const long DEFAULT_PERIOD = 60000;
unsigned long period= DEFAULT_PERIOD;
long adjust = 0;

printaRelogio();

void loop() {
  unsigned long delta= millis() - lastIncrement;
  if(delta> period){
    lastIncrement = millis();
    adjust -= (delta- DEFAULT_PERIOD);
    period = DEFAULT_PERIOD + adjust;
    incrementaHoraPorMinuto();
    printaRelogio();
  }
  if(Serial.avaliable()){ //Checa se algo foi mandado pelo USB
    char val= Serial.read();
    // Opção 1 e 2 é para mudar o x e o y respectivamente
    if(val == '1'){
        while (!Serial.avaliable()){}
        gx = Serial.parseFloat();
    }
    if(val == '2'){
        while (!Serial.avaliable()){}
        gy = Serial.parseFloat();
    }
    // vai printar gx e gy no monitor serial
    if(val== '3'){
      Serial.println("print");
      Serial.println(gx);
      Serial.println(gy);
    }
    // printar angulo 
    if(val == '4'){
        float a1, a2;
        convertToAngle(deltax + (gx* xf), gy * yf, a1, a2);
        Serial.println("print 2");
        Serial.println(deltax + (gx * xf));
        Serial.println(gy * yf);
        Serial.println(a1);
        Serial.println(a2);
    }
    // vai para o lugar de gx e gy
    if(val == '5'){
        moveTo(deltax, xf, yf, gx, gy);
    }
    // relogio novamente
    if(val == '6'){
        printaRelogio();
    }
    // goAway e perto é para controlar as led
    if(val == '7'){
        goAway();
    }
    if(val == '8'){
        perto();
    }
  }
}