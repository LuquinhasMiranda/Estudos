#include <ESP8266WiFi.h>
 
const char* ssid = "Ap11";
const char* password = "apartamento11";
 
WiFiServer server(80);
 
void setup() {
pinMode(D2, OUTPUT);
  
Serial.begin(115200);
delay(10);
Serial.print("Conectando a ");
Serial.print(ssid);
 
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) { //ENQUANTO STATUS FOR DIFERENTE DE CONECTADO
delay(500);
Serial.print(".");
}

Serial.print("Conectado a rede sem fio ");
Serial.println(ssid);
server.begin();
Serial.println("Servidor iniciado");
 
Serial.print("IP para se conectar ao NodeMCU: ");
Serial.print("http://");
Serial.println(WiFi.localIP());
}

void loop() {
WiFiClient client = server.available(); //VERIFICA SE ALGUM CLIENTE ESTÁ CONECTADO NO SERVIDOR
if (!client) {
  return;
}

Serial.println("Novo cliente se conectou!"); //ESCREVE O TEXTO NA SERIAL
while(!client.available()){ //ENQUANTO CLIENTE ESTIVER CONECTADO
delay(1); //INTERVALO DE 1 MILISEGUNDO
}

String request = client.readStringUntil('\r'); //FAZ A LEITURA DA PRIMEIRA LINHA DA REQUISIÇÃO
Serial.println(request); //ESCREVE A REQUISIÇÃO NA SERIAL
if (request[5] == '1') digitalWrite(D2, LOW);
else if (request[5] == '0') digitalWrite(D2, HIGH);
client.flush(); //AGUARDA ATÉ QUE TODOS OS DADOS DE SAÍDA SEJAM ENVIADOS AO CLIENTE
 
client.println("HTTP/1.1 OK"); //ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
client.println("Content-Type: text/html"); //ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
client.println("");
client.println("<!DOCTYPE HTML>"); //INFORMA AO NAVEGADOR A ESPECIFICAÇÃO DO HTML
client.println("<html>"); //ABRE A TAG "html"
client.print("<div style=\"width:100%; text-align:center;\"></div><a href=\"1\"><div href=\"1\" style=\"display: inline-block;background: #000;border-radius: 4px;font-size: 14px;color: #FFF;padding: 8px 12px;cursor: pointer;\">ON</div></a><a href=\"0\"><div href=\"0\" style=\"display: inline-block;background: #000;border-radius: 4px;font-size: 14px;color: #FFF;padding: 8px 12px;cursor: pointer;\">OFF</div></a>");
client.println("</html>"); //FECHA A TAG "html"
delay(100);
}
