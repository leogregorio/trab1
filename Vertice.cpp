#include "Vertice.h"
#include "Aresta.h"
#include <stdlib.h>

Vertice::Vertice(int ID){
  this->valor = 0;
  this->ID = ID;
  this->rootAresta = NULL;
  this->grau = 0;

}

Vertice::Vertice(int ID, double valor){
  this->valor = valor;
  this->ID = ID;
  this->rootAresta = NULL;
  this->grau = 0;
}

void Vertice::conectarAresta(Aresta* e){
  e->setProximo(this->rootAresta);
  this->rootAresta = e;
  
}

void Vertice::conectarAresta(int connID, double valor){
  Aresta* p = new Aresta(connID, NULL, valor);
  this->conectarAresta(p);
}

bool Vertice::removerAresta(int connID){
  if(this->rootAresta == NULL){
    //nothing to remover
    return false;
  } else {
    Aresta* a = NULL;
    Aresta* p = this->rootAresta;
    while(p != NULL){
      if(p->getVerticeID() == connID){
        //remover Aresta
        if(a == NULL){
          this->rootAresta = p->getProximo();
        } else {
          a->setProximo(p->getProximo());
        }
        p = NULL;
        this->grau--;
        return true;
      }
      a = p;
      p = p->getProximo();
    }
    //Aresta wasn't found
    return false;
  }
}

int Vertice::getID(){
  return this->ID;
}

double Vertice::getValor(){
  return this->valor;
}

void Vertice::setValor(double valor){
  this->valor = valor;
}

Aresta* Vertice::getRootAresta(){
  return this->rootAresta;
}

void Vertice::setRootAresta(Aresta* rootAresta){
  this->rootAresta = rootAresta;
}

Vertice* Vertice::getProximo(){
  return this->proximo;
}

void Vertice::setProximo(Vertice* proximo){
  this->proximo = proximo;
}
