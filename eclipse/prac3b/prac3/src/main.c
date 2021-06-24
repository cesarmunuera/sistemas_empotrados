/*
 * main.c
 *
 *  Created on: 05/03/2021
 *      Author: cesar
 */
#include "leon3_uart.h"
#include "leon3_bprint.h"
#include "leon3_hw_irqs.h"
#include "leon3_ev_handling.h"

void hw_irq_vector_0x11_handler(void){
	leon3_print_string("handler hw irq vector 0x11\n");
}

void trap_0x83(void){	// Apartado 7
	leon3_print_string("error, division por 0");
}

int main(){

	//Instalar como manejador del trap 0x83 la rutina que habilita las interrupciones
	leon3_install_handler(0x83, leon3_trap_handler_enable_irqs);


	//Instalar el manejador del trap que 0x84 la rutina deshabilita las interrupciones
	leon3_install_handler(0x84, leon3_trap_handler_disable_irqs);


	//Deshabilitar las interrupciones
	leon3_sys_call_disable_irqs();


	//Instalar la funcion hw_irq_vector_0x11_handler como manejador de la interrupcion de nivel 1
	//COMPLETAR
	leon3_install_handler(0x11, hw_irq_vector_0x11_handler);


	//Apartado 7
	leon3_install_handler(0x82, trap_0x83);


	/**
	 * Desenmascarar las interrupcion de nivel 1 (correspondiente al vector 17, es decir,
	 * el vector 0x11)
	 */
	leon3_unmask_irq(1);


	//Habilitar las interrupciones
	leon3_sys_call_enable_irqs();

	/**Apartado 4
	 * Lo que ocurre cuando pones esos breakpoints y llegamos al ta, es que nos lleva
	 * a la funcion leon3_trap_handler_enable_irqs.
	 */

	//Apartado 6
	//leon3_sys_call_disable_irqs();

	//Apartado 5
	//leon3_mask_irq(1);

	//Fuerza la interrupcion
	leon3_sparc_force_irq(1);


	//Apartado 7
	//uint8_t i, j;
	//for (i=10; i>0; i--)
		//j=j/(i-9);

	return 0;
}
