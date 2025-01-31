
# Controle de Animação de LEDs utilizando temporizador one shot (único disparo)

Este repositório contém o projeto de controle de uma animação utilizando temporizadores de um único disparo.

## Componentes
- Microcontrolador Raspberry Pi Pico W.
- 03 LEDs (vermelho, amarelo e verde).
- 03 Resistores de 330 Ω.
- Botão (Pushbutton).

## Funcionamento

- Ao pressionar o botão três LEDs são ligados, e desde então espera se três segundos e desliga se um, restando dois, espera se mais 3 segundos e desliga-se mais um, e se espera mais 3 segundos para desligar-se o último
- Através de protocolo UART e USB é possível visualizar uma mensagem exibindo quantos segundos se passaram desde o início do programa

## Instruções de uso

### Requisitos
- Ambiente de desenvolvimento **VS Code**.
- **Simulador Wokwi** para simulação do hardware.
- Kit de desenvolvimento **Pico SDK**.

### Passos para Execução
1. Clone este repositório:
   ```bash
   git clone ttps://github.com/andrelimatecnologias/Atividade_1_temporizador_periodico.git
   ```
2. Instale as dependências necessárias para o Pico SDK.
3. Importe o projeto no **VS Code** e configure o simulador Wokwi.
4. Compile o código e inicie a simulação no Wokwi
5. Coloque a placa em modo Bootsel e transfira o código para iniciar a aplicação na placa BitDogLab
6. Aperte o botão e obseve que a animação vai começar. Espere até a animação terminar para apertar no botão novamente, pois, se pressionar antes nada irá acontecer.

### Observação
A prática pode ser realizada tanto com o simulador Wokwi, como em hardware real. (No hardware real o LED RGB da placa BitDogLab será utilizado, portanto ao desligar cada um dos LEDs se espera obter um efeito como:
   1. primeiro instante o LED estará branco: Verde,Azul e Vermelho ligados soma se a cor branca.
   2. segundo instante o LED estará Roxo (Magenta): Azul e Vermelho ligados soma se a cor Roxa (Magenta).
   3. terceiro instante o LED estará Vermelho pois é o único ligado.

## Vídeo de teste
Um vídeo mostrando o teste desta atividade pode ser acessado no link: https://www.youtube.com/watch?v=ddZUTpptMZ0

## Autor do projeto:
André Souza Lima
