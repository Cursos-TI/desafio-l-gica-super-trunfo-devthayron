#include <stdio.h>
#include <string.h>

// Estrutura de carta
struct Cartao {
    char nome_pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

int main() {
    // --- Cartas pré-cadastradas (pode alterar depois) ---
    struct Cartao carta1 = {"Brasil", 213000000, 8515767.0, 14400.0, 100, 213000000 / 8515767.0};
    struct Cartao carta2 = {"Argentina", 45000000, 2780000.0, 600.0, 50, 45000000 / 2780000.0};

    int opcao;

    printf("===== SUPER TRUNFO - Nível Aventureiro =====\n");
    printf("Carta 1: %s\n", carta1.nome_pais);
    printf("Carta 2: %s\n\n", carta2.nome_pais);

    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\n===== RESULTADO =====\n");

    switch (opcao) {
        case 1: // População
            printf("Comparando População:\n");
            printf("%s: %d habitantes\n", carta1.nome_pais, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome_pais, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nome_pais);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Vencedor: %s\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Comparando Área:\n");
            printf("%s: %.2f km²\n", carta1.nome_pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome_pais, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nome_pais);
            } else if (carta1.area < carta2.area) {
                printf("Vencedor: %s\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhões USD\n", carta1.nome_pais, carta1.pib);
            printf("%s: %.2f bilhões USD\n", carta2.nome_pais, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nome_pais);
            } else if (carta1.pib < carta2.pib) {
                printf("Vencedor: %s\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Comparando Pontos Turísticos:\n");
            printf("%s: %d pontos\n", carta1.nome_pais, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.nome_pais, carta2.pontos_turisticos);

            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Vencedor: %s\n", carta1.nome_pais);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("Vencedor: %s\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade (regra invertida)
            printf("Comparando Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", carta1.nome_pais, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.nome_pais, carta2.densidade);

            if (carta1.densidade < carta2.densidade) { // menor vence
                printf("Vencedor: %s\n", carta1.nome_pais);
            } else if (carta1.densidade > carta2.densidade) {
                printf("Vencedor: %s\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
