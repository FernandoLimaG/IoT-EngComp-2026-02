# IoT 1 - Trabalho Prático

***Internet das Coisas I  
Engenharia de Computação - 3° Período  
PUC Minas  - Campus Lourdes***

## Integrantes

- Fernando Gonçalves
- Fernando Queiroz
- Henrique Figueiredo
- Isabela Miranda
- Laura Martins
- Pedro de Castro

## Objetivo

Desenvolvimento de projeto utilizando microcontrolador ESP-32 com controle e aquisição de dados remotamente.

## Projeto

Estacionamento Inteligente

## Materiais Utilizados

## Tecnologias

- C/C++
- Python
- PostgreSQL
- MQTT
- MQTT Panel

## Ambiente de Desenvolvimento

- Arduino IDE
- VS Code

## Subdiretórios

O repositório é particionado para melhor organização do projeto e melhorar a experiência do usuário.
Os particionamentos são descritos em:

### Documentação

Acesso na pasta *docs* ou pelo link: [<u>Documentação</u>](./docs/)

### Mídias

Acesso na pasta *media* ou pelo link: [<u>Mídias</u>](./media/)

### Trabalhos Intermediários

Acesso na pasta *tps-sala* ou pelo link: [<u>Trabalhos Intermediários</u>](./tps-sala/)

### Trabalho Final

Acesso na pasta *tp-final* pelo link: [<u>Trabalho Final</u>](./tp-final/)

## Utilização

### Clonar o Repositório

- Por HTTPS
```bash
git clone https://github.com/FernandoLimaG/IoT-EngComp-2026-02.git
cd IoT-EngComp-2026-02/
```

- Por SSH
```bash
git clone git@github.com:FernandoLimaG/IoT-EngComp-2026-02.git
cd IoT-EngComp-2026-02/
```
### Códigos ESP (.ino)

>IMPORTANTE: Para o correto funcionamento do sistema lembre-se de garantir o casamento entre os pinos do microcontrolador 
e sua indicação no código. Caso decida utilizar pinos diferentes, altere o código para os novos valores.

Após clonar o repositório, abra o código utilizando seu ambiente de desenvolvimento de preferência para microcontroladores, 
selecione sua placa conectada ao computador, compile e execute (*build*).

### Servidor MQTT - Aquisição de Dados

Para acompanhar a aquisição de dados do projeto, utilize algum software MQTT como *MQTT Panel*, cadastre clientes 
com as nomenclaturas **exatas** referenciadas na documentação.
