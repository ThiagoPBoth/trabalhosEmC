#include<stdio.h>

void criaMatrizInicial(char m[3][3]){
	
	
	printf("Jogo da velha:\n\n");
	int i, j;
	
	for(i = 0; i < 3; i++) {
	
		for(j = 0; j < 3; j++) {
		
			m[i][j] = '_';
			printf("%c\t", m[i][j]);
		
		}
		
		printf("\n");
	
	}
		
}

void printaMatriz(char matriz[3][3]) {
	
	int i, j;
	
	for (i = 0; i < 3; i++) {
				
		for (j = 0; j < 3; j++) {
				
			printf("%c\t", matriz[i][j]);
				
		}
			
		printf("\n");
			
	}
		
}


int jogadaPrimeiroJogador(char matriz[3][3]) {
	
	int i, j, linha, coluna;
	
	//vai pedir para digitar uma posicao ate ela ser valida. A posicao jah nao pode ter sido usada. tambem confere se a posicao existe na matriz
	do {
			
		printf("\nVez do jogador um:");
		
		printf("\nDigite a linha: ");
		scanf("%d", &linha);
		
		printf("Digite a coluna: ");
		scanf("%d", &coluna);
			
	} while((linha < 1 || linha > 3) || (coluna < 1 || coluna > 3) || (matriz[linha - 1][coluna - 1] != '_'));
		
	//somente quando achar uma posicao valida pode inserir X naquela posicao. Sempre X vai se do jogador par e O do jogador impar 	
	matriz[linha - 1][coluna - 1] = 'x';
			
	
	printf("\n\n");
	
	//printa matriz normalmente para o usuario saber como esta o jogo		
	printaMatriz(matriz);
			
	printf("\n\n");
	
	//teste para ver se alguma linha foi formada por X		
	int auxA = 0, ganhou = 0;
			
	for (i = 0; i < 3; i++) {
			
		auxA = 0;
				
		for (j = 0; j < 3; j++) {
				
			if(matriz[i][j] == 'x') {
				
				//essa variavel vai contar o numero de aparicoes do X em cada linha
				auxA++;
						
			}
				
		}
				
		//caso a variavel auxA seja igual a 3, quer dizer que uma linha foi completada com X, entao a variavel ganhou eh incrementada
		if(auxA >= 3) {
			ganhou++;
		}
			
			
	}
			
		
			
	//teste para ver se alguma coluna foi formada por X		
	int auxB = 0;
			
	for (j = 0; j < 3; j++) {
			
		auxB = 0;
				
		for (i = 0; i < 3; i++) {
				
			if(matriz[i][j] == 'x') {
				
				//essa variavel vai contar o numero de aparicoes do X em cada coluna
				auxB++;
			}
							
		}
							
		if(auxB >= 3) {
			
			//caso a variavel auxB seja igual a 3, quer dizer que uma coluna foi completada com X, entao a variavel ganhou eh incrementada
			ganhou++;
		}
			
	}
			
	
	//teste para saber se a diagonal principal esta completa com X		
	int auxC = 0;
			
	for (i = 0, j = 0; i < 3 && j < 3; i++, j++) {
			
		if(matriz[i][j] == 'x') {
			
			//caso a posicao tiver X incrementa auxC
			auxC++;
		}
	}
			
	//teste para saber se a diagonal secundaria esta completa com X			
	int auxD = 0;
			
	for (i = 0, j = 2; i < 3 && j >= 0; i++, j--) {
			
		if(matriz[i][j] == 'x') {
		
			//caso a posicao tiver X incrementa auxD
			auxD++;
		}
	}
			
			
	//Caso auxC ou auxD sejam 3, quer dizer que uma das diagonais esta preenchida de X, entao incrementa a variavel ganhou		
	if(auxC == 3 || auxD == 3) {
		ganhou++;
	}
			
	
	//caso ganhou for maior que 0, de alguma das 8 formas possiveis o jogador preencheu os X necessarios. Logo retorno 1 para main indicando que ele ganhou	
	if(ganhou > 0) {
				
		return 1;	
	} else {
		
		//caso ganhou seja 0, retorna 0 para indicar que nao ganhou ainda		
		return 0;
	}
	
}

//mesma logica acima
int jogadaSegundoJogador(char matriz[3][3]) {
	
	int i, j, linha, coluna;
	
	do {
		
		printf("\nVez do jogador dois:");
		
		printf("\nDigite a linha: ");	
		scanf("%d", &linha);
		
		printf("Digite a coluna: ");	
		scanf("%d", &coluna);
					
	} while((linha < 1 || linha > 3) || (coluna < 1 || coluna > 3) || (matriz[linha - 1][coluna - 1] != '_'));
			
	matriz[linha - 1][coluna - 1] = 'o';
						
	printf("\n\n");
	//printa matriz
	printaMatriz(matriz);
			
	printf("\n\n");
			
			
			
			
	int auxA = 0, ganhou = 0;
			
	for (i = 0; i < 3; i++) {
			
		auxA = 0;
				
		for (j = 0; j < 3; j++) {
				
			if(matriz[i][j] == 'o') {
				auxA++;
			}
				
		}
				
		if(auxA >= 3) {
			ganhou++;
		}
			
			
	}
			
			
	int auxB = 0;
			
	for (j = 0; j < 3; j++) {
			
		auxB = 0;
				
		for (i = 0; i < 3; i++) {
				
			if(matriz[i][j] == 'o') {
				auxB++;
			}
					
					
		}
					
					
		if(auxB >= 3) {
			ganhou++;
		}
			
	}
			
			
	int auxC = 0;
			
	for (i = 0, j = 0; i < 3 && j < 3; i++, j++) {
				
				
		if(matriz[i][j] == 'o') {
					
			auxC++;
				
		}
	}

	int auxD = 0;
			
	for (i = 0, j = 2; i < 3 && j >= 0; i++, j--) {
			
		if(matriz[i][j] == 'o') {
			
			auxD++;
		}
	}
			
			
			
	if(auxC == 3 || auxD == 3) {
		ganhou++;
	}
		
		
		
		
		
	if(ganhou > 0) {
				
		return 1;
	} else {
				
		return 0;
	}

}
 

void main() {


	char matriz[3][3];
	
	int k, cont = 0, deuVelha = 0;
	
	printf("\nREGRAS PARA INICIAR:\n- Decida quem serah o jogador um e o jogador dois (o primeiro jogador serah X e o segundo O)\n- Para jogar, vc precisa digitar a linha e coluna que deseja inserir O ou X\n- Caso vc digite uma posicao ja ocupada, terah que digitar novamente\n\n");
	
	char jogarNovamente;
	do {
		
		//funcao preencher a matriz normalmente. Ela eh preenchida com _
		criaMatrizInicial(matriz);
		
		//for para rodar o maximo de vezes posiveis, ou seja, 9. já que eh o total de posicoes
		for(k = 0; k < 9; k++) {
		
			//quando cont for par quer dizer que o jogador numero 1 vai jogar, quando for impar o segundo vai jogar
			if(cont % 2 == 0) {
			
				//praticamente toda logica do jogo esta aqui
				int ganhou = jogadaPrimeiroJogador(matriz);
				
				//caso a funcao acima retornar 1 quer dizer que o jogador venceu e nem precisa continuar executando
				if(ganhou == 1) {
					
					printf("O jogador numero 1 ganhou!");
					//deuVelha recebe 1 para representar que houve ganhador
					deuVelha = 1;
					break;
				}
				
				
			
			} else {
			
				int ganhou = jogadaSegundoJogador(matriz);
				
				if(ganhou == 1) {
					
					printf("O jogador numero 2 ganhou!");
					deuVelha = 1;
					break;
				}
	
			
			}
			
			//muito importante: vai ser incrementado para alternar as jogadas entre os dois jogadores
			cont++;
		}
		
		//caso nenhum jogador vencer, deuVelha continuara valendo 0
		if (deuVelha == 0) {
			
			printf("\nNenhum jogador venceu!\n");
		}
		
		printf("\nDeseja jogar novamente? (S) para sim e (N) para nao: ");
		fflush(stdin);
		scanf("%c", &jogarNovamente);
	
	} while(jogarNovamente == 's' || jogarNovamente == 'S');

}
