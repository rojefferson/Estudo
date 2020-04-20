#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int leitor;


    while(scanf("%d",&leitor) != EOF)
    {
        int  pares = 0;
        int sapato[70] = {};
        int direito[70] = {};
        int esquerdo[70] = {};
        int numero = 0;
        char posicao ;

        for (int i = 0; i < leitor; i++)
        {
          
            scanf("%d %c\n",&numero,&posicao); 
            sapato[numero] ++;
            if(posicao == 'D')
            {
                if(esquerdo[numero] > 0){
                    esquerdo[numero] --;
                    sapato[numero] -= 2;
                    pares ++; 
                }else{
                    direito[numero] ++;
                }
                
            }else
            {
                if(direito[numero] > 0){
                    direito[numero] --;
                    sapato[numero] -= 2;
                    pares ++;
                }else{
                    esquerdo[numero]++;
                }
            }        
        }
        
        cout << pares << endl;
    }


    return 1;
}