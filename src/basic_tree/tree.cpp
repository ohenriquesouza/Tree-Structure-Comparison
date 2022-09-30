#include "tree.hpp"
#include"fila.hpp"

Tree* CreateTree(){
	
    return nullptr;
}

bool TVazia(Tree **t){
  
  return *t == nullptr;

}

void insertTree(Tree **t, Record r){

  if(TVazia(t)){
 
    *t = (Tree*)malloc(sizeof(Tree));
 
    (*t)->esq = nullptr; 
 
    (*t)->dir = nullptr; 
 
    (*t)->reg = r; 
  
  }
  else {
    
    if(r.key < (*t)->reg.key){
   
      insertTree(&(*t)->esq, r);
   
    }
    
    if(r.key > (*t)->reg.key){
   
      insertTree(&(*t)->dir, r);
   
    }
  
  }

}

void pesquisa(Tree **t, Tree **aux, Record r){

  if(*t == nullptr){
   
    printf("[ERROR]: Node not found!");
   
    return;
 
  }

  if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
  
  if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;

}


int isInTree(Tree *t, Record r) {
  
  if(t == nullptr){ 
    
    return 0;
  
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != nullptr){ 
		
        antecessor(&(*t)->dir, aux);
		
        return;
  }
  	
  aux->reg = (*t)->reg;
  
  aux = *t; 
  
  *t = (*t)->esq;
  
  free(aux);

} 


void removeTree(Tree **t, Record r){

	Tree *aux;
  	
  	if (*t == nullptr){ 

  		printf("[ERROR]: Record not found!!!\n");

    	return;

  	}

  	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }

  	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == nullptr){ 

  		aux = *t;  

  		*t = (*t)->esq;

    	free(aux);

    	return;

  	}

  	if ((*t)->esq != nullptr){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  

  	*t = (*t)->dir;

  	free(aux);

}


void preordem(Tree *t)
{

  if(!(t == nullptr)){

    printf("%d ", t->reg.key);

    preordem(t->esq); 

    preordem(t->dir); 

  }
}


void central(Tree *t)
{
  if(!(t == nullptr)){
    
    central(t->esq); 
    
    printf("%d ", t->reg.key);
    
    central(t->dir); 
  
  }
}

void posordem(Tree *t)
{
  if(!(t == nullptr)){
    
    posordem(t->esq); 
    
    posordem(t->dir); 
    
    printf("%d ", t->reg.key);
  }
}

void widthPath(Tree *t){
  
  Fila q;
  
  Item no, filho;
  
  FFVazia(&q);
  
  no.p = t;
  
  Enfileira(&q, no);

  while (!isVazia(&q)){

    Desenfileira(&q, &no);
  
    printf("%d ", no.p->reg.key);

    if(no.p->esq != nullptr){
 
      filho.p = no.p->esq;
 
      Enfileira(&q, filho);

    }

    if(no.p->dir != nullptr){
  
      filho.p = no.p->dir;
  
      Enfileira(&q, filho);

    }

  }

}