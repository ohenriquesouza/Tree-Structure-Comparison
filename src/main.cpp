#include "avl.hpp"
#include "fila.hpp"
#include "tree.hpp"
#include "rb.hpp"
#include "quicksort.hpp"
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace chrono;

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

    steady_clock::time_point t1 = steady_clock::now();
    steady_clock::time_point t2;

    duration <double> tempo_gastoVector = duration_cast<duration<double>>(t1 - t1);
    duration <double> tempo_gastoAPB = duration_cast<duration<double>>(t1 - t1);
    duration <double> tempo_gastoAVL = duration_cast<duration<double>>(t1 - t1);
    duration <double> tempo_gastoRB = duration_cast<duration<double>>(t1 - t1);
    duration <double> tempo_gastoMAPA = duration_cast<duration<double>>(t1 - t1);
    duration <double> tempo_gastou_MAPA = duration_cast<duration<double>>(t1 - t1);

    float auxiliar;

    ifstream myfile;

    string caminho = "src/files/";

    caminho.append(to_string(TAM)).append("NumbersFile.txt");

    myfile.open(caminho);

    if(myfile.is_open()){

        while(getline(myfile, linha)){

            auxiliar = stof(linha);

            values.push_back(auxiliar);

            r.key = rAVL.key = rRB.key = auxiliar;

            r.value = rAVL.value = rRB.value = 1;

            t1 = steady_clock::now();
            insertTree(&raizAPB, r);
            t2 = steady_clock::now();
            tempo_gastoAPB += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            insertTreeAVL(&raizAVL, rAVL);
            t2 = steady_clock::now();
            tempo_gastoAVL += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            insertTreeRB(&raizRB, rRB);
            t2 = steady_clock::now();
            tempo_gastoRB += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            Mapa.insert({auxiliar, 1});
            t2 = steady_clock::now();
            tempo_gastoMAPA += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            u_Mapa.insert({auxiliar, 1});
            t2 = steady_clock::now();
            tempo_gastou_MAPA += duration_cast<duration<double>>(t2 - t1);
        

            t1 = steady_clock::now();
            ComparaTempo.push_back(auxiliar);
            t2 = steady_clock::now();
            tempo_gastoVector += duration_cast<duration<double>>(t2 - t1);
            // tempo_gastoVector += ((double)(clock() - beginVector) / CLOCKS_PER_SEC);

        }

        t1 = steady_clock::now();
        Quicksort sort(ComparaTempo);
        sort.Sort();
        t2 = steady_clock::now();
        tempo_gastoVector += duration_cast<duration<double>>(t2 - t1);
        // tempo_gastoVector += ((double)(clock() - beginVector) / CLOCKS_PER_SEC);

        myfile.close();

        printf("\n\n---------------------------------INÍCIO DAS INSERÇÕES---------------------------------\n\n");
        cout<<"* "<<TAM<<" elementos inseridos na Árvore binária com sucesso, tempo decorrido: "<<tempo_gastoAPB.count()<<"s"<<endl;
        cout<<"* "<<TAM<<" elementos inseridos na Árvore AVL com sucesso, tempo decorrido: "<<tempo_gastoAVL.count()<<"s"<<endl;
        cout<<"* "<<TAM<<" elementos inseridos na Árvore Red/Black com sucesso, tempo decorrido: "<<tempo_gastoRB.count()<<"s"<<endl;
        cout<<"* "<<TAM<<" elementos inseridos no Mapa com sucesso, tempo decorrido: "<<tempo_gastoMAPA.count()<<"s"<<endl;
        cout<<"* "<<TAM<<" elementos inseridos no Mapa Desordenado com sucesso, tempo decorrido: "<<tempo_gastou_MAPA.count()<<"s"<<endl;
        cout<<"* "<<TAM<<" elementos inseridos e ordenados no Vector com sucesso, tempo decorrido: "<<tempo_gastoVector.count()<<"s"<<endl;

    }else{

        cout<<"Arquivo não encontrado."<<endl;
    }

    // printf("\n-------------------------------------------------------------------------------------\n");
    printf("\nFim da inserção dos %d elementos\n",TAM);
    printf("---------------------------------------------------------------------------------------\n\n");

    ifstream myfile2;

    caminho.assign("src/files/entrada.txt");

    myfile2.open(caminho);

    tempo_gastoVector = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoAPB = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoAVL = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoRB = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoMAPA = duration_cast<duration<double>>(t1 - t1);
    tempo_gastou_MAPA = duration_cast<duration<double>>(t1 - t1);

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

            t1 = steady_clock::now();
            pesquisaAPB(&raizAPB, &raizAPB, r);
            t2 = steady_clock::now();
            tempo_gastoAPB += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            pesquisaAVL(&raizAVL, &raizAVL, rAVL);
            t2 = steady_clock::now();
            tempo_gastoAVL += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            pesquisaRB(&raizRB, &raizRB, rRB);
            t2 = steady_clock::now();
            tempo_gastoRB += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            it = Mapa.find(auxiliar);
            if(it != Mapa.end()){/*cout<<"achei"*/;}
            t2 = steady_clock::now();
            tempo_gastoMAPA += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            itr = u_Mapa.find(auxiliar);
            if(itr != u_Mapa.end()){/*cout<<"achei"*/;}
            t2 = steady_clock::now();
            tempo_gastou_MAPA += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            binary_search(ComparaTempo.begin(), ComparaTempo.end(), auxiliar);
            t2 = steady_clock::now();
            tempo_gastoVector += duration_cast<duration<double>>(t2 - t1);

        }

        myfile2.close();

        printf("\n\n---------------------------------INÍCIO DAS BUSCAS---------------------------------\n\n");
        cout<<"* Todos os elementos foram pesquisados na Árvore binária com sucesso, tempo decorrido: "<<tempo_gastoAPB.count()<<"s"<<endl;
        cout<<"* Todos os elementos foram pesquisados na Árvore AVL com sucesso, tempo decorrido: "<<tempo_gastoAVL.count()<<"s"<<endl;
        cout<<"* Todos os elementos foram pesquisados na Árvore Red/Black com sucesso, tempo decorrido: "<<tempo_gastoRB.count()<<"s"<<endl;
        cout<<"* Todos os elementos foram pesquisados no Mapa com sucesso, tempo decorrido: "<<tempo_gastoMAPA.count()<<"s"<<endl;
        cout<<"* Todos os elementos foram pesquisados no Mapa Desordenado com sucesso, tempo decorrido: "<<tempo_gastou_MAPA.count()<<"s"<<endl;
        cout<<"* Todos os elementos foram pesquisados no Vector com sucesso, tempo decorrido: "<<tempo_gastoVector.count()<<"s"<<endl;

    }else{

        cout<<"Arquivo não encontrado."<<endl;
    }

    // printf("\n-------------------------------------------------------------------------------------\n");
    printf("\nFim da pesquisa dos %d elementos\n",TAM);
    printf("---------------------------------------------------------------------------------------\n\n");

    ifstream myfile3;

    caminho.assign("src/files/entrada.txt");

    myfile3.open(caminho);

    tempo_gastoVector = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoAPB = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoAVL = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoRB = duration_cast<duration<double>>(t1 - t1);
    tempo_gastoMAPA = duration_cast<duration<double>>(t1 - t1);
    tempo_gastou_MAPA = duration_cast<duration<double>>(t1 - t1);

    if(myfile3.is_open()){

        map <float, int>::iterator it;

        unordered_map <float, int>::iterator itr;

        // cout<<"ABRIU O ARQUIVO"<<endl;

        while(getline(myfile3, linha)){

            auxiliar = stof(linha);

            r.key = rAVL.key =  rRB.key = auxiliar;

            r.value = rAVL.value =  rRB.value = 1;

            t1 = steady_clock::now();
            removeTree(&raizAPB, r);
            t2 = steady_clock::now();
            tempo_gastoAPB += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            removeTreeAVL(&raizAVL, &raizAVL, rAVL);
            t2 = steady_clock::now();
            tempo_gastoAVL += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            pesquisaRBparaRemover(&raizRB, raizRB, rRB);
            t2 = steady_clock::now();
            tempo_gastoRB += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            it = Mapa.find(auxiliar);
            if(it != Mapa.end()){Mapa.erase(it);}
            t2 = steady_clock::now();
            tempo_gastoMAPA += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            itr = u_Mapa.find(auxiliar);
            if(itr != u_Mapa.end()){u_Mapa.erase(itr);}
            t2 = steady_clock::now();
            tempo_gastou_MAPA += duration_cast<duration<double>>(t2 - t1);

            t1 = steady_clock::now();
            if(binary_search(ComparaTempo.begin(), ComparaTempo.end(), auxiliar)){ComparaTempo.erase(lower_bound(ComparaTempo.begin(), ComparaTempo.end(), auxiliar));}
            t2 = steady_clock::now();
            tempo_gastoVector += duration_cast<duration<double>>(t2 - t1);
        }

        myfile3.close();

        printf("\n\n---------------------------------INÍCIO DAS REMOÇÕES---------------------------------\n\n");
        cout<<"* Elementos foram removidos da Árvore binária com sucesso, tempo decorrido: "<<tempo_gastoAPB.count()<<"s"<<endl;
        cout<<"* Elementos foram removidos da Árvore AVL com sucesso, tempo decorrido: "<<tempo_gastoAVL.count()<<"s"<<endl;
        cout<<"* Elementos foram removidos da Árvore Red/Black com sucesso, tempo decorrido: "<<tempo_gastoRB.count()<<"s"<<endl;
        cout<<"* Elementos foram removidos do Mapa com sucesso, tempo decorrido: "<<tempo_gastoMAPA.count()<<"s"<<endl;
        cout<<"* Elementos foram removidos do Mapa Desordenado com sucesso, tempo decorrido: "<<tempo_gastou_MAPA.count()<<"s"<<endl;
        cout<<"* Elementos foram removidos do Vector com sucesso, tempo decorrido: "<<tempo_gastoVector.count()<<"s"<<endl;

    }else{

        cout<<"Arquivo não encontrado."<<endl;
    }

    // printf("\n-------------------------------------------------------------------------------------\n");
    printf("\nFim da remoção dos elementos\n");
    printf("---------------------------------------------------------------------------------------\n\n");

}

int main(){

    learquivos(500);

    learquivos(5000);

    learquivos(50000);

    learquivos(500000);
}