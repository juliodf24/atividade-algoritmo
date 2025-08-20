#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    char nome[128];
    printf("qual seu nome: ");
    gets( nome);
    
    int matricula;
    printf("qual a sua matricula: ");
    scanf("%d",&matricula);
    
    char disciplina[128];
    printf("qual o nome da sua Disciplina: ");
    gets( disciplina);
    
    char turma[128];
    printf("qual sua turma: ");
    gets(turma);
    
    float altura;
    printf("qual a sua altura em metros: ");
    scanf("%f", &altura);
    
    float peso;
    printf("qual a sua peso em quilos: ");
    scanf("%f", &peso);
    
    printf(" Seu nome e %s  , matricula %d, estuda %s na turma %s \n  altura: %f m , Peso: %f Kg", nome, matricula, disciplina, turma, altura, peso);
    
    
    return 0;
}