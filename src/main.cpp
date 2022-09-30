#include "avl_tree/avl.hpp"
#include "basic_tree/fila.hpp"
#include "basic_tree/tree.hpp"
#include "red_black_tree/rb.hpp"

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

            if(opcao1 == 1)
                //CHAMA A BINARIA
            if(opcao1 == 2)
                //CHAMA A AVL
            if(opcao1 == 3)
                //CHAMA A RB
            if(opcao1 == 0)
                //VOLTA AO MENU
        }
        
        if(opcao == 2 && contMenu >= 1){

            int opcao2;

            contMenu++;

            cout<<"---MENU DE OPCOES---"<<endl;

            cout<<"1 - 500 entradas;"<<endl;

            cout<<"2 - 5000 entradas;"<<endl;

            cout<<"3- 50000 entradas;"<<endl;

            cout<<"4- 500000 entradas;"<<endl;

            cout<<"0 - Voltar ao menu;"<<endl;

            cin>>opcao2;

            if(opcao2 == 1)
                //PUXA ARQ 500
            if(opcao2 == 2)
                //PUXA ARQ 5000
            if(opcao2 == 3)
                //PUXA ARQ 50000
            if(opcao2 == 4)
                //PUXA ARQ 500000
            if(opcao2 == 0)
                //VOLTA AO MENU
        }
        else
            cout<<"Antes de escolher o arquivo, voce deve escolher a estrutura desejada"<<endl;

    }
    
    cout<<"Programa finalizado."<<endl;
    exit();
}