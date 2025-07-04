#include <stdio.h>
#include <string.h>

int main() {
    // Definindo as duas cartas (pré-definidas conforme simplificação)
    struct Carta {
        char estado[3];         // Sigla do estado (2 caracteres + \0)
        char codigo[4];         // Código da carta (3 caracteres + \0)
        char cidade[50];        // Nome da cidade
        unsigned long populacao; // População
        float area;             // Área em km²
        float pib;              // PIB em bilhões de reais
        int pontos_turisticos;  // Número de pontos turísticos
        float densidade;        // Densidade populacional
        float pib_per_capita;   // PIB per capita
    };
    
    // Cadastro da Carta 1 - São Paulo
    struct Carta carta1 = {
        .estado = "SP",
        .codigo = "A01",
        .cidade = "São Paulo",
        .populacao = 12300000,
        .area = 1521.11,
        .pib = 699.28,
        .pontos_turisticos = 50
    };
    
    // Cadastro da Carta 2 - Rio de Janeiro
    struct Carta carta2 = {
        .estado = "RJ",
        .codigo = "B02",
        .cidade = "Rio de Janeiro",
        .populacao = 6748000,
        .area = 1200.25,
        .pib = 300.50,
        .pontos_turisticos = 30
    };
    
    // Calcular densidade e PIB per capita para ambas as cartas
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;
    
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;
    
    // Escolher o atributo para comparação (definido no código)
    // Opções: "populacao", "area", "pib", "densidade", "pib_per_capita"
    char atributo_escolhido[] = "populacao"; // Alterar aqui para testar outros atributos
    
    // Variáveis para armazenar os valores comparados
    float valor1, valor2;
    int inverte_comparacao = 0; // Flag para indicar se menor valor vence (caso da densidade)
    
    // Determinar quais valores comparar com base no atributo escolhido
    if (strcmp(atributo_escolhido, "populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
    } 
    else if (strcmp(atributo_escolhido, "area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } 
    else if (strcmp(atributo_escolhido, "pib") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } 
    else if (strcmp(atributo_escolhido, "densidade") == 0) {
        valor1 = carta1.densidade;
        valor2 = carta2.densidade;
        inverte_comparacao = 1; // Para densidade, menor valor vence
    } 
    else if (strcmp(atributo_escolhido, "pib_per_capita") == 0) {
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
    } 
    else {
        printf("Atributo inválido para comparação!\n");
        return 1;
    }
    
    // Determinar a carta vencedora
    int carta_vencedora;
    
    if (inverte_comparacao) {
        // Para densidade, menor valor vence
        carta_vencedora = (valor1 < valor2) ? 1 : 2;
    } else {
        // Para outros atributos, maior valor vence
        carta_vencedora = (valor1 > valor2) ? 1 : 2;
    }
    
    // Exibir informações das cartas
    printf("Carta 1 - %s (%s):\n", carta1.cidade, carta1.estado);
    printf("  População: %lu\n", carta1.populacao);
    printf("  Área: %.2f km²\n", carta1.area);
    printf("  PIB: %.2f bilhões\n", carta1.pib);
    printf("  Pontos Turísticos: %d\n", carta1.pontos_turisticos);
    printf("  Densidade: %.2f hab/km²\n", carta1.densidade);
    printf("  PIB per capita: %.2f reais\n\n", carta1.pib_per_capita);
    
    printf("Carta 2 - %s (%s):\n", carta2.cidade, carta2.estado);
    printf("  População: %lu\n", carta2.populacao);
    printf("  Área: %.2f km²\n", carta2.area);
    printf("  PIB: %.2f bilhões\n", carta2.pib);
    printf("  Pontos Turísticos: %d\n", carta2.pontos_turisticos);
    printf("  Densidade: %.2f hab/km²\n", carta2.densidade);
    printf("  PIB per capita: %.2f reais\n\n", carta2.pib_per_capita);
    
    // Exibir resultado da comparação
    printf("Comparação de cartas (Atributo: %s):\n", atributo_escolhido);
    
    // Formatar a exibição do valor conforme o tipo de atributo
    if (strcmp(atributo_escolhido, "populacao") == 0) {
        printf("Carta 1 - %s: %lu\n", carta1.cidade, (unsigned long)valor1);
        printf("Carta 2 - %s: %lu\n", carta2.cidade, (unsigned long)valor2);
    } 
    else if (strcmp(atributo_escolhido, "area") == 0 || strcmp(atributo_escolhido, "densidade") == 0) {
        printf("Carta 1 - %s: %.2f km²\n", carta1.cidade, valor1);
        printf("Carta 2 - %s: %.2f km²\n", carta2.cidade, valor2);
    } 
    else if (strcmp(atributo_escolhido, "pib") == 0) {
        printf("Carta 1 - %s: %.2f bilhões\n", carta1.cidade, valor1);
        printf("Carta 2 - %s: %.2f bilhões\n", carta2.cidade, valor2);
    } 
    else if (strcmp(atributo_escolhido, "pib_per_capita") == 0) {
        printf("Carta 1 - %s: %.2f reais\n", carta1.cidade, valor1);
        printf("Carta 2 - %s: %.2f reais\n", carta2.cidade, valor2);
    }
    
    printf("Resultado: Carta %d (%s) venceu!\n", 
           carta_vencedora, 
           (carta_vencedora == 1) ? carta1.cidade : carta2.cidade);
    
    return 0;
}