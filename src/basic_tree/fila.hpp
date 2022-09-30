#ifndef FILA_HPP
#define FILA_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "tree.hpp"

struct Item{
	Tree *p;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};


void FFVazia(Fila *f);

bool isVazia(Fila *f);

void Enfileira(Fila *f, Item d);

void Desenfileira(Fila *f, Item *d);

#endif