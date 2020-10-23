#include"NoFila.h"



NoFila::NoFila(){}

NoFila::~NoFila(){};

int NoFila::getInfo()
{
    return info;
}

NoFila* NoFila::getProx()
{
    return proximo;
}

void NoFila::setInfo(int info)
{
    this->info = info;
}

void NoFila::setProx(NoFila *proximo)
{
    this->proximo = proximo;
}
