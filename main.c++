// --- Mapeamento de Pinos (Hardware) ---

// Atuadores (LEDs)
const int ledVermelho = 8;
const int ledVerde = 9;
const int ledAmarelo = 10;
const int ledAzul = 7; // Pino azul do LED RGB

// Atuador (Som)
const int pinoBuzzer = 11;

// Sensores (Botões do Jogo)
const int botaoVermelho = 2;
const int botaoVerde = 3;
const int botaoAmarelo = 4;
const int botaoAzul = 5;

// Sensor (Botão de Reset)
const int botaoReset = 6;

// --- Variáveis Globais do Jogo ---
int sequencia[50];      // Array para armazenar a sequência. Nível máximo = 50.
int nivelAtual = 0;     // Controla o tamanho da sequência (pontuação).
int passoAtual = 0;     // Controla qual passo da sequência o jogador está.
bool aguardandoInput = false; // Flag para saber se é a vez do jogador.

// --- Configuração Inicial (Executa uma vez) ---
void setup() {
  // Configura pinos dos atuadores como SAÍDA (OUTPUT)
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);

  // Configura pinos dos sensores como ENTRADA (INPUT)
  pinMode(botaoVermelho, INPUT);
  pinMode(botaoVerde, INPUT);
  pinMode(botaoAmarelo, INPUT);
  pinMode(botaoAzul, INPUT);
  pinMode(botaoReset, INPUT);

  // Usa uma porta analógica não conectada para gerar uma semente aleatória
  randomSeed(analogRead(A0));
  
  delay(1000); // Pausa inicial
  iniciarNovoNivel(); // Começa o primeiro nível do jogo
}

// --- Loop Principal (Executa continuamente) ---
void loop() {
  // Verifica a cada ciclo se o botão de reset foi pressionado.
  // Isso permite que o reset funcione a qualquer momento.
  if (digitalRead(botaoReset) == HIGH) {
    reiniciarJogo();
  }

  // Se o jogo não estiver sendo resetado, continua a lógica normal.
  if (aguardandoInput) {
    int botaoPressionado = lerBotao();

    if (botaoPressionado != 0) { // Se algum botão do jogo foi pressionado
      if (botaoPressionado == sequencia[passoAtual]) { // Se acertou o passo
        passoAtual++;
        if (passoAtual == nivelAtual) { // Se completou a sequência do nível
          aguardandoInput = false;
          delay(500);
          somSucesso();
          delay(1000);
          iniciarNovoNivel(); // Passa para o próximo nível
        }
      } else { // Se errou o passo
        aguardandoInput = false;
        somErro();
        reiniciarJogo(); // Reinicia o jogo
      }
    }
  }
}

// --- Funções Principais do Jogo ---

void iniciarNovoNivel() {
  nivelAtual++;
  passoAtual = 0;
  sequencia[nivelAtual - 1] = random(1, 5); // Adiciona nova cor aleatória (1 a 4)
  mostrarSequencia();
  aguardandoInput = true; // Libera a vez para o jogador
}

void reiniciarJogo() {
  aguardandoInput = false; // Trava o input do jogador durante o reset
  efeitoReset(); // Chama o efeito visual e sonoro de reset
  nivelAtual = 0; // Zera a pontuação
  delay(500);
  iniciarNovoNivel(); // Começa um jogo completamente novo
}

void mostrarSequencia() {
  // Garante que todos os LEDs estão apagados antes de começar
  digitalWrite(ledVermelho, LOW); digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW); digitalWrite(ledAzul, LOW);
  delay(500);

  // Mostra cada cor da sequência até o nível atual
  for (int i = 0; i < nivelAtual; i++) {
    acionarCor(sequencia[i], 400); // Mostra a cor por 400ms
    delay(150); // Pausa entre as cores
  }
}

// --- Funções Auxiliares ---

int lerBotao() {
  if (digitalRead(botaoVermelho) == HIGH) { acionarCor(1, 150); return 1; }
  if (digitalRead(botaoVerde) == HIGH) { acionarCor(2, 150); return 2; }
  if (digitalRead(botaoAmarelo) == HIGH) { acionarCor(3, 150); return 3; }
  if (digitalRead(botaoAzul) == HIGH) { acionarCor(4, 150); return 4; }
  return 0; // Retorna 0 se nenhum botão for pressionado
}

void acionarCor(int cor, int duracao) {
  switch (cor) {
    case 1: digitalWrite(ledVermelho, HIGH); tone(pinoBuzzer, 262); break; // Dó
    case 2: digitalWrite(ledVerde, HIGH); tone(pinoBuzzer, 294); break;    // Ré
    case 3: digitalWrite(ledAmarelo, HIGH); tone(pinoBuzzer, 330); break; // Mi
    case 4: digitalWrite(ledAzul, HIGH); tone(pinoBuzzer, 349); break;      // Fá
  }
  delay(duracao);
  // Desliga tudo após a duração
  digitalWrite(ledVermelho, LOW); digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW); digitalWrite(ledAzul, LOW);
  noTone(pinoBuzzer);
}

void somSucesso() {
  tone(pinoBuzzer, 523, 150); delay(160); // Dó alto
  tone(pinoBuzzer, 659, 150); delay(160); // Mi alto
  tone(pinoBuzzer, 784, 150); delay(160); // Sol alto
}

void somErro() {
  tone(pinoBuzzer, 131, 1000); // Som grave e longo de erro
  // Pisca LEDs rapidamente para indicar o erro
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledVermelho, HIGH); digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH); digitalWrite(ledAzul, HIGH);
    delay(250);
    digitalWrite(ledVermelho, LOW); digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW); digitalWrite(ledAzul, LOW);
    delay(250);
  }
  noTone(pinoBuzzer);
}

void efeitoReset() {
  // Som distinto para reset (dois tons, do alto para o baixo)
  tone(pinoBuzzer, 440, 200); delay(200); // Lá
  tone(pinoBuzzer, 220, 300); delay(300); // Lá (oitava abaixo)

  // Pisca todos os LEDs 3 vezes, como solicitado
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledVermelho, HIGH); digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH); digitalWrite(ledAzul, HIGH);
    delay(150);
    digitalWrite(ledVermelho, LOW); digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW); digitalWrite(ledAzul, LOW);
    delay(150);
  }
  noTone(pinoBuzzer);
}
