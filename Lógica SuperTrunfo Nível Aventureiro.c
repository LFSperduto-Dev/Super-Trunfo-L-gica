#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char pais[50];
    char codigo[4];
    unsigned long populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n=== SUPER TRUNFO - MENU DE ATRIBUTOS ===\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("0. Sair\n");
    printf("======================================\n");
    printf("Escolha o atributo para comparação: ");
}

// Função para comparar as cartas
void compararCartas(struct Carta carta1, struct Carta carta2, int opcao) {
    char atributo[30];
    float valor1, valor2;
    int inverte = 0; // Flag para indicar se menor valor vence
    
    // Determinar qual atributo será comparado
    switch(opcao) {
        case 1:
            strcpy(atributo, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2:
            strcpy(atributo, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3:
            strcpy(atributo, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4:
            strcpy(atributo, "Pontos Turísticos");
            valor1 = carta1.pontos_turisticos;
            valor2 = carta2.pontos_turisticos;
            break;
        case 5:
            strcpy(atributo, "Densidade Demográfica");
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            inverte = 1; // Para densidade, menor valor vence
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }
    
    // Exibir informações das cartas
    printf("\n=== COMPARAÇÃO ===\n");
    printf("País 1: %s\n", carta1.pais);
    printf("País 2: %s\n", carta2.pais);
    printf("Atributo: %s\n", atributo);
    
    // Formatar a exibição conforme o tipo de atributo
    if (opcao == 1) { // População
        printf("%s: %lu habitantes\n", carta1.pais, (unsigned long)valor1);
        printf("%s: %lu habitantes\n", carta2.pais, (unsigned long)valor2);
    } 
    else if (opcao == 2 || opcao == 5) { // Área ou Densidade
        printf("%s: %.2f km²\n", carta1.pais, valor1);
        printf("%s: %.2f km²\n", carta2.pais, valor2);
    } 
    else if (opcao == 3) { // PIB
        printf("%s: %.2f bilhões\n", carta1.pais, valor1);
        printf("%s: %.2f bilhões\n", carta2.pais, valor2);
    } 
    else if (opcao == 4) { // Pontos Turísticos
        printf("%s: %d pontos\n", carta1.pais, (int)valor1);
        printf("%s: %d pontos\n", carta2.pais, (int)valor2);
    }
    
    // Determinar o vencedor
    if (inverte) {
        if (valor1 < valor2) {
            printf("\nResultado: %s venceu!\n", carta1.pais);
        } else if (valor2 < valor1) {
            printf("\nResultado: %s venceu!\n", carta2.pais);
        } else {
            printf("\nResultado: Empate!\n");
        }
    } else {
        if (valor1 > valor2) {
            printf("\nResultado: %s venceu!\n", carta1.pais);
        } else if (valor2 > valor1) {
            printf("\nResultado: %s venceu!\n", carta2.pais);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
}

int main() {
    // Cadastro das cartas (pré-definidas)
    struct Carta carta1 = {
        .pais = "Brasil",
        .codigo = "BR01",
        .populacao = 213993437,
        .area = 8515767.049,
        .pib = 1.609, // trilhões
        .pontos_turisticos = 150,
        .densidade = 25.13
    };
    
    struct Carta carta2 = {
        .pais = "Argentina",
        .codigo = "AR01",
        .populacao = 45376763,
        .area = 2780400,
        .pib = 0.445, // trilhões
        .pontos_turisticos = 85,
        .densidade = 16.32
    };
    
    int opcao;
    char continuar;
    
    do {
        // Exibir menu e obter escolha do usuário
        exibirMenu();
        scanf("%d", &opcao);
        
        // Limpar buffer do teclado
        while(getchar() != '\n');
        
        // Processar a opção escolhida
        if (opcao == 0) {
            printf("Encerrando o jogo...\n");
            break;
        }
        
        // Comparar cartas com base na opção escolhida
        compararCartas(carta1, carta2, opcao);
        
        // Perguntar se deseja continuar
        printf("\nDeseja comparar por outro atributo? (S/N): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);
        
        // Limpar buffer do teclado
        while(getchar() != '\n');
        
    } while (continuar == 'S');
    
    printf("Obrigado por jogar Super Trunfo!\n");
    return 0;
}