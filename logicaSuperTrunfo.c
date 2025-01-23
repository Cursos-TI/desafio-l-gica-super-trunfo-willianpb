#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
// Teste larissa

typedef struct 
{
    char nomePais[30];
    char nomeEstado[30];
    char codigoCidade[3];
    unsigned int populacao;
    unsigned int pontosTuristicos;
    float area;
    float pib;
    float pibPerCapita;
    float densidade;
} Card;

void PreencheCarta(Card * card);
void PrintCarta(Card * card);
void VerificaVencedora(Card * card1, Card * card2);
float CalcularSuperPoder(Card * card);
void CalcularPonto(int * ponto1, int * ponto2, float valor1, float valor2);

void PreencheCarta(Card * card) 
{
     printf("Digite o nome do País: ");
    scanf("%s", card->nomePais);

    printf("Digite o nome do Estado: ");
    scanf("%s", card->nomeEstado);

    printf("Digite o nome do Código: ");
    scanf("%s", card->codigoCidade);

    unsigned int populacao;
    printf("Digite a quantidade Populacional: ");
    scanf("%u", &populacao);
    card->populacao = populacao;

    unsigned int pontosTuristicos;
    printf("Digite a quantidade de Pontos Turísticos: ");
    scanf("%u", &pontosTuristicos);
    card->pontosTuristicos = pontosTuristicos;

    float pib;
    printf("Digite o PIB: ");
    scanf("%f", &pib);
    card->pib = pib;

    float area;
    printf("Digite a Área: ");
    scanf("%f", &area);
    card->area = area;

    card->pibPerCapita = 0;
    card->densidade = 0;

    if(card->area > 0) {
        card->densidade = card->populacao / card->area;
    }

    if(card->populacao > 0){
        card->pibPerCapita = card->pib / card->populacao;
    }
}

void PrintCarta(Card * card1) 
{
    printf("\nPaís: %s", card1->nomePais);
    printf("\nEstado: %s", card1->nomeEstado);
    printf("\nCódigo: %s", card1->codigoCidade);
    printf("\nPopulação: %d", card1->populacao);
    printf("\nPontos Turísticos: %d", card1->pontosTuristicos);
    printf("\nÁrea: %.2f", card1->area);
    printf("\nPIB: %.2f", card1->pib);
    printf("\nDensidade Populacional: %.2f", card1->densidade);
    printf("\nPIB per Capita: %.2f", card1->pibPerCapita);
}

float CalcularSuperPoder(Card * card)
{
    return (float)card->area 
        + card->densidade 
        + card->pib 
        + card->pibPerCapita 
        + card->pontosTuristicos 
        + card->populacao;
}

void CalcularPonto(int * ponto1, int * ponto2, float valor1, float valor2)
{
    if(valor1 > valor2)
    {
        *ponto1 += 1;
    }
    else if(valor1 < valor2)
    {
        *ponto2 += 1;       
    }
}

void VerificaVencedora(Card * card1, Card * card2)
{
    int pontosCarta1 = 0;
    int pontosCarta2 = 0;

    if(card1->densidade > card2->densidade)
    {
        pontosCarta2++;
    }
    else if(card1->densidade < card2->densidade)
    {
        pontosCarta1++;       
    }

    CalcularPonto(&pontosCarta1, &pontosCarta2, card1->area, card2->area);
    CalcularPonto(&pontosCarta1, &pontosCarta2, card1->pib, card2->pib);
    CalcularPonto(&pontosCarta1, &pontosCarta2, card1->pibPerCapita, card2->pibPerCapita);
    CalcularPonto(&pontosCarta1, &pontosCarta2, (float)card1->pontosTuristicos, (float)card2->pontosTuristicos);
    CalcularPonto(&pontosCarta1, &pontosCarta2, (float)card1->populacao, (float)card2->populacao);

    if(pontosCarta1 > pontosCarta2)
    {
        printf("\nA carta vencedora foi: %s\n", card1->nomePais);
    }
    else if(pontosCarta1 < pontosCarta2)
    {
        printf("\nA carta vencedora foi: %s\n", card2->nomePais);
    }
    else
    {
        printf("\nHouve um empate entre as cartas\n");
    }

    printf("\nPONTOS %s: %d \n",card1->nomePais, pontosCarta1);
    printf("PONTOS %s: %d \n",card2->nomePais, pontosCarta2);
}

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    Card card1;
    Card card2;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    printf("\nPreencha os dados da primeira carta\n");
    PreencheCarta(&card1);

    printf("\nPreencha os dados da segunda carta\n");
    PreencheCarta(&card2);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    printf("\n**** Informações da Carta 1 ****");
    PrintCarta(&card1);
    printf("\n****************\n");
    
    printf("\n**** Informações da Carta 2 ****");
    PrintCarta(&card2);
    printf("\n****************\n");

    VerificaVencedora(&card1, &card2);

    return 0;
}
