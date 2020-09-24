#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "ia.h"

int main() {
	int aux;
	char jogadordavez, vencedor, primeirojogador = 'o';
	
	srand(time(NULL));
	
	for(;;) {
		jogadordavez = trocarjogador(primeirojogador);
		primeirojogador = trocarjogador(primeirojogador);
		vencedor = '0';
		
		inicializar();
		int cheio, posicao;
		
		while(vencedor == '0') {
			imprimir(tabuleiro);
			
			if(jogadordavez == 'x') {
				posicao = lerterminal(jogadordavez);
			}
			else if(jogadordavez == 'o') {
				printf("o? ...\n");
				usleep(500000);
				posicao = ia('o');
				//getchar();
			}
			
			jogar(jogadordavez, posicao);
			
			vencedor = checarvencedor(tabuleiro, jogadordavez);
			
			if(vencedor != '0') {
				break;
			}
			
			cheio = 1;
			for(aux = 0; aux < 9; aux++) {
				if(tabuleiro[aux] == ' ') {
					cheio = 0;
					break;
				}
			}
			if(cheio == 1) {
				vencedor = 'n';
				break;
			}
			
			jogadordavez = trocarjogador(jogadordavez);
		}
		
		imprimir(tabuleiro);
		
		if(vencedor == 'n') {
			printf("\nEmpate!");
		}
		else {
			printf("%c venceu a partida.\n", vencedor);
		}
		
		switch(vencedor) {
			case 'x':
				winsx++;
				break;
				
			case 'o':
				winso++;
				break;
			
			case 'n':
				empates++;
				break;
		}
		
		getchar();
	}
}
