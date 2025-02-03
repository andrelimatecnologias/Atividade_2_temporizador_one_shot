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
static volatile bool executando;


void inicializacao(){
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);

    gpio_set_dir(LED_RED,GPIO_OUT);
    gpio_set_dir(LED_GREEN,GPIO_OUT);
    gpio_set_dir(LED_BLUE,GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON,GPIO_IN);
    gpio_pull_up(BUTTON);    
    
}


/*
    Nesta função o temporizador é chamado e realimentado até que todos os LEDs se apaguem finalizando a animação, liberando a variável
    "executando" para que permita que o botão reinicie tudo novamente
*/
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if(executando){
        if(gpio_get(LED_GREEN)){
            gpio_put(LED_GREEN,0);
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            return 0;
        }
        if(gpio_get(LED_BLUE)){
            gpio_put(LED_BLUE,0);
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            return 0;
        }
        if(gpio_get(LED_RED)){
            gpio_put(LED_RED,0);
            executando=false;
        }
    }
    return 0;
}

void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    if ((current_time - last_time) > debounce_time) {
        last_time = current_time; 
        if (!executando){
            executando=true;
            gpio_put(LED_BLUE,1);
            gpio_put(LED_RED,1);
            gpio_put(LED_GREEN,1);
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        }
    }
}

int main()
{
    stdio_init_all();
    inicializacao();

    // A variável "cont" contará quantos segundos se passou durante a execução do programa para ser exibido
    int cont=0;

    executando = false;
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    while (true) {
        cont++;
        printf("Passou se %d segundo(s)\n",cont);
        sleep_ms(1000);
    }
}
