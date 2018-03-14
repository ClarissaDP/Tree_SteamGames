#include "steamGames.h"


/*------------------------------------------------------------------------------*/
/* Rotações para esquerda e direita												*/
/*------------------------------------------------------------------------------*/

ApAVL rotDir (ApAVL p) {
	ApAVL f;

	f = p->esq;
	p->esq = f->dir;
	f->dir = p;

	return f;
}

ApAVL rotEsq (ApAVL p) {
	ApAVL f;

	f = p->dir;
	p->dir = f->esq;
	f->esq = p;

	return f;
}


/*------------------------------------------------------------------------------*/
/* Arruma o balancemento da árvore, conforme regras								*/
/*------------------------------------------------------------------------------*/

ApAVL balanceiaAVL (ApAVL p) {
	ApAVL filho, neto;


	/* Desbalanceado esquerda */
	if (p->bal == 2){ 
		filho = p->esq;

		/* Caso esq-es */
		if (filho->bal == 1) { 
			filho->bal = 0;
			p->bal = 0;
			return rotDir(p);
		}

		/* Caso esq-dir */
		else{ 
			neto = filho->dir;

			if (neto->bal == 0) {
				filho->bal = 0;
				p->bal = 0;
			}
			else if (neto->bal == 1) {
				filho->bal = 0;
				p->bal = (-1);
			}
			else {
				filho->bal = 1;
				p->bal = 0;
			}
			neto->bal = 0;
			p->esq = rotEsq(filho);
			return rotDir(p);
		}
	}

	/* Desbalanceado direita */
	else{ 
	filho = p->dir;

		/* Caso dir-dir */
		if (filho->bal == (-1)) { 
			filho->bal = 0;
			p->bal = 0;
			return rotEsq(p);
		}

		/* Caso dir-esq */
		else { 
			neto = filho->esq;

			if (neto->bal == 0) {
				filho->bal = 0;
				p->bal = 0;
			}
			else if (neto->bal == (-1)) {
				filho->bal = 0;
				p->bal = 1;
			}
			else {
				filho->bal = (-1);
				p->bal = 0;
			}
			neto->bal = 0;
			p->dir = rotDir(filho);
			return rotEsq(p);
		}
	}
}


/*------------------------------------------------------------------------------*/
/* Cria um novo Nodo e inicializa												*/
/*------------------------------------------------------------------------------*/

ApAVL criaNodoAVL (int k, int linha) {
	ApAVL novo;

	if (!(novo = (ApAVL)malloc(sizeof(tipoAVL))))
		return NULL;

	novo->codigo = k; 
	novo->linhaRegistroAVL = linha;
	novo->esq = novo->dir = NULL;
	novo->bal = 0;
	return novo;
}


/*------------------------------------------------------------------------------*/
/* Insere um novo número e chama o balanceamento, caso necessário				*/
/*------------------------------------------------------------------------------*/

ApAVL insereAVL (ApAVL p, int k, int *mudaA, int linha) {

	if (p == NULL) {
		*mudaA = TRUE;
		p = criaNodoAVL(k,linha);
		return p;
	}

	if (p->codigo == k) {
		*mudaA = FALSE;
		return p;
	}

	if (k < p->codigo) {
		p->esq = insereAVL(p->esq,k,mudaA,linha);
	if (*mudaA)
		p->bal++;
	if (p->bal == 2) 
		p = balanceiaAVL(p);
	}

	else {
		p->dir = insereAVL(p->dir,k,mudaA,linha);
	if (*mudaA) 
		p->bal--;
	if (p->bal == (-2)) 
		p = balanceiaAVL(p);
	}

  if (p->bal == 0)
		*mudaA = FALSE;

	return p;
}


/*------------------------------------------------------------------------------*/
/* Procura e retorna o apontador de um valor específico							*/
/*------------------------------------------------------------------------------*/

ApAVL buscaAVL (ApAVL p, int k) {

	if (p == NULL || p->codigo == k) 
		return p;

	if (k < p->codigo)
		return buscaAVL (p->esq,k);
	return buscaAVL(p->dir,k);
}

