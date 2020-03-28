#include <bits/stdc++.h>
using namespace std;

vector<string> split (string texto, char c){

    vector<string> palavras;
    string  buff;
    for(char caracter : texto)
    {
        if (caracter == ' '){
            palavras.push_back(buff);
             buff = "";
        }else
        {
            buff += caracter;
        }   
    }
    return palavras;
}



typedef struct no {
    string palavra;
    
}no;

int main(){    
    int qtd;    
    cin >> qtd;
    bool erroPrimeiraLinha = true;
    for (int i = 0; i < qtd+1; i++)
    {     
        string linha;
        getline(cin,linha);
        if (erroPrimeiraLinha)
        {
            erroPrimeiraLinha= false;
            continue;
        }       
        vector<string> palavras = split(linha,' ');
        for(string var : palavras)
        {
            cout << var << endl;
        }   
    }
    return 1;
}
