#ifndef NOFILA_H_INCLUDED
#define NOFILA_H_INCLUDED

class NoFila
{

public:
    NoFila();
    ~NoFila();
    int getInfo();
    NoFila* getProx();
    void setInfo(int info);
    void setProx(NoFila *p);

private:
    int info; 
    NoFila *proximo; 
};