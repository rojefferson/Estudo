#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen ("saida.txt","w",stdout);

    int a, leitor, soma;

    cin >>  a >> leitor ;

    while( leitor <= 0){
        cin >> leitor;
    }
    soma = 0;
    for (int i = 0; i < leitor; i++)
    {
        soma  +=  a + i;
    }
    cout << soma << endl;
    return 1;
}