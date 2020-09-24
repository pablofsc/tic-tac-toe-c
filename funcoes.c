#include "protitipos.h" 

#ifdef __unix__
	void limpartela() {
		system("clear");
	}
#endif

#ifdef _WIN32
	void limpartela() {
		system("cls");
	}
#endif

char tabuleiro[9];
int winsx = 0, winso = 0, empates = 0;

void inicializar() {
	int casa;
	for(casa = 0; casa < 9; casa++) {
		tabuleiro[casa] = ' ';
	}
}

void imprimir(char tab[9]) {
	limpartela();
	
	printf("x: %i\n", winsx);
	printf("o: %i\n", winso);
	printf("empates: %i\n", empates);
	
	printf("\n    A   B   C  ");
	printf("\n 1  %c │ %c │ %c ", tab[0], tab[1], tab[2]);
	printf("\n   ───┼───┼─── ");
	printf("\n 2  %c │ %c │ %c ", tab[3], tab[4], tab[5]);
	printf("\n   ───┼───┼─── ");
	printf("\n 3  %c │ %c │ %c ", tab[6], tab[7], tab[8]);
	printf("\n\n");
}

char trocarjogador(char atual) {
	if(atual == 'x') {
		return('o');
	}
	else {
		return('x');
	}
}

char checarvencedor(char tab[9], char jogvez) {
	if(tab[0] == jogvez && tab[1] == jogvez && tab[2] == jogvez) return(jogvez);
	if(tab[3] == jogvez && tab[4] == jogvez && tab[5] == jogvez) return(jogvez);
	if(tab[6] == jogvez && tab[7] == jogvez && tab[8] == jogvez) return(jogvez);

	if(tab[0] == jogvez && tab[3] == jogvez && tab[6] == jogvez) return(jogvez);
	if(tab[1] == jogvez && tab[4] == jogvez && tab[7] == jogvez) return(jogvez);
	if(tab[2] == jogvez && tab[5] == jogvez && tab[8] == jogvez) return(jogvez);
	
	if(tab[0] == jogvez && tab[4] == jogvez && tab[8] == jogvez) return(jogvez);
	if(tab[2] == jogvez && tab[4] == jogvez && tab[6] == jogvez) return(jogvez);
	
	return('0');
}

int jogar(char jog, int pos) {
	if(tabuleiro[pos] == ' ') {
		tabuleiro[pos] = jog;
		return(0);
	}
	else {
		printf("Erro\n");
		getchar();
		return(1);
	}
}

int lerterminal(char jogadordavez){
	int pos, x, y;
	
	do {
		printf("%c? ", jogadordavez);
		char entrada[64] = {'\0', '\0', '\0'};
		
		fgets(entrada, 64, stdin);
		
		if(entrada[1] - 49 >= 0 && entrada[1] - 49 <= 2) { // usuário digitou xy
			x = entrada[0];
			y = entrada[1];
		}
		else { // usuario digitou yx
			x = entrada[1];
			y = entrada[0];
		}
		
		if(x >= 97) {
			x -= 97;
		}
		else {
			x -= 65;
		}
		
		y -= 49;
		
		if(entrada[2] != '\n') {
			x = -1;
			y = -1;
		}
		
		pos = y*3 + x;
	} while((0 > y || y > 2) || (0 > x || x > 2) || tabuleiro[pos] != ' ');
	
	return(pos);
}
