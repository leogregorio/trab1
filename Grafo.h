#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <fstream>
#include <vector>
#include "Vertice.h"
#include "Aresta.h"


class Grafo {

  private:
  Vertice* rootVertice;
  int n, m;
  bool direcionado;


  public:
  Grafo();

  int addVertice(int ID); //return ID of added Vertice
  int addVertice(int ID, double valor);
  bool removerVertice(int ID);

  Vertice* getVertice(int ID);
  Vertice* getRootVertice();
  double getArestaValor(int ID1, int ID2);

  bool addAresta(int ID1, int ID2, double valor); //return true if added; false, ow
  bool removerAresta(int ID1, int ID2);


  int getN();
  int getM();
  bool isNull();
  bool isEmpty();
  void printVertices();
  int getGrauMedio();

  void camLargura(int id_no, std::ofstream& saida);
};



#endif // GRAFO_H
