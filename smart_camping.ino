const int pinDetecteur_1 = 5;    // Détecteur PIR  pin 1
const int pinDetecteur_2 = 6;    // Détecteur PIR  pin 2
const int pinDetecteur_3 = 7;    // Détecteur PIR  pin 3
const int buzzerPin = 12;     // Buzzer pin
const int bouttonPin = 8;      // boutton pin
const int safeLedPin = 2;     // LED verte indiquant l'état de sécurité
const int dangerLedPin = 3;   // LED rouge indiquant l'état de sécurité

int DetecteurVal_1 = 0;  // Detecteur 1 statue
int DetecteurVal_2 = 0;  // Detecteur 2 statue
int DetecteurVal_3 = 0;  // Detecteur 3 statue
int bouttonVal = 0;    // Boutton status
boolean alarmActive = false;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pinDetecteur_1, INPUT);
  pinMode(pinDetecteur_2, INPUT);
  pinMode(pinDetecteur_3, INPUT);
  pinMode(safeLedPin, OUTPUT);
  pinMode(dangerLedPin, OUTPUT);

  pinMode(bouttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  DetecteurVal_1 = digitalRead(pinDetecteur_1);
  DetecteurVal_2 = digitalRead(pinDetecteur_2);
  DetecteurVal_3 = digitalRead(pinDetecteur_3);
  bouttonVal = digitalRead(bouttonPin);

  digitalWrite(safeLedPin, !alarmActive);     // Show safe(Green) LED status
  digitalWrite(dangerLedPin, alarmActive);    // Show danger(Red) LED status
  
  verifMouvement();

  // Python Communication
  Serial.print(DetecteurVal_1);
  Serial.print(",");
  Serial.print(DetecteurVal_2);
  Serial.print(",");
  Serial.print(DetecteurVal_3);
  Serial.print(",");
  Serial.print(bouttonVal);
  Serial.print(",");
  Serial.println(alarmActive);
}

void verifMouvement() {
  if (DetecteurVal_1 == HIGH || DetecteurVal_2 == HIGH || DetecteurVal_3 == HIGH) {
    if (!alarmActive) {
      activerAlarme();
    }
  }
  if (bouttonVal == HIGH) {
    desactiverAlarme();
  }
}

void activerAlarme() {
  digitalWrite(safeLedPin, LOW);
  digitalWrite(dangerLedPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  Serial.println("Alarm activated");
  alarmActive = true;
}

void desactiverAlarme() {
  digitalWrite(safeLedPin, HIGH);
  digitalWrite(dangerLedPin, LOW);
  digitalWrite(buzzerPin, LOW);
  Serial.println("Alarm deactivated");
  alarmActive = false;
  delay(1000); 
}
