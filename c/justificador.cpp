#include <bits/stdc++.h>
using namespace std;


string retornaEspacos (string palavra){
    
    if (palavra.length() < 50){
         return palavra + retornaEspacos(palavra + "  ");
    }

   return "";
}


int main(){
    freopen ("saida.txt","w",stdout);
    int qtdPalavras;
    string palavraEspaco = retornaEspacos(" ");
    bool primeiro = true;


    while(true){
        cin >> qtdPalavras;
        int maiorTam   = -1;
        if (!qtdPalavras) break;
      
        

        if(primeiro == false){
            printf("\n");
        }else{
            primeiro =  false;
        }
        

        vector<string> palavras;
        string palavra;
        maiorTam = -5000;

        for (int i = 0; i < qtdPalavras; i++)
        {
            cin >> palavra;
            palavras.push_back(palavra); 

            if((int)palavra.length() >= maiorTam){
                maiorTam =  (int)palavra.length();
            }
                  
        }
        
        for (int j = 0; j < qtdPalavras; j++)
        {
            cout <<  palavraEspaco.substr(0,maiorTam - (int)palavras[j].length()) + palavras[j] << endl;
            //cout << palavras[j].length() << "-" << maiorTam <<  endl;
        }
    }

    return 1;
}