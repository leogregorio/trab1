#include "Grafo.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <math.h>

Grafo::Grafo(){
  this->n = 0;
  this->m = 0;
  this->rootVertice = NULL;
  this->direcionado = false;
}

int Grafo::addVertice(int ID){
  return this->addVertice(ID, 0);
}


int Grafo::addVertice(int ID, double valor){
  Vertice* v = new Vertice(ID, valor);
  v->setProximo(this->rootVertice);
  this->rootVertice = v;
  this->n += 1;

  return v->ID;
}

bool Grafo::removerVertice(int ID){
  if(this->rootVertice == NULL){
    //nada pra removerr
    return false;
  } else {
    Vertice* a = NULL;
    Vertice* p = this->rootVertice;
    while(p != NULL){
      if(p->getID() == ID){
        //remover vertice
        if(a == NULL){
          this->rootVertice = p->getProximo();
        } else {
          a->setProximo(p->getProximo());
        }
        p = NULL;
        this->n -= 1;
        return true;
      }
      a = p;
      p = p->getProximo();
    }
    //Vertice não encontrado
    return false;
  }
}


Vertice* Grafo::getVertice(int ID){
  if(this->rootVertice == NULL){
    return NULL;
  } else {
    Vertice* p = this->rootVertice;
    while(p != NULL){
      if(p->getID() == ID){
        return p;
      }
      p = p->getProximo();
    }
    return NULL;
  }
}




double Grafo::getArestaValor(int ID1, int ID2){
  Vertice* a = this->getVertice(ID1);
  Aresta* e = this->getVertice(ID1)->getRootAresta();
  while(e != NULL){
    if(e->getVerticeID() == ID2){
      return e->getValor();
    }
    e = e->getProximo();
  }
  return 0; //returns 0 if there's no Aresta between the
            //specified vertices (ID1, ID2);
}

bool Grafo::addAresta(int ID1, int ID2, double valor){
  Vertice* a = this->getVertice(ID1);
  Vertice* b = this->getVertice(ID2);
  if(a != NULL && b != NULL){
    a->conectarAresta(ID2, valor); a->grau++;
    b->conectarAresta(ID1, valor); b->grau++;
    this->m += 1;
    
    return true;
  }
  else {
    return false;
  }
}

bool Grafo::removerAresta(int ID1, int ID2){
  Vertice* a = this->getVertice(ID1);
  Vertice* b = this->getVertice(ID2);
  if(a != NULL && b != NULL){
    if(a->removerAresta(ID2)){
      //if removerd Aresta successfully
        if(b->removerAresta(ID1)){
          this->m -= 1;
          return true;
        } else {
          return false;
        }
    } else {
      return false;
    }
  } else {
    return false;
  }
}

int Grafo::getN(){
  return this->n;
}

int Grafo::getM(){
  return this->m;
}

bool Grafo::isNull(){
  return n == 0;
}

bool Grafo::isEmpty(){
  return m == 0;
}

void Grafo::printVertices(){
  Vertice* p = this->rootVertice;
  Aresta* e;
  while(p != NULL){
    std::cout << "[" << p->getID() << "] : " << " grau:" << p->grau << endl;  
    e = p->getRootAresta();
    while(e != NULL){
      std::cout << e->getVerticeID() << "(" << e->getValor() << ") ";
      e = e->getProximo();
    }
    std::cout << std::endl;
    p = p->getProximo();
  }
}


int Grafo::getGrauMedio()
{
  int soma = 0;
  for(int i = 0; i< this->getN(); i++)
    soma += this->getVertice(i)->grau;
  return soma/this->getN();
}


void Grafo::camLargura(int id_no, ofstream& saida){
    No* inic = this->getPrimeiroNo();
    bool* verticeVisitado = new bool[this->n];
    int indice;

    //preenche o vetor com 0
    for(int i = 0; i < this->n; i++, inic = inic->getProximoNo()){
        mapaVertices[i] = inic->getId();
        verticeVisitado[i] = false;
    }

    //Fila e ja coloca o no alvo como visitado
    FilaEncadeada* fila = new FilaEncadeada();
    indice = detIndice(mapaVertices, id_no);
    verticeVisitado[indice]=true;

    //adiciona o primeir vertice à fila 
    fila->enfileira(id_no);

 
    No* noAux;
    
    while(!fila->vazia()){
        noAux = this->getNo(fila->desenfileira()); //retirando vertice da fila
        Aresta* auxiliar = noAux->getPrimeiraAresta();
        while(auxiliar!=NULL){
            indice = detIndice(mapaVertices, auxiliar->getIdDestino());
            if(verticeVisitado[indice] == false) {
                saida<<"["<<noAux->getId()<<","<<auxiliar->getIdDestino()<<"] nao é retorno"<<endl;
                verticeVisitado[indice] = true;
                fila->enfileira(auxiliar->getIdDestino());
            } else {
                saida<<"["<<noAux->getId()<<" , "<<auxiliar->getIdDestino()<<"] é retorno"<<endl;
            }
            auxiliar = auxiliar->getProximaAresta();
        }
    }
}



/*
vector<int> Grafo::getVerticeIDList(){
  vector<int> ids;
  Vertice* p = this->rootVertice;
  while(p != NULL){
    ids.push_back(p->getID());
    p = p->getProximo();
  }
  return ids;
}

*/

/*
int Grafo::detIndice(int* mapaVertices, int id) {
    for(int i=0; i < this->getOrdem(); i++) {
        if(mapaVertices[i] == id)
            return i;
    }
}
*/