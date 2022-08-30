#include <iostream>
#include <cstdio>
#include "ms.hpp"

using namespace std;

void InsereVetor(LE &li, int vetor[]);

int main()
{
    int vetor[20] = {70,1,12,8,99,72,5,15,20,91,14,61,66,41,81,88,16,21,34,90};
    LE li;
    
    setlocale(LC_ALL, "Portuguese");

    cout<< "ALGORITMO MERGE SORT - LISTA POR CONTIGUIDADE FÍSICA\n"<<endl;

    cout<< "DESORDENADO: \n"<<endl;
    InsereVetor(li,vetor);
    li.imprime();
    cout << "\nORDENADO COM CADA ESTADO DE ITERACAO: \n"<<endl;
    li.mergeSort(0,19,true);
    cout <<endl;
    li.imprime();
    cout <<endl;
    //cout << "NUMERO DE ACESSOS: " << li.PegaAcessos() <<endl;
    cout <<endl;
    cout<< "---------------------------------------------------------"<<endl;
    li.~LE();
    cout << "ORDENACAO DE LISTAS RANDOM: \n "<<endl;
    int tam = 1;
    for(int i=1; i<=100; ++i)
    {
        int intervalo = 1000;
        li.listaRandom(i,intervalo);
        cout << "Tamanho da lista -> " << tam <<endl;
        cout << "LISTA -> ";
        li.imprime();
        cout << "\nORDENADO - > ";
        li.mergeSort(0,tam-1,false);
        li.imprime();
        cout <<endl;
        li.~LE();
        li.ResetaDados();
        tam++;
    }
    system("PAUSE");
    return 0;
}

void InsereVetor(LE &li, int vetor[])
{
    for(int i = 0; i < 20; ++i)
    {   
        li.insere(vetor[i],i);
    }
}