#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"



//  Os valores definido abaixo correspondem a identificação das portas GPIO para os LEDs e o Botão
#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12
#define BUTTON 5


// As variáveis abaixo são utilizadas para viabilizar um debounce para o pressionamento do botão via software
static volatile uint32_t last_time = 0;
static volatile uint32_t debounce_time = 200000;

/*
    A variável "executando" vai ser utilizada como controle para que não haja uma reinicialização da configuração dos temporizadores
    antes do apagar de todos os LEDs, concluindo a animação.
*/
static bool executando;



int main()
{
    stdio_init_all();

    // A variável "cont" contará quantos segundos se passou durante a execução do programa para ser exibido
    int cont=0;

    executando = false;

    while (true) {
        cont++;
        printf("Passou se %d segundo(s)\n",cont);
        sleep_ms(1000);
    }
}
