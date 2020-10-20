#ifndef Vertice_H_INCLUDED
#define Vertice_H_INCLUDED


class Aresta;

class Vertice {

  private:



    double valor;
    Aresta* rootAresta;

    Vertice* proximo;
    int color;


  public:
    int grau;
    int ID;
    Vertice(int ID);
    Vertice(int ID, double valor);
    void conectarAresta(int connID, double valor);
    void conectarAresta(Aresta* e);
    bool removerAresta(int connID);
    int getID();
    double getValor();
    Aresta* getRootAresta();
    void setValor(double valor);
    void setRootAresta(Aresta* rootAresta);

    Vertice* getProximo();
    void setProximo(Vertice* proximo);


    bool operator < (Vertice& v)
    {
      return (this->valor < v.getValor());
    }
};

#endif
