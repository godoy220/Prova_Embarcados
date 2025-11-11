# Projeto de Sistema Embarcado: Jogo "Simon Diz" com 4 Cores

*adicionar link do video*

---

### 1. Integrantes da Equipe

*   Felipe F. Corrêa
*   Gabriel G. Motta
*   Felipe R. Pelentil

---

### 2. Objetivo do Projeto

O objetivo deste projeto foi desenvolver um jogo eletrônico de memória e reflexo, popularmente conhecido como "Genius" ou "Simon Diz", utilizando a plataforma Arduino. O sistema gera uma sequência aleatória e crescente de luzes e sons, e o jogador deve repeti-la corretamente.

O projeto cumpre os requisitos de utilizar no mínimo 3 sensores e 2 atuadores, com a seguinte configuração:
*   **Sensores:** 4 botões para o jogador (Vermelho, Verde, Amarelo, Azul) e 1 botão para reset.
*   **Atuadores:** 4 LEDs para o feedback visual (Vermelho, Verde, Amarelo e um LED RGB para a cor Azul) e 1 Buzzer para o feedback sonoro.

---

### 3. Lista de Elementos Utilizados

| Componente              | Quantidade | Custo Estimado (Unid.) | Custo Total (Est.) |
| ----------------------- | :--------: | :--------------------: | :----------------: |
| Arduino Uno R3          |      1     |         R$ 50,00         |      R$ 50,00      |
| Protoboard 400 Pontos   |      1     |         R$ 10,00         |      R$ 10,00      |
| Botão (Push-button)     |      5     |         R$ 0,50          |      R$ 2,50       |
| LED Vermelho 5mm        |      1     |         R$ 0,20          |      R$ 0,20       |
| LED Verde 5mm           |      1     |         R$ 0,20          |      R$ 0,20       |
| LED Amarelo 5mm         |      1     |         R$ 0,20          |      R$ 0,20       |
| LED RGB (Cátodo Comum)  |      1     |         R$ 1,00          |      R$ 1,00       |
| Buzzer Passivo 5V       |      1     |         R$ 2,00          |      R$ 2,00       |
| Resistor 220Ω           |      4     |         R$ 0,10          |      R$ 0,40       |
| Resistor 10kΩ           |      5     |         R$ 0,10          |      R$ 0,50       |
| Jumpers Macho-Macho     |   ~20      |         R$ 0,25          |      R$ 5,00       |
| **CUSTO TOTAL ESTIMADO**|            |                        |    **~R$ 72,00**   |

*(Os custos são aproximados e podem variar dependendo do fornecedor).*

---

### 4. Esquema de Montagem

O circuito foi montado conforme o esquema abaixo. Os botões utilizam resistores de pull-down para garantir uma leitura estável, e os LEDs utilizam resistores para limitar a corrente.

*adicionar foto do circuito feito em aula*

**Pinos Utilizados:**
*   **LEDs:** Portas 7 (Azul), 8 (Vermelho), 9 (Verde), 10 (Amarelo).
*   **Botões:** Portas 2 (Vermelho), 3 (Verde), 4 (Amarelo), 5 (Azul).
*   **Botão de Reset:** Porta 6.
*   **Buzzer:** Porta 11.

---

### 5. Fotos e GIFs do Sistema Montado

Abaixo estão algumas imagens do projeto finalizado e em funcionamento.

**Foto 1: Visão Geral do Projeto**
*(Insira a imagem aqui)*

**GIF 1: Jogador Acertando a Sequência**
*(Insira o GIF aqui)*

**GIF 2: Efeito do Botão de Reset**
*(Insira o GIF aqui)*

---

### 6. Estrutura do Código e Versionamento

O código-fonte (`.ino`) está totalmente comentado para explicar a lógica de funcionamento, incluindo:
*   Mapeamento de pinos para hardware.
*   Variáveis globais que controlam o estado do jogo.
*   Funções principais como `iniciarNovoNivel()`, `reiniciarJogo()` e `mostrarSequencia()`.
*   Funções auxiliares para leitura de botões e acionamento de atuadores.


