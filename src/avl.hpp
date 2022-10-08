#ifndef AVL_HPP 
#define AVL_HPP

#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct RecordAVL{
	float key;
	int value;
};

struct TreeAVL{
	RecordAVL reg;
	TreeAVL *left, *right;
	int weight;
};

TreeAVL* CreateTreeAVL();

void insertTreeAVL(TreeAVL **t, RecordAVL r);

void pesquisaAVL(TreeAVL **t, TreeAVL **aux, RecordAVL r);

int isInTreeAVL(TreeAVL *t, RecordAVL r);

void removeTreeAVL(TreeAVL **t, TreeAVL **f, RecordAVL r);

void antecessor(TreeAVL **t, TreeAVL *aux);

void rebalanceTree(TreeAVL **t);

void preordem(TreeAVL *t);

void central(TreeAVL *t);

void posordem(TreeAVL *t);

int getWeight(TreeAVL **t);

int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(TreeAVL **t);

void rotacaoSimplesEsquerda(TreeAVL **t);

void rotacaoDuplaDireita(TreeAVL **t);

void rotacaoDuplaEsquerda(TreeAVL **t);


#endif