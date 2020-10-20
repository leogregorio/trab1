#ifndef ARESTA_H
#define ARESTA_H


class Vertice;

class Aresta {

  private:
    int VerticeID;
    Aresta* proximo;
    double valor;


  public:


    Aresta();
    Aresta(int VerticeID, Aresta* proximo, double valor);
    int getVerticeID();
    Aresta* getProximo();
    double getValor();
    void setVerticeID(int VerticeID);
    void setProximo(Aresta* proximo);
    void setValor(double valor);
};

#endif // Aresta_H
