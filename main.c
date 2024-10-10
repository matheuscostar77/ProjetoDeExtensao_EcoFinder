#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void ola(){
    FILE *file;
    file = fopen("enderCads","w");

    system("clear");
    struct endereco{
        char bairro[50];
        char rua[50];
        char numero[50];
    };
    struct endereco rbn;
    printf("Digite o bairro da sua casa:");
    fgets(rbn.bairro,50,stdin);

    rbn.bairro[strcspn(rbn.bairro,"\n")]=0;

    fprintf(file,"%s\n",rbn.bairro);


    fclose(file);

    file = fopen("enderCads","r");

}

int main(){
    
    setlocale(LC_ALL,"portuguese");
    system("clear");
    
    int escolha;



    printf("Escolha uma opção:\n(1)Cadastrar endereço\n(2)Locais para coleta");
    scanf("%d",&escolha);
    getchar();


    switch (escolha)
    {
    case 1:

        ola();
        break;
    
    default:
        printf("n foi");
        break;
    }
}