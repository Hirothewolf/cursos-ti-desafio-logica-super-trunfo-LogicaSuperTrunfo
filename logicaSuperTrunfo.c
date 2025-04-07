#include <stdio.h> // Biblioteca para entrada (scanf) e saída (printf)

// Jogo Super Trunfo - Desafio C
// Combina cadastro e cálculos (Tema 1) com escolha e comparação (Tema 2)

int main() {
    // --- Variáveis para a Carta 1 (Jogador) ---
    char estado1;
    char codigo1[10];
    char cidade1[50];
    unsigned long int populacao1; // Usa unsigned long int para números grandes de população
    float area1;
    float pib1;                   // PIB em bilhões
    int pontos_turisticos1;
    float densidade1;             // Calculado: populacao / area
    float pibPerCapita1;          // Calculado: (pib * 1 bilhão) / populacao
    float superPoder1;            // Calculado (soma dos atributos)

    // --- Variáveis para a Carta 2 (Computador) ---
    char estado2;
    char codigo2[10];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // --- Cadastro da Carta 1 ---
    printf("--- Cadastro da Carta 1 (Jogador) ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1); // Lê o caractere do estado

    printf("Codigo (ex: A01): ");
    scanf("%s", codigo1); // Lê a string do código

    // Limpa o buffer do teclado antes de ler o nome da cidade
    // Isso é necessário porque o scanf anterior deixa um '\n' (Enter)
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Nome da cidade: ");
    scanf("%[^\n]", cidade1); // Lê a string do nome da cidade (aceita espaços)

    printf("Populacao: ");
    scanf("%lu", &populacao1); // %lu para ler unsigned long int

    printf("Area (km^2): ");
    scanf("%f", &area1); // %f para ler float

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos1); // %d para ler int

    // --- Cálculos para a Carta 1 ---
    // Densidade = População / Área
    if (area1 > 0) { // Verifica se a área é válida para evitar divisão por zero
        densidade1 = (float)populacao1 / area1; // (float) converte populacao1 para float antes da divisão
    } else {
        densidade1 = 0; // Define densidade como 0 se área for inválida
    }

    // PIB per Capita = (PIB * 1 bilhão) / População
    if (populacao1 > 0) { // Verifica se a população é válida
        pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1; // 1e9f é 1 bilhão em float
    } else {
        pibPerCapita1 = 0;
    }

    // Super Poder = Soma de atributos + (1 / densidade)
    // Quanto menor a densidade, maior o inverso, maior o poder.
    float inversoDensidade1 = 0;
    if (densidade1 > 0) {
        inversoDensidade1 = 1.0f / densidade1; // 1.0f para garantir divisão float
    }
    // Soma simples como exemplo (a fórmula pode variar)
    superPoder1 = (float)populacao1 + area1 + (float)pontos_turisticos1 + pibPerCapita1 + inversoDensidade1;

    // --- Cadastro da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 (Computador) ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo (ex: B02): ");
    scanf("%s", codigo2);

    // Limpa o buffer novamente
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km^2): ");
    scanf("%f", &area2);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // --- Cálculos para a Carta 2 ---
    if (area2 > 0) {
        densidade2 = (float)populacao2 / area2;
    } else {
        densidade2 = 0;
    }

    if (populacao2 > 0) {
        pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    } else {
        pibPerCapita2 = 0;
    }

    float inversoDensidade2 = 0;
    if (densidade2 > 0) {
        inversoDensidade2 = 1.0f / densidade2;
    }
    superPoder2 = (float)populacao2 + area2 + (float)pontos_turisticos2 + pibPerCapita2 + inversoDensidade2;

    // --- Exibição Opcional dos Dados Completos ---
    // É útil para verificar se os cadastros e cálculos estão corretos
    printf("\n--- DADOS CARTA 1: %s ---\n", cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f\n", area1);
    printf("PIB: %.2f Bi\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade: %.2f\n", densidade1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);
    printf("--------------------------\n");

    printf("\n--- DADOS CARTA 2: %s ---\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f\n", area2);
    printf("PIB: %.2f Bi\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade: %.2f\n", densidade2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);
    printf("--------------------------\n");

    // --- Menu de Escolha de Atributo (Tema 2) ---
    int escolha_atributo;
    printf("\n--- Escolha o atributo para comparar ---\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. Pontos Turisticos\n");
    printf("4. Densidade Populacional (Menor vence!)\n");
    printf("5. PIB per Capita\n");
    printf("6. Super Poder\n");
    printf("Digite o numero do atributo: ");
    scanf("%d", &escolha_atributo); // Lê a escolha do jogador

    printf("\n--- RESULTADO DA RODADA ---\n");

    // --- Comparação usando switch e if-else (Tema 2) ---
    switch (escolha_atributo) {
        case 1: // População
            printf("Comparando: Populacao\n");
            printf("%s: %lu vs %s: %lu\n", cidade1, populacao1, cidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Vencedor: %s (Carta 1)\n", cidade1);
            } else if (populacao2 > populacao1) {
                printf("Vencedor: %s (Carta 2)\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break; // Sai do switch

        case 2: // Área
            printf("Comparando: Area\n");
            printf("%s: %.2f vs %s: %.2f\n", cidade1, area1, cidade2, area2);
            if (area1 > area2) {
                printf("Vencedor: %s (Carta 1)\n", cidade1);
            } else if (area2 > area1) {
                printf("Vencedor: %s (Carta 2)\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // Pontos Turísticos
            printf("Comparando: Pontos Turisticos\n");
            printf("%s: %d vs %s: %d\n", cidade1, pontos_turisticos1, cidade2, pontos_turisticos2);
            if (pontos_turisticos1 > pontos_turisticos2) {
                printf("Vencedor: %s (Carta 1)\n", cidade1);
            } else if (pontos_turisticos2 > pontos_turisticos1) {
                printf("Vencedor: %s (Carta 2)\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Densidade Populacional (MENOR vence)
            printf("Comparando: Densidade Populacional (Menor vence!)\n");
            printf("%s: %.2f vs %s: %.2f\n", cidade1, densidade1, cidade2, densidade2);
            // Verifica se ambos são válidos antes de comparar
            if (densidade1 > 0 && densidade2 > 0) {
                if (densidade1 < densidade2) { // Menor vence
                    printf("Vencedor: %s (Carta 1)\n", cidade1);
                } else if (densidade2 < densidade1) { // Menor vence
                    printf("Vencedor: %s (Carta 2)\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            } else if (densidade1 > 0) { // Só densidade 1 é válida, então ela vence
                 printf("Vencedor: %s (Carta 1) - Densidade da Carta 2 invalida.\n", cidade1);
            } else if (densidade2 > 0) { // Só densidade 2 é válida, então ela vence
                 printf("Vencedor: %s (Carta 2) - Densidade da Carta 1 invalida.\n", cidade2);
            } else { // Ambas inválidas
                 printf("Resultado: Empate (ambas densidades invalidas)!\n");
            }
            break;

        case 5: // PIB per Capita
            printf("Comparando: PIB per Capita\n");
            printf("%s: %.2f vs %s: %.2f\n", cidade1, pibPerCapita1, cidade2, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2) {
                printf("Vencedor: %s (Carta 1)\n", cidade1);
            } else if (pibPerCapita2 > pibPerCapita1) {
                printf("Vencedor: %s (Carta 2)\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // Super Poder
            printf("Comparando: Super Poder\n");
            printf("%s: %.2f vs %s: %.2f\n", cidade1, superPoder1, cidade2, superPoder2);
            // Compara floats diretamente (pode ter pequena imprecisão, mas simplificado)
            if (superPoder1 > superPoder2) {
                printf("Vencedor: %s (Carta 1)\n", cidade1);
            } else if (superPoder2 > superPoder1) {
                printf("Vencedor: %s (Carta 2)\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default: // Caso o jogador digite uma opção inválida
            printf("Opcao de atributo invalida! Escolha um numero de 1 a 6.\n");
            break;
    } // Fim do switch

    printf("--------------------------\n");

    return 0; // Indica que o programa terminou com sucesso
}
