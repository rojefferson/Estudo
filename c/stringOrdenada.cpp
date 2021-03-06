    #include <bits/stdc++.h>
    using namespace std;

    typedef struct no {
        string palavra;
        no *anterior;
        no *proximo;
    }no;

    typedef struct  fila
    {
        no * cabeca;
        int tamanho;   
    }fila;

    vector<string> split (string texto, char c);
    no * retornaNovoNo(string texto);
    void inserirDepois (fila *f, no * elemento,string texto);
    void inserirFilaVazia(fila * f,string texto);
    void printNo(no * n);
    void printFila(fila * f);
    fila * retornaNovaFila();
    void inserirDepoisOrdenado(fila * f, no * elemento , string texto);

    int main(){    
        freopen ("myfile.txt","w",stdout);
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
            fila *f = retornaNovaFila();
            for(string palavra : palavras)
            {   
            // cout << palavra << endl;
                inserirDepoisOrdenado(f,f->cabeca,palavra);
            }   

            printFila(f);
        }
        return 1;
    }



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
        if (buff.length() > 1)
        palavras.push_back(buff);
        
        return palavras;
    }


    void inserirDepoisOrdenado(fila * f, no * elemento , string texto){
        if(f -> tamanho == 0){
            inserirFilaVazia(f,texto);
            return;
        }
        
        if((texto.length() <= elemento -> palavra.length())){
            if(elemento -> proximo == NULL){      
                no * n = retornaNovoNo(texto);
                elemento -> proximo = n;
                n->proximo = NULL;
                n->anterior =  elemento;
                f->tamanho ++;            
                return;
            }else{
                inserirDepoisOrdenado(f,elemento -> proximo ,texto);
            }
        }else{  
            no *n = retornaNovoNo(texto);
            if (elemento -> anterior != NULL){
                (elemento ->anterior) -> proximo = n;
            }
            n -> anterior = elemento -> anterior;
            n ->proximo = elemento;
            if(elemento -> anterior == NULL)
            {
                f ->cabeca = n;
            }  
            elemento -> anterior = n;
            f->tamanho ++;
        }
        return;
    }



    no * retornaNovoNo(string texto){
        no  * novoElemento = (no *)malloc(sizeof(no));
        novoElemento -> anterior = NULL;
        novoElemento ->proximo = NULL;
        novoElemento -> palavra =  texto;
        return novoElemento;
    }


    void inserirDepois (fila *f, no * elemento,string texto){
        if(f->tamanho  == 0 ){
            inserirFilaVazia(f,texto);
        }else{
            if (elemento -> proximo == NULL){
                no *  novoN = retornaNovoNo(texto);
                novoN -> anterior =  elemento;
                elemento ->proximo = novoN;
                f->tamanho ++;
            }else{
                inserirDepois(f,elemento ->proximo ,  texto);
            }
        }
    }


    void inserirFilaVazia(fila * f,string texto)
    {
        no * n = (no *)malloc(sizeof(no));
        n->anterior = NULL;
        n->proximo = NULL;
        n->palavra =  texto;
        f->cabeca =  n;
        f->tamanho ++;
    }

    void printNo(no * n){
        cout << n -> palavra;
        if(n->proximo ==  NULL)
        {
            cout << endl;
            return;
        }else
        {
            cout << " ";
            printNo(n->proximo);
        }
        
    }


    void printFila(fila * f){
        printNo(f -> cabeca);
    }

    fila * retornaNovaFila(){
        fila * f = (fila *)malloc(sizeof(fila));
        f->cabeca = NULL;
        f->tamanho = 0;
    }
