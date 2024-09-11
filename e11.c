#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
// isso � um fun��o que limpa o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int num1, num2, escolha, valido = 0;

//pegando a resposta do usu�rio e verificando se ele est� correto
    while(!valido){
        printf("Digite dois n�meros inteiros: ");
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
//op��es para o usu�rio
        printf("\n          Menu       \n");
        printf("1    -Multiplica��o- \n");
        printf("2    -Divis�o-       \n");
        printf("3    -Adi��o-        \n");
        printf("4    -Subtra��o-     \n");

        printf("Digite a op��o de sua escolha ");

        if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= 4) {
            valido = 1;
        } else {
            // esse fprint � para tratamento de erro mais correto de se usar
            fprintf(stderr, "Os 'numeros foram digiados incorretamente! \n");
            limparBuffer();

        }
    }
        switch(escolha) {
            case 1:
                printf("a multiplica��o entre %d e %d � %d", num1, num2, num1 * num2);
            break;

            case 2:
                if (num1 == 0 || num2 == 0){
                    fprintf(stderr, "0 n�o pode ser divisivel");
                    limparBuffer();
                } else{
                 printf("a divis�o entre %d e %d � %d", num1, num2, (float)num1 / num2);
                }
                break;
            case 3:
                printf("a adic�o entre %d e %d � %d", num1, num2, num1 + num2);
            break;

            case 4:
                printf("a adic�o entre %d e %d � %d", num1, num2, num1 - num2);
            break;
        }






}
