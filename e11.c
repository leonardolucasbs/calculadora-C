#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
// isso é um função que limpa o buffer de entrada
 
 
void limpa_tela(){
    system("cls");
}
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int num1, num2, escolha;
    int valido = 0;
 
 
//pegando a resposta do usuário e verificando se ele está correto
    while (true){
    while(!valido){
        printf("Digite dois números inteiros: ");
        if(scanf("%d %d", &num1, &num2) == 2){
           valido = 1;
        } else {
            fprintf(stderr, "Os numeros foram digiados incorretamente! \n");
            limparBuffer();
        }
    }
    limparBuffer();
    valido = 0;
 
 
    while(!valido){
//opções para o usuário
        printf("\n        Menu       \n");
        printf("1    -Multiplicação- \n");
        printf("2    -Divisão-       \n");
        printf("3    -Adição-        \n");
        printf("4    -Subtração-     \n");
 
 
        printf("Digite a opção de sua escolha ");
 
 
        if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= 4) {
            valido = 1;
        } else {
            // esse fprint é para tratamento de erro mais correto de se usar
            fprintf(stderr, "Os 'numeros foram digiados incorretamente! \n");
            limparBuffer();
 
 
        }
    }
        switch(escolha) {
            case 1:
                printf("a multiplicação entre %d e %d é %d", num1, num2, num1 * num2);
            break;
 
 
            case 2:
                if (num1 == 0 || num2 == 0){
                    fprintf(stderr, "0 nào pode ser divisivel");
                    limparBuffer();
                } else{
                 printf("a divisão entre %d e %d é %d", num1, num2,(float) num1 / num2);
                }
                break;
            case 3:
                printf("a adicão entre %d e %d é %d", num1, num2, num1 + num2);
            break;
 
 
            case 4:
                printf("a adicão entre %d e %d é %d", num1, num2, num1 - num2);
            break;
        }
        int res;
        printf("\nVocê deseja continuar? [1] - sim [0] - não");
        scanf("%d", &res);
        if (res == 1){
            limpa_tela();
        }else if(res == 0){
            break;
        }
 
 
    }
 
 
 
 
 
 
 
 
}
