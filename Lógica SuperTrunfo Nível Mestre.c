#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_ATRIBUTOS 5

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

// Função para exibir o menu de atributos disponíveis
void exibirMenuAtributos(bool disponiveis[]) {
    printf("\n=== MENU DE ATRIBUTOS DISPONÍVEIS ===\n");
    if (disponiveis[0]) printf("1. População\n");
    if (disponiveis[1]) printf("2. Área\n");
    if (disponiveis[2]) printf("3. PIB\n");
    if (disponiveis[3]) printf("4. Pontos Turísticos\n");
    if (disponiveis[4]) printf("5. Densidade Demográfica\n");
    printf("====================================\n");
}

// Função para obter a escolha do usuário
int obterEscolha(bool disponiveis[], const char* mensagem) {
    int escolha;
    bool valida = false;
    
    do {
        printf("%s", mensagem);
        scanf("%d", &escolha);
        
        // Limpar buffer do teclado
        while(getchar() != '\n');
        
        // Validar escolha
        if (escolha >= 1 && escolha <= NUM_ATRIBUTOS && disponiveis[escolha-1]) {
            valida = true;
        } else {
            printf("Opção inválida! Escolha um número correspondente a um atributo disponível.\n");
        }
    } while (!valida);
    
    return escolha;
}

// Função para comparar dois valores de atributo
int compararAtributo(float valor1, float valor2, bool inverte) {
    if (inverte) { // Para densidade, menor valor vence
        if (valor1 < valor2) return 1;
        if (valor2 < valor1) return 2;
    } else { // Para outros atributos, maior valor vence
        if (valor1 > valor2) return 1;
        if (valor2 > valor1) return 2;
    }
    return 0; // Empate
}

// Função para obter o valor do atributo de uma carta
float obterValorAtributo(struct Carta carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade;
        default: return 0;
    }
}

// Função para obter o nome do atributo
const char* obterNomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para formatar a exibição do valor do atributo
void formatarValorAtributo(int atributo, float valor) {
    switch(atributo) {
        case 1: printf("%.0f habitantes", valor); break;
        case 2: printf("%.2f km²", valor); break;
        case 3: printf("%.2f bilhões", valor); break;
        case 4: printf("%.0f pontos", valor); break;
        case 5: printf("%.2f hab/km²", valor); break;
        default: printf("%.2f", valor);
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
    
    char continuar;
    
    do {
        bool atributos_disponiveis[NUM_ATRIBUTOS] = {true, true, true, true, true};
        int atributo1, atributo2;
        
        // Mostrar informações básicas das cartas
        printf("\n=== CARTAS PARA COMPARAÇÃO ===\n");
        printf("Carta 1: %s (%s)\n", carta1.pais, carta1.codigo);
        printf("Carta 2: %s (%s)\n", carta2.pais, carta2.codigo);
        
        // Escolher primeiro atributo
        exibirMenuAtributos(atributos_disponiveis);
        atributo1 = obterEscolha(atributos_disponiveis, "Escolha o primeiro atributo para comparação: ");
        atributos_disponiveis[atributo1-1] = false; // Marcar como indisponível
        
        // Escolher segundo atributo
        exibirMenuAtributos(atributos_disponiveis);
        atributo2 = obterEscolha(atributos_disponiveis, "Escolha o segundo atributo para comparação: ");
        
        // Obter valores dos atributos
        float valor1_atr1 = obterValorAtributo(carta1, atributo1);
        float valor2_atr1 = obterValorAtributo(carta2, atributo1);
        float valor1_atr2 = obterValorAtributo(carta1, atributo2);
        float valor2_atr2 = obterValorAtributo(carta2, atributo2);
        
        // Determinar se é para inverter a comparação (apenas para densidade)
        bool inverte1 = (atributo1 == 5);
        bool inverte2 = (atributo2 == 5);
        
        // Comparar os atributos individualmente
        int resultado_atr1 = compararAtributo(valor1_atr1, valor2_atr1, inverte1);
        int resultado_atr2 = compararAtributo(valor1_atr2, valor2_atr2, inverte2);
        
        // Calcular soma dos atributos
        float soma1 = valor1_atr1 + valor1_atr2;
        float soma2 = valor2_atr1 + valor2_atr2;
        
        // Determinar o vencedor geral
        int vencedor_geral = (soma1 > soma2) ? 1 : ((soma2 > soma1) ? 2 : 0);
        
        // Exibir resultados
        printf("\n=== RESULTADOS DA COMPARAÇÃO ===\n");
        
        // Resultado do primeiro atributo
        printf("\nAtributo 1: %s\n", obterNomeAtributo(atributo1));
        printf("%s: ", carta1.pais); formatarValorAtributo(atributo1, valor1_atr1); printf("\n");
        printf("%s: ", carta2.pais); formatarValorAtributo(atributo1, valor2_atr1); printf("\n");
        printf("Vencedor: %s\n", 
               resultado_atr1 == 0 ? "Empate!" : 
               (resultado_atr1 == 1 ? carta1.pais : carta2.pais));
        
        // Resultado do segundo atributo
        printf("\nAtributo 2: %s\n", obterNomeAtributo(atributo2));
        printf("%s: ", carta1.pais); formatarValorAtributo(atributo2, valor1_atr2); printf("\n");
        printf("%s: ", carta2.pais); formatarValorAtributo(atributo2, valor2_atr2); printf("\n");
        printf("Vencedor: %s\n", 
               resultado_atr2 == 0 ? "Empate!" : 
               (resultado_atr2 == 1 ? carta1.pais : carta2.pais));
        
        // Resultado geral
        printf("\n=== RESULTADO FINAL ===\n");
        printf("Soma dos atributos para %s: %.2f\n", carta1.pais, soma1);
        printf("Soma dos atributos para %s: %.2f\n", carta2.pais, soma2);
        
        if (vencedor_geral == 0) {
            printf("\nResultado final: Empate!\n");
        } else {
            printf("\nResultado final: %s venceu!\n", 
                   vencedor_geral == 1 ? carta1.pais : carta2.pais);
        }
        
        // Perguntar se deseja continuar
        printf("\nDeseja realizar outra comparação? (S/N): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);
        
        // Limpar buffer do teclado
        while(getchar() != '\n');
        
    } while (continuar == 'S');
    
    printf("\nObrigado por jogar Super Trunfo!\n");
    return 0;
}