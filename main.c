#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char usuario[50];
    char senha[50];

} Login;

void cadastro(){

    FILE *file;
    file = fopen("usuarioCads.txt","a");

    Login cads;

    printf("Digite o usuário: ");
    fgets(cads.usuario,50,stdin);

    printf("Digite a senha: ");
    fgets(cads.senha,50,stdin);

    cads.usuario[strcspn(cads.usuario, "\n")] = 0;
    cads.senha[strcspn(cads.senha, "\n")] = 0;


    fprintf(file,"%s %s\n",cads.usuario,cads.senha);

    fclose(file);

}

int logar(char usuario[],char senha[]){
    FILE *file;
    file = fopen("usuarioCads.txt","r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }
    
    char usuarioInsert[50],senhaInsert[50];

    printf("Digite o usuário: ");
    fgets(usuarioInsert,50,stdin);

    printf("Digite a senha: ");
    fgets(senhaInsert,50,stdin);

    usuarioInsert[strcspn(usuarioInsert, "\n")] = 0;
    senhaInsert[strcspn(senhaInsert, "\n")] = 0;


    while(fscanf(file,"%s %s",usuario,senha) != EOF){

        if(strcmp(usuarioInsert,usuario) == 0 && strcmp(senhaInsert,senha) == 0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    return 0;

}

void consulta(){
    FILE *file;
    file = fopen("enderCads.txt","r");

    char linhas[200];
    printf("Pontos de coleta disponíveis:\n");
    while(fgets(linhas, sizeof(linhas),file) != NULL){
        printf("%s",linhas);
    }
    printf("\n");

    fclose(file);
}


void cadEndereco(){
    FILE *file;
    file = fopen("enderCads.txt","a");

    
    typedef struct {
        char bairro[50];
        char rua[50];
        char numero[50];
    } endereco;

    endereco rbn;

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


}

int main(){
    
    setlocale(LC_ALL,"portuguese");
    system("clear");
    
    Login cads;
    int login,escolha;

    printf("(1)Cadastro\n(2)Login\n");
    scanf("%d",&login);
    getchar();

    switch(login){
        case 1:
            cadastro();

            break;

        case 2:
            int autentificador = 0;
            while(autentificador != 1){
                if(logar(cads.usuario,cads.senha) == 1){
                    autentificador = 1;
                    
                }else{
                    system("clear");
                    printf("Login ou senha incorretos, tente novamente.\n");
                }
            }
    }

    system("clear");

    printf("Escolha uma opção:\n(1)Cadastrar endereço\n(2)Fazer chamado\n(3)Ver chamados\n");
    scanf("%d",&escolha);
    getchar();
    

    switch (escolha)
    {
    case 1:
        system("clear");
        cadEndereco();
        break;
    case 2:
        printf("Não implementado\n");
        break;
    case 3:
        system("clear");
        consulta();
        break;

    default:
        printf("Não implementado\n");
        break;
    }
}