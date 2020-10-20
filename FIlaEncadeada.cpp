#include"FilaEncadeada.h"

FilaEncadeada::FilaEncadeada(){
    primeiro = NULL;
    NoFim = NULL;
    tamanho = 0;
    

}

FilaEncadeada::~FilaEncadeada(){
 NoFila *p = primeiro;

    while(p != NULL)
    {

        if(p->getProx()!=NULL)
        {
            p = p->getProx();
        }
        else
          p = NULL;
        delete primeiro;
        primeiro = p;
    }

}

int FilaEncadeada::getInicio() // volta no primeiro no
{
    if(!vazia())
    {
        return primeiro->getInfo();
    }
    else
    {
        cout<<"Lista vazia!\n";
        exit(1);
    }
}

void FilaEncadeada::enfileira(int val) // insere No no final da lista
{
    NoFila *p = new NoFila();
    p->setInfo(val);
    p->setProx(NULL);

    if(NoFim == NULL)
        primeiro = p; 
    else
        NoFim->setProx(p); 
    NoFim = p; 
}

int FilaEncadeada::desenfileira() // elimina No do inicio
{
    NoFila *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        if(primeiro == NULL)
            NoFim = NULL; // a fila esvaziou
        int val = p->getInfo();
        delete p; // exclui o No do inicio
        return val;
    }
    cout << "ERRO: Fila vazia" << endl;
    exit(1);
}

bool FilaEncadeada::vazia() // verifica se esta vazia
{
    if(primeiro==NULL)
        return true;

    else
        return false;
}

int FilaEncadeada::getTamanho()
{
    return tamanho;
}