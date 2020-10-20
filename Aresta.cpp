#include "Aresta.h"

#include "Aresta.h"
#include "Vertice.h"

Aresta::Aresta(){

}

Aresta::Aresta(int VerticeID, Aresta* proximo, double valor){
  this->VerticeID = VerticeID;
  this->proximo = proximo;
  this->valor = valor;
}

int Aresta::getVerticeID(){
  return this->VerticeID;
}

void Aresta::setVerticeID(int VerticeID){
  this->VerticeID = VerticeID;
}

Aresta* Aresta::getProximo(){
  return this->proximo;
}

void Aresta::setProximo(Aresta* proximo){
  this->proximo = proximo;
}

double Aresta::getValor(){
  return this->valor;
}

void Aresta::setValor(double valor){
  this->valor = valor;
}
