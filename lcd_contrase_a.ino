/*
 * Nombre: Yadira Flores
 * Tarea programa mensaje
 */

#include <LiquidCrystal.h>  //libreria necesaria para utilizar LCD

LiquidCrystal lcd (12,11,5,4,3,2);

String m_1 = "Contraseña";
String m_2 = "Contraseña Aceptada";
String m_3 = "Contraseña Denegada";
String contr;

void setup() {
    Serial.begin(9600);
    lcd.begin(16,2);

}

void loop() {
  if (Serial.available()>0){     //dato por leer
    contr=Serial.readString();   //Lee dato ingresado por teclado
    Serial.println(contr);       //Imprime en terminal mensaje
    lcd.clear();
    if(contr=="9218A"){         //Compara el texto ingresado con la contraseña establecida
      lcd.setCursor(0, 0);      //Ubica cursor lcd posicion 0,0
      lcd.print(m_2);           //Imprime m_2
      lcd.setCursor(0, 1);      //Ubica cursor lcd posicion 0,1
      lcd.print(m_1);           //Imprime m_1
    }
    else{                       //en caso de contraseña incorrecta imprime
      lcd.setCursor(0, 0);       //Ubica cursor lcd posicion 0,0
      lcd.print(m_3);           //Imprime m_3
      lcd.setCursor(0, 1);       //Ubica cursor lcd posicion 0,1
      lcd.print(m_1);            //Imprime m_1
    }
  }  
 }
