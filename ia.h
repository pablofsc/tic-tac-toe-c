#include "jogo.h"

char tabaux[9];

int prever(char jog) {
	int nota = 0, casa;
	
	for(casa = 0; casa < 9; casa++) {
		if(tabaux[casa] == ' ') {
			tabaux[casa] = jog;
			
			if(checarvencedor(tabaux, jog) == jog) {
				nota += 1;
			}
			else if(checarvencedor(tabaux, trocarjogador(jog)) == trocarjogador(jog)) {
				nota -= 1;
			}
			else {
				nota += (-1)*prever(trocarjogador(jog));
			}
			
			tabaux[casa] = ' ';
		}
	}
	
	return(nota);
}

int ia(char maquina) {
	int nota, notamaior = -999999, retorno, casa;
	
	for(casa = 0; casa < 9; casa++) {
		tabaux[casa] = tabuleiro[casa];
	}
	
	for(casa = 0; casa < 9; casa++) {
		if(tabaux[casa] == ' ') {
			nota = 0;
			tabaux[casa] = maquina;
			
			if(checarvencedor(tabaux, maquina) == maquina) { // checa se jogar nessa casa vence o jogo imediatamente
				return(casa);
			}
			else {
				nota = prever(maquina); // chama a função recursiva para gerar uma nota para essa casa
			}
			
			if(nota > notamaior) {
				notamaior = nota;
				retorno = casa;
			}
			else if(nota == notamaior) { // caso haja duas casas com a mesma nota...
				if(rand() % 2 == 1) { // ...escolhe uma delas aleatoriamente
					retorno = casa;
				}
			}
				
			tabaux[casa] = ' '; // esvazia a casa
			
			tabaux[casa] = trocarjogador(maquina);
			
			if(checarvencedor(tabaux, trocarjogador(maquina)) == trocarjogador(maquina)) { // verifica se o humano ganharia na próxima rodada
				return(casa); // impede-o
			}
			
			tabaux[casa] = ' '; // esvazia a casa para checar a próxima
			//printf("%i: %i\n", casa, nota);
		}
	}
	
	return(retorno);
}
