#include "leon3_bprint.h"
#include "leon3_hw_irqs.h"
#include "leon3_ev_handling.h"
#include "leon3_uart.h"

uint8_t irq_counter = 0;
char RxChars[9];

/* Esta funcion se utilizara como manejador de la interrupcion que genera la recepcion
 * por el puerto serie.
 * La funcion almacena en RxChars los primeros 8 caracteres que se reciben, reenviando,
 * además el sucesor por el mismo canal Tx
 */
void uart_rx_irq_handler(void){

	char aux;
	aux = leon3_getchar();

	if (irq_counter<8){
		RxChars[irq_counter]=aux;
		aux++;
		leon3_putchar(aux);
	}
	irq_counter++;
}

int main(){

	uint8_t i;

	leon3_install_handler(LEON3_SPARC_ENABLE_IRQ_TRAPVECTOR,leon3_trap_handler_enable_irqs);
	leon3_install_handler(LEON3_SPARC_DISABLE_IRQ_TRAPVECTOR,leon3_trap_handler_disable_irqs);


	leon3_sys_call_disable_irqs();//Desabilitamos las interrupciones


	/* COMPLETAR instalando como manejador de la interrupcion de nivel 2 la rutina
	 * uart_rx_irq_handler
	 */
	leon3_install_handler(0x12, uart_rx_irq_handler);
	//FIN COMPLETAR


	leon3_UART_ConfigRXTXLoop(1);//Habilitamos loop-back


	leon3_UART_RX_IRQ_ENABLE();//Habilitamos la interrupcion de recepcion por la UART


	leon3_UART_RX_ENABLE();//Habilito la recepcion por la UART


	/*COMPLETAR habilitando las interrupciones y desenmascarando la interrupcion de
	 * nivel 2
	 */
	leon3_unmask_irq(2);			//Desenmascaramos la interrupción de nivel 2

	leon3_sys_call_enable_irqs();	//Habilitamos las interrupciones
	//FIN COMPLETAR


	leon3_putchar('1');


	while(irq_counter < 8);//Sondeo si los 8 caracteres se han recibido


	//Tras recibir los 8 caracteres, conficura la UART sin loop-back
	leon3_UART_ConfigRXTXLoop(0);


	/*Envio de nuevo los 8 caracteres que se recibieron, pero sin loop-back, por lo
	 * que apareceran por pantalla.
	 */
	for(i=0; i<9; i++){
		leon3_putchar(RxChars[i]);
	}
	leon3_putchar('\n');


	while(!leon3_UART_TF_IS_EMPTY());//Espero a que todos lo caracteres se hayan enviado


	return 0;
}
