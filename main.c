#include "steamGames.h"


int main(int argc, char *argv[]) {
	FILE *lol, *hue;
	int i, codigo, muda = FALSE, busca;
	char nome[15], semInteresse[500], c = 'a', achar[15];


	if( argc < 3 ) {
		printf("Parâmetros incompletos: %s arqDados arqBuscas\n", argv[0]);
		return (-1);
	}


	/* Inicialização de Árvores */
	ApAVL AVL = NULL;
	ApAVL retornoAVL;

	Ap234 DTQ;
	Ap234 retorno234;

	if(!( DTQ = (Ap234) malloc (sizeof(tipo234)) )) {
		printf("Erro de alocação");
		return (-1);
	}

	DTQ = criaNodo234("\0", 0);
	DTQ->qtdNome = 0;
	

	/* Abertura de arquivos */

	lol = fopen(argv[1], "r");
  
	if (lol == NULL) {
		printf("Arquivo %s não pode ser aberto.\n", argv[1]);
		return 1;
	}


	hue = fopen(argv[2], "r");
	
 	if (hue == NULL) {
		printf("Arquivo %s não pode ser aberto.\n", argv[2]);
		return 1;
	}


	/* Leitura do arquivo de Dados e Montagem das árvores */

	fscanf(lol, "%d %s", &codigo, nome);
	for(i = 0; !(feof(lol)) && codigo != 0; ++i) {
  		AVL = insereAVL(AVL, codigo, &muda, i);
  		DTQ = insere234(DTQ, nome, i);

  		fscanf(lol, "\n%[^\n]", semInteresse);
      fscanf(lol, "%d %s", &codigo, nome);
	}


	/* Impressão das árvores completas */

	printf("Codigo:\n");
	imprimeAVL(AVL);
	printf("\n\nNome:\n");
	imprime234(DTQ);
	printf("\n\n");


	/* Leitura do arquivo de Busca e Procurar/Imprimir conforme opção */

	while (c != 'f') {
		
		fscanf(hue,"%c",&c);

		switch (c) {
	
			case 'c': 	fscanf(hue,"%d",&busca);
						retornoAVL = buscaAVL(AVL,busca);
						if(retornoAVL)
							imprimeLinhaAVL(retornoAVL->linhaRegistroAVL, lol);
						break;

			case 'n': 	fscanf(hue,"%s",achar);
						busca234(DTQ, achar, lol);
						break;

			case 'f':	break;

      		case EOF:	printf("Fim de arquivo errado...\n");
						c = 'f';
						break;
		}

	}

	liberaGeralAVL(AVL);
	liberaGeral234(DTQ);

	fclose(lol);
	fclose(hue);

	return 0;
}
