#ifndef LEARQ_HPP
#define LEARQ_HPP

vector leArquivo500(Tree **t);

vector leArquivo5000(Tree **t);

vector leArquivo50000(Tree **t);

vector leArquivo500000(Tree **t);

#endif

vector leArquivo500(Tree **t){

    cout<<"Iniciando leitura do arquivo"<<endl;

    string linha;

    float auxiliar;

    vector<float> values;

    ifstream myfile;

    myfile.open("500NumbersFile.txt");

    if(myfile.is_open()){

        while(!myfile.eof()){

            getline(myfile, linha);

            auxiliar = stof(linha);

            values.push_back(auxiliar);

        }

    }

    myfile.close();

    cout<<"Fim da leitura"<<endl;

    return values;

}

vector leArquivo5000(Tree **t){

    cout<<"Iniciando leitura do arquivo"<<endl;

    string linha;

    float auxiliar;

    vector<float> values;

    ifstream myfile;

    myfile.open("5000NumbersFile.txt");

    if(myfile.is_open()){

        while(!myfile.eof()){

            getline(myfile, linha);

            auxiliar = stof(linha);

            values.push_back(auxiliar);

        }

    }

    myfile.close();

    cout<<"Fim da leitura"<<endl;

    return values;

}

vector leArquivo50000(Tree **t){

    cout<<"Iniciando leitura do arquivo"<<endl;

    string linha;

    float auxiliar;

    vector<float> values;

    ifstream myfile;

    myfile.open("50000NumbersFile.txt");

    if(myfile.is_open()){

        while(!myfile.eof()){

            getline(myfile, linha);

            auxiliar = stof(linha);

            values.push_back(auxiliar);

        }

    }

    myfile.close();

    cout<<"Fim da leitura"<<endl;

    return values;

}

vector leArquivo500000(Tree **t){

    cout<<"Iniciando leitura do arquivo"<<endl;

    string linha;

    float auxiliar;

    vector<float> values;

    ifstream myfile;

    myfile.open("500000NumbersFile.txt");

    if(myfile.is_open()){

        while(!myfile.eof()){

            getline(myfile, linha);

            auxiliar = stof(linha);

            values.push_back(auxiliar);

        }

    }

    myfile.close();

    cout<<"Fim da leitura"<<endl;

    return values;

}