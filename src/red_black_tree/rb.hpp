#ifndef RB_HPP 
#define RB_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Record{
	int key;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
	Tree *pai; 
	bool cor;  // (FALSE = VERMELHOR, TRUE = PRETO)
};


Tree* CreateTreeRB();

void rotacaoSimplesEsquerda(Tree **raiz, Tree *child);

void rotacaoSimplesDireita(Tree **raiz, Tree *child);

void insertFixUp(Tree **raiz, Tree *child);

void insertTreeRB(Tree **t, Tree **pai, Tree **raiz, Record r);

void pesquisa(Tree **t, Tree **aux, Record r);

void preordem(Tree *t);

void central(Tree *t);

void posordem(Tree *t);

#endif