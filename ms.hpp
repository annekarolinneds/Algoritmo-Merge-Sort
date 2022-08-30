#ifndef MS_HPP
#define MS_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <locale.h>

#define MAX_TAM 1000+1

using namespace std;

int contadorDeSwap = 0;
int contadorDeAcessos = 0;
string acessos = "";
string trocas = "";

class LE //Lista Estatica
{
   public:
    int tamanho;
    int lista [MAX_TAM];

LE()
{
    tamanho = 0;
}
~LE()
{
    tamanho = 0;
}

void insere(int elemento, int posicao)
{
    if(posicao>tamanho)
    {
        cout << "\n ERROR: Posicao Invalida" <<endl;
        return;
    }
    if(tamanho == MAX_TAM)
    {
        cout << "\n ERROR: Lista Cheia!!" <<endl;
        return;
    }
    for(int i = tamanho; i>posicao; --i)
    {
        lista[i] = lista[i-1];
    }
    lista[posicao] = elemento;
    tamanho++;
}

void imprime()
{
    for(int i=0; i<tamanho;++i)
        cout << lista[i] << " ";
    cout<<endl;
}

int PegaTrocas()
{
    return contadorDeSwap;
}
int PegaAcessos()
{
    return contadorDeAcessos;
}
void ResetaDados() //Limpa os dados, para evitar dados errados
{
    contadorDeSwap = 0;
    contadorDeAcessos = 0;
}
    //----------------------------
    
    //MERGE SORTE 
void merge(int const esquerda, int const meio, int const direita, bool confere)
{
    auto const VetorAux1 = meio - esquerda + 1;
	auto const VetorAux2 = direita - meio;

	auto *esquerdaArray = new int[VetorAux1], *direitaArray = new int[VetorAux2];

	for (auto i = 0; i < VetorAux1; i++) esquerdaArray[i] = lista[esquerda + i];
	for (auto j = 0; j < VetorAux2; j++) direitaArray[j] = lista[meio + 1 + j];

	auto IndexVetorAux1 = 0, indexVetorAux2 = 0; 
	int indexVetorMerge = esquerda; 

	while (IndexVetorAux1 < VetorAux1 && indexVetorAux2 < VetorAux2) 
    {
		if (esquerdaArray[IndexVetorAux1] <= direitaArray[indexVetorAux2]) 
        {
			lista[indexVetorMerge] = esquerdaArray[IndexVetorAux1];
			IndexVetorAux1++;
		}
		else 
		{
			lista[indexVetorMerge] = direitaArray[indexVetorAux2];
			indexVetorAux2++;
		}
		indexVetorMerge++;
	}

	while (IndexVetorAux1 < VetorAux1) 
    {
		lista[indexVetorMerge] = esquerdaArray[IndexVetorAux1];
		IndexVetorAux1++;
		indexVetorMerge++;
	}

	while (indexVetorAux2 < VetorAux2) 
    {
		lista[indexVetorMerge] = direitaArray[indexVetorAux2];
		indexVetorAux2++;
		indexVetorMerge++;
	}
    if(confere == true)
        imprime();
   
}

void mergeSort(int const esquerda, int const direita, bool confere)
{
    if (esquerda >= direita)
        return; 
    if(esquerda < direita)
    {
        auto meio = esquerda + (direita - esquerda) / 2;
        mergeSort(esquerda, meio,confere);
        mergeSort(meio + 1, direita,confere);
        merge(esquerda, meio, direita,confere);
    }
       
}
      
void listaRandom(int tamLista, int intervalo)
{
    srand(tamLista);
    for(int i = 0; i < tamLista; ++i)
    {
        int elemento = rand() % intervalo;
        insere(elemento,i);
    }
}

};

#endif