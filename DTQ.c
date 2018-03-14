#include "steamGames.h"


/*------------------------------------------------------------------------------*/
/* Split 2-3-4 -> raiz ou não													*/
/*------------------------------------------------------------------------------*/

Ap234 split234 (Ap234 atual, Ap234 q) {
	int i, ins, qtd, k;
	Ap234 novoEsq, novoDir;


	novoEsq = criaNodo234(q->nome[0], q->linhaRegistro234[0]);
	novoDir = criaNodo234(q->nome[2], q->linhaRegistro234[2]);

	novoEsq->Ap[0] = q->Ap[0];
	novoEsq->Ap[1] = q->Ap[1];

	novoDir->Ap[0] = q->Ap[2];
	novoDir->Ap[1] = q->Ap[3];
	

	if(atual == NULL) {

		strcpy(q->nome[0], q->nome[1]);
		q->linhaRegistro234[0] = q->linhaRegistro234[1]; 

		for ( i = 1 ; i < 4 ; ++i ) 
			strcpy(q->nome[i], "\0");		
		q->qtdNome = 1;

		q->Ap[0] = novoEsq;
		q->Ap[1] = novoDir;

		q->Ap[2] = NULL;
		q->Ap[3] = NULL;


		return q;

	}

	/* Adicionar junto em atual... */	
	else {

		qtd = atual->qtdNome;
		atual = insereNoNodo(atual, q->nome[1], q->linhaRegistro234[1]);

		for(ins = qtd; (ins > 0) && ((strcasecmp(q->nome[1], atual->nome[ins]) != 0)) ; --ins);
		
		for(i = qtd ; i > ins ; --i) 
			atual->Ap[i+1] = atual->Ap[i];

		atual->Ap[i] = novoEsq;
		atual->Ap[i+1] = novoDir;	


		free(q);

		return atual;

	}

}	



/*------------------------------------------------------------------------------*/
/* Função que cria um novo apontador do tipo 2-3-4								*/
/*------------------------------------------------------------------------------*/

Ap234 criaNodo234 (char *jogo, int linha) {
	int i;	
	Ap234 novo;

	if(!( novo = (Ap234) malloc (sizeof(tipo234)) )) {
		printf("Erro de alocação");
		return NULL;
	}

	strcpy(novo->nome[0], jogo);
	novo->linhaRegistro234[0] = linha;
	novo->qtdNome = 1;

	for(i = 0 ; i < 4 ; ++i)
		novo->Ap[i] = NULL;

	return novo;
}



/*------------------------------------------------------------------------------*/
/* Inserção na árvore 2-3-4 -> Pessimista										*/
/*------------------------------------------------------------------------------*/

Ap234 insere234 (Ap234 q, char *jogo, int linha) {
	int i;


	if (q == NULL)   
		return q;

	if ( q->qtdNome == 3 ) 
		q = split234(NULL, q);


	/* Verificação para inserção - Todos os casos. */
	if ( (q->qtdNome == 0) || (strcasecmp(jogo,q->nome[0]) < 0) ) {

		i = 0;
		if((q->Ap[0] != NULL) && (q->Ap[0]->qtdNome == 3)) { 
			q = split234(q, q->Ap[0]);

	 		if (strcasecmp(jogo,q->nome[0]) >= 0)
				i = 1;
		}


		q->Ap[i] = insere234(q->Ap[i], jogo, linha);


		if(q->Ap[i] == NULL) {
			q = insereNoNodo( q, jogo, linha);

			for(i = 0 ; i < 4 ; ++i)
				q->Ap[i] = NULL;
		}
	}

	else if( (q->qtdNome == 1) || (strcasecmp(jogo,q->nome[1]) < 0) ) {

		i = 1;
		if((q->Ap[1] != NULL) && (q->Ap[1]->qtdNome == 3)) {
			q = split234(q, q->Ap[1]);

	  		if (strcasecmp(jogo,q->nome[1]) >= 0)
				i = 2;
		}

		q->Ap[i] = insere234(q->Ap[i], jogo, linha);


		if(q->Ap[i] == NULL) {
			q = insereNoNodo( q, jogo, linha);

			for(i = 0 ; i < 4 ; ++i)
				q->Ap[i] = NULL;
		}

	}

	else {

		i = 2;
		if((q->Ap[2] != NULL) && (q->Ap[2]->qtdNome == 3)) {
			q = split234(q, q->Ap[2]);
	  		if (strcasecmp(jogo,q->nome[2]) >= 0)
				i = 3;
		}

		q->Ap[i] = insere234(q->Ap[i], jogo, linha);


		if(q->Ap[i] == NULL) {
			q = insereNoNodo( q, jogo, linha);

			for(i = 0 ; i < 4 ; ++i)
				q->Ap[i] = NULL;
		}

	}


	return q;

}


/*------------------------------------------------------------------------------*/
/* Insere em um nodo específico da 2-3-4 (no vetor)								*/
/*------------------------------------------------------------------------------*/

Ap234 insereNoNodo(Ap234 q, char *jogo, int linha) {
	int i, k, ins = 0;


	for( i = 0 ; (!ins) && (i < q->qtdNome) ; ++i) {

		if(strcasecmp(jogo,q->nome[i]) < 0 ) { 
			q->qtdNome++;

			for(k = (q->qtdNome-1); k >= i  ; --k) {
				strcpy(q->nome[k+1], q->nome[k]);
				q->linhaRegistro234[k+1] = q->linhaRegistro234[k];
			}

			strcpy(q->nome[i], jogo);
			q->linhaRegistro234[i] = linha;
			ins = 1;
		}
	}
	if(!ins) {
		q->qtdNome++;		
		strcpy(q->nome[i], jogo);
		q->linhaRegistro234[i] = linha;
	}


	return q;
}



/*------------------------------------------------------------------------------*/
/* Busca e chama a função que imprime na linha (para todos os casos - repetidos)*/
/*------------------------------------------------------------------------------*/

void busca234 (Ap234 q, char *jogo, FILE *lol) {
	int i;

	if (q == NULL)
		return;


	for(i = 0; (i < q->qtdNome) && ((strcasecmp(jogo, q->nome[i]) >= 0)) ; ++i) {
		if((strcasecmp(jogo, q->nome[i]) == 0))
			imprimeLinha234(q->linhaRegistro234[i], lol);
	}

	if ( i == q->qtdNome ) {

		busca234(q->Ap[i-1], jogo, lol);
		busca234(q->Ap[i], jogo, lol);

	}

	else {

		busca234(q->Ap[i], jogo, lol);
		busca234(q->Ap[i+1], jogo, lol);
	}	

	return;

}
