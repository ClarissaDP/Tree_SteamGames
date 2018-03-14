#include "steamGames.h"


/*------------------------------------------------------------------------------*/
/* Imprime a linha no registro para AVL											*/
/*------------------------------------------------------------------------------*/


void imprimeLinhaAVL(int linha, FILE *lol) {
	int i;
	char linhaInteira[500];

	rewind(lol);

	for(i = 0 ; i < linha; ++i)
		fscanf(lol, "\n%[^\n]", linhaInteira);

	fscanf(lol, "\n%[^\n]", linhaInteira);
	printf("%s\n", linhaInteira);

}



/*------------------------------------------------------------------------------*/
/* Imprime a linha no registro para 2-3-4										*/
/*------------------------------------------------------------------------------*/


void imprimeLinha234(int linha, FILE *lol) {
	int i;
	char linhaInteira[500], nome[15], codigo[7];

	rewind(lol);

	for(i = 0 ; i < linha; ++i) 
		fscanf(lol, "\n%[^\n]", linhaInteira);

	fscanf(lol, "%s %s \n%[^\n]",codigo, nome, linhaInteira);
	printf("%s %s %s\n",nome, codigo, linhaInteira);

}


/*------------------------------------------------------------------------------*/
/* Imprime a árvore AVL, conforme especificações de espaços, em pré-ordem				*/
/*------------------------------------------------------------------------------*/

void imprimeAVL (ApAVL p) {
	if(p == NULL) 
		return;

	printf("(%d",p->codigo);
	if (p->esq != NULL)
		printf(" ");

	imprimeAVL(p->esq);
	if ( p->dir != NULL)
		printf(" ");
	imprimeAVL(p->dir);

  printf(")");
  return;


}



/*------------------------------------------------------------------------------*/
/* Imprime a árvore 2-3-4, conforme especificações de espaços, em pré-ordem			*/
/*------------------------------------------------------------------------------*/

void imprime234 (Ap234 q) {
	int i;

	if(q == NULL) 
		return;

	printf("(");	
	for (i = 0 ; i < q->qtdNome ; ++i) {
		printf("%s",q->nome[i]);
		if ( (i+1) < q->qtdNome)	
			printf(";");
	}

	if (q->Ap[0] != NULL)
		printf(" ");

	for (i = 0; i <= q->qtdNome; ++i) 
		imprime234(q->Ap[i]);


	printf(")");

	return;
}



/*------------------------------------------------------------------------------*/
/* Libera todos os espaços das duas árvores											*/
/*------------------------------------------------------------------------------*/


void liberaGeralAVL (ApAVL p) {
	if (p == NULL) 
		return;

	liberaGeralAVL(p->esq);
	liberaGeralAVL(p->dir);

	free(p);

	return;
}


void liberaGeral234 (Ap234 q) {
	int i;

	if (q == NULL) 
		return;

	for(i = 0; i <= q->qtdNome ; ++i)
		liberaGeral234(q->Ap[i]);

	free(q);

	return;
}

