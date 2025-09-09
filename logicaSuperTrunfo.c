#include <stdio.h>
#include <string.h>

struct Cartao {
    char nome_pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

int main() {
    // Cartas fixas
    struct Cartao carta1 = {"Brasil", 213000000, 8515767.0, 14400.0, 100, 213000000 / 8515767.0};
    struct Cartao carta2 = {"Argentina", 45000000, 2780000.0, 600.0, 50, 45000000 / 2780000.0};

    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2, soma_c1, soma_c2;

    printf("===== SUPER TRUNFO - Nível Mestre =====\n");
    printf("Carta 1: %s\n", carta1.nome_pais);
    printf("Carta 2: %s\n\n", carta2.nome_pais);

    // --- Escolha do primeiro atributo ---
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // --- Escolha do segundo atributo (menu dinâmico) ---
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    if (atributo1 != 1) printf("1 - População\n");
    if (atributo1 != 2) printf("2 - Área\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turísticos\n");
    if (atributo1 != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo2);

    // Garantir que não sejam iguais
    if (atributo1 == atributo2) {
        printf("\nErro: você não pode escolher o mesmo atributo duas vezes!\n");
        return 1;
    }

    // --- Obter valores dos atributos escolhidos ---
    switch (atributo1) {
        case 1: valor1_c1 = carta1.populacao; valor1_c2 = carta2.populacao; break;
        case 2: valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: valor1_c1 = carta1.pontos_turisticos; valor1_c2 = carta2.pontos_turisticos; break;
        case 5: valor1_c1 = carta1.densidade; valor1_c2 = carta2.densidade; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    switch (atributo2) {
        case 1: valor2_c1 = carta1.populacao; valor2_c2 = carta2.populacao; break;
        case 2: valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: valor2_c1 = carta1.pontos_turisticos; valor2_c2 = carta2.pontos_turisticos; break;
        case 5: valor2_c1 = carta1.densidade; valor2_c2 = carta2.densidade; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    // --- Regras de comparação ---
    soma_c1 = 0;
    soma_c2 = 0;

    // Primeiro atributo
    if (atributo1 == 5) { // densidade (menor vence)
        soma_c1 += (valor1_c1 < valor1_c2) ? 1 : 0;
        soma_c2 += (valor1_c2 < valor1_c1) ? 1 : 0;
    } else {
        soma_c1 += (valor1_c1 > valor1_c2) ? 1 : 0;
        soma_c2 += (valor1_c2 > valor1_c1) ? 1 : 0;
    }

    // Segundo atributo
    if (atributo2 == 5) { // densidade (menor vence)
        soma_c1 += (valor2_c1 < valor2_c2) ? 1 : 0;
        soma_c2 += (valor2_c2 < valor2_c1) ? 1 : 0;
    } else {
        soma_c1 += (valor2_c1 > valor2_c2) ? 1 : 0;
        soma_c2 += (valor2_c2 > valor2_c1) ? 1 : 0;
    }

    // --- Exibir resultados ---
    printf("\n===== RESULTADO =====\n");
    printf("Carta 1: %s\n", carta1.nome_pais);
    printf("Carta 2: %s\n\n", carta2.nome_pais);

    printf("Atributo 1 escolhido: %d\n", atributo1);
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_pais, valor1_c1, carta2.nome_pais, valor1_c2);

    printf("\nAtributo 2 escolhido: %d\n", atributo2);
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_pais, valor2_c1, carta2.nome_pais, valor2_c2);

    printf("\nPlacar final -> %s: %.0f pontos | %s: %.0f pontos\n",
           carta1.nome_pais, soma_c1, carta2.nome_pais, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("Vencedor: %s\n", carta1.nome_pais);
    } else if (soma_c2 > soma_c1) {
        printf("Vencedor: %s\n", carta2.nome_pais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
