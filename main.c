#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumeroAleatorio(int min, int max){
    int x = min + rand() % (max - min + 1);
    return x;
}

char* preencherSenha(int tamanho, int op, int numero, int letraMinuscula, int letraMaiuscula){
    char* senha = malloc(tamanho + 1); 
    for (int i = 0; i < tamanho; i++) {
            if(numero && gerarNumeroAleatorio(0,1)){
                senha[i] = (char) gerarNumeroAleatorio(48, 57);
                continue;
            }
            else if (letraMinuscula && gerarNumeroAleatorio(0,1)){
                senha[i] = (char) gerarNumeroAleatorio(97, 122);
                continue;
            }
            else if (letraMaiuscula && gerarNumeroAleatorio(0,1)){
                senha[i] = (char) gerarNumeroAleatorio(65, 90);
                continue;
            }else {
                i--;
                continue;
            }
    }
    senha[tamanho] = '\0';
    return senha; 
}
char* gerarSenha(int tamanho, int op, int numero, int letraMinuscula, int letraMaiuscula){
    char* senha = malloc(tamanho + 1); 
    int validado = 0;
    while (!validado){
        int numeroV = 0;
        int letraMaiusculaV = 0;
        int letraMinusculaV = 0;
        int x;
        senha = preencherSenha(tamanho, op, numero, letraMinuscula, letraMaiuscula);
        for (int i = 0; i < tamanho; i++){
            x = (int) senha[i];
            if(x >= 65 && x <= 90){
                letraMaiusculaV = 1;
            }
            if(x >= 97 && x <= 122){
                letraMinusculaV = 1;
            }
            if(x >= 48 && x <= 57){
                numeroV = 1;
            }
        }
        if(numeroV == numero && letraMaiusculaV == letraMaiuscula && letraMinusculaV == letraMinuscula){
            validado = 1;
        }
        
    }
    
    senha[tamanho] = '\0';
    return senha; 
}

int main(void){
    srand(time(0));
    printf("-----------------teste----------------\n");
    printf("        Gerador de senha     \n");
    printf("---------------------------------\n\n");
    printf("1- gerar senha de 4 caracteres\n");
    printf("2- gerar senha de 8 caracteres\n");
    printf("3- gerar senha de 16 caracteres\n\n");
    printf("---------------------------------\n\n");
    printf("senha de 4 digitos: %s\n", gerarSenha(4,1,1, 1, 1));
    printf("senha de 4 digitos: %s\n", gerarSenha(4,1,1, 1, 1));
    printf("senha de 4 digitos: %s\n", gerarSenha(4,1,1, 1, 1));
    printf("senha de 4 digitos: %s\n", gerarSenha(4,1,1, 1, 1));
    return 0;
}