// ===== TP2: Hardware =====

const int led_red = 32;
const int led_ylw = 33;
const int led_grn = 25;

const int btn_red = 27;
const int btn_ylw = 14;
const int btn_grn = 12;

int btn_red_state = 0;
int btn_ylw_state = 0;
int btn_grn_state = 0;

void setup()
{
  // Leitura Serial
  Serial.begin(9600);

  // Led's
  pinMode(led_red, OUTPUT);
  pinMode(led_ylw, OUTPUT);
  pinMode(led_grn, OUTPUT);
  
  // Btn's
  pinMode(btn_red, INPUT);
  pinMode(btn_ylw, INPUT);
  pinMode(btn_grn, INPUT);
  
  // Start = LOW
  digitalWrite(led_red, 0);
  digitalWrite(led_ylw, 0);
  digitalWrite(led_grn, 0);
}

void loop()
{
  btn_red_state = digitalRead(btn_red);
  btn_ylw_state = digitalRead(btn_ylw);
  btn_grn_state = digitalRead(btn_grn);

  // Led Vermelho
  if(btn_red_state == 1) {
    digitalWrite(led_red, 1);
    Serial.println("Botao do led 'VERMELHO' pressionado!");
    delay(100);
  } else{ digitalWrite(led_red, 0); }

  // Led Amarelo
  if(btn_ylw_state == 1) {
    digitalWrite(led_ylw, 1);
    Serial.println("Botao do led 'AMARELO' pressionado!");
    delay(100);
  } else{ digitalWrite(led_ylw, 0); }

  // Led Verde
  if(btn_grn_state == 1) {
    digitalWrite(led_grn, 1);
    Serial.println("Botao do led 'VERDE' pressionado!");
    delay(100);
  } else{ digitalWrite(led_grn, 0); }
}
