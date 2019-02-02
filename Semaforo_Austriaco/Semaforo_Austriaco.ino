
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
int tempoVR = 0;
int tempoGiallo = 0;

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
  //Come prima domanda 
  Serial.println("Quanti lampeggi vuoi che faccia il verde?");
  while(Serial.available() ==0);
  numLampeggiVerde = Serial.readString().toInt();

  Serial.println("Quanto vuoi che restino accesi il verde e il rosso?");
  while(Serial.available() ==0);
  tempoVR = Serial.readString().toInt();

  Serial.println("Quanto vuoi che resti acceso il giallo?");
  while(Serial.available() ==0);
  tempoGiallo = Serial.readString().toInt();
}

void lampeggio1() {
  for(int i=0; i<numLampeggiVerde; i++){
  digitalWrite (V1, LOW);
  delay (500);
  digitalWrite (V1, HIGH);
  delay (500);
  }
}

void lampeggio2() {
  for(int i=0; i<numLampeggiVerde; i++){
  digitalWrite (V2, LOW);
  delay (500);
  digitalWrite (V2, HIGH);
  delay (500); 
  }
}

void loop() {
  Serial.begin(9600);
  // put your main code here, to run repeatedly:  
  if (richiesta ==0)
  {
    richiediValori();
  }
  
  digitalWrite (R1, HIGH);
  digitalWrite (V2, HIGH);
  delay (tempoVR);
  
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
  delay (tempoVR);
  
  lampeggio1();
  
  digitalWrite (V1, LOW);
  digitalWrite (G2, HIGH);
  digitalWrite (G1, HIGH);
  delay (tempoGiallo);
  digitalWrite (G2, LOW);
  digitalWrite (G1, LOW);
  digitalWrite (R2, LOW);
    
  richiesta++;
}
