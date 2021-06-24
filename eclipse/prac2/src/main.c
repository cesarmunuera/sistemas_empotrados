#include "leon3_uart.h"
int main(){
	int i=0;
	char aux='0';
	for (i=0; i<10; i++){
		leon3_putchar(aux); leon3_putchar('\n');
		aux++;
	}
	leon3_putchar('\n');
	return 0;
}
