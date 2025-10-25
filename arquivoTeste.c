#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "funcoes.h"
#include "minunit-master/minunit.h"
//estou chamando o arquivo .h , que armazena as funções
MU_TEST(test_calculaIngressos){
    int caso1[] = {5, 10, 12};      // todas crianças → 3*10 = 30
    int caso2[] = {20, 30};         // adultos → 2*30 = 60
    int caso3[] = {65, 80};         // idosos → 2*15 = 30
    int caso4[] = {10, 25, 70};     // mistura → 10 + 30 + 15 = 55

    //CASO 1
    mu_check(30==calculaIngressos(caso1, 3));
    //CASO 2
    mu_check(60==calculaIngressos(caso2, 2));
    //CASO 3
    mu_check(30==calculaIngressos(caso3, 2));
    //CASO 4
    mu_check(55==calculaIngressos(caso4, 3));
    //mu_assert_int_eq(5,7);
}

MU_TEST(test_entrada){
    criaArquivoEntrada(4);
    mu_check(4 ==entrada_teste(4));


}

MU_TEST(test_entradaIngressos){
    int caso1[] = {5, 10, 12};      // todas crianças → 3*10 = 30
    int caso2[] = {20, 30};         // adultos → 2*30 = 60
    int caso3[] = {65, 80};         // idosos → 2*15 = 30
    int caso4[] = {10, 25, 70};     // mistura → 10 + 30 + 15 = 55

    criaArquivoEntradaIngressos(3, caso1);
    mu_check(entradaIngressos_teste(3) == 0);

    criaArquivoEntradaIngressos(2, caso2);
    mu_check(entradaIngressos_teste(2) == 0);

    criaArquivoEntradaIngressos(2, caso3);
    mu_check(entradaIngressos_teste(2) == 0);

    criaArquivoEntradaIngressos(3, caso4);
    mu_check(entradaIngressos_teste(3) == 0);
}


MU_TEST_SUITE(testaGeral){
    MU_RUN_TEST(test_calculaIngressos);
    MU_RUN_TEST(test_entrada);
    MU_RUN_TEST(test_entradaIngressos);
}

//
int main() {

    MU_RUN_SUITE(testaGeral);
    MU_REPORT();
    setlocale(LC_ALL, "Portuguese");
   return MU_EXIT_CODE;
}
