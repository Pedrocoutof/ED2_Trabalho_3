#include "ArvoreB.h"
#include "time.h"

#include "iostream"
using namespace std;

ArvoreB::ArvoreB(int t)
{
    raiz = NULL;
    this->t = t;
    this->m = 2 * t;
    this->comparacaoBusca = 0;
    this->comparacaoInsercao = 0;
}

void ArvoreB::imprimeArvore()
{
    cout << "Impressao ArvoreB:" << endl;
    if (raiz != NULL)
    {
        raiz->imprimeNo();
    }
}

NoArvoreB * ArvoreB::busca(string k)
{
    comparacaoBusca++;
    if (raiz == NULL)
        return NULL;

    NoArvoreB * resp = raiz->busca(k, &comparacaoBusca);

    return resp;
}

int ArvoreB::buscaRetornaPosicaoID(string k)
{
    int posID;
    comparacaoBusca++;
    if (raiz == NULL)
        return -1;

    NoArvoreB * resp = raiz->buscaRetornaID(k, &comparacaoBusca, &posID);

    return posID;
}

void ArvoreB::insere(string reviewID, int posID)
{
    InfoNo k;
    k.review_id = reviewID;
    k.posID = posID;
    comparacaoInsercao++;
    if (raiz == NULL)
    {
        raiz = new NoArvoreB(t, true);
        raiz->setChaves(k);
        raiz->setN(1);
    }
    else
    {
        //verifica se o nó tem espaço,
        //se sim realiza a inserção normal, se não chama a inserção por divisão de nó
        comparacaoInsercao++;
        if (raiz->getN() != m - 1)
        {
            raiz->insereVazio(k, &comparacaoInsercao);
        }
        else
        {
            NoArvoreB *novoNo = new NoArvoreB(t, false);

            novoNo->setNo(0, raiz);
            novoNo->cisao(0, raiz, &comparacaoInsercao);

            int i = 0;
            comparacaoInsercao++;
            if (novoNo->getChaves(0).review_id < k.review_id)
                i++;

            novoNo->getNo(i)->insereVazio(k, &comparacaoInsercao);

            raiz = novoNo;
        }
    }
}

int ArvoreB::getOrdem(){
    return this->t;
}

void ArvoreB::zeraComparacoes(){
    this->comparacaoBusca = 0;
    this->comparacaoInsercao = 0;
}

