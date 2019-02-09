//Dichiaro le variabili globali che identificano i 3 colori del semaforo, così facendo se si cambia l'ingresso di un cavo occorre modificare il numero solo in un posto
//Dichiaro le variabili globali per il numero di lampeggi del verde e per la durata di accensione dei 3 colori
//Dichiaro la variabile "richiesta", che mi servirà unicamente nell'if per evitare che rifaccia le domande ad ogni riinizio del ciclo loop
int V1 = 12;
int G1 = 10;
int R1 = 8;
int V2 = 6;
int G2 = 4;
int R2 = 2;
int richiesta        = 0;
int numLampeggiVerde = 0;
int tempoVerde       = 0;
int tempoGiallo      = 0;
int tempoLampeggi    = 0;

void setup() {
  pinMode(V1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(R2, OUTPUT);
}

void richiediValori() {
  //Come prima domanda chiedo all'utente quanti lampeggi vuole far fare al verde
  Serial.println("Quanti lampeggi vuoi che faccia il verde?");
  while(Serial.available() ==0);
  numLampeggiVerde = Serial.readString().toInt();
  //Chiedo quanto vuole che duri ogni lampeggio del verde
  Serial.println("Quanto vuoi che siano lunghi i lampeggi del verde?");
  while(Serial.available() ==0);
  tempoLampeggi = Serial.readString().toInt();
  //Chiedo quando vuole far durare il verde
  Serial.println("Quanto vuoi che resti acceso il verde?");
  while(Serial.available() ==0);
  tempoVerde = Serial.readString().toInt();
  //Chiedo quanto vuole far durare il giallo
  Serial.println("Quanto vuoi che resti acceso il giallo?");
  while(Serial.available() ==0);
  tempoGiallo = Serial.readString().toInt();
  //Non inserisco la stessa domanda per il rosso perché la sua durata dipende dalla durata del verde e del rosso, non può essere differente
}

void lampeggio(int led) {
  //Ciclo for che fa lampeggire il verde, come tempo del delay inserisco la variabile che aveva dato l'utente in input
  for(int i=0; i<numLampeggiVerde; i++){
  digitalWrite (led, LOW);
  delay (tempoLampeggi);
  digitalWrite (led, HIGH);
  delay (tempoLampeggi);
  }
}

void semaforo(int verde, int rosso){
  //Creazione di un unico metodo per entrambi i 2 semafori utilizzando delle cariabili d'appoggio che al primo ciclo assumono il valore V2, V1, R2, R1 e al secondo si "specchiano"
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
  Serial.begin(9600);
  //Questo ciclo if mi serve per far comparire le domande solo al primo avvio, ad ogni ciclo questa variabile si incrementa di 1 così il ciclo if restituisce falso  
  if (richiesta ==0)
    richiediValori();  
  //Il ciclo generico della sequenza dei colori rimane pressoché invariato
  semaforo(V2, R1);
  semaforo(V1, R2);  
  //Come già precisato la variabile richiesta aumenta di una unità ad ogni ciclo
  richiesta++;
}
