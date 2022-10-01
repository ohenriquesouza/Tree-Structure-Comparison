#include "avl_tree/avl.hpp"
#include "basic_tree/fila.hpp"
#include "basic_tree/tree.hpp"
#include "red_black_tree/rb.hpp"
#include "funcoes/funcoes.hpp"
#include "leArquivos.hpp"

int main(){
    
    int opcao, contMenu = 0;
    
    while(opcao != 0){

        cout<<"---MENU  DE OPCOES---"<<endl;
        
        cout<<"1 - Escolher tipo de árvore;"<<endl;
        
        cout<<"2 - Escolher o arquivo a ser lido;"<<endl;
        
        cout<<"0 - Encerrar o programa;"<<endl;

        cin>>opcao;

        if(opcao == 1){

            int opcao1;

            contMenu++;

            cout<<"---MENU DE OPCOES---"<<endl;

            cout<<"1 - Arvore Binaria;"<<endl;

            cout<<"2 - Arvore AVL;"<<endl;

            cout<<"3- Arvore Red/Black;"<<endl;

            cout<<"0 - Voltar ao menu;"<<endl;

            cin>>opcao1;

            if(opcao1 == 1){
                //CHAMA A BINARIA

                Tree *raiz = CreateTree();
                Record r;

                cout<<"Árvore binária criada com sucesso!"<<endl;

                escolheArquivo(&raiz, r);

            }
                
            if(opcao1 == 2){
                //CHAMA A AVL

                Tree *raiz = CreateTreeAVL();

                cout<<"Árvore AVL criada com sucesso!"<<endl;

                // escolheArquivo(&raiz);

            }
                
            if(opcao1 == 3){
                //CHAMA A RB

                Tree *raiz = CreateTreeRB();

                cout<<"Árvore Red/Black criada com sucesso!"<<endl;

                // escolheArquivo(&raiz);

            }
                
            if(opcao1 == 0){
                //VOLTA AO MENU

                cout<<"Programa finalizado!"<<endl;

            }
                
        }

        if(opcao == 2 && contMenu < 1)
            cout<<"Primeiro, escolha com qual estrutura deseja continuar!"<<endl;

    }
    
    cout<<"Programa finalizado."<<endl;
    exit();
}