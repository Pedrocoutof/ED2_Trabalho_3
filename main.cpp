/// CONSTANTES
#define TAM_VINTE 20
#define TAM_CINQUENTA 50
#define TAM_CEM 100
#define TAM_QUINHENTOS 500
#define TAM_MIL 1000
#define TAM_CINCO_MIL 5000
#define TAM_DEZ_MIL 10000
#define TAM_QUINHENTOS_MIL 500000
#define RANGE 1000000

/// INCLUDES EXTRAS
#include <iostream>
using namespace std;
#include "Cronometro.h"

/// TRABALHO 1
#include "BIN.h"
#include "TiktokReviews.h"

/// TRABALHO 2
#include "HeapSort.h"
#include "QuickSort.h"
#include "CombSort.h"
#include "Hash.h"

/// TRABALHO 3
#include "ArvoreVP.h"
#include "ArvoreB.h"

// Funcao que realiza a analise guardando informacoes como tempo gasto em um arquivo chamado 'saida.txt'
void analiseArvoreVP(ArvoreVP arvVP){

    FILE * arq_saida = fopen("saida.txt", "a");
    TiktokReviews vetorTiktokReviews[TAM_MIL];
    TiktokReviews tiktokReviewBusca[TAM_CEM];
    int M; // Vari�vel feita para controlar o numero de vezes que o teste ir� se repetir
    int somaComparacaoBusca = 0, somaComparacaoInsercao = 0;
    double somaTempoBusca = 0, somaTempoInsercao = 0;

    fprintf(arq_saida, "======= ARVORE VP de tamanho 1000 =======");

    // Vamos repetir tr�s vezes
    for(M = 0; M < 3; M++){
    arvVP.zeraComparacoes(); // Zera o numero de comparacoes para que nao some no proximo loop
    Cronometro croInsercao, croBusca; //Criamos o cronometro para insercao e para busca

        // Criamos um vetor de TiktokReviews que sera usado para ser pesquisado
        for(int i = 0; i < TAM_CEM; i++){
            tiktokReviewBusca[i] = retornaRegistro(valorAleatorio(RANGE));
        }

        croInsercao.IniciaCronometro();
        for(int i = 0 ; i < TAM_MIL; i++){
            int posAleatoria = valorAleatorio(RANGE);
            vetorTiktokReviews[i] = retornaRegistro(posAleatoria);
            arvVP.insere(vetorTiktokReviews[i].review_id, posAleatoria); // Inserimos na ArvoreVP apenas a string 'review_id' e sua posicao no arquivo <.bin>
        }
        croInsercao.FinalizaCronometro();


        croBusca.IniciaCronometro();
        for(int i = 0; i < 100; i++){
            arvVP.busca(tiktokReviewBusca[i].review_id); // Realiza a busca utilizando apenas a string
        }
        croBusca.FinalizaCronometro();


        fprintf(arq_saida, "\n%d� - Vez", M+1);
        fprintf(arq_saida, "\n Numero de Comparacoes Insercao : %d", arvVP.getComparacaoInsercao());
        fprintf(arq_saida, "\n Numero de Comparacoes Busca : %d", arvVP.getComparacaoBusca());
        fprintf(arq_saida, "\n Tempo gasto na Insercao : %lf", croInsercao.getTempoGasto());
        fprintf(arq_saida, "\n Tempo gasto na Busca : %lf", croBusca.getTempoGasto());

        somaComparacaoBusca += arvVP.getComparacaoBusca();
        somaComparacaoInsercao += arvVP.getComparacaoInsercao();
        somaTempoInsercao += croInsercao.getTempoGasto();
        somaTempoBusca += croBusca.getTempoGasto();
    }

    fprintf(arq_saida, "\n\n Medias:\n");
    fprintf(arq_saida, "\nMedia de comparacoes por insercao: %d", somaComparacaoInsercao/M);
    fprintf(arq_saida, "\nMedia de comparacoes por busca: %d", somaComparacaoBusca/M);
    fprintf(arq_saida, "\nMedia de tempo gasto por insercao: %lf", somaTempoInsercao/M);
    fprintf(arq_saida, "\nMedia de tempo gasto por busca: %lf", somaTempoBusca/M);
    fprintf(arq_saida, "\n==========================================\n\n");


    }

// Funcao que realiza o teste/busca da Arvore V. P.
void testeArvoreVP(ArvoreVP arvVP){
    TiktokReviews vetorTiktokReviews[TAM_CEM];
    int posAleatoria = 0;

    for(int i = 0; i < TAM_CEM; i++){
        posAleatoria = valorAleatorio(RANGE);
        vetorTiktokReviews[i] = retornaRegistro(posAleatoria);
        arvVP.insere(vetorTiktokReviews[i].review_id, posAleatoria);
    }

    int opcao, opcao2;
    do{

        cout << endl << "== Deseja imprimir no console os review_id's guardados na arvore VP? ==";
        cout << endl << " 1 - Sim";
        cout << endl << " 2 - Nao";
        cout << endl << "   > ";
        cin >> opcao;
        if(opcao == 1){
            arvVP.imprime();
        }
    }while(false);

    char pesquisa[90];
    cout  << endl << "Digite o review_ID que deseja pesquisar : " << endl;
    cout << "   > ";
    cin >> pesquisa;

    int posIDPesquisa = arvVP.buscaRetornaPosID(pesquisa);

    if(posIDPesquisa != -1){
        cout << endl << "Chave encontrada! Posicao do ID : " << posIDPesquisa << endl;
        cout << endl << "Deseja imprimir todo conteudo dessa posicao?";
        cout << endl << " 1 - Sim";
        cout << endl << " 2 - Nao";
        cout << endl << "   > ";
        cin >> opcao2;

        if(opcao2 == 1){
            cout << endl << endl;
            acessaRegistro(posIDPesquisa);
        }
    }else{
        cout << endl << "Chave nao encontrada !";
    }
}

// Funcao responsavel por direcionar o �s opcoes da Arvore V. P.
void funcaoArvoreVP(){

    int opcao;
    ArvoreVP arvVP;


do{
        cout  << endl << " == ARVORE VP == " << endl;
        cout << " 1 - Modo de analise (gera relatorio)" << endl;
        cout << " 2 - Modo de Teste (realizar busca)" << endl;
        cout << " 3 - Sair" << endl;
        cout << "   > ";
        cin >> opcao;

        if(opcao == 1){
            analiseArvoreVP(arvVP);

        }
        else if(opcao == 2){
            testeArvoreVP(arvVP);
        }

    }while(opcao != 3);

}

// Funcao que realiza o teste/busca da Arvore B
void testeArvoreB(ArvoreB arvB){

    for(int i = 0; i < TAM_CEM; i++){
        int posAleatoria = valorAleatorio(RANGE);
        arvB.insere(retornaRegistro(posAleatoria).review_id, posAleatoria);
    }

    int opcao;
    cout << endl << "== Deseja imprimir no console os review_id's guardados na arvore b? ==";
    cout << endl << " 1 - Sim";
    cout << endl << " 2 - Nao";
    cout << endl << "   > ";
    cin >> opcao;

    if(opcao == 1){
        arvB.imprimeArvore();
    }


    char pesquisa[90];
    cout  << endl << "Digite o review_ID que deseja pesquisar : " << endl;
    cout << "   > ";
    cin >> pesquisa;

    int posicaoID = arvB.buscaRetornaPosicaoID(pesquisa);

    if(posicaoID != -1){
        cout << endl << "== Deseja imprimir todo conteudo da chave? ==";
        cout << endl << " 1 - Sim";
        cout << endl << " 2 - Nao";
        cout << endl << "  > ";
        int opcao2;
        cin >> opcao2;
        if(opcao2 == 1){
            acessaRegistro(posicaoID);
        }
    }else{
        cout << endl << "Chave nao encontrada ! " << endl;
    }
}

// Funcao que realiza a analise guardando informacoes como numero de comparacoes em um arquivo chamado 'saida.txt'
void analiseArvoreB(ArvoreB arvB){

    FILE * arq_saida = fopen("saida.txt", "a");
    int posAleatoria, M;
    double somaTempoInsercao = 0, somaTempoBusca = 0;
    int somaComparacaoInsercao = 0, somaComparacaoBusca = 0;
    TiktokReviews tikokReviewsBusca[TAM_CEM];

    fprintf(arq_saida, " ===== Analise Arvore-B de ordem %d =====", arvB.getOrdem());

    for(M = 0; M < 3; M++){

        arvB.zeraComparacoes();
        Cronometro croInsercao, croBusca;

        for(int i = 0; i < TAM_CEM; i++){
            tikokReviewsBusca[i] = retornaRegistroAleatorio(RANGE);
        }

        croInsercao.IniciaCronometro();
        for(int i = 0; i < TAM_DEZ_MIL; i++){
            posAleatoria = valorAleatorio(RANGE);
            TiktokReviews tiktokReview = retornaRegistro(posAleatoria);
            arvB.insere(tiktokReview.review_id, posAleatoria);
        }
        croInsercao.FinalizaCronometro();

        croBusca.IniciaCronometro();
        for(int i = 0; i < 100; i++){
            arvB.busca(tikokReviewsBusca[i].review_id);
        }
        croBusca.FinalizaCronometro();

        somaComparacaoBusca += arvB.getComparacaoBusca();
        somaComparacaoInsercao += arvB.getComparacaoInsercao();
        somaTempoInsercao += croInsercao.getTempoGasto();
        somaTempoBusca += croBusca.getTempoGasto();

        fprintf(arq_saida, "\n%d� - Vez", M+1);
        fprintf(arq_saida, "\n Numero de Comparacoes Insercao : %d", arvB.getComparacaoInsercao());
        fprintf(arq_saida, "\n Numero de Comparacoes Busca : %d", arvB.getComparacaoBusca());
        fprintf(arq_saida, "\n Tempo gasto na Insercao : %lf", croInsercao.getTempoGasto());
        fprintf(arq_saida, "\n Tempo gasto na Busca : %lf", croBusca.getTempoGasto());

    }

    fprintf(arq_saida, "\n\n Medias:\n");
    fprintf(arq_saida, "\nMedia de comparacoes por insercao: %d", somaComparacaoInsercao/M);
    fprintf(arq_saida, "\nMedia de comparacoes por busca: %d", somaComparacaoBusca/M);
    fprintf(arq_saida, "\nMedia de tempo gasto por insercao: %lf", somaTempoInsercao/M);
    fprintf(arq_saida, "\nMedia de tempo gasto por busca: %lf", somaTempoBusca/M);
    fprintf(arq_saida, "\n==========================================\n\n");


}

// Funcao responsavel por direcionar o �s opcoes da Arvore B
void funcaoArvoreB(){
    int ordem;

    cout << "== Digite a ordem da Arvore B ==" << endl;
    cout << "   > ";
    cin >> ordem;

    int opcao;
    ArvoreB arvB(ordem);
    Cronometro croInsersao;

do{
        cout  << endl << " == ARVORE B == " << endl;
        cout << " 1 - Modo de analise (gera relatorio)" << endl;
        cout << " 2 - Modo de Teste (realizar busca)" << endl;
        cout << " 3 - Sair" << endl;
        cout << "   > ";
        cin >> opcao;

        if(opcao == 1){
            ///GERAR RELATORIO
            analiseArvoreB(arvB);
        }
        else if(opcao == 2){
            ///REALIZA BUSCA
            testeArvoreB(arvB);
        }


    }while(opcao != 3);


}

int main(int argc, char * argv[])
{
    geraArqBinario("tiktok_app_reviews.bin", argv[1]);
    //geraArqBinario("tiktok_app_reviews.bin", "H:\\UFJF\\2021.3\\ED2\\Trabalhos\\ArquivosCSV\\tiktok_app_reviews_reduzido_milhao.csv");

    srand(time(nullptr));

    int opcao;

    do{
        cout << "\n==== MENU PRINCIPAL ====" << endl;
        cout << " 1 - Arvore Vermelho e Preto" << endl;
        cout << " 2 - Arvore B" << endl;
        cout << " 3 - Sair" << endl;
        cout << "   > ";
        cin >> opcao;

        if(opcao == 1){
                funcaoArvoreVP();
        }
        else if(opcao == 2){
                funcaoArvoreB();
        }

    }while(opcao != 3);

    return 0;
}
