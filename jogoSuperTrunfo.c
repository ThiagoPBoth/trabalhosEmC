/*

Jogo Super Trunfo - Comidas
Autores: Felipe Silva Righi e Thiago Paulo Both

*/

#include <stdio.h>
#include <string.h>
#include <time.h>

struct carta { //Struct para salvar informacoes sobre as cartas

	char nome[20];
	int sabor;
	int saudavel;
	int aroma;
	char tipo;
	int superTrunfo;

}baralhoCompleto[16]; //variavel para guardar o baralho completo


void criaBaralho(struct carta baralhoCompleto[16]) { //funcao que cria as cartas do jogo de forma estatica

	strcpy(baralhoCompleto[0].nome, "Maca");
	baralhoCompleto[0].sabor = 7;
	baralhoCompleto[0].saudavel = 9;
	baralhoCompleto[0].aroma = 9;
	baralhoCompleto[0].tipo = 'A';
	baralhoCompleto[0].superTrunfo = 0;
	
	strcpy(baralhoCompleto[1].nome, "Tangerina");
	baralhoCompleto[1].sabor = 8;
	baralhoCompleto[1].saudavel = 9;
	baralhoCompleto[1].aroma = 6;
	baralhoCompleto[1].tipo = 'A';
	baralhoCompleto[1].superTrunfo = 0;
	
	strcpy(baralhoCompleto[2].nome, "Morango");
	baralhoCompleto[2].sabor = 10;
	baralhoCompleto[2].saudavel = 9;
	baralhoCompleto[2].aroma = 7;
	baralhoCompleto[2].tipo = 'A';
	baralhoCompleto[2].superTrunfo = 0;
	
	strcpy(baralhoCompleto[3].nome, "Pizza");
	baralhoCompleto[3].sabor = 10;
	baralhoCompleto[3].saudavel = 5;
	baralhoCompleto[3].aroma = 10;
	baralhoCompleto[3].tipo = 'A';
	baralhoCompleto[3].superTrunfo = 0;
	
	strcpy(baralhoCompleto[4].nome, "Abacaxi");
	baralhoCompleto[4].sabor = 9;
	baralhoCompleto[4].saudavel = 9;
	baralhoCompleto[4].aroma = 7;
	baralhoCompleto[4].tipo = 'B';
	baralhoCompleto[4].superTrunfo = 0;
	
	strcpy(baralhoCompleto[5].nome, "Amendoim");
	baralhoCompleto[5].sabor = 8;
	baralhoCompleto[5].saudavel = 5;
	baralhoCompleto[5].aroma = 5;
	baralhoCompleto[5].tipo = 'B';
	baralhoCompleto[5].superTrunfo = 0;
	
	strcpy(baralhoCompleto[6].nome, "Peixe");
	baralhoCompleto[6].sabor = 6;
	baralhoCompleto[6].saudavel = 9;
	baralhoCompleto[6].aroma = 9;
	baralhoCompleto[6].tipo = 'B';
	baralhoCompleto[6].superTrunfo = 0;
	
	strcpy(baralhoCompleto[7].nome, "Queijo");
	baralhoCompleto[7].sabor = 8;
	baralhoCompleto[7].saudavel = 5;
	baralhoCompleto[7].aroma = 5;
	baralhoCompleto[7].tipo = 'B';
	baralhoCompleto[7].superTrunfo = 0;
	
	strcpy(baralhoCompleto[8].nome, "Pastel");
	baralhoCompleto[8].sabor = 10;
	baralhoCompleto[8].saudavel = 5;
	baralhoCompleto[8].aroma = 9;
	baralhoCompleto[8].tipo = 'C';
	baralhoCompleto[8].superTrunfo = 0;
	
	strcpy(baralhoCompleto[9].nome, "Brocolis");
	baralhoCompleto[9].sabor = 10;
	baralhoCompleto[9].saudavel = 5;
	baralhoCompleto[9].aroma = 5;
	baralhoCompleto[9].tipo = 'C';
	baralhoCompleto[9].superTrunfo = 0;
	
	strcpy(baralhoCompleto[10].nome, "Rabanete");
	baralhoCompleto[10].sabor = 7;
	baralhoCompleto[10].saudavel = 9;
	baralhoCompleto[10].aroma = 9;
	baralhoCompleto[10].tipo = 'C';
	baralhoCompleto[10].superTrunfo = 1;
	
	strcpy(baralhoCompleto[11].nome, "Pepino");
	baralhoCompleto[11].sabor = 6;
	baralhoCompleto[11].saudavel = 8;
	baralhoCompleto[11].aroma = 5;
	baralhoCompleto[11].tipo = 'C';
	baralhoCompleto[11].superTrunfo = 0;
	
	strcpy(baralhoCompleto[12].nome, "Gilo");
	baralhoCompleto[12].sabor = 5;
	baralhoCompleto[12].saudavel = 8;
	baralhoCompleto[12].aroma = 6;
	baralhoCompleto[12].tipo = 'D';
	baralhoCompleto[12].superTrunfo = 0;
	
	strcpy(baralhoCompleto[13].nome, "Figado");
	baralhoCompleto[13].sabor = 5;
	baralhoCompleto[13].saudavel = 10;
	baralhoCompleto[13].aroma = 5;
	baralhoCompleto[13].tipo = 'D';
	baralhoCompleto[13].superTrunfo = 0;
	
	strcpy(baralhoCompleto[14].nome, "Churrasco");
	baralhoCompleto[14].sabor = 10;
	baralhoCompleto[14].saudavel = 7;
	baralhoCompleto[14].aroma = 10;
	baralhoCompleto[14].tipo = 'D';
	baralhoCompleto[14].superTrunfo = 0;
	
	strcpy(baralhoCompleto[15].nome, "Churros");
	baralhoCompleto[15].sabor = 9;
	baralhoCompleto[15].saudavel = 6;
	baralhoCompleto[15].aroma = 10;
	baralhoCompleto[15].tipo = 'D';
	baralhoCompleto[15].superTrunfo = 0;
	
	int i;
	
	printf("Baralho com todas as cartas:\n\n");
	
	for(i = 0; i < 16; i++) { //imprime o baralho completo
	
		printf("\n\n");
		puts(baralhoCompleto[i].nome);
		printf("\nSabor: %d ", baralhoCompleto[i].sabor);
		printf("\nSaudavel: %d ", baralhoCompleto[i].saudavel);
		printf("\nAroma: %d ", baralhoCompleto[i].aroma);
		printf("\nTipo: %c ", baralhoCompleto[i].tipo);
		printf("\nSuper Trunfo: %d ", baralhoCompleto[i].superTrunfo);
		
		printf("\n\n\n");

	}

}


void embaralhaBaralhoCompleto(struct carta baralhoCompleto[16]){ //funcao que embaralha as cartas do jogo de forma aleatoria

	srand(time(NULL));
	
	int i = 0, j;
	
	struct carta guardaCarta;
	
	do {
	
		//salvando o objeto da posicao "i" para nao sobrescreve-lo
		strcpy(guardaCarta.nome, baralhoCompleto[i].nome);
		guardaCarta.sabor = baralhoCompleto[i].sabor;		
		guardaCarta.saudavel = baralhoCompleto[i].saudavel;
		guardaCarta.aroma = baralhoCompleto[i].aroma;
		guardaCarta.tipo = baralhoCompleto[i].tipo;
		guardaCarta.superTrunfo = baralhoCompleto[i].superTrunfo;
	
		//sorteando uma posicao para fazer as trocas
		j = rand() % 16;
		
		//a posicao sorteada vai para posicao "i"
		strcpy(baralhoCompleto[i].nome, baralhoCompleto[j].nome);
		baralhoCompleto[i].sabor = baralhoCompleto[j].sabor;
		baralhoCompleto[i].saudavel = baralhoCompleto[j].saudavel;
		baralhoCompleto[i].aroma = baralhoCompleto[j].aroma;
		baralhoCompleto[i].tipo = baralhoCompleto[j].tipo;
		baralhoCompleto[i].superTrunfo = baralhoCompleto[j].superTrunfo;
		
		//a posicao sorteada recebe a carta que foi salva anteriormente
		strcpy(baralhoCompleto[j].nome, guardaCarta.nome);
		baralhoCompleto[j].sabor = guardaCarta.sabor;
		baralhoCompleto[j].saudavel = guardaCarta.saudavel;
		baralhoCompleto[j].aroma = guardaCarta.aroma;
		baralhoCompleto[j].tipo = guardaCarta.tipo;
		baralhoCompleto[j].superTrunfo = guardaCarta.superTrunfo;
		
		
		i++;
		//essas trocas sao efetuadas 16 vezes. Obs: nada impede de uma carta permanecer no mesmo lugar
	} while(i < 16);
	
	
	printf("\n\nBaralho embaralhado:\n"); //imprime o baralho ja embaralhado
	for(i = 0; i < 16; i++) {
	
		printf("\n");
		puts(baralhoCompleto[i].nome);
		printf("\nSabor: %d ", baralhoCompleto[i].sabor);
		printf("\nSaudavel: %d ", baralhoCompleto[i].saudavel);
		printf("\nAroma: %d ", baralhoCompleto[i].aroma);
		printf("\nTipo: %c ", baralhoCompleto[i].tipo);
		printf("\nSuper Trunfo: %d ", baralhoCompleto[i].superTrunfo);
		
		printf("\n\n\n");
	
	}
	
}

void distribuiCartas(struct carta baralhoCompleto[16], struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16]){
	//funcao que distribui as 8 primeiras cartas para o j1 e as 8 ultimas para o j2
	
	int i, j;
	
	//preenchendo todas as posicoes do nome para limpar a sujeira do j1
	for(i = 0; i < 16; i++){
		
		strcpy(baralhoJogadorUm[i].nome, "vazio");
		
	}
	
	for(i = 0; i < 8; i++){
		
		strcpy(baralhoJogadorUm[i].nome, baralhoCompleto[i].nome);
		baralhoJogadorUm[i].sabor = baralhoCompleto[i].sabor;
		baralhoJogadorUm[i].saudavel = baralhoCompleto[i].saudavel;
		baralhoJogadorUm[i].aroma = baralhoCompleto[i].aroma;
		baralhoJogadorUm[i].tipo = baralhoCompleto[i].tipo;
		baralhoJogadorUm[i].superTrunfo = baralhoCompleto[i].superTrunfo;
	}
	
	//preenchendo todas as posicoes do nome para limpar a sujeira do j2
	for(i = 0; i < 16; i++){
		
			strcpy(baralhoJogadorDois[i].nome, "vazio");
			
		}
	
	//logica para preencher as 8 primeiras posicoes de um vetor com as 8 ultimas posicoes de outro vetor
	for(i = 0, j = 8; i < 8 && j < 16; i++, j++){
		//puts(baralhoCompleto[j].nome);
		strcpy(baralhoJogadorDois[i].nome, baralhoCompleto[j].nome);
		baralhoJogadorDois[i].sabor = baralhoCompleto[j].sabor;
		baralhoJogadorDois[i].saudavel = baralhoCompleto[j].saudavel;
		baralhoJogadorDois[i].aroma = baralhoCompleto[j].aroma;
		baralhoJogadorDois[i].tipo = baralhoCompleto[j].tipo;
		baralhoJogadorDois[i].superTrunfo = baralhoCompleto[j].superTrunfo;
	}
	
		printf("\n\nBaralho do jogador um:\n"); //imprime o baralho do jogador um
	for(i = 0; i < 8; i++) {
	
		printf("\n");
		puts(baralhoJogadorUm[i].nome);
		printf("\nSabor: %d ", baralhoJogadorUm[i].sabor);
		printf("\nSaudavel: %d ", baralhoJogadorUm[i].saudavel);
		printf("\nAroma: %d ", baralhoJogadorUm[i].aroma);
		printf("\nTipo: %c ", baralhoJogadorUm[i].tipo);
		printf("\nSuper Trunfo: %d ", baralhoJogadorUm[i].superTrunfo);
		
		printf("\n\n\n");
	
	}
	
	printf("\n\nBaralho do jogador dois:\n"); //imprime o baralho do jogador dois
	for(i = 0; i < 8; i++) {
		
		printf("\n");
		puts(baralhoJogadorDois[i].nome);
		printf("\nSabor: %d ", baralhoJogadorDois[i].sabor);
		printf("\nSaudavel: %d ", baralhoJogadorDois[i].saudavel);
		printf("\nAroma: %d ", baralhoJogadorDois[i].aroma);
		printf("\nTipo: %c ", baralhoJogadorDois[i].tipo);
		printf("\nSuper Trunfo: %d ", baralhoJogadorDois[i].superTrunfo);
		
		printf("\n\n\n");
	
	}
	
	
	
	
}

void printaUm(struct carta baralhoJogadorUm[16]){ //funcao que imprime o baralho do jogador um
	int i;
	
	printf("\n\n\nbaralho do jogador 1 nesta rodada: \n");
	for (i = 0; i < 16; i++){
		
		int teste = strcmp(baralhoJogadorUm[i].nome, "vazio");
		
		if(teste == 0){
		
			printf("\n");
			puts(baralhoJogadorUm[i].nome);
		
		} else {
			
			printf("\n\n");
			puts(baralhoJogadorUm[i].nome);
			printf("\nSabor: %d", baralhoJogadorUm[i].sabor);
			printf("\nSasudavel: %d", baralhoJogadorUm[i].saudavel);
			printf("\nAroma: %d", baralhoJogadorUm[i].aroma);
			printf("\nTipo: %c", baralhoJogadorUm[i].tipo);
			printf("\nSuper Trunfo: %d", baralhoJogadorUm[i].superTrunfo);
			
		}
		
	}
}

void printaDois(struct carta baralhoJogadorDois[16]){ //funcao que imprime o baralho do jogador dois
	int i;
	
	printf("\n\n\nbaralho do jogador 1 nesta rodada: \n");
	for (i = 0; i < 16; i++){
		
		int teste = strcmp(baralhoJogadorDois[i].nome, "vazio");
		
		if(teste == 0){
		
			printf("\n");
			puts(baralhoJogadorDois[i].nome);
		
		} else {
		
			printf("\n\n");
			puts(baralhoJogadorDois[i].nome);
			printf("\nSabor: %d", baralhoJogadorDois[i].sabor);
			printf("\nSaudavel: %d", baralhoJogadorDois[i].saudavel);
			printf("\nAroma: %d", baralhoJogadorDois[i].aroma);
			printf("\nTipo: %c", baralhoJogadorDois[i].tipo);
			printf("\nSuper Trunfo: %d", baralhoJogadorDois[i].superTrunfo);
			
		}
		
	}
}

void printaBaralhos(struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16]){
	//funcao que imprime o baralho tanto do jogador um e do jogador dois
	
	int i;
	
	printf("\n\n\nbaralho do jogador 1:\n");
	for (i = 0; i < 16; i++){
		
		int teste = strcmp(baralhoJogadorUm[i].nome, "vazio");
		
		if(teste == 0){
			
			printf("\n");
			puts(baralhoJogadorUm[i].nome);
		
		} else {
			
			printf("\n\n");
			puts(baralhoJogadorUm[i].nome);
			printf("\nSabor: %d", baralhoJogadorUm[i].sabor);
			printf("\naudavel: %d", baralhoJogadorUm[i].saudavel);
			printf("\nAroma: %d", baralhoJogadorUm[i].aroma);
			printf("\nTipo: %c", baralhoJogadorUm[i].tipo);
			printf("\nSuper Trunfo: %d", baralhoJogadorUm[i].superTrunfo);
			
		}
		
	}
	
	printf("\n\n\nbaralho do jogador 2:\n");
	for (i = 0; i < 16; i++){
		
		int teste = strcmp(baralhoJogadorDois[i].nome, "vazio");
		
		if(teste == 0){
		
			printf("\n");
			puts(baralhoJogadorDois[i].nome);
		
		} else {
			
			printf("\n\n");
			puts(baralhoJogadorDois[i].nome);
			printf("\nSabor:%d", baralhoJogadorDois[i].sabor);
			printf("\nSaudavel: %d", baralhoJogadorDois[i].saudavel);
			printf("\nAroma: %d", baralhoJogadorDois[i].aroma);
			printf("\nTipo:%c", baralhoJogadorDois[i].tipo);
			printf("\nSuper Trunfo: %d", baralhoJogadorDois[i].superTrunfo);
			
		}
		
	}
	
	
}

void alteraPosicaoUm(struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16]){
	//funcao que altera a posicao das cartas quando o jogador um vence a rodada
	
	int i, guardaPosicao;
	struct carta salvaCarta;
	
	//primeiro é salva a carta da posicao 0 do baralho do jogador um
	strcpy(salvaCarta.nome, baralhoJogadorUm[0].nome);
	salvaCarta.sabor = baralhoJogadorUm[0].sabor;
	salvaCarta.saudavel = baralhoJogadorUm[0].saudavel;
	salvaCarta.aroma = baralhoJogadorUm[0].aroma;
	salvaCarta.tipo = baralhoJogadorUm[0].tipo;
	salvaCarta.superTrunfo = baralhoJogadorUm[0].superTrunfo;
	
	
	//aqui as cartas validas sao puxadas para frente 	
	for(i = 0; i < 16; i++){
		
		//somente as cartas validas serao puxadas, por isso temos o seguinte teste:		
		int teste = strcmp(baralhoJogadorUm[i + 1].nome, "vazio");
		
		if(teste != 0) {
			
			strcpy(baralhoJogadorUm[i].nome, baralhoJogadorUm[i + 1].nome);
			baralhoJogadorUm[i].sabor = baralhoJogadorUm[i + 1].sabor;
			baralhoJogadorUm[i].saudavel = baralhoJogadorUm[i + 1].saudavel;
			baralhoJogadorUm[i].aroma = baralhoJogadorUm[i + 1].aroma;
			baralhoJogadorUm[i].tipo = baralhoJogadorUm[i + 1].tipo;
			baralhoJogadorUm[i].superTrunfo = baralhoJogadorUm[i + 1].superTrunfo;
					
		//quando perceber que a carta da posicao "i" + 1 esta vazia, armazena-se o "i"			
		} else {
			
			guardaPosicao = i;
			break;
		}
					
	}
	
	//na posicao guardada eh acrescentada a carta da posicao 0 do jogador dois		
	strcpy(baralhoJogadorUm[guardaPosicao].nome, baralhoJogadorDois[0].nome);
	baralhoJogadorUm[guardaPosicao].sabor = baralhoJogadorDois[0].sabor;
	baralhoJogadorUm[guardaPosicao].saudavel = baralhoJogadorDois[0].saudavel;
	baralhoJogadorUm[guardaPosicao].aroma = baralhoJogadorDois[0].aroma;
	baralhoJogadorUm[guardaPosicao].tipo = baralhoJogadorDois[0].tipo;
	baralhoJogadorUm[guardaPosicao].superTrunfo = baralhoJogadorDois[0].superTrunfo;
	
	//na posicao que sucede a posicao guardada armazena-se a carta que foi salva anteriormente		
	strcpy(baralhoJogadorUm[guardaPosicao + 1].nome, salvaCarta.nome);
	baralhoJogadorUm[guardaPosicao + 1].sabor = salvaCarta.sabor;
	baralhoJogadorUm[guardaPosicao + 1].saudavel = salvaCarta.saudavel;
	baralhoJogadorUm[guardaPosicao + 1].aroma = salvaCarta.aroma;
	baralhoJogadorUm[guardaPosicao + 1].tipo = salvaCarta.tipo;
	baralhoJogadorUm[guardaPosicao + 1].superTrunfo = salvaCarta.superTrunfo;
			
	
	//o baralho do jogador tambem deve ser ajeitado: basta puxar as cartas par afrente		
	for(i = 0; i < 16; i++){
				
		int teste = strcmp(baralhoJogadorDois[i + 1].nome, "vazio");
		if(teste != 0) {
					
			strcpy(baralhoJogadorDois[i].nome, baralhoJogadorDois[i + 1].nome);
			baralhoJogadorDois[i].sabor = baralhoJogadorDois[i + 1].sabor;
			baralhoJogadorDois[i].saudavel = baralhoJogadorDois[i + 1].saudavel;
			baralhoJogadorDois[i].aroma = baralhoJogadorDois[i + 1].aroma;
			baralhoJogadorDois[i].tipo = baralhoJogadorDois[i + 1].tipo;
			baralhoJogadorDois[i].superTrunfo = baralhoJogadorDois[i + 1].superTrunfo;
					
					
		} else {
			guardaPosicao = i;
			break;
		}
					
	}
			
	strcpy(baralhoJogadorDois[guardaPosicao].nome, "vazio");
	
	//printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
	
}



void alteraPosicaoDois(struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16]){
	//funcao que altera a posicao das cartas quando o jogador dois vence a rodada (memsa logica da funcao anterior)
	
	struct carta salvaCarta;
	int i, guardaPosicao;
	
	//tratando o baralho do jogador dois que ganhou a rodada
	strcpy(salvaCarta.nome, baralhoJogadorDois[0].nome);
	salvaCarta.sabor = baralhoJogadorDois[0].sabor;
	salvaCarta.saudavel = baralhoJogadorDois[0].saudavel;
	salvaCarta.aroma = baralhoJogadorDois[0].aroma;
	salvaCarta.tipo = baralhoJogadorDois[0].tipo;
	salvaCarta.superTrunfo = baralhoJogadorDois[0].superTrunfo;
	
	for(i = 0; i < 16; i++) {
		
		int teste = strcmp(baralhoJogadorDois[i + 1].nome, "vazio");
		
		if(teste != 0){
			
			strcpy(baralhoJogadorDois[i].nome, baralhoJogadorDois[i + 1].nome);
			baralhoJogadorDois[i].sabor = baralhoJogadorDois[i + 1].sabor;
			baralhoJogadorDois[i].saudavel = baralhoJogadorDois[i + 1].saudavel;
			baralhoJogadorDois[i].aroma = baralhoJogadorDois[i + 1].aroma;
			baralhoJogadorDois[i].tipo = baralhoJogadorDois[i + 1].tipo;
			baralhoJogadorDois[i].superTrunfo = baralhoJogadorDois[i + 1].superTrunfo;
			
		} else {
			guardaPosicao = i;
			break;
		}
			
	}
	
	strcpy(baralhoJogadorDois[guardaPosicao].nome, baralhoJogadorUm[0].nome);
	baralhoJogadorDois[guardaPosicao].sabor = baralhoJogadorUm[0].sabor;
	baralhoJogadorDois[guardaPosicao].saudavel = baralhoJogadorUm[0].saudavel;
	baralhoJogadorDois[guardaPosicao].aroma = baralhoJogadorUm[0].aroma;
	baralhoJogadorDois[guardaPosicao].tipo = baralhoJogadorUm[0].tipo;
	baralhoJogadorDois[guardaPosicao].superTrunfo = baralhoJogadorUm[0].superTrunfo;
	
	strcpy(baralhoJogadorDois[guardaPosicao + 1].nome, salvaCarta.nome);
	baralhoJogadorDois[guardaPosicao + 1].sabor = salvaCarta.sabor;
	baralhoJogadorDois[guardaPosicao + 1].saudavel = salvaCarta.saudavel;
	baralhoJogadorDois[guardaPosicao + 1].aroma = salvaCarta.aroma;
	baralhoJogadorDois[guardaPosicao + 1].tipo = salvaCarta.tipo;
	baralhoJogadorDois[guardaPosicao + 1].superTrunfo = salvaCarta.superTrunfo;
	
	//remontando baralho do jogador 1 que perdeu esta rodada
	for(i = 0; i < 16; i++){
		
		int teste = strcmp(baralhoJogadorUm[i + 1].nome, "vazio");
		
		if(teste != 0){
			
			strcpy(baralhoJogadorUm[i].nome, baralhoJogadorUm[i + 1].nome);
			baralhoJogadorUm[i].sabor = baralhoJogadorUm[i + 1].sabor;
			baralhoJogadorUm[i].saudavel = baralhoJogadorUm[i + 1].saudavel;
			baralhoJogadorUm[i].aroma = baralhoJogadorUm[i + 1].aroma;
			baralhoJogadorUm[i].tipo = baralhoJogadorUm[i + 1].tipo;
			baralhoJogadorUm[i].superTrunfo = baralhoJogadorUm[i + 1].superTrunfo;
			
		} else {
			guardaPosicao = i;
			break;
		}
		
	}
	
	strcpy(baralhoJogadorUm[i].nome, "vazio");
	
//	printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
	
	
}

void alteraPosicaoEmpate(struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16]){
	//funcao que altera a posicao dos baralhos dos dois jogadores quando houver empate normal
	//regra: quando ha empate, a primeira carta de cada jogador vai para o final do montate do seu baralho
	//a logica tambem eh parecida com as duas funcoes enteriores
	
	struct carta salvaCarta;
	int i, guardaPosicao;
	
	//empate cartas do j1
	strcpy(salvaCarta.nome, baralhoJogadorUm[0].nome);
	salvaCarta.sabor = baralhoJogadorUm[0].sabor;
	salvaCarta.saudavel = baralhoJogadorUm[0].saudavel;
	salvaCarta.aroma = baralhoJogadorUm[0].aroma;
	salvaCarta.tipo = baralhoJogadorUm[0].tipo;
	salvaCarta.superTrunfo = baralhoJogadorUm[0].superTrunfo;
	
	for(i = 0; i < 16; i++){
		
		int teste = strcmp(baralhoJogadorUm[i + 1].nome, "vazio");
		
		if(teste != 0){
			strcpy(baralhoJogadorUm[i].nome, baralhoJogadorUm[i + 1].nome);
			baralhoJogadorUm[i].sabor = baralhoJogadorUm[i + 1].sabor;
			baralhoJogadorUm[i].saudavel = baralhoJogadorUm[i + 1].saudavel;
			baralhoJogadorUm[i].aroma = baralhoJogadorUm[i + 1].aroma;
			baralhoJogadorUm[i].tipo = baralhoJogadorUm[i + 1].tipo;
			baralhoJogadorUm[i].superTrunfo = baralhoJogadorUm[i + 1].superTrunfo;
		}
		
		else{
			guardaPosicao = i;
			break;
		}	
	}
	
	strcpy(baralhoJogadorUm[guardaPosicao].nome, salvaCarta.nome);
	baralhoJogadorUm[guardaPosicao].sabor = salvaCarta.sabor;
	baralhoJogadorUm[guardaPosicao].saudavel = salvaCarta.saudavel;
	baralhoJogadorUm[guardaPosicao].aroma = salvaCarta.aroma;
	baralhoJogadorUm[guardaPosicao].tipo = salvaCarta.tipo;
	baralhoJogadorUm[guardaPosicao].superTrunfo = salvaCarta.superTrunfo;
	
	
	
	//empate cartas do j2
	strcpy(salvaCarta.nome, baralhoJogadorDois[0].nome);
	salvaCarta.sabor = baralhoJogadorDois[0].sabor;
	salvaCarta.saudavel = baralhoJogadorDois[0].saudavel;
	salvaCarta.aroma = baralhoJogadorDois[0].aroma;
	salvaCarta.tipo = baralhoJogadorDois[0].tipo;
	salvaCarta.superTrunfo = baralhoJogadorDois[0].superTrunfo;
	
	for(i = 0; i < 16; i++){
		
		int teste = strcmp(baralhoJogadorDois[i + 1].nome, "vazio");
		
		if(teste != 0){
			strcpy(baralhoJogadorDois[i].nome, baralhoJogadorDois[i + 1].nome);
			baralhoJogadorDois[i].sabor = baralhoJogadorDois[i + 1].sabor;
			baralhoJogadorDois[i].saudavel = baralhoJogadorDois[i + 1].saudavel;
			baralhoJogadorDois[i].aroma = baralhoJogadorDois[i + 1].aroma;
			baralhoJogadorDois[i].tipo = baralhoJogadorDois[i + 1].tipo;
			baralhoJogadorDois[i].superTrunfo = baralhoJogadorDois[i + 1].superTrunfo;
		}
		
		else{
			guardaPosicao = i;
			break;
		}	
	}
	
	strcpy(baralhoJogadorDois[guardaPosicao].nome, salvaCarta.nome);
	baralhoJogadorDois[guardaPosicao].sabor = salvaCarta.sabor;
	baralhoJogadorDois[guardaPosicao].saudavel = salvaCarta.saudavel;
	baralhoJogadorDois[guardaPosicao].aroma = salvaCarta.aroma;
	baralhoJogadorDois[guardaPosicao].tipo = salvaCarta.tipo;
	baralhoJogadorDois[guardaPosicao].superTrunfo = salvaCarta.superTrunfo;
	
	
	
	
}

int pegarPosicaoEmpateUm(struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16]){
	//funcao que conta a quantidade de cartas que o jogador um tem na rodada
	//ela ajuda a resolver o empate quando um dos jogadores so possui uma carta
	
	int i, quantidadeCartasUm;	
			
	for(i = 0; i < 16; i++){
				
		int teste = strcmp(baralhoJogadorUm[i].nome, "vazio");
		
		if(teste == 0) {
			quantidadeCartasUm = i;
			break;
		}			
	}
			
	
	return quantidadeCartasUm;
	
}

int testa(struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16], int controlaJogadas){
	//funcao que testa se o jogador tem o supertrunfo ou nao e realiza as jogadas se satifazer uma das condicionais if's e else's
	
	srand(time(NULL));
	int aux = 0;
	
	//bloco de codigo que teste a parte do superTrunfo__________________________________________________
	
	//se o jogador um tiver o superTrunfo
	if(baralhoJogadorUm[0].superTrunfo == 1){
		
		//esta variavel auxilia para nao executar as operacoes apos este bloco de codigo que trata o super trunfo
		aux = 1;
		
		//se o jogador dois nao tiver carta do tipo A, o jogador um ganha
		if(baralhoJogadorDois[0].tipo != 'A'){
			
			alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
			printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
			//variavel decrementada para auxiliar no sistema que deixa o jogador que ganhou a ultima rodada escolher a caracteristica para batalhar
			if(controlaJogadas % 2 != 0){
				controlaJogadas--;	
			}
			
		
		//jogador dois tem carta do tipo A entao ele deve ganhar esta rodada
		} else {
			
			alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
			printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
			if(controlaJogadas % 2 == 0){
				controlaJogadas--;	
			}
			
		}
		
	//caso o jogador dois tenha o super trunfo sera a mesma logica	
	} else if (baralhoJogadorDois[0].superTrunfo == 1){
		
		aux = 1;
			
		if(baralhoJogadorUm[0].tipo != 'A'){
				
			alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
			printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
			if(controlaJogadas % 2 == 0){
				controlaJogadas--;	
			}
			
		} else {
			
			alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
			printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
			if(controlaJogadas % 2 != 0){
				controlaJogadas--;	
			}
			
		}
	
	}
	//__________________________________________________________________
	
	//so entra aqui se nao tiver trunfo envolvido. Neste momento que a variavel aux entra
	if(aux == 0){
		
		//jogador 1 eh o impar e ele comeca escolhendo a caracteristica
		if(controlaJogadas % 2 != 0){
						
			printf("\n\nAqui o jogador 1 escolhe a caracteristica para batalhar: ");
			//sera escolhida de forma automatica
			int escolheCaracteristica = rand() % 3;
			printf("\n\nA caracteristica escolhida foi a %d", escolheCaracteristica);
			
			//vai comparar o sabor
			if(escolheCaracteristica == 0) {
				
				if(baralhoJogadorUm[0].sabor > baralhoJogadorDois[0].sabor) {
					
					alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					controlaJogadas--;
					
				} else if (baralhoJogadorUm[0].sabor == baralhoJogadorDois[0].sabor) {
					
					//chama funcao que conta a quantidade de cartas do jogador 1. Se for 15, ele deve ganhar:
					int contadorCartasj1 = pegarPosicaoEmpateUm(baralhoJogadorUm, baralhoJogadorDois);
					
					if(contadorCartasj1 == 15){
						//retorna que o jogador 1 ganhou pelo empate da ultima carta do jogador 2
						
						alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
						printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
						controlaJogadas--;				                              
					
						
						} else if (contadorCartasj1 == 1) {
							//retorna que o jogador 2 ganhou pelo empate da ultima carta do jogador 1
							
							alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						} else {
							//chama a funcao do empate normal
							
							alteraPosicaoEmpate(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						}
					
				} else {
					
					alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					
				}
				
			//vai comparar a caracteristica saudavel	
			} else if(escolheCaracteristica == 1){
				
				if(baralhoJogadorUm[0].saudavel > baralhoJogadorDois[0].saudavel) {
					
					alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					controlaJogadas--;
					
				} else if (baralhoJogadorUm[0].saudavel == baralhoJogadorDois[0].saudavel) {
					
					//chama funcao que conta a quantidade de cartas do jogador 1. Se for 15, ele deve ganhar:
					int contadorCartasj1 = pegarPosicaoEmpateUm(baralhoJogadorUm, baralhoJogadorDois);
					if(contadorCartasj1 == 15){
						//retorna que o jogador 1 ganhou pelo empate da ultima carta do jogador 2
						
						alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
						printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
						controlaJogadas--;				                              
					
						
						} else if (contadorCartasj1 == 1) {
							//retorna que o jogador 2 ganhou pelo empate da ultima carta do jogador 1
							
							alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						} else {
							//chama a funcao do empate normal
							
							alteraPosicaoEmpate(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						}
					
				} else {
					
					alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					
				}
				
			//vai comparar o aroma	
			} else if(escolheCaracteristica == 2){
			
				if(baralhoJogadorUm[0].aroma > baralhoJogadorDois[0].aroma) {
					
					alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					controlaJogadas--;
					
				} else if (baralhoJogadorUm[0].aroma == baralhoJogadorDois[0].aroma) {
					
					//chama funcao que conta a quantidade de cartas do jogador 1. Se for 15, ele deve ganhar:
					int contadorCartasj1 = pegarPosicaoEmpateUm(baralhoJogadorUm, baralhoJogadorDois);
					if(contadorCartasj1 == 15){
						//retorna que o jogador 1 ganhou pelo empate da ultima carta do jogador 2
						
						alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
						printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
						controlaJogadas--;				                              
					
						
						} else if (contadorCartasj1 == 1) {
							//retorna que o jogador 2 ganhou pelo empate da ultima carta do jogador 1
							
							alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						} else {
							//chama a funcao do empate normal
							
							alteraPosicaoEmpate(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						}
					
				} else {
					
					alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					
				}
				
			}
			
			
			
			
		} else {
			
			
			printf("\n\nAqui o jogador 2 escolhe a caracteristica para batalhar: ");
			
			int escolheCaracteristica = rand() % 3;
			printf("\n\nA caracteristica escolhida foi a %d", escolheCaracteristica);
			
			//vai comparar o sabor
			if(escolheCaracteristica == 0) {
				
				if(baralhoJogadorDois[0].sabor > baralhoJogadorUm[0].sabor) {
					
					alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					controlaJogadas--;
					
				} else if (baralhoJogadorDois[0].sabor == baralhoJogadorUm[0].sabor) {
					
					//chama funcao que conta a quantidade de cartas do jogador 1. Se for 15, ele deve ganhar:
					int contadorCartasj1 = pegarPosicaoEmpateUm(baralhoJogadorUm, baralhoJogadorDois);
					if(contadorCartasj1 == 15){
						//retorna que o jogador 1 ganhou pelo empate da ultima carta do jogador 2
						
						alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
						printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
						controlaJogadas--;				                              
					
						
						} else if (contadorCartasj1 == 1) {
							//retorna que o jogador 2 ganhou pelo empate da ultima carta do jogador 1
							
							alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						} else {
							//chama a funcao do empate normal
							
							alteraPosicaoEmpate(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						}
					
				} else {
					
					alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					
				}
				
			//vai comparar a caracteristica saudavel	
			} else if(escolheCaracteristica == 1){
				
				if(baralhoJogadorDois[0].saudavel > baralhoJogadorUm[0].saudavel) {
					
					alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					controlaJogadas--;
					
				} else if (baralhoJogadorDois[0].saudavel == baralhoJogadorUm[0].saudavel) {
					
					//chama funcao que conta a quantidade de cartas do jogador 1. Se for 15, ele deve ganhar:
					int contadorCartasj1 = pegarPosicaoEmpateUm(baralhoJogadorUm, baralhoJogadorDois);
					if(contadorCartasj1 == 15){
						//retorna que o jogador 1 ganhou pelo empate da ultima carta do jogador 2
						
						alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
						printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
						controlaJogadas--;				                              
					
						
						} else if (contadorCartasj1 == 1) {
							//retorna que o jogador 2 ganhou pelo empate da ultima carta do jogador 1
							
							alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						} else {
							//chama a funcao do empate normal
							
							alteraPosicaoEmpate(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						}
					
				} else {
					
					alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					
				}
				
			//vai comparar o aroma	
			} else if(escolheCaracteristica == 2){
			
				if(baralhoJogadorDois[0].aroma > baralhoJogadorUm[0].aroma) {
					
					alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					controlaJogadas--;
					
				} else if (baralhoJogadorDois[0].aroma == baralhoJogadorUm[0].aroma) {
					
					//chama funcao que conta a quantidade de cartas do jogador 1. Se for 15, ele deve ganhar:
					int contadorCartasj1 = pegarPosicaoEmpateUm(baralhoJogadorUm, baralhoJogadorDois);
					if(contadorCartasj1 == 15){
						//retorna que o jogador 1 ganhou pelo empate da ultima carta do jogador 2
						
						alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
						printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
						controlaJogadas--;				                              
					
						
						} else if (contadorCartasj1 == 1) {
							//retorna que o jogador 2 ganhou pelo empate da ultima carta do jogador 1
							
							alteraPosicaoDois(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						} else {
							//chama a funcao do empate normal
							
							alteraPosicaoEmpate(baralhoJogadorUm, baralhoJogadorDois);
							printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
							
						}
					
				} else {
					
					alteraPosicaoUm(baralhoJogadorUm, baralhoJogadorDois);
					printaBaralhos(baralhoJogadorUm, baralhoJogadorDois);
					
				}
				
			}
			
			
		}
		
	}
	
	
	
	return controlaJogadas;	
}


int verificaGanhou(struct carta baralhoJogadorUm[16], struct carta baralhoJogadorDois[16]){
	//funcao que verifica se um dos jogadores venceu a jogo, retornando o resultado para a funcao main

	int umGanhou = 0;
	int doisGanhou = 0;
	
	umGanhou = strcmp(baralhoJogadorUm[15].nome, "vazio");
	doisGanhou = strcmp(baralhoJogadorDois[15].nome, "vazio");
	
	if(umGanhou != 0){
		return 1;
	}
	
	if(doisGanhou != 0){
		return 2;
	}
	
	return 0;
	
}

void main() { 
	//funcao principal que chama as funcoes cria, embaralha, distribuir as cartas, verifica se um dos jogadores venceu ou nao e inicia o jogo 
	
	int i;
	
	struct carta baralhoJogadorUm[16];
	struct carta baralhoJogadorDois[16];
	
	criaBaralho(baralhoCompleto);
	
	system("pause");
	system("cls");
	
	embaralhaBaralhoCompleto(baralhoCompleto);
	
	distribuiCartas(baralhoCompleto, baralhoJogadorUm, baralhoJogadorDois);
	
	int controlaJogadas = 1, fim = 0;
	
	do {
		
		
		
		controlaJogadas = testa(baralhoJogadorUm, baralhoJogadorDois, controlaJogadas);
		system("pause");
		
		//verificando se aguem ganhou pela ultima posicao
		fim = verificaGanhou(baralhoJogadorUm, baralhoJogadorDois);
		
		if(fim == 1){
			printf("O primeiro jogador ganhou");
			break;
		} else if(fim == 2){
			printf("O segundo jogador ganhou");
			break;
		} else {
			printf("\nNenhum ganahdor nesta rodada");
		}
		
		controlaJogadas++;
			
	} while(fim == 0);
	
}
