#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct app{
	
	char nome[30];

	struct app *prox;
	
};
typedef struct app App;

struct tela{
	
	int id;
	App *aplicativo;
	struct tela *ant;
	struct tela *prox;
};
typedef struct tela Tela;

App *inserePrimeirosApps(App *app){
	
	//criando 3 aplicativos, fazendo-os apontar um para o outro
	app = (App*) malloc(sizeof(App));
	app->prox = NULL;
	strcpy(app->nome, "INSTA");
		
	App *novoApp;
	novoApp = (App*) malloc(sizeof(App));
	novoApp->prox = NULL;
	strcpy(novoApp->nome, "CONFIGURACOES");
	app->prox = novoApp;
		
	App *novoApp2;
	novoApp2 = (App*) malloc(sizeof(App));
	novoApp2->prox = NULL;
	strcpy(novoApp2->nome, "FACE");
	novoApp->prox = novoApp2;
		
	return app;
}

Tela *printaApps(Tela *t){
	
	//sempre armazeno a tela e o app cabeca para devolver para Main
	Tela *telaCabeca = t;
	App *appCabeca = t->aplicativo;  		
	int cont = 0;
	
	while(t != NULL){
			
		printf("\n\nTela %d:\n", t->id);
		//IMPORTANTE: ___________sempre guardo o app inicial de cada tela e depois que navegar por todos os apps da tela, seta o primeiro app para este guardado. Em todo lugar utiliza esta logica
		App *maisUmApp = t->aplicativo;
		
		for(cont = 0; cont < 4; cont++){
				
			if(t->aplicativo->nome == NULL){
				
				break;
				
			} else {
				
				puts(t->aplicativo->nome);
				if(t->aplicativo->prox == NULL){
					
					break;
				
				} else {
					
					t->aplicativo = t->aplicativo->prox;
				}
					
			}
			
		}
		
		//apontando novamente para o primeiro aplicativo da sua tela
		t->aplicativo = maisUmApp;	
		t = t->prox;
		
	}
		
	telaCabeca->aplicativo = appCabeca;	
	return telaCabeca;
			
}

int escolheOpcao(){
	
	printf("\n\n O que voce deseja fazer? Utilize os nuemros para escolher:");
    printf("\n 1. ADD APP");
    printf("\n 2. REMOVER APP");
    printf("\n 3. VISUALIZAR TELA POR TELA");
    printf("\n 5. DESLIGAR");

    int opcao;
    printf("\n\n SELECIONE UMA OPCAO: ");
    scanf("%d", &opcao);
   
    return opcao;
}

App *insereApp(App *app, char nome[30]){
	
	App *auxApp = app;
	
	//vai ate o ultimo app
	while(auxApp->prox != NULL){	
		auxApp = auxApp->prox;	
	}
	
	//cria o novo e faz os devidos apontamentos
	App *novo;
	novo = (App*) malloc(sizeof(App));	
	auxApp->prox = novo;
	novo->prox = NULL;
	strcpy(novo->nome, nome);
	
	return app;
		
}

Tela *verificaNecessidadeNovaTela(Tela *t, App *app, int *pontQuant){
	
	Tela *telaCabeca = t;
	App *appCabeca = app;
	
	int cont = 1;
	
	//conta quantos apps tem na lista de app para fazer comparacao com aquela variavel da Main
	while(app->prox != NULL){		
		cont++;
		app = app->prox;
	}
	
	//compara com a variavel da Main	
	if(cont > *pontQuant){
		//devo criar nova tela
		
		//primeiro navega ate a ultima tela existente
		while(t->prox != NULL){
			t = t->prox;
		}
		
		//como uma nova tela eh criada. Essa variavel deve ser aumentada em 4, para garantir a criacao de telas corretamente
		*pontQuant = *pontQuant + 4;
		
		//criando nova tela e fazendo os devidos apontamentos. Inclusive que o ultimo app inserido eh o primeiro desta tela
		Tela *novaTela;
		novaTela = (Tela*) malloc(sizeof(Tela));
		t->prox = novaTela;
		novaTela->ant = t;
		novaTela->id = t->id + 1;
		novaTela->aplicativo = app;
		novaTela->prox = NULL;
		 
	}
	
	telaCabeca->aplicativo = appCabeca;
	return telaCabeca;
	
}

Tela *removerAppPrimeiros(App *app, Tela *t, char nome[30], App **pontApp, int *pConfereJaExlcuiu){
	
	int teste = 0, igual;
	
	Tela *telaCabeca = t;
	App *appCabeca = t->aplicativo;
	
	int cont = 0;
	App *maisUmApp = t->aplicativo;
	
	while(t != NULL){
		
		//se teste for 1 quer dizer que um app ja foi excluido. Entao basta em cada peoxima tela, fazer o ponteiro do primeiro app apontar para o proximo app
		if(teste == 1){
			
			t->aplicativo = t->aplicativo->prox;
			t = t->prox;
			
		} else {
			
			for(cont = 0; cont < 4; cont++){
				
				if(cont == 0){
					
					if(t->aplicativo->nome != NULL){
									
						igual = strcmp(t->aplicativo->nome, nome);
							
					}
					
					if(t->aplicativo->nome == NULL){
					
						break;
					
					//caso o app seja o primeiro de uma tela
					} else if(igual == 0){
						//setando essa variavel da main para 1, assim nao entrara na outra funcao
						*pConfereJaExlcuiu = 1;
							
						//se for o primeiro app da primeira tela entra aqui
						if(t->ant == NULL){
								
							//faz a reconfiguracao de apontamentos e da free() no app apagado. 
							maisUmApp = t->aplicativo->prox;								
							App *auxApp = app;
							app = app->prox;
							auxApp->prox = NULL;
							free(auxApp);
							//muda o app cabeca da lista de apps la da Main via ponteiro
							*pontApp = app;
							t->aplicativo = maisUmApp;
								
							teste = 1;
							break;
							//se for o primeiro app que nao eh da primeira tela entra aqui
						} else {
								
							//preciso deletar o app da lista de app, para isso tenho q chegar pela lista de app ate o app que vai sair						
							App *auxExcluir = t->aplicativo;
							t->aplicativo = t->aplicativo->prox;
								
							while(app->prox != NULL){
									
								int val = strcmp(app->prox->nome, auxExcluir->nome);
								if(val == 0){
										
									App *excluir = app->prox;
									app->prox = excluir->prox;
									free(excluir);
									break;
										
								}
									
								app = app->prox;
							}
													
							teste = 1;
							break;
						}
							
					} else {
						
						if(t->aplicativo->prox != NULL){
							
							int i = strcmp(t->aplicativo->prox, nome);
							
							if(i == 0){
								
								*pConfereJaExlcuiu = 1;	
								teste = 1;
								
								App *tAplicativo = t->aplicativo->prox;
								t->aplicativo->prox = tAplicativo->prox;
								
								while(app->prox != NULL){
									
									int val = strcmp(app->prox->nome, tAplicativo->nome);
										
									if(val == 0){
											
										free(app->prox);
										break;
									}
									
									app = app->prox;
								}
								
							}
							
						}
							
					}
					
				}
						
			}
			
			t = t->prox;
			
		}
		
		if(t == NULL){
			telaCabeca->aplicativo = maisUmApp;
			return telaCabeca;
		}
				
	}
		
	telaCabeca->aplicativo = maisUmApp;
	return telaCabeca;
	
}

Tela *removerAppUltimos(App *app, Tela *t, char nome[30]){
	
	Tela *telaCabeca = t;
	App *appCabeca = t->aplicativo;
	int aux = 0;
	int cont;	
	App *guardaPrimeiro;
	
	while(t != NULL){
		
		if(aux == 1){
			
			t->aplicativo = t->aplicativo->prox;
						
		} else {
			
			for(cont = 0; cont < 4; cont++){
				
				if(cont == 0){
					
					//sempre guarda o primeiro app de cada tela para no final do percorrimento setar este app como o primeiro		
					guardaPrimeiro = t->aplicativo;
					
				}
				
				//so entra quando estiver navegando nos dois ultimos apps de cada tela
				if(cont == 1 || cont == 2){
					
					//para conseguir fazer o teste
					App *tAplicativo = t->aplicativo;
					int teste = strcmp(tAplicativo->prox->nome, nome);
					
					//achou o app a ser excluido
					if(teste == 0){
						
						//navega a lista de app para dar um free no app a ser excluido
						while(app->prox != NULL){
							
							int test = strcmp(app->prox->nome, nome);
							
							if(test == 0){
								
								App *maisAux = app->prox;
								app->prox = maisAux->prox;	
								maisAux->prox = NULL;
								free(maisAux);
								aux = 1;
								t->aplicativo = guardaPrimeiro;
								break;
							}
							
							app = app->prox;
						}
						
					}
					
				}
				
				if(aux == 1){
					break;
				}
				
				t->aplicativo = t->aplicativo->prox;
				
				if(cont == 3){					
					t->aplicativo = guardaPrimeiro;	
				}
			}
			
		}
					
		t = t->prox;
		
	}
	
	telaCabeca->aplicativo = appCabeca;
	return telaCabeca;
	
}

Tela *verificaNecessidadeApagarTela(Tela *t, int *pontQuant){
	
	Tela *telaCabeca = t;
	App *appCabeca = t->aplicativo;
	
	//vai ate a ultima tela
	while(t->prox != NULL){		
		t = t->prox;		
	}
	
	//se o primeiro app da ultima tela for nulo eh pq deve apagar a tela
	if(t->aplicativo == NULL){
	
		t->ant->prox = NULL;
		free(t);
		//IMPORTANTE________decrementar em 4 essa varavel de controle da Main. Ela eh fundamental para controlar quando criar novas telas
		*pontQuant = *pontQuant - 4;
		
	}
		
	telaCabeca->aplicativo = appCabeca;
	return telaCabeca;
		
}

int confereExisteApp(App *app, char nome[30]){

	int existeApp = 0;
	
	while(app != NULL){
	
		int teste = strcmp(app->nome, nome);
		if(teste == 0){
		
			existeApp = 1;
			break;
		}
		
		app = app->prox;
	}
	
	if(existeApp == 1){
		return 1;
	}	
	
	return 0;
	
}

void printaUmaTela(App *app, Tela *t){
	printf("\n\n");
	
	//sempre armazeno o app cabeca e passo ele na chamada da propria funcao
	App *appCabeca = app;
	
	printf("Tela %d:\n", t->id);
	
	//na lista de apps, vai ate o app no qual a tela esta apontando
	while(app != NULL){
		
		int igual = strcmp(t->aplicativo->nome, app->nome);
		
		if(igual == 0){
			break;
		}
		
		app = app->prox;
	}
	
	//printa os 4 apps da lista de apps
	int i;
	
	for(i = 0; i < 4; i++){
		
		if(app->nome == NULL){
			break;
		}
		
		puts(app->nome);
		app = app->prox;
	}
	
	char dOUe[1];
	printf("\nClique na tecla (D) para ir para tela direita e a tecla (E) para ir para tela esquerda.\nCaso deseje sair da visualizacao, digite a letra (S) de sair: ");
	fflush(stdin);
	gets(dOUe);
	strupr(dOUe);
	
	int testDireita = strcmp(dOUe, "D");
	int testEsquerda = strcmp(dOUe, "E");
	int sair = strcmp(dOUe, "S");
			
	if(sair == 0){
		
	}else if (testDireita != 0 && testEsquerda != 0){
		
		printf("\nValor invalido");
		
	}else if(testDireita == 0 && t->prox != NULL){
		
		//passa o app cabeca e a proxima tela	
		printaUmaTela(appCabeca, t->prox);
		
	} else if (testEsquerda == 0 && t->ant != NULL){
		
		//passa o app cabeca e a tela anterior	
		printaUmaTela(appCabeca, t->ant);
		
	} else if(t->prox == NULL || t->ant == NULL){
		
		printf("\nNao existe proxima tela!");
		
	}
	
}

void main(){
		
	int opcao = 0;
	char nomeApp[30];
	Tela *tela = NULL;
	App *app = NULL;
	//variavel que auxilida na criacao de tela, seu valor sera alterado dentro das funcoes, por isso tem o ponteiro
	int quant = 4;
	int *pontQuant = &quant;
	
	//insere os primeiros app de forma mais simples
	app = inserePrimeirosApps(app);
	
	//criando a primeira tela para os primeiros apps
	tela = (Tela*) malloc(sizeof(Tela));
	tela->ant = NULL;
	tela->prox = NULL;
	tela->id = 1;
	tela->aplicativo = app;
	
	//printa as telas
	tela = printaApps(tela);
	
	//necessario caso seja apagado o primeiro app de tudo
	App **pontApp = &app;
	
	//funcao que permite o usuario escolher o que fazer	
	opcao = escolheOpcao();

	
	while(opcao !=5){
		
		switch(opcao){
			case 1:
				printf("\n Digite o App: ");
				fflush(stdin);
				gets(nomeApp);
				
				//primeiro testa se existe o app
				int existeApp = confereExisteApp(app, nomeApp);
				if(existeApp != 1){
					
					//insere na lista de app
					app = insereApp(app, nomeApp);
					
					//caso necessario cria novba tela
					tela = verificaNecessidadeNovaTela(tela, app, pontQuant);
					tela = printaApps(tela);
					
				} else {
					
					printf("\nEste app já está instalado!");
				}
					
			break;
				
			case 2:	
				printf("\nQual App você deseja remover? ");
				fflush(stdin);
				gets(nomeApp);
				
				int existe = confereExisteApp(app, nomeApp);
				int naoEhConfig = strcmp(nomeApp, "CONFIGURACOES");
				
				if(existe == 1){
					
					//testa se nao eh o app de CONFIGURACOES. Por controle do programa ele nao pode ser desinstalado
					if(naoEhConfig == 0){
						printf("\nVoce nao possui eh um admin! Proibido excluir este APP!");
						
					} else {
						
						//dentro da proxima funcao, caso um app ser excluido, a variavel a seguir eh setada para 1					
						int confereJaExcluiu = 0;
						int *pConfereJaExlcuiu = &confereJaExcluiu;
						
						//essa funcao apaga os apps caso sejam um dos dois primeiros de qualquer tela
						tela = removerAppPrimeiros(app, tela, nomeApp, pontApp, pConfereJaExlcuiu);
						
						if(confereJaExcluiu == 0){
							
							//essa funcao apaga os apps caso nao sejam um dos dois primeiros de qualquer tela
							tela = removerAppUltimos(app, tela, nomeApp);
							
						}
						
						//caso seja necessario apagar a ultima tela, nessa funcao sera excluida
						tela = verificaNecessidadeApagarTela(tela, pontQuant);	
						tela = printaApps(tela);				
						printf("\n\n");
												
					}
						
				} else {
					printf("\nO app digitado nao esta instalado!");
				}
						
				break;
				
			case 3:
				//chama funcao para visualizar tela por tela
				printaUmaTela(app, tela);
				break;
				
			default:
				printf("\nValor inválido!");
		}
		
		opcao = escolheOpcao();
	}
	
}
