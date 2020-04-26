#include <bits/stdc++.h>
using namespace std;


int main(){
    
    long long num1,num2,soma;


    cin >> num1 >> num2;

    soma = ((num1+num2) *  (num2-num1 + 1))/2;

    cout << soma << endl;
    return 1;
}