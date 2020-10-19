#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<chrono>
#include<math.h>
#include<fstream>
#include"Grafo.h"

using namespace std;



int encontraValor(string str)
{
  int valor = 0;
  for(unsigned int i=0; i < str.size(); i++)
  {
    valor += (int)((str[i]-'0')*pow(10,str.size()-i-1));

  }
  return valor;
}


int main(int argc, const char* argv[])
{

    cout << "CRIANDO GRAFO" << endl;

    Grafo g;

    string arquivoEntrada = argv[1];
    ifstream entrada;
    entrada.open(arquivoEntrada);
    
   

    string linha;

    if(entrada.is_open())
    {
        

        getline(entrada,linha);
        int N = encontraValor(linha);

        for(int i = 0; i < N; i++)
        {
            g.addVertice(i); cout << "adicionou vertice " << i << endl;
        }

        cout << "N = "   << N << endl;
        
        int linhaatual = 0;
        while(!entrada.eof())
        {   
            int cont = 0;

            string v1,v2,val;
        

            getline(entrada,linha);
            int vertice1,vertice2;
        
            while(linha[cont] != ' ' )
            {
                v1 += linha[cont];
                cont++;
            }   
            // cout << "#################" << endl;
            cont++;
            while(linha[cont] != ' ')
            {
                v2 += linha[cont];
                cont++;
            }
            cont++;
            while(linha[cont] >= '0' && linha[cont] <= '9')
            {
                val += linha[cont];
                cont++;
            }

            g.addAresta(encontraValor(v1),encontraValor(v2),encontraValor(val)); cout << "A: " << v1 << " , " << v2 << " v:" << encontraValor(val) << endl;
            cout << "grau de " << v1 << " :" << g.getVertice(encontraValor(v1))->grau << endl;
            cout << "grau de " << v2 << " :" << g.getVertice(encontraValor(v2))->grau << endl; 
            cout << "################################" << endl << endl;
            linhaatual++;
        }
        cout << "fechando arquivo, linhaatual = " << linhaatual << endl;
        entrada.close();
    }
    else
    {
        cerr << "Erro ao abrir arquivo!" << endl;
        return 0;
    }




    g.addAresta(2,3,11);
    g.addAresta(3,0,12);
    g.addAresta(3,4,112);
    g.addAresta(4,1,5);
    g.addAresta(4,0,25);
    g.addAresta(0,2,48);
    g.addAresta(1,3,1);
    g.addAresta(1,2,6);
    g.addAresta(2,4,71);


    g.printVertices();

    cout << "GRAU MEDIO: \n" << g.getGrauMedio() << endl;
    return 0;
}
