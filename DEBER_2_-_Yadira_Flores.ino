/* TAREA_1 Realizar 6 Juegos de luces con 10 leds y 3 swtch.
 * juego 1: 000 - ninguna accion  
 * juego 1: 010 - solo encienden pares
 * juego 1: 011 - solo encienden impares
 * juego 1: 101 - aleatorio(random)
 * juego 1: 110 - secuencia (10,1)(9,2)(8,3)(7,4)(5,6)
 * juego 1: 111 - juego a su eleccion, solo 5 veces
 * 
 * Yadira Flores
 * 30 de octbre del 2016
 */

//varibles de tipo entero para los 10 leds de acuerdo al pin
int led_1=13;
int led_2=12;
int led_3=11;
int led_4=10;
int led_5=9;
int led_6=8;
int led_7=7;
int led_8=6;
int led_9=5;
int led_10=4;
//varible de tipo entero para switch 1,2,3
int sw_1=1;
int sw_2=2;
int sw_3=3;
int contador = 0; //variable de tipo entero cont
int leds_p [5]={led_2,led_4,led_6,led_8,led_10}; //vector led pares
int leds_i [5]={led_1,led_3,led_5,led_7,led_9}; //vector led impares
//vectores juego 5 - de extremos a medios
int leds [5]={led_10,led_9,led_8,led_7,led_6};
int ledi [5]={led_1,led_2,led_3,led_4,led_5}; 
//vector juego 6           
int led [10]={led_1,led_2,led_3,led_4,led_5,led_6,led_7,led_8,led_9,led_10};
int cont = 0;

void setup() {
  //pines de salida para los 10 leds 
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  pinMode(led_5,OUTPUT);
  pinMode(led_6,OUTPUT);
  pinMode(led_7,OUTPUT);
  pinMode(led_8,OUTPUT);
  pinMode(led_9,OUTPUT);
  pinMode(led_10,OUTPUT);
  pinMode(sw_1,INPUT);
  pinMode(sw_2,INPUT);
  pinMode(sw_3,INPUT);

}

void loop() {
  
  //--------------- juego1: 000 - no enciende ningun led-----------------------
  if(digitalRead(sw_1)==LOW&&digitalRead(sw_2)==LOW&&digitalRead(sw_3)==LOW)    //condicion switch juego 1
  {
    digitalWrite(led[contador],LOW);                                            //apaga leds del vector led 
    delay(200);                                                                 //retardo
    }
  
  //--------------- juego2: 010 - solo pares encienden-------------------------
  if(digitalRead(sw_1)==LOW&&digitalRead(sw_2)==HIGH&&digitalRead(sw_3)==LOW)   //condicion switch juego 2
  {
    for(;contador<5;contador++){                                               //contador juego
    digitalWrite(leds_p[contador],HIGH);                                        //enciende leds del vector leds_p
    delay(200);                                                                 //retardo
    digitalWrite(leds_p[contador],LOW);                                         //apaga leds del vector leds_p
    delay(200);                                                                 //retardo
    }
    contador=0;                                                                 //reinicia contador
   } 

   //-------------- juego3: 011 - solo impares encienden-------------------------
   if(digitalRead(sw_1)==LOW&&digitalRead(sw_2)==HIGH&&digitalRead(sw_3)==HIGH) //condicion switch juego 3
   {
    for(;contador<5;contador++){                                               //contador juego
    digitalWrite(leds_i[contador],HIGH);                                        //enciende leds del vector leds_i
    delay(200);                                                                 //retardo
    digitalWrite(leds_i[contador],LOW);                                         //apaga leds del vector leds_i
    delay(200);                                                                 //retardo
    }
    contador=0;                                                                 //reinicia contador
   }

   //-------------- juego4: 101 - de manera aleatoria(ramdom)--------------------
   if(digitalRead(sw_1)==HIGH&&digitalRead(sw_2)==LOW&&digitalRead(sw_3)==HIGH) //condicion switch juego 4
   {
    int rnd = random(11);
    digitalWrite (rnd, HIGH);                                                   //enciende leds en aleatorio 
    delay (150);                                                                //retardo
    digitalWrite (rnd, LOW);                                                    //enciende leds en aleatorio
    delay (150);                                                                //retardo
    }
    
   //-------------- juego5: 110 - secuencia (10,1)(9,2)(8,3)....(5,6)------------
   if(digitalRead(sw_1)==HIGH&&digitalRead(sw_2)==HIGH&&digitalRead(sw_3)==LOW) //condicion switch juego 5
   {
    for(;contador<5;contador++){                                               //contador juego
    digitalWrite(leds[contador],HIGH);                                          //enciende leds del vector leds
    digitalWrite(ledi[contador],HIGH);                                          //enciende leds del vector ledi
    delay(200);                                                                 //retardo
    digitalWrite(leds[contador],LOW);                                           //apaga leds del vector leds
    digitalWrite(ledi[contador],LOW);                                           //apaga leds del vector ledi
    delay(200);                                                                 //retardo
    }
    contador = 0;                                                               //reinicia contador
    }
       
   //-------------- juego6: 111 - secuencia (1,2,3,4,5,6,7,8,9,10) 5 veces------------
   if(digitalRead(sw_1)==HIGH&&digitalRead(sw_2)==HIGH&&digitalRead(sw_3)==HIGH)  //condicion switch juego 6
   {
    for(;cont<5;cont++){                                                          //condicion limite del juego en 5 veces
      for(;contador<10;contador++){                                               //contador juego
        digitalWrite(led[contador],HIGH);                                         //enciende leds del vector led
        delay(200);                                                               //retardo
        digitalWrite(led[contador],LOW);                                          //apaga leds del vector leds
        delay(200);                                                               //retardo
        }
        contador=0;                                                               //reinicia contador
     }
   } 
}  
