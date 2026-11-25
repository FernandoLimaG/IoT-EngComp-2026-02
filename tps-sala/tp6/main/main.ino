#include "secret.h"

#include <WiFi.h>
#include <PubSubClient.h>

/* Definicoes para o MQTT */
#define TOPICO_SUBSCRIBE_LED         "topico_liga_desliga_led"
#define TOPICO_PUBLISH_TEMPERATURA   "topico_sensor_temperatura"

//id mqtt (para identificação de sessão)
#define ID_MQTT  "IoT_PUC_eng_comp_mqtt"

// Global var
const int PIN_LED 25;
const char* BROKER_MQTT = "test.mosquitto.org";
//const char* BROKER_MQTT = "broker.emqx.io";   // broker secundario caso mosquitto down
const int BROKER_PORT = 1883;
long numAleatorio;

// Global objetos MQTT
WiFiClient espClient;
PubSubClient MQTT(espClient);

/* Metodos */
void initWiFi(void);
void initMQTT(void);
void mqtt_callback(char* topic, byte* payload, unsigned int length);
void reconnectMQTT(void);
void reconnectWiFi(void);
void VerificaConexoesWiFIeMQTT(void);

void initWiFi(void)
{
  delay(10);
  Serial.println("------Conexao WI-FI------");
  Serial.print("Conectando-se na rede: ");
  Serial.println(SSID);
  Serial.println("Aguarde");

  reconnectWiFi();
}


void initMQTT(void)
{
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);   //informa qual broker e porta deve ser conectado
  MQTT.setCallback(mqtt_callback);            //atribui função de callback
}

void mqtt_callback(char* topic, byte* payload, unsigned int length)
{
  String msg;

  /* obtem a string do payload recebido */
  for (int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    msg += c;
  }

  Serial.print("String via MQTT: ");
  Serial.println(msg);

  if(msg.equals("L")
  {
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED aceso mediante comando MQTT");
  }
  
  else if (msg.equals("D"))
  {
    digitalWrite(PIN_LED, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED apagado mediante comando MQTT");
  }

  else Serial.println("Não identificou comando MQTT");
}

void reconnectMQTT(void)
{
  while (!MQTT.connected())
  {
    Serial.print("* Tentando se conectar ao Broker MQTT: ");
    Serial.println(BROKER_MQTT);

    if (MQTT.connect(ID_MQTT))
    {
      Serial.println("Conectado com sucesso ao broker MQTT!");
      MQTT.subscribe(TOPICO_SUBSCRIBE_LED);
    }

    else
    {
      Serial.println("Falha ao reconectar no broker.");
      Serial.println("Havera nova tentativa de conexao em 2s");
      delay(2000);
    }
  }  
}

void VerificaConexoesWiFIeMQTT(void)
{
  if (!MQTT.connected())
    reconnectMQTT(); //se não há conexão com o Broker, a conexão é refeita

  reconnectWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}

void reconnectWiFi(void)
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  WiFi.begin(SSID, PASSWORD); // Conectar WI-FI

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.println(".");
  }

  Serial.println();
  Serial.print("Conectado com sucesso na rede ");
  Serial.print(SSID);
  Serial.println("\nIP obtido: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nDisciplina IoT: acesso a nuvem via ESP32");
  delay(1000);

  // programa LED interno como saida
  pinMode(PIN_LED, OUTPUT);

  digitalWrite(PIN_LED, HIGH);
  delay(1000);
  digitalWrite(PIN_LED, LOW);
  
  // GERANDO TEMPERATURA COMO UM NÚMERO ALEATÓRIO
  randomSeed(analogRead(0));

  initWiFi();
  initMQTT();
}

void loop() {
  char temperatura_str[10] = {0};
  
  VerificaConexoesWiFIeMQTT();

  // valor aleatorio entre 10 e 100
  numAleatorio = random(10, 101);
  
  // formata a temperatura como string
  sprintf(temperatura_str, "%dC", numAleatorio);

  /*  Publica a temperatura */
  MQTT.publish(TOPICO_PUBLISH_TEMPERATURA, temperatura_str);
  
  /* keep-alive da comunicação com broker MQTT */
  MQTT.loop();
  delay(2000);
}
