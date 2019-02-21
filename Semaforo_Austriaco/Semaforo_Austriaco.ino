//Variabili per il primo semaforo
int V1 = 12;
int G1 = 10;
int R1 = 8;
//Variabili per il secondo semaforo
int V2 = 6;
int G2 = 4;
int R2 = 2;
//Variabili per i valori di tempo e numero dei lampeggi
int numLampeggiVerde  = 0;
int tempoVerde        = 0;
int tempoGiallo       = 0;
int tempoLampeggi     = 0;

void setup() {
  Serial.begin(9600);
  pinMode(V1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(R2, OUTPUT);
  
  numLampeggiVerde  = richiediValori("Quanti lampeggi vuoi che faccia il verde?", numLampeggiVerde);
  tempoLampeggi     = richiediValori("Quanti millisecondi vuoi che durino i lampeggi del verde?", tempoLampeggi);
  tempoVerde        = richiediValori("Quanti millisecondi vuoi che resti acceso il verde?", tempoVerde);
  tempoGiallo       = richiediValori("Quanti millisecondi vuoi che resti acceso il giallo?", tempoGiallo);  
  //Non inserisco la stessa domanda per il rosso perché la sua durata dipende dalla durata del verde e del rosso, non può essere differente
}

int richiediValori(String domanda, int valore) {
  Serial.println(domanda);
  while(Serial.available() ==0);
  valore = Serial.readString().toInt();
  return valore;
}

void lampeggio(int led) {
  //Ciclo for che fa lampeggiare il verde, come tempo del delay inserisco la variabile che aveva dato l'utente in input
  for(int i=0; i<numLampeggiVerde; i++){
  digitalWrite (led, LOW);
  delay (tempoLampeggi);
  digitalWrite (led, HIGH);
  delay (tempoLampeggi);
  }
}

void semaforo(int verde, int rosso){
  //Creazione di un unico metodo per entrambi i 2 semafori utilizzando delle variabili d'appoggio che al primo ciclo assumono il valore V2 e R1, al secondo V1 e R2
  digitalWrite (rosso, HIGH);
  digitalWrite (verde, HIGH);
  delay (tempoVerde);  
  lampeggio(verde); 
  digitalWrite (verde, LOW);
  digitalWrite (G1, HIGH);
  digitalWrite (G2, HIGH);
  delay (tempoGiallo);
  digitalWrite (G1, LOW);
  digitalWrite (G2, LOW);
  digitalWrite (rosso, LOW);
}

void loop() {
  //Due cicli separati per il primo e per il secondo semaforo
  semaforo(V2, R1);
  semaforo(V1, R2);  
}
