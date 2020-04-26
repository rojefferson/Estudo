#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int qtdMergulhadores, qtdVivos;
    int leitor;
    while(scanf("%d %d",&qtdMergulhadores,&qtdVivos) != EOF){
        int mergulhadores[qtdMergulhadores] = {};

        for (int i = 0; i < qtdVivos; i++)
        {
            cin >> leitor;
            mergulhadores[leitor-1] = 1;
        }

        bool entrou = false;
        for (int i = 0; i <  qtdMergulhadores; i++)
        {
            if(mergulhadores[i] == 0){
                cout << (i+1) << " ";
                entrou =  true;
            }  
        }
        
        if(entrou){
            cout << endl;
        }else
        {
            cout << "*" << endl;
        }

    }

    
}