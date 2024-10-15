#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

// Função que limpa a tela
void limpa_tela(){
    system("cls");  // Use "clear" se estiver no Linux
}

// Função que limpa o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para verificar se o resultado está dentro do intervalo permitido
bool resultado_valido(int resultado) {
    return (resultado >= -32768 && resultado <= 32767);
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int num1, num2, escolha;
    int valido = 0;

    while (true) {
        // Pegando a resposta do usuário e verificando se ele está correto
        while (!valido) {
            printf("Digite dois números inteiros: ");
            if (scanf("%d %d", &num1, &num2) == 2) {
                valido = 1;
            } else {
                fprintf(stderr, "Os números foram digitados incorretamente!\n");
                limparBuffer();
            }
        }
        limparBuffer();
        valido = 0;

        // Menu de opções para o usuário
        while (!valido) {
            printf("\n        Menu       \n");
            printf("1    - Multiplicação - \n");
            printf("2    - Divisão -       \n");
            printf("3    - Adição -        \n");
            printf("4    - Subtração -     \n");
            printf("Digite a opção de sua escolha: ");

            if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= 4) {
                valido = 1;
            } else {
                fprintf(stderr, "Opção inválida! Por favor, escolha uma opção entre 1 e 4.\n");
                limparBuffer();
            }
        }
        limparBuffer();
        valido = 0;

        switch (escolha) {
            case 1: {
                // Multiplicação
                int multiplicacao = num1 * num2;
                if (resultado_valido(multiplicacao)) {
                    printf("A multiplicação entre %d e %d é %d\n", num1, num2, multiplicacao);
                } else {
                    printf("\nErro: O resultado da multiplicação está fora do intervalo permitido.\n");
                }
                break;
            }
            case 2: {
                // Divisão
                if (num2 == 0) {
                    fprintf(stderr, "Erro: Não é possível dividir por zero!\n");
                } else {
                    float divisao = (float) num1 / num2;
                    if (resultado_valido((int) divisao)) {
                        printf("A divisão entre %d e %d é %.2f\n", num1, num2, divisao);
                    } else {
                        printf("\nErro: O resultado da divisão está fora do intervalo permitido.\n");
                    }
                }
                break;
            }
            case 3: {
                // Adição
                int soma = num1 + num2;
                if (resultado_valido(soma)) {
                    printf("A adição entre %d e %d é %d\n", num1, num2, soma);
                } else {
                    printf("\nErro: O resultado da adição está fora do intervalo permitido.\n");
                }
                break;
            }
            case 4: {
                // Subtração
                int subtracao = num1 - num2;
                if (resultado_valido(subtracao)) {
                    printf("A subtração entre %d e %d é %d\n", num1, num2, subtracao);
                } else {
                    printf("\nErro: O resultado da subtração está fora do intervalo permitido.\n");
                }
                break;
            }
        }

        // Perguntar ao usuário se ele deseja continuar
        int res;
        printf("\nVocê deseja continuar? [1] - sim [0] - não: ");
        scanf("%d", &res);
        if (res == 1) {
            limpa_tela();
        } else if (res == 0) {
            break;
        }
    }
    return 0;
}
