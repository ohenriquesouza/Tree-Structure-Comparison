#include "rb.hpp"

TreeRB* CreateTreeRB(){
  
  return NULL;

}

void insertFixUp(TreeRB **raiz, TreeRB *child){

  TreeRB *tio;

  while((child != *raiz) && (child->pai->cor == false)){
      
      if(child->pai == child->pai->pai->esq){
        
        tio = child->pai->pai->dir;

        //caso 1:
        if((tio != NULL) && (tio->cor == false)){

          child->pai->cor = true;

          tio->cor = true;

          child->pai->pai->cor = false;

          child = child->pai->pai;
        
        }
        else{
          
          //caso 2
          if(child == child->pai->dir){
        
            child = child->pai;
        
            rotacaoSimplesEsquerda(raiz, child);
          }
          
          //caso 3
          child->pai->cor = true;
        
          child->pai->pai->cor = false;
        
          rotacaoSimplesDireita(raiz, child->pai->pai);
        }

      }
      else{
        
        tio = child->pai->pai->esq;
        
        //caso 1
        if((tio != NULL) && (tio->cor == false)){
      
          child->pai->cor = true;
      
          tio->cor = true;
      
          child->pai->pai->cor = false;
      
          child = child->pai->pai;
        
        }
        else{
          
          //caso 2
          if(child == child->pai->esq){
        
            child = child->pai;
        
            rotacaoSimplesDireita(raiz, child);
          }

          //caso 3
          child->pai->cor = true;
        
          child->pai->pai->cor = false;
        
          rotacaoSimplesEsquerda(raiz, child->pai->pai);      
        }

      }

  }

  (*raiz)->cor = true;
}


void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, RecordRB r){
  
  if(*t == NULL){
    
    *t = (TreeRB*)malloc(sizeof(TreeRB));
    
    (*t)->esq = NULL; 
    
    (*t)->dir = NULL; 
    
    (*t)->pai = pai!=t?*pai:NULL;
    
    (*t)->cor = false; //false: vermelho  true:preto
    
    (*t)->reg = r; 
    
    insertFixUp(raiz, *t);
    
  }
  else { 

    if(r.key < (*t)->reg.key){
  
      insertTreeRB(&(*t)->esq, t, raiz, r);
  
      return;
    }
    
    if(r.key > (*t)->reg.key){
  
      insertTreeRB(&(*t)->dir, t, raiz, r);
  
      return;
  
    }

  }

}


void pesquisaRB(TreeRB **t, TreeRB **aux, RecordRB r){

  if(*t == NULL){
  
    // printf("[ERROR]: Node not found!");
  
    return;
  }

  if((*t)->reg.key > r.key){ pesquisaRB(&(*t)->esq, aux, r); return;}
  
  if((*t)->reg.key < r.key){ pesquisaRB(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

void rotacaoSimplesEsquerda(TreeRB **raiz, TreeRB *child){
  
  TreeRB *x, *y;

  x = child;
  
  y = child->dir;
  
  x->dir = y->esq;

  if(y->esq != NULL)
  
    y->esq->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL)
  
    *raiz = y;

  else{

    if(x == x->pai->esq)
  
      x->pai->esq = y;

    else
  
      x->pai->dir = y;
  
  }

  y->esq = x;
  
  x->pai = y;
}


void rotacaoSimplesDireita(TreeRB **raiz, TreeRB *child){
  
  TreeRB *x, *y;

  x = child;
  
  y = child->esq;
  
  x->esq = y->dir;

  if(y->dir != NULL)
  
    y->dir->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL){
  
    *raiz = y;
  }

  else{

    if(x == x->pai->dir)
  
      x->pai->dir = y;

    else
  
      x->pai->esq = y;
  
  }

  y->dir = x;
  
  x->pai = y;
  
}


void preordem(TreeRB *t){
 
  if(!(t == NULL)){
 
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
 
    preordem(t->esq); 
 
    preordem(t->dir); 
 
  }
}


void central(TreeRB *t){
 
  if(!(t == NULL)){
 
    central(t->esq); 
 
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
 
    central(t->dir); 
 
  }
}

void posordem(TreeRB *t){
 
  if(!(t == NULL)){
 
    posordem(t->esq); 
 
    posordem(t->dir); 
 
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
 
  }
}

TreeRB *tree_minimum(TreeRB *auxiliar){

  while(auxiliar->esq != nullptr)

    auxiliar = auxiliar->esq;

  return auxiliar;
}

void removeTreeRB(TreeRB **t, TreeRB* z, TreeRB* y, TreeRB *x){

  y = z;

  corOriginal = y->cor;

  //caso1
  if(z->esq == nullptr){

    x = z->dir;

    transplantTreeRB(t, z, z->dir);
  }
  //caso2
  else if(z->dir == nullptr){

    x = z->esq;
      
    transplantTreeRB(t, z, z->esq);
  }
  else{

    y = tree_minimum(z->dir);

    corOriginal = y->cor;

    x = y->dir;

    if(y->pai == z)
      
      x->pai = y;
    else{
      
      transplantTreeRB(t, y, y->dir);

      y->dir = z->dir;

      y->dir->pai = y;

      transplantTreeRB(t, z, y);

      y->esq = z->esq;

      y->esq->pai = y;

      y->cor = z->cor;
    }
  }
  if(corOriginal == true)

    removeFixUpTreeRB(t, x, x);

  free(z);
}

void transplantTreeRB(TreeRB **t, TreeRB *temp, TreeRB *tempFilho){

  if(temp->pai == nullptr)

    (*t) = tempFilho;

  else if(temp == temp->pai->esq)

    temp->pai->esq = tempFilho;
    
  else

    temp->pai->dir = tempFilho;
  
  tempFilho->pai = temp->pai;
}

void removeFixUpTreeRB(TreeRB **t, TreeRB *x, TreeRB *w){

  while(x != (*t) && x->cor == true){

    if(x == x->pai->esq){

      w = x->pai->dir;

      if(w->cor == false){

        w->cor = true;

        x->pai->cor = false;

        rotacaoSimplesEsquerda(t, x->pai);

        w = x->pai->dir;
      }
      if(w->esq->cor == true && w->dir->cor == true){

        w->cor = false;

        x = x->pai;
      }
      else if(w->dir->cor == true){

        w->esq->cor = true;

        w->cor = false;

        rotacaoSimplesDireita(t, w);

        w = x->pai->dir;
      }
      else{
        
        w->cor = x->pai->cor;

        x->pai->cor = true;

        w->dir->cor = true;

        rotacaoSimplesEsquerda(t, x->pai);

        x = (*t);
      }
    }
    else{
        w = x->pai->esq;

        if (w->cor == false){

          w->cor  = true;

          x->pai->cor = false;

          rotacaoSimplesDireita(t, x->pai);

          w = x->pai->esq;
        }

        else if (w->dir->cor == true && w->esq->cor == true){

          w->cor = false;

          x = x->pai;
        }

        else if (w->esq->cor == true) {

          w->dir->cor = true;

          w->cor = false;

          rotacaoSimplesEsquerda(t, w);

          w = x->pai->esq;
        }

        else{
          w->cor = x->pai->cor;

          x->pai->cor = true;

          w->esq->cor = true;

          rotacaoSimplesDireita(t, x->pai);

          x = (*t);
        }
    }
  }
  x = (*t);
}

void pesquisaRBparaRemover(TreeRB **t, TreeRB *aux, RecordRB r){

  while(aux != nullptr && r.key != aux->reg.key){

    if(r.key < aux->reg.key)
      aux = aux->esq;
    else
      aux = aux->dir;
  }

  if(aux->reg.key == r.key)
    removeTreeRB(t, aux, aux, aux);
  else
    /*cout<<"nao achei<<endl"*/
}