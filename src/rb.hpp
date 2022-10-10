#ifndef RB_HPP 
#define RB_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <iostream>

using namespace std;

struct RecordRB{
	float key;
	int value;
};

struct TreeRB{
	RecordRB reg;
	TreeRB *esq, *dir;
	TreeRB *pai; 
	bool cor;  // (FALSE = VERMELHOR, TRUE = PRETO)
};


TreeRB* CreateTreeRB();

TreeRB *tree_minimum(TreeRB *auxiliar);

void rotacaoSimplesEsquerda(TreeRB **raiz, TreeRB *child);

void rotacaoSimplesDireita(TreeRB **raiz, TreeRB *child);

void insertFixUp(TreeRB **raiz, TreeRB *child);

void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, RecordRB r);

void removeTreeRB(TreeRB **t, TreeRB* z, TreeRB* y, TreeRB *x);

void transplantTreeRB(TreeRB **t, TreeRB *temp, TreeRB *tempFilho);

void removeFixUpTreeRB(TreeRB **t, TreeRB *x, TreeRB *w);

void pesquisaRB(TreeRB **t, TreeRB **aux, RecordRB r);

void pesquisaRBparaRemover(TreeRB **t, TreeRB *aux, RecordRB r);

void preordem(TreeRB *t);

void central(TreeRB *t);

void posordem(TreeRB *t);

#endif