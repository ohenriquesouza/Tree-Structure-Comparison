#include "funcoes.hpp"

void escolheArquivoAPB(Tree **t, Record r){

    int opcao2 = nullptr;

    while(opcao2 != 0){

        cout<<"---MENU DE OPCOES---"<<endl;

        cout<<"1 - 500 entradas;"<<endl;

        cout<<"2 - 5000 entradas;"<<endl;

        cout<<"3- 50000 entradas;"<<endl;

        cout<<"4- 500000 entradas;"<<endl;

        cout<<"0 - Voltar ao menu;"<<endl;

        cin>>opcao2;

        if(opcao2 == 1){
            //PUXA ARQ 500

            leArquivo500(&raiz);

            double tempo_gasto = 0.0;

            clock_t begin = clock();

            for(long unsigned int i = 0; i < values.size(); i++){

                r.key = values[i];

                r.value = 1;

                insertTree(&raiz, r);
            }

            clock_t end = clock();

            tempo_gasto += (double)(end - begin) / CLOCKS_PER_SEC;

            cout<<"Elementos inseridos com sucesso, tempo decorrido: %f", tempo_gasto<<endl;
        }
           
        if(opcao2 == 2){
            //PUXA ARQ 5000

            leArquivo5000(&raiz);

            double tempo_gasto = 0.0;

            clock_t begin = clock();

            for(long unsigned int i = 0; i < values.size(); i++){

                r.key = values[i];

                r.value = 1;

                insertTree(&raiz, r);
            }

            clock_t end = clock();

            tempo_gasto += (double)(end - begin) / CLOCKS_PER_SEC;

            cout<<"Elementos inseridos com sucesso, tempo decorrido: %f", tempo_gasto<<endl;
        }
            
        if(opcao2 == 3){
            //PUXA ARQ 50000

            leArquivo50000(&raiz);

            double tempo_gasto = 0.0;

            clock_t begin = clock();

            for(long unsigned int i = 0; i < values.size(); i++){

                r.key = values[i];

                r.value = 1;

                insertTree(&raiz, r);
            }

            clock_t end = clock();

            tempo_gasto += (double)(end - begin) / CLOCKS_PER_SEC;

            cout<<"Elementos inseridos com sucesso, tempo decorrido: %f", tempo_gasto<<endl;
        }
            
        if(opcao2 == 4){
            //PUXA ARQ 500000

            leArquivo500000(&raiz);

            double tempo_gasto = 0.0;

            clock_t begin = clock();

            for(long unsigned int i = 0; i < values.size(); i++){

                r.key = values[i];

                r.value = 1;

                insertTree(&raiz, r);
            }

            clock_t end = clock();

            tempo_gasto += (double)(end - begin) / CLOCKS_PER_SEC;

            cout<<"Elementos inseridos com sucesso, tempo decorrido: %f", tempo_gasto<<endl;
        }
            
        if(opcao2 == 0){
            //VOLTA AO MENU
        }
            
        else
            cout<<"Antes de escolher o arquivo, voce deve escolher a estrutura desejada"<<endl;
    }
    
}