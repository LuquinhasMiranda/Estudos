#include <ESP8266WiFi.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA PARA FUNCIONAMENTO DO CÓDIGO
 
const char* ssid = "Ap11"; //VARIÁVEL QUE ARMAZENA O NOME DA REDE SEM FIO EM QUE VAI CONECTAR
const char* password = "apartamento11"; //VARIÁVEL QUE ARMAZENA A SENHA DA REDE SEM FIO EM QUE VAI CONECTAR
 
WiFiServer server(25565); //CASO OCORRA PROBLEMAS COM A PORTA 80, UTILIZE OUTRA (EX:8082,8089) E A CHAMADA DA URL FICARÁ IP:PORTA(EX: 192.168.0.15:8082)

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) { //ENQUANTO STATUS FOR DIFERENTE DE CONECTADO
  delay(500);
  Serial.print(".");
  }

  server.begin(); //INICIA O SERVIDOR PARA RECEBER DADOS NA PORTA DEFINIDA EM "WiFiServer server(porta);"
 
  Serial.print("\nIP para se conectar ao NodeMCU: "); //ESCREVE O TEXTO NA SERIAL
  Serial.print("http://"); //ESCREVE O TEXTO NA SERIAL
  Serial.println(WiFi.localIP()); //ESCREVE NA SERIAL O IP RECEBIDO DENTRO DA REDE SEM FIO (O IP NESSA PRÁTICA É RECEBIDO DE FORMA AUTOMÁTICA)

  pinMode(2, OUTPUT);
}

bool on_off;

void loop() {
  WiFiClient client = server.available(); //VERIFICA SE ALGUM CLIENTE ESTÁ CONECTADO NO SERVIDOR
  if (!client) { //SE NÃO EXISTIR CLIENTE CONECTADO, FAZ
  return; //REEXECUTA O PROCESSO ATÉ QUE ALGUM CLIENTE SE CONECTE AO SERVIDOR
  }

  on_off = !on_off;
  digitalWrite(2, on_off);

  while(!client.available()){ //ENQUANTO CLIENTE ESTIVER CONECTADO
  delay(1); //INTERVALO DE 1 MILISEGUNDO
  }

  delay(1);
  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
}
