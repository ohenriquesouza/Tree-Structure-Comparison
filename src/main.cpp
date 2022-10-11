#include "avl.hpp"
#include "fila.hpp"
#include "tree.hpp"
#include "rb.hpp"
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

void learquivos(int TAM){

    map <float, int> Mapa;

    unordered_map <float, int> u_Mapa;

    Tree *raizAPB = CreateTree();
    Record r;

    TreeAVL *raizAVL = CreateTreeAVL();
    RecordAVL rAVL;

    TreeRB *raizRB;
    RecordRB rRB;

    initializeTreeRB(&raizRB);

    vector <float> ComparaTempo;

    vector <float> values;

    string linha;

    double tempo_gastoVector = 0.0, tempo_gastoAPB = 0.0, tempo_gastoAVL = 0.0, tempo_gastoRB = 0.0, tempo_gastoMAPA = 0.0, tempo_gastou_MAPA = 0.0;

    float auxiliar;

    ifstream myfile;

    string caminho = "src/files/";

    caminho.append(to_string(TAM)).append("NumbersFile.txt");

    myfile.open(caminho);

    clock_t beginAPB;

    clock_t beginAVL;

    clock_t beginRB;

    clock_t beginMAPA;

    clock_t beginu_MAPA;

    clock_t beginVector;

    if(myfile.is_open()){

        while(getline(myfile, linha)){

            auxiliar = stof(linha);

            values.push_back(auxiliar);

            r.key = rAVL.key = rRB.key = auxiliar;

            r.value = rAVL.value = rRB.value = 1;

            beginAPB = clock();
            insertTree(&raizAPB, r);
            tempo_gastoAPB += ((double)(clock() - beginAPB) / CLOCKS_PER_SEC);

            beginAVL = clock();
            insertTreeAVL(&raizAVL, rAVL);
            tempo_gastoAVL += ((double)(clock() - beginAVL) / CLOCKS_PER_SEC);

            beginRB = clock();
            insertTreeRB(&raizRB, rRB);
            tempo_gastoRB += ((double)(clock() - beginRB) / CLOCKS_PER_SEC);

            beginMAPA = clock();
            Mapa.insert({auxiliar, 1});
            tempo_gastoMAPA += ((double)(clock() - beginMAPA) / CLOCKS_PER_SEC);

            beginu_MAPA = clock();
            u_Mapa.insert({auxiliar, 1});
            tempo_gastou_MAPA += ((double)(clock() - beginu_MAPA) / CLOCKS_PER_SEC);

            beginVector = clock();
            ComparaTempo.push_back(auxiliar);
            sort(ComparaTempo.begin(), ComparaTempo.end()); //ordena o vector
            tempo_gastoVector += ((double)(clock() - beginVector) / CLOCKS_PER_SEC);

        }

        myfile.close();

        printf("\n\n---------------------------------INÍCIO DAS INSERÇÕES---------------------------------\n\n");
        printf("* %d elementos inseridos na Árvore binária com sucesso, tempo decorrido: %0.6lf(s)\n",TAM, tempo_gastoAPB);
        printf("* %d elementos inseridos na Árvore AVL com sucesso, tempo decorrido: %0.6lf(s)\n",TAM, tempo_gastoAVL);
        printf("* %d elementos inseridos na Árvore Red/Black com sucesso, tempo decorrido: %0.6lf(s)\n",TAM, tempo_gastoRB);
        printf("* %d elementos inseridos no Mapa com sucesso, tempo decorrido: %0.6lf(s)\n",TAM, tempo_gastoMAPA);
        printf("* %d elementos inseridos no Mapa Desordenado com sucesso, tempo decorrido: %0.6lf(s)\n",TAM, tempo_gastou_MAPA);
        printf("* %d elementos inseridos e ordenados no Vector com sucesso, tempo decorrido: %0.6lf(s)\n",TAM, tempo_gastoVector);

    }else{

        cout<<"Arquivo não encontrado."<<endl;
    }

    printf("\n-------------------------------------------------------------------------------------\n");
    printf("Fim da inserção dos %d elementos\n",TAM);
    printf("---------------------------------------------------------------------------------------\n\n");

    ifstream myfile2;

    caminho.assign("src/files/entrada.txt");

    myfile2.open(caminho);

    tempo_gastoAPB =  tempo_gastoAVL = tempo_gastoRB = 0;

    if(myfile2.is_open()){

        map <float, int>::iterator it;

        unordered_map <float, int>::iterator itr;

        while(getline(myfile2, linha)){

            auxiliar = stof(linha);

            values.push_back(auxiliar);

            r.key = rAVL.key = rRB.key = auxiliar;

            it = Mapa.find(auxiliar);

            itr = u_Mapa.find(auxiliar);

            r.value = rAVL.value = rRB.value = 1;

            beginAPB = clock();
            isInTreeAPB(raizAPB, r);
            tempo_gastoAPB += ((double)(clock() - beginAPB) / CLOCKS_PER_SEC);

            beginAVL = clock();
            isInTreeAVL(raizAVL, rAVL);
            tempo_gastoAVL += ((double)(clock() - beginAVL) / CLOCKS_PER_SEC);

            beginRB = clock();
            pesquisaRB(&raizRB, &raizRB, rRB);
            tempo_gastoRB += ((double)(clock() - beginRB) / CLOCKS_PER_SEC);

            beginMAPA = clock();
            it = Mapa.find(auxiliar);
            if(it != Mapa.end()){/*cout<<"achei"*/;}
            tempo_gastoMAPA += ((double)(clock() - beginMAPA) / CLOCKS_PER_SEC);

            beginu_MAPA = clock();
            itr = u_Mapa.find(auxiliar);
            if(itr != u_Mapa.end()){/*cout<<"achei"*/;}
            tempo_gastou_MAPA += ((double)(clock() - beginu_MAPA) / CLOCKS_PER_SEC);

            beginVector = clock();
            binary_search(ComparaTempo.begin(), ComparaTempo.end(), auxiliar);
            tempo_gastoVector += ((double)(clock() - beginVector) / CLOCKS_PER_SEC);

        }

        myfile2.close();

        printf("\n\n---------------------------------INÍCIO DAS BUSCAS---------------------------------\n\n");
        printf("* Todos os elementos foram pesquisados na Árvore binária com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoAPB);
        printf("* Todos os elementos foram pesquisados na Árvore AVL com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoAVL);
        printf("* Todos os elementos foram pesquisados na Árvore Red/Black com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoRB);
        printf("* Todos os elementos foram pesquisados no Mapa com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoMAPA);
        printf("* Todos os elementos foram pesquisados no Mapa Desordenado com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastou_MAPA);
        printf("* Todos os elementos foram pesquisados no Vector com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoVector);

    }else{

        cout<<"Arquivo não encontrado."<<endl;
    }

    printf("\n-------------------------------------------------------------------------------------\n");
    printf("Fim da pesquisa dos %d elementos\n",TAM);
    printf("---------------------------------------------------------------------------------------\n\n");

    ifstream myfile3;

    caminho.assign("src/files/entrada.txt");

    myfile3.open(caminho);

    tempo_gastoAPB =  tempo_gastoAVL = tempo_gastoRB = 0;

    if(myfile3.is_open()){

        map <float, int>::iterator it;

        unordered_map <float, int>::iterator itr;

        // cout<<"ABRIU O ARQUIVO"<<endl;

        while(getline(myfile3, linha)){

            auxiliar = stof(linha);

            r.key = rAVL.key =  rRB.key = auxiliar;

            r.value = rAVL.value =  rRB.value = 1;

            beginAPB = clock();
            removeTree(&raizAPB, r);
            tempo_gastoAPB += ((double)(clock() - beginAPB) / CLOCKS_PER_SEC);

            beginAVL = clock();
            removeTreeAVL(&raizAVL, &raizAVL, rAVL);
            tempo_gastoAVL += ((double)(clock() - beginAVL) / CLOCKS_PER_SEC);

            beginRB = clock();
            pesquisaRBparaRemover(&raizRB, raizRB, rRB);
            tempo_gastoRB += ((double)(clock() - beginRB) / CLOCKS_PER_SEC);

            beginMAPA = clock();
            it = Mapa.find(auxiliar);
            if(it != Mapa.end()){Mapa.erase(it);}
            tempo_gastoMAPA += ((double)(clock() - beginMAPA) / CLOCKS_PER_SEC);

            beginu_MAPA = clock();
            itr = u_Mapa.find(auxiliar);
            if(itr != u_Mapa.end()){u_Mapa.erase(itr);}
            tempo_gastou_MAPA += ((double)(clock() - beginu_MAPA) / CLOCKS_PER_SEC);

            beginVector = clock();
            if(binary_search(ComparaTempo.begin(), ComparaTempo.end(), auxiliar)){ComparaTempo.erase(lower_bound(ComparaTempo.begin(), ComparaTempo.end(), auxiliar));}
            tempo_gastoVector += ((double)(clock() - beginVector) / CLOCKS_PER_SEC);
        }

        myfile3.close();

        printf("\n\n---------------------------------INÍCIO DAS REMOÇÕES---------------------------------\n\n");
        printf("* Elementos foram removidos da Árvore binária com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoAPB);
        printf("* Elementos foram removidos da Árvore AVL com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoAVL);
        printf("* Elementos foram removidos da Árvore Red/Black com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoRB);
        printf("* Elementos foram removidos do Mapa com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoMAPA);
        printf("* Elementos foram removidos do Mapa Desordenado com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastou_MAPA);
        printf("* Elementos foram removidos do Vector com sucesso, tempo decorrido: %0.6lf(s)\n", tempo_gastoVector);

    }else{

        cout<<"Arquivo não encontrado."<<endl;
    }

    printf("\n-------------------------------------------------------------------------------------\n");
    printf("Fim da remoção dos elementos\n");
    printf("---------------------------------------------------------------------------------------\n\n");

}

int main(){

    //learquivos(500);

    learquivos(5000);

    //learquivos(50000);

    //learquivos(500000);
}