#include <stdio.h>


struct cartao{
    char estado[3];
    char codigo[4];
    char nome_cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int qtd_ponto_turistico;
    float densidade, per_capita;
};

int main(){
    // Definição dos cartões (cartões predefinidos)
    struct cartao cartao1 = {
        "SP", "001", "São Paulo", 12300000, 1521.11, 699000000, 10, 0, 0
    };
    
    struct cartao cartao2 = {
        "RJ", "002", "Rio de Janeiro", 6000000, 1182.28, 634000000, 5, 0, 0
    };    
    
    // Cálculo da densidade populacional e PIB per capita
    cartao1.densidade = (float) cartao1.populacao / cartao1.area;
    cartao1.per_capita = (float) cartao1.pib / cartao1.populacao;

    cartao2.densidade = (float) cartao2.populacao / cartao2.area;
    cartao2.per_capita = (float) cartao2.pib / cartao2.populacao;
    
    // Comparação de área entre as duas cartas
    printf("Comparação de área entre o cartão 1 vs cartão 2:\n");

    if (cartao1.area > cartao2.area){
        printf("Cartão 1: %.2f vs cartão 2: %.2f \n",cartao1.area,cartao2.area);
        printf("Cartão1 vence\n");
    } else {
        printf("Cartão 1: %.2f vs cartão 2: %.2f \n",cartao1.area,cartao2.area);
        printf("Cartão2 vence!\n");
    }
    
    return 0;
}