#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


void cadEndereco(){
    FILE *file;
    file = fopen("enderCads.txt","a");

    system("clear");
    struct endereco{
        char bairro[50];
        char rua[50];
        char numero[50];
    };

    struct endereco rbn;

    printf("Digite o bairro da sua casa:");
    fgets(rbn.bairro,50,stdin);

    printf("Digite a rua da sua casa: ");
    fgets(rbn.rua,50,stdin);

    printf("Digite o numero da casa");
    fgets(rbn.numero,50,stdin);

    rbn.bairro[strcspn(rbn.bairro,"\n")]=0;
    rbn.rua[strcspn(rbn.rua,"\n")]=0;
    rbn.numero[strcspn(rbn.numero,"\n")]=0;

    fprintf(file,"%s, %s, %s\n",rbn.bairro,rbn.rua,rbn.numero);


    fclose(file);

    file = fopen("enderCads","r");

}

int main(){
    
    setlocale(LC_ALL,"portuguese");
    system("clear");
    
    int escolha;



    printf("Escolha uma opção:\n(1)Cadastrar endereço\n(2)Ver chamados");
    scanf("%d",&escolha);
    getchar();


    switch (escolha)
    {
    case 1:

        cadEndereco();
        break;
    case 2:
        
        break;

    default:
        printf("n foi");
        break;
    }
}