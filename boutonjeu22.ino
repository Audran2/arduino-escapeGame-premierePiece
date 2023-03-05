// Definition pin des LED
#define LED_PIN 6
#define LED_PIN2 7
#define LED_PIN3 8
#define LED_PIN4 9
#define LED_PIN5 10
#define LED_PIN6 11
#define LED_PIN7 12
#define LED_PIN8 13
// Definition pin des boutons
#define BUTTON_PIN 5
#define BUTTON_PIN2 4
#define BUTTON_PIN3 3
#define BUTTON_PIN4 2
// Definition pin des potentiometre
int analogPin = 0;
int val_potentio1 = 0; 

int analogPin2 = 1;
int val_potentio2 = 0; 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
  pinMode(LED_PIN5, OUTPUT);
  pinMode(LED_PIN6, OUTPUT);
  pinMode(LED_PIN7, OUTPUT);
  pinMode(LED_PIN8, OUTPUT);
  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUTTON_PIN2, INPUT);
  pinMode(BUTTON_PIN3, INPUT);
  pinMode(BUTTON_PIN4, INPUT);
  
  Serial.begin(9600);
 
}

void loop() {

  // Lecture de nos PIN Analog
  val_potentio1 = analogRead(analogPin);  //lecture de la valeur analogue (potentiomètre)1
  val_potentio2 = analogRead(analogPin2);  //lecture de la valeur analogue (potentiomètre)2
  
  // On les mets tous en LOW pour éviter une condition qui bug ou ne se desactive pas correctement
  
 if ((val_potentio1 >= -0) && (val_potentio1 <=50)) {
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW);
  digitalWrite(LED_PIN5, LOW);
  digitalWrite(LED_PIN6, LOW);
  digitalWrite(LED_PIN7, LOW);
  digitalWrite(LED_PIN8, LOW);
  digitalWrite(LED_PIN, LOW);
  }
  if ((val_potentio2 >= -0) && (val_potentio2 <=50)) {
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW);
  digitalWrite(LED_PIN5, LOW);
  digitalWrite(LED_PIN6, LOW);
  digitalWrite(LED_PIN7, LOW);
  digitalWrite(LED_PIN8, LOW);
  digitalWrite(LED_PIN, LOW);
  }
  // Solution final
   if ((val_potentio1 >= 230) && (val_potentio1 <=330) && (val_potentio2 >= 900) && (val_potentio2 <=1040) && (digitalRead(BUTTON_PIN4) == HIGH) && (digitalRead(BUTTON_PIN3) == HIGH) ) {
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN4, HIGH);
  digitalWrite(LED_PIN5, HIGH);
  digitalWrite(LED_PIN6, HIGH);
  digitalWrite(LED_PIN7, HIGH);
  digitalWrite(LED_PIN8, HIGH);
  digitalWrite(LED_PIN, HIGH);
  }
 
  // Condition potentiometre 1
  // Position EST , 0 deg
  if ((val_potentio1 >= 0) && (val_potentio1 <=20)) {
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN6, LOW);
  }
  // Position NORD 90 deg
  else if ( (val_potentio1 >= 230) && (val_potentio1 <=330))
  {
  digitalWrite(LED_PIN2, HIGH); 
  }
  // Position OUEST 180 deg
  else if ( (val_potentio1 >= 540) && (val_potentio1 <=640))
  {
  digitalWrite(LED_PIN3, HIGH);  
  }
  // Position SUD 270 deg
  else if ( (val_potentio1 >= 850) && (val_potentio1 <=1040))
  {
  digitalWrite(LED_PIN6, HIGH);  
  }
  
  // Condition potentiometre 2
  if ((val_potentio2 >= 0) && (val_potentio2 <=10)) {
  digitalWrite(LED_PIN5, LOW);
  digitalWrite(LED_PIN6, LOW);
  digitalWrite(LED_PIN2, LOW);
  }
  // Position NORD
  else if ( (val_potentio2 >= 230) && (val_potentio2 <=330))
  {
  digitalWrite(LED_PIN5, HIGH); 

  }
  // Position OUEST
  else if ( (val_potentio2 >= 540) && (val_potentio2 <=640))
  {
  digitalWrite(LED_PIN6, HIGH);  

  }
  // Position SUD
  else if ( (val_potentio2 >= 900) && (val_potentio2 <=1040))
  {
  digitalWrite(LED_PIN2, HIGH); 

  }
  // Condition 1 : bouton
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);   
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);

  }

   // Condition 2 : bouton
  if (digitalRead(BUTTON_PIN2) == HIGH) {
    digitalWrite(LED_PIN6, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN4, LOW);   
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);

  }

 // Condition 3 : bouton
   if (digitalRead(BUTTON_PIN3) == HIGH) {
    digitalWrite(LED_PIN5, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);   
    digitalWrite(LED_PIN4, LOW);
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);

  }

 // Condition 4 : bouton
  if (digitalRead(BUTTON_PIN4) == HIGH) {
    digitalWrite(LED_PIN6, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);   
    digitalWrite(LED_PIN4, LOW);
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);

  }

//--------------------------------------1----------------------------------------//
  // Condition 1 : Les deux premiers boutons en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    digitalWrite(LED_PIN6, HIGH);
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);

  }


  // Condition 2 : Le premier et troisième en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN3) == HIGH) {
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    digitalWrite(LED_PIN8, HIGH);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);   
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN7, LOW);

  }


   // Condition 3 : Le premier et quatrième en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN4) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN7, HIGH);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);   
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN8, LOW);

  }
 
  //------------------------------------2------------------------------------------//
    // Condition 1 : Le deuxième et troisème en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN3) == HIGH) {
    digitalWrite(LED_PIN4, HIGH);
    digitalWrite(LED_PIN7, HIGH);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);   
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN8, LOW);
  }
 
    // Condition 2 : Le deuxième et quatrième en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN4) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN7, HIGH);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);   
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN5, LOW);
    digitalWrite(LED_PIN8, LOW);

  }

    //------------------------------------3------------------------------------------//
     // Condition 1 : Le troisème et quatrième en même temps
  if (digitalRead(BUTTON_PIN3) == HIGH && digitalRead(BUTTON_PIN4) == HIGH) {
    digitalWrite(LED_PIN5, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW); 
    digitalWrite(LED_PIN4, LOW);   
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);
  }

  // ------------Fin des conditions de deux boutons en même temps----------------//
  //---------------------------------------1-1------------------------------------//
   // Condition 1 : Le premier et deuxième et troisème en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == HIGH && digitalRead(BUTTON_PIN3) == HIGH) {
    digitalWrite(LED_PIN5, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW); 
    digitalWrite(LED_PIN6, LOW);   
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);
  
  }

    // Condition 2 : Le premier et deuxième et quatrième en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == HIGH && digitalRead(BUTTON_PIN4) == HIGH) {
    digitalWrite(LED_PIN8, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW); 
    digitalWrite(LED_PIN5, LOW);   
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN7, LOW); 
    digitalWrite(LED_PIN, LOW); 

  }
 
   // Condition 3 : Le deuxième et troisième et quatrième en même temps
  if (digitalRead(BUTTON_PIN2) == HIGH && digitalRead(BUTTON_PIN3) == HIGH && digitalRead(BUTTON_PIN4) == HIGH) {
    digitalWrite(LED_PIN7, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN4, LOW); 
    digitalWrite(LED_PIN5, LOW);   
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN8, LOW); 
    digitalWrite(LED_PIN3, LOW); 
  
  }

  // Condition 3 : Le premier et troisième et quatrième en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN3) == HIGH && digitalRead(BUTTON_PIN4) == HIGH) {
    digitalWrite(LED_PIN4, HIGH);
    digitalWrite(LED_PIN5, HIGH);
    
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW); 
    digitalWrite(LED_PIN3, LOW);   
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN8, LOW); 
    digitalWrite(LED_PIN7, LOW); 
  }

  //----------------------1:2---------------------//
   // Condition 3 : Le premier et troisième et quatrième en même temps
  if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN3) == HIGH && digitalRead(BUTTON_PIN4) == HIGH && digitalRead(BUTTON_PIN2) == HIGH) {
    digitalWrite(LED_PIN4, HIGH);
    digitalWrite(LED_PIN5, HIGH);
    digitalWrite(LED_PIN7, HIGH);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW); 
    digitalWrite(LED_PIN3, LOW);   
    digitalWrite(LED_PIN6, LOW);
    digitalWrite(LED_PIN8, LOW);   
  }

}
