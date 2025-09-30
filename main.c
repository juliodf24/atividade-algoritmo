#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumeroAleatorio(int min, int max){
    int x = min + rand() % (max - min + 1);
    return x;
}
// teste 
void preencherSenha(char *enderecoSenha, int tamanho, int numero, int letraMinuscula, int letraMaiuscula, int caractereEspecial){
    char *senha = enderecoSenha;
    int Vnumero = 0, VletraMaiuscula = 0, VletraMinuscula = 0, VcaractereEspecial = 0;
    for (int i = 0; i < tamanho; i++){
        if(numero && gerarNumeroAleatorio(0,1)){
            senha[i] = (char) gerarNumeroAleatorio(48, 57);
            Vnumero = 1;
        }
        else if (letraMinuscula && gerarNumeroAleatorio(0,1)){
            senha[i] = (char) gerarNumeroAleatorio(97, 122);
            VletraMinuscula = 1;
        }
        else if (letraMaiuscula && gerarNumeroAleatorio(0,1)){
            senha[i] = (char) gerarNumeroAleatorio(65, 90);
            VletraMaiuscula = 1;
        }else if (caractereEspecial && gerarNumeroAleatorio(0,1)){
            senha[i] = (char) gerarNumeroAleatorio(35, 38);
            VcaractereEspecial = 1;
        }else {
            i--;
            continue;
        }
        if(i == 3){
            if(Vnumero != numero || VletraMaiuscula != letraMaiuscula || VletraMinuscula != letraMinuscula || VcaractereEspecial != caractereEspecial){
                i = -1;
                Vnumero = 0;
                VletraMaiuscula = 0;
                VletraMinuscula = 0;
                VcaractereEspecial = 0;
            }
        }
    }
    senha[tamanho] = '\0';
}
void gerarSenha(char *senha, int op, int tamanho){
    switch (op){
    case 1:
        preencherSenha(senha, tamanho, 0,1,0,0);
        break;
    case 2:
        preencherSenha(senha, tamanho, 0,1,1,0);
        break;
    case 3:
        preencherSenha(senha, tamanho, 1,1,1,0);
        break;
    case 4:
        preencherSenha(senha, tamanho, 1,1,1,1);
        break;
    
    default:
        break;
    }
}

int main(void){
    srand(time(0));
    char senha[20];
    int tamanho = 0;
    int erro = 0;
    int op = 0;
    while (!(op >= 1 && op <= 3)){
        system("clear");
        printf("---------------------------------\n");
        printf("        Gerador de senha     \n");
        printf("---------------------------------\n\n");
        printf("1- gerar senha de 4 caracteres\n");
        printf("2- gerar senha de 10 caracteres\n");
        printf("3- gerar senha de 16 caracteres\n\n");
        printf("---------------------------------\n");
        if(erro){
            printf("\033[31m! digite uma opção valida !\033[0m\n\n");
        }
        printf("Digite o número de uma opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                tamanho = 4;
                break;
            case 2:
                tamanho = 10;
                break;
            case 3:
                tamanho = 16;
                break;
        
            default:
                erro = 1;
                continue;
        }
    }
    erro = 0;
    op = 0;
    while (!(op >= 1 && op <= 4)){
        system("clear");
        printf("---------------------------------\n");
        printf("        Gerador de senha     \n");
        printf("---------------------------------\n\n");
        printf("Composição:\n");
        printf("1- Somente letras Minusculas\n");
        printf("2- Letras Minusculas e Maiusculas\n");
        printf("3- Letras e Números\n");
        printf("4- Letras, Números e Caractere Especial\n\n");
        printf("---------------------------------\n");
        if(erro){
            printf("\033[31m! digite uma opção valida !\033[0m\n\n");
        }
        printf("Digite o número de uma opção: ");
        scanf("%d", &op);
        if(op >= 1 && op <= 4){
            gerarSenha(senha, op, tamanho);
            break;
        }
        erro = 1;
    }
    erro = 0;
    system("clear");
    printf("---------------------------------\n");
    printf("        Gerador de senha     \n");
    printf("---------------------------------\n\n");
    printf("\n");
    printf("\n");
    printf("Senha Gerada: %s\n", senha);
    printf("\n");
    printf("\n\n");
    printf("---------------------------------\n");
    system("PAUSE");
}