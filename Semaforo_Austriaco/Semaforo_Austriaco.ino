
//Dichiaro le variabili globali che identificano i 3 colori del semaforo, così facendo se si cambia l'ingresso di un cavo occorre modificare il numero solo in un posto
//Dichiaro le variabili globali per il numero di lampeggi del verde e per la durata di accensione dei 3 colori
//Dichiaro la variabile "richiesta", che mi servirà unicamente nell'if per evitare che rifaccia le domande ad ogni riinizio del ciclo loop

int V1 = 12;
int G1 = 10;
int R1 = 8;

int V2 = 6;
int G2 = 4;
int R2 = 2;

int richiesta = 0;
int numLampeggiVerde = 0;
int tempoVerde = 0;
int tempoGiallo = 0;
int tempoLampeggi = 0;

void setup() {
  // put your setup code here, to run once:
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

void lampeggio1() {
  //Ciclo for che fa lampeggire il verde del semaforo 1, come tempo del delay inserisco la variabile che aveva dato l'utente in input
  for(int i=0; i<numLampeggiVerde; i++){
  digitalWrite (V1, LOW);
  delay (tempoLampeggi);
  digitalWrite (V1, HIGH);
  delay (tempoLampeggi);
  }
}

void lampeggio2() {
  //Ciclo for che fa lampeggire il verde del semaforo 2, come tempo del delay inserisco la stessa variabile utilizzata nel ciclo precedente
  for(int i=0; i<numLampeggiVerde; i++){
  digitalWrite (V2, LOW);
  delay (tempoLampeggi);
  digitalWrite (V2, HIGH);
  delay (tempoLampeggi); 
  }
}

void loop() {
  Serial.begin(9600);
  // put your main code here, to run repeatedly:
  //Questo ciclo if mi serve per far comparire le domande solo al primo avvio, ad ogni ciclo questa variabile si incrementa di 1 così il ciclo if restituisce falso  
  if (richiesta ==0)
  {
    richiediValori();
  }

  //Il ciclo generico della sequenza dei colori rimane pressoché invariato
  digitalWrite (R1, HIGH);
  digitalWrite (V2, HIGH);
  delay (tempoVerde);  
  lampeggio2();  
  digitalWrite (V2, LOW);
  digitalWrite (G1, HIGH);
  digitalWrite (G2, HIGH);
  delay (tempoGiallo);
  digitalWrite (G1, LOW);
  digitalWrite (G2, LOW);
  digitalWrite (R1, LOW);
  digitalWrite (R2, HIGH);
  digitalWrite (V1, HIGH);
  delay (tempoVerde);  
  lampeggio1(); 
  digitalWrite (V1, LOW);
  digitalWrite (G2, HIGH);
  digitalWrite (G1, HIGH);
  delay (tempoGiallo);
  digitalWrite (G2, LOW);
  digitalWrite (G1, LOW);
  digitalWrite (R2, LOW);

  //Come già precisato la variabile richiesta aumenta di una unità ad ogni ciclo
  richiesta++;
}
