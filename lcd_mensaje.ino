/*
 * Nombre: Yadira Flores
 * Tarea programa contraseña
 */
 
#include <LiquidCrystal.h>           //libreria necesaria para utilizar LCD
LiquidCrystal lcd (12,11,5,4,3,2);
char mensaje [4];
String m_ent;
int cont=0; 

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  
}

void loop() {
  if (Serial.available()>0){
    m_ent=Serial.readString();                    // Lee mensaje que se ingresado mediante teclado
    m_ent.toCharArray(mensaje,m_ent.length()+1);  // Convierte el mensaje ingresado en un vector
    Serial.println(m_ent);                        // Imprime en terminal el mensaje
  }  
    lcd.clear();                                  // Borra la informacion de LCD
    for(;cont<m_ent.length()+1;cont++){           // Contador desde cero hasta el numero de caracteres que tiene la palabra
      lcd.setCursor(cont, 0);                     // Ubica el cursor en la posicion 0,0
      lcd.print(mensaje[cont]);                   // Imprime el mensaje ingrasado por teclado
      delay(300);
    }    
    cont=0;                                       //Reinicia el contador
    
}

  
