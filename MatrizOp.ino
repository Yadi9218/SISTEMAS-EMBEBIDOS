/*
   Nombre: Yadira Flores
   Tarea Matriz Operaciones
   Realizar los siguientes metodos que seran impresos por cx serial:
   -La suma de cada fila
   -La multiplicacion de cada columna
   -El promedio de las sumas de todas las columnas (solo imprime un valor)
*/

#include "MatrizOp.h"        //libreria creada para la matriz, llama datos dentro del programa 
int sw_1 = 1;
int sw_2 = 2;
int sw_3 = 3;
int i = 0;                   //filas
int j = 0;                   //columnas
int s;                       //suma
int m;                       //multiplicacion
float p;                     //promedio
float sump = 0;              //suma promedio

void setup() {

  Serial.begin(9600);

}

void loop() {

  //-----------------La Suma de cada fila-----------------

  Serial.println ("------- Programa MatrizOp -------");
  Serial.println ("");
  Serial.println ("Suma por cada fila de la matriz de 20x3:");
  Serial.println ("");
  for (i = 0; i < 20; i++) {    //ciclo for control de filas
    while (j <= 2) {            //condicion control columnas
      s = s + matriz[i][j];     //suma de cada fila
      delay(300);               //tiempo de retardo
      j++;
    }
    Serial.print("La suma de la fila es: ");         //imprime Mensaje
    Serial.println(s);                               //imprime Suma
    s = 0;
    j = 0;
  }

  //-----------------La multiplicacion de cada columna-----------------

  Serial.println ("");
  Serial.println ("Multiplicacion por cada columna de la matriz de 20x3:");
  Serial.println ("");
  long int m;
  for (i = 0; i <= 2; i++) {      //ciclo for control filas
    for (j = 0; j <= 19; j++) {   //ciclo for control columnas
      m = m * matriz[j][i];       //multiplicacion de cada columna
    }
    Serial.print( "La multiplicacion de la columna: " );          //imprime mensaje
    Serial.println(m);                                            //imprime multiplicacion de cada columna
    delay(300);                                                   //tiempo de retardo
    m = 1;
    j = 0;
  }

  //-----------------El promedio de las sumas de todas las columnas-----------------

  if (i <= 20) {
    Serial.println ("");
    Serial.println ("El promedio de las sumas de todas las columnas: ");        //imprime mensaje
    Serial.println ("");
    for (i = 0; i < 3; i++) {               //ciclo for control filas
      for (j = 0; j < 20; j++) {            //ciclo for control columnas
        s = s + matriz[j][i];
      }
      j = 0;
    }
    if (s != 0) {
      p = s / i;                           //promedio suma columnas
      Serial.println(p);                   //imprime promedio
      delay(150);
      s = 0;
      i = 21;
      Serial.println ("-------Fin del Programa-------");
    }
  }
}
