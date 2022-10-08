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

// void removeRB(TreeRB **t, TreeRB* aux1,TreeRB* aux2,TreeRB *aux3){

//   enum type default_Color;	

//   default_Color = aux2->color;	

//   //case 1
//   if (aux1->left == nullptr){

//     aux3 = aux1->right;

//     TreansplantRB(t, aux1, aux1->right);
    
//   }

//   //case 2
//   else if (aux1->right == nullptr){
//     aux3 = aux2->left;
//     TreansplantRB(t, aux1, aux1->left);
//   }

//   else{
//     aux2 = tree_successor(aux1->right);

//     default_Color = aux2->color;

//     aux3 = aux2->right;

//     if (aux2->pai == aux1){

//       aux3->pai = aux2;
//     }
//     else {
//       TreansplantRB(t, aux2, aux2->right);

//       aux2->right    = aux1->right;		

//       aux2->right->pai = aux2;
//     }

//     TreansplantRB(t, aux1, aux2);

//     aux2->left= aux1->left;

//     aux2->left->pai = aux2;

//     aux2->color = aux1->color;
//   }

//   if (default_Color == black)

//     RB_delete_fix(t, aux3, aux3);

//   free(aux1);
// }

// void removeRB_fix(TreeRB **t, TreeRB *aux1,TreeRB *aux2){

//   while (aux1 != (*root) && aux1->color == black){

//     if (aux1 == aux1->pai->left){

//       aux2 = aux1->pai->right;

//       if (aux2->color == red){	

//         aux2->color = black;

//         aux1->pai->color = red;

//         rotacaoEsquerda(root, aux1->pai);

//         aux2 = aux1->pai->right;
//       }
//       else if (aux2->left->color == black && aux2->right->color == black){	

//         aux2->color = red;

//         aux1 = aux1->pai;
//       }
//       else if (aux2->right->color == black){

//         aux2->left->color = black;

//         aux2->color     = red;

//         rotacaoDireita(root, aux2);

//         aux2 = aux1->pai->right;
//       }
//       else{
//         aux2->color     = aux1->pai->color;

//         aux1->pai->color  = black;	

//         aux2->right->color = black;	

//         rotacaoEsquerda(root, aux1->pai);

//         aux1 = (*root);
//       }
//   }
//   else{
//       aux2 = aux1->pai->left;

//       if (aux2->color == red){

//         aux2->color    = black;

//         aux1->pai->color = red;

//         rotacaoDireita(root, aux1->pai);

//         aux2 = aux1->pai->left;
//       }
//       else if (aux2->right->color == black && aux2->left->color == black){

//         aux2->color=red;

//         aux1=aux1->pai;
//       }
//       else if (aux2->left->color == black) {

//         aux2->right->color = black;

//         aux2->color     = red;

//         rotacaoEsquerda(root, aux2);

//         aux2 = aux1->pai->left;
//       }
//       else{
//         aux2->color     = aux1->pai->color;

//         aux1->pai->color  = black;

//         aux2->left->color = black;

//         rotacaoDireita(root, aux1->pai);

//         aux1 = (*root);
//       }
//   }
// }

//   aux1->color = black;
// }
