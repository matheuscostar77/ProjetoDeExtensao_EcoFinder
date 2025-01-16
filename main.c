#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int contexto=3;
int teste_coletas_disponiveis=0;
char nomemenu[50];
char userInsert[50], senhaInsert[50];
int posicao = 0;

typedef struct {
    char bairro[50];
    char rua[50];
    char numero[50];
    char material[50];
} Endereco;

Endereco end[100];

typedef struct {
    char user[50];
    char senha[50];
    int userNumber;
} Login;

void escreverArquivo();
int verChamados();
void reservar();
void fazerChamado(int senhaEndereco;
void mudarEndereco(int senhaEnd);
int loginColetor(char user[], char senha[]);
int cadastroColetor();
void cadastroUsuario;
int logarUsuario(char user[], char password[]);
void cadastroEndereco();
void paginainicial();


int main() {

    setlocale(LC_ALL, "Portuguese");
    system("cls");

    for (int i = 0; i < 100; i++) {
        strcpy(end[i].bairro, "");
        strcpy(end[i].rua, "");
        strcpy(end[i].numero, "");
        strcpy(end[i].material, "");
    }


    remove("enderCads.txt");

    Login cads;
    int escolha = 10, acesso;
    int senhaEnd;

    paginainicial();
    system("cls");
    while (escolha > 0 || escolha < 0) {
        acesso = 0;
        while(escolha >  3 || escolha < 0){
            system("cls");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("                                                                                                                 .........                \n");
            printf("                                                                                                               ..#########+. .              \n");
            printf("                                                                                                               -##############.            \n");
            printf("                                                                                                              -######.-######+             \n");
            printf("                                                                                                              ..+###..+######.             \n");
            printf("                                                                                                              .. ...  ..-###+.             \n");
            printf("                                                                                                       ...+####-               ..          \n");
            printf("                                                                                                        .#######.          ..+###.         \n");
            printf("                                                                                                        .#######.          +######.        \n");
            printf("                                                                                                        +#####.+-        .+.+#####-        \n");
            printf("                                                                                                        .####--....    .-##..+####.        \n");
            printf("                                                                                                         .########-  .-##########.         \n");
            printf("                                                                                                          .#######- .-##########.          \n");
            printf("                                                                                                            .+#####-    -#######.           \n");
            printf("                                                                                                                        .+#.               \n");
            printf("                                                                                                                          ..               \n");
            printf("\n");
            printf("\n                                                                                                     +-----------------------------+              ");
            printf("\n                                                                                *  Para cadastrar-se como usuário comum         - Digite (1)                         *");
            printf("\n                                                                                *  Para cadastrar-se como coletor               - Digite (2)                         *");
            printf("\n                                                                                *  Para realizar o login(seja comum ou coletor) - Digite (3)                         *");
            printf("\n                                                                                *  Para ler nossa política de privacidade       - Digite (4)                         *");
            printf("\n                                                                                *  Para fechar o programa                       - Digite (0)                         *");
            printf("\n                                                                                                     +-----------------------------+            \n");
            printf("\n                                                                                                                  Opção: ");
            scanf("%d", &escolha);
            getchar();


            switch (escolha) {
                case 1:
                    cadastroUsuario();
                    break;

                case 3: {
                    int autenticador = 0;
                    int tentativas=5;

                    while (autenticador != 1) {
                        if (logarUsuario(cads.user, cads.senha) == 0) {
                            if (loginColetor(cads.user, cads.senha) == 1) {

                                autenticador = 1;
                                acesso = 1;
                            } else {
                                system("cls");

                                for(int i =1; i <= 9;i++){
                                    printf("\n");
                                }
                                if(tentativas > 0){
                                    printf("\n                                                                           ----    Ops..sua senha ou nome de usuário podem estar incorretos, tente novamente :( ----");
                                    printf("\n                                                                                                         - %d TENTATIVAS RESTANTES! ", tentativas);
                                    printf("\n                                                                                                                       °                      ");
                                } else{
                                    printf("\n                                                                        !  POXA que pena, você atingiu limite de tentativas, seu acesso foi cancelado  ! ");
                                    printf("\n                                                                                    °        Tecle ENTER para sair, até mais :(        ° ");
                                    getchar();
                                    system("cls");

                                    escolha = 10;
                                    break;
                                }
                                tentativas--;
                            }
                        } else {
                            autenticador = 1;
                        }
                    }
                    break;
                }

                case 2:
                    cadastroColetor();
                    acesso = 1;
                    break;

                case 4:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n                                                                                  Politica de Privacidade\n\n");
                    printf("                           \t\t              Esta aplicação foi projetada para gerenciar dados de usuários e endereços de forma simples e segura.\n");
                    printf("                           \t\t              Leia atentamente os seguintes pontos para entender como seus dados são tratados:\n\n");
                    printf("                           \t\t              1. Coleta de Dados\n");
                    printf("                           \t\t               - São coletados nomes de usuários, senhas e informações sobre endereços (bairro, rua e número) exclusivamente para fins de cadastro e gerenciamento no sistema.\n\n");
                    printf("                           \t\t              2. Uso de Dados\n");
                    printf("                           \t\t               - Os dados de usuários e endereços cadastrados são utilizados para funcionalidades como login, reserva de materiais e visualização de pontos de coleta.\n\n");
                    printf("                           \t\t              3. Armazenamento Temporário\n");
                    printf("                           \t\t               - Os dados de endereços são armazenados em arquivos temporários durante a execução do programa e excluídos automaticamente ao final do programa.\n\n");
                    printf("                           \t\t              4. Segurança\n");
                    printf("                           \t\t               - Senhas e dados sensíveis são tratados com cuidado e não são compartilhados com terceiros.\n");
                    printf("                           \t\t               - No entanto, como o programa é de uso local, a proteção contra acesso não autorizado depende do ambiente onde ele é executado.\n\n");
                    printf("                           \t\t              5. Exclusão de Dados\n");
                    printf("                           \t\t               - Todos os dados relacionados a endereços são removidos imediatamente após o encerramento do programa.\n");
                    printf("                           \t\t               - Os dados de login permanecem no arquivo para reutilização futura, caso não seja solicitada a exclusão da conta.\n\n");
                    printf("                           \t\t              6. Consentimento\n");
                    printf("                           \t\t               - Ao utilizar este programa, o usuário concorda com os termos descritos nesta política de privacidade.\n\n\n");

                    printf("                           \t\t                Digite enter para retornar");
                    getchar();
                    break;


                case 0:
                    system("cls");
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("                                                                                                     .........                \n");
                    printf("                                                                                                   ..#########+. .              \n");
                    printf("                                                                                                   -##############.            \n");
                    printf("                                                                                                  -######.-######+             \n");
                    printf("                                                                                                  ..+###..+######.             \n");
                    printf("                                                                                                  .. ...  ..-###+.             \n");
                    printf("                                                                                           ...+####-               ..          \n");
                    printf("                                                                                            .#######.          ..+###.         \n");
                    printf("                                                                                            .#######.          +######.        \n");
                    printf("                                                                                            +#####.+-        .+.+#####-        \n");
                    printf("                                                                                            .####--....    .-##..+####.        \n");
                    printf("                                                                                             .########-  .-##########.         \n");
                    printf("                                                                                              .#######- .-##########.          \n");
                    printf("                                                                                                .+#####-    -#######.           \n");
                    printf("                                                                                                            .+#.               \n");
                    printf("                                                                                                              ..               \n");
                    printf("\n                                                                               OBRIGADO POR USAR O ECO-FINDER! ATÉ A PROXIMA! :) ...\n");
                    return 0;

            }

        }

        while (escolha != 0) {
            if (acesso == 1) {
         system("cls");

        for(int i =1; i <= 9;i++){
            printf("\n");
        }
        printf("\n                                                                                             OLÁ %s  SEJA BEM VINDO(A) AO ECO-FINDER!! ", nomemenu );
        printf("\n");
        printf("\n                                                                                                                 °                    ");
        printf("\n");
        printf("\n                                                                                          *  Para Visualizar os chamados - Digite (1)    *");
        printf("\n                                                                                          *  Para Reservar um chamado    - Digite (2)    *");
        printf("\n                                                                                          *  Para sair                   - Digite (0)    *");
        printf("\n");
        printf("\n                                                                                                   °            ---               °     ");
        printf("\n                                                                                                              Opção: ");
        scanf("%d", &escolha);
                getchar();

                switch (escolha) {
                    case 1:
                        system("cls");
                        verChamados();
                        break;

                    case 2:
                        reservar();
                        break;
                    case 0:
                        system("cls");
                        for(int i = 1; i <= 9;i++){
                            printf("\n");
                        }
                        printf("\n                                                                                      Obrigado por usar o ECO-FINDER coletor(a) %s!", nomemenu);
                        printf("\n                                                                          Esperamos que tenhamos ajudado com suas coletas! :) (Digite ENTER para sair) ...");
                        getchar();
                        default:
                        printf("                                                                                            Opção invalida..saindo\n");
                        break;
                }
            } else {
                system("cls");
                for(int i =1; i <= 9;i++){
                    printf("\n");
                }
                printf("\n                                                                                           OLÁ %s  SEJA BEM VINDO(A) AO ECO-FINDER!! ", nomemenu );
                printf("\n");
                printf("\n                                                                                                               °                                    ");
                printf("\n");
                printf("\n                                                                                  *  Cadastre endereço onde será realizada a coleta - Digite (1)    *");
                printf("\n                                                                                  *  Para informar o tipo de material               - Digite (2)    *");
                printf("\n                                                                                  *  Para visualizar os chamados                    - Digite (3)    *");
                printf("\n                                                                                  *  Caso deseje alterar o endereço cadastrado      - Digite (4)    *");
                printf("\n                                                                                  *  Para sair                                      - Digite (0)    *");
                printf("\n");
                printf("\n                                                                                                °             ---               °             ");
                printf("\n                                                                                                             Opção: ");
                scanf("%d", &escolha);
                getchar();

                switch (escolha) {
                    case 1:
                        system("cls");
                        cadastroEndereco();
                        break;

                    case 2:
                        printf("\n                                                                                                  Digite a ID do endereço: ");
                        scanf("%d", &senhaEnd);
                        fazerChamado(senhaEnd);
                        break;

                    case 3:
                        system("cls");
                        verChamados();
                        break;

                    case 4:
                        system("cls");
                        for(int i =1; i <= 9;i++){
                            printf("\n");
                        }
                        printf("\n                                                                                                                        °                      ");
                        printf("\n                                                                                            -- Preencha as informações que deseja alterar abaixo  --");
                        printf("\n                                                                                                                        -                      ");
                        printf("\n                                                                                                           Digite a ID de seu endereço: ");
                        scanf("%d", &senhaEnd);
                        mudarEndereco(senhaEnd);
                        break;

                        case 0:
                        system("cls");
                        for(int i =1; i <= 9;i++){
                            printf("\n");
                        }
                        printf("\n                                                                                 Obrigado por usar o ECO-FINDER %s até a proxima! :) (Digite ENTER para sair) ...", nomemenu);
                        getchar();
                        break;
                }
            }
        }
        escolha = 10;
    }
    return 0;
}

void escreverArquivo() {
    FILE *file;
    remove("enderCads.txt");

    file = fopen("enderCads.txt", "a+b");

    int i = 0;

    while (i < posicao) {
        if (strcmp(end[i].material, "\0") == 0) {
            fprintf(file, "ID: %d - BAIRRO: %s, RUA: %s, NÚMERO: %s\n", i, end[i].bairro, end[i].rua, end[i].numero);
        } else if (strcmp(end[i].material, "RESERVADO") == 0) {
            fprintf(file, "ID: %d - BAIRRO: %s, RUA: %s, NÚMERO: %s       %s\n", i, end[i].bairro, end[i].rua, end[i].numero, end[i].material);
        } else {
            fprintf(file, "ID: %d - BAIRRO: %s, RUA: %s, NÚMERO: %s  MATERIAL DISPONÍVEL: %s", i, end[i].bairro, end[i].rua, end[i].numero, end[i].material);
        }
        i++;
    }

    fclose(file);
}

int verChamados() {
      FILE *file;
    file = fopen("enderCads.txt", "r");
    if (file == NULL) {

        teste_coletas_disponiveis=1;

        system("cls");

        for(int i =1; i <= 7;i++){
            printf("\n");
        }

        printf("\n                                                                                    Sem pontos de coletas cadastrados até o momento %s, Volte uma outro momento :( ", nomemenu);
        printf("\n                                                                                                    digite enter para voltar ao menu   ");
        getchar();
        return teste_coletas_disponiveis;
    }

    system("cls");
    char linhas[200];
    for(int i =1; i <= 7;i++){
        printf("\n");
    }

    printf("\n                                                                                   ----- Pontos de coleta Disponiveis -----\n");
    while (fgets(linhas, sizeof(linhas), file) != NULL) {
        printf("\n                                                           %s", linhas);

    }
    printf("\n");
    fclose(file);

    if(contexto == 1 )
    {
    printf("\n                                                          OK! Agora que já visualizou os IDs dos chamados, pressione ENTER para dar continuidade com à reserva! ");
    printf("\n                                                                                        digite ENTER para prosseguir   ");
    }else{
    printf("\n                                                                                        digite ENTER para prosseguir   ");
    }
    getchar();
    return 0;
 }

void reservar() {
    int i = 0, reserva;
    int instru_coletador=0;
    if(verChamados() == 1){
      teste_coletas_disponiveis = 0;
       return;

    }

    else{
        system("cls");
        contexto=1;
        verChamados();
        contexto=0;
        system("cls");

        for(int i =1; i <= 7;i++){
        printf("\n");
        }
        printf("\n                                                                          °                                  ");
        printf("\n                                                                         -- OK! Siga as instruções e reserve o chamado que deseje --    ");
        printf("\n                                                                          _                                  ");
        printf("\n");
        printf("\n                                                                            Digite o ID do endereço que deseja realizar a coleta: ");
        scanf("%d", &reserva);

        if(strcmp(end[reserva].bairro,"\0") == 1 && strcmp(end[reserva].material,"\0") == 1 || strcmp(end[reserva].material,"RESERVADO") == 0){
            printf("                                                                          ID incorreto ou não o endereço não possui material disponível no momento. Aperte enter para digitar novamente!\n");
            getchar();
        }
        else{
            strcpy(end[reserva].material, "RESERVADO");

            while (getchar() != '\n');

            escreverArquivo();

            system("cls");
            for(int i =1; i <= 7;i++){
                printf("\n");
            }
            printf("\n                                                                        Perfeito Coletor(a) %s, chamado reservado com sucesso! :) ", nomemenu);
            printf("\n                                                                                      digite enter para voltar ao menu   ");
            getchar();
            system("cls");

        }

    }
}

void fazerChamado(int senhaEndereco) {
    int escolha, i = 0;

    system("cls");

    for(int i =1; i <= 8; i++){
        printf("\n");
    }
    printf("\n                                                --- Nesta etapa especifique qual o tipo de material será recolhido no endereço posteriormente cadastrado  ---   ");
    printf("\n                                                                       - -   Digite o número de identificação do tipo de material   - - ");
    printf("\n                                                                         !(Caso digite uma Opção invalida, o programa retorna ao menu)! ");
    printf("\n");
    printf("\n                                                                                       (1) Vidro   (2) Vidro       ");
    printf("\n                                                                                       (3) Papel   (4) Plástico    ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            strcpy(end[senhaEndereco].material, "Metal");
            break;
        case 2:
            strcpy(end[senhaEndereco].material, "Vidro");
            break;
        case 3:
            strcpy(end[senhaEndereco].material, "Papel");
            break;
        case 4:
            strcpy(end[senhaEndereco].material, "Plástico");
            break;
        default:
            printf("                                                                                     Opção inválida.");
    }
    system("cls");
    for(int i =1; i <= 10;i++){
        printf("\n");
        }
    printf("\n                                                                     material especificado com sucesso! para visualiza-lo volte ao menu e digite (3) ");
    printf("\n                                                                                      digite enter para voltar ao menu   ");
    getchar();
    getchar();

    escreverArquivo();
}

void mudarEndereco(int senhaEnd) {
    int i = 0;

    getchar();
    printf("\n                                                                                                 Digite o seu bairro: ");
    fgets(end[senhaEnd].bairro, 50, stdin);

    printf("\n                                                                                                 Digite a sua rua: ");
    fgets(end[senhaEnd].rua, 50, stdin);

    printf("\n                                                                                                 Digite o número do endereço: ");
    fgets(end[senhaEnd].numero, 50, stdin);

    system("cls");

    for(int i =1; i <= 9;i++){
        printf("\n");
        }
    printf("\n                                                                     Endereço alterado com sucesso! para visualiza-lo volte ao menu e digite (3) ");
    printf("\n                                                                                      digite enter para voltar ao menu   ");
    getchar();


    end[senhaEnd].bairro[strcspn(end[senhaEnd].bairro, "\n")] = '\0';
    end[senhaEnd].rua[strcspn(end[senhaEnd].rua, "\n")] = '\0';
    end[senhaEnd].numero[strcspn(end[senhaEnd].numero, "\n")] = '\0';

    escreverArquivo();
}

int loginColetor(char user[], char senha[]) {
    FILE *file;

    file = fopen("cadastroColetor.txt", "rb");
    if (file == NULL) {
        printf("                                                                                     Erro ao abrir o arquivo.");
        return 0;
    }

    Login rbn;
    userInsert[strcspn(userInsert, "\n")] = '\0';
    senhaInsert[strcspn(senhaInsert, "\n")] = '\0';



    while (fscanf(file, "%s %s", rbn.user, rbn.senha) != EOF) {
        if (strcmp(userInsert, rbn.user) == 0 && strcmp(senhaInsert, rbn.senha) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int cadastroColetor() {
    FILE *file;
    file = fopen("cadastroColetor.txt", "ab");
    if (file == NULL) {
        printf("                                                                                     Erro ao abrir o arquivo");
        return 0;
    }

    Login cad;

    printf("                                                                                              Digite seu nome de usuário:  ");
    fgets(cad.user, 50, stdin);

    printf("                                                                                              Digite sua senha: ");
    fgets(cad.senha, 50, stdin);

    strcpy(nomemenu, cad.user);
    nomemenu[strcspn(nomemenu, "\n")] = '\0';
    cad.user[strcspn(cad.user, "\n")] = '\0';
    cad.senha[strcspn(cad.senha, "\n")] = '\0';


    fprintf(file, "%s %s\n", cad.user, cad.senha);
    fclose(file);

    return 1;
}

void cadastroUsuario() {
    FILE *file;
    file = fopen("userCads.txt", "ab");
    if (file == NULL) {
        printf("                                                                                     Erro ao abrir o arquivo.");
        return;
    }

    Login cads;

    printf("                                                                                                  Digite seu nome de usuário: ");
    fgets(cads.user, 50, stdin);

    printf("                                                                                                  Digite sua senha: ");
    fgets(cads.senha, 50, stdin);

    strcpy(nomemenu, cads.user);
    nomemenu[strcspn(nomemenu, "\n")] = '\0';
    cads.user[strcspn(cads.user, "\n")] = '\0';
    cads.senha[strcspn(cads.senha, "\n")] = '\0';

    fprintf(file, "%s %s \n", cads.user, cads.senha);
    fclose(file);
}
int logarUsuario(char user[], char password[]) {
    FILE *file;
    file = fopen("userCads.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    Login rbn;

    printf("\n                                                                                                   Digite seu nome de usuário: ");
    fgets(userInsert, 50, stdin);

    printf("\n                                                                                                   Digite sua senha          : ");
    fgets(senhaInsert, 50, stdin);

    userInsert[strcspn(userInsert, "\n")] = '\0';
    senhaInsert[strcspn(senhaInsert, "\n")] = '\0';

    while (fscanf(file, "%s %s", rbn.user, rbn.senha) != EOF) {
        if (strcmp(userInsert, rbn.user) == 0 && strcmp(senhaInsert, rbn.senha) == 0) {
            strcpy(nomemenu, userInsert);

            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void cadastroEndereco() {
    FILE *file;
    file = fopen("enderCads.txt", "a");
    if (file == NULL) {
        printf("                                                                                       Erro ao abrir o arquivo.\n");
        return;
    }

    for(int i =1; i <= 9;i++){
        printf("\n");
    }
    printf("\n                                                                                                               °                      ");
    printf("\n                                                                                           -- Agora preencha as informações abaixo  --");
    printf("\n                                                                                                               -                      ");
    printf("\n                                                                                              Digite o seu bairro: ");
    fgets(end[posicao].bairro, 50, stdin);

    printf("\n                                                                                              Digite a sua rua: ");
    fgets(end[posicao].rua, 50, stdin);

    printf("\n                                                                                              Digite o número do endereço: ");
    fgets(end[posicao].numero, 50, stdin);

    end[posicao].bairro[strcspn(end[posicao].bairro, "\n")] = '\0';
    end[posicao].rua[strcspn(end[posicao].rua, "\n")] = '\0';
    end[posicao].numero[strcspn(end[posicao].numero, "\n")] = '\0';

    fprintf(file, "ID: %d - BAIRRO: %s, RUA: %s, NÚMERO: %s\n", posicao, end[posicao].bairro, end[posicao].rua, end[posicao].numero);
    fclose(file);


    system("cls");
    for(int i =1; i <= 9;i++){
        printf("\n");
    }
    printf("\n                                                                     Endereço cadastrado com sucesso! o ID do endereço é: %d\n", posicao);
    printf("\n                                                                               digite enter para voltar ao menu   ");
    getchar();
    posicao++;

}
void paginainicial(){


    printf("   \n");
    printf("                                                                                                                         °                       \n");
    printf("                                                                                                             &&&&&&&&&&&&&&&&&&&&&&&&&&                    \n");
    printf("                                                                                                            &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                 \n");
    printf("                                                                                                          &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                \n");
    printf("                                                                                                         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&     &&        \n");
    printf("                                                                                                         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&        \n");
    printf("                                                                                                        &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&         \n");
    printf("                                                                                                       &&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&          \n");
    printf("                                                                                                     &&&&&&&&&&&&&&&&&&&&&   &&&&&&&&&&&&&&&&&&&           \n");
    printf("                                                                                                    &&&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&             \n");
    printf("                                                                                                      &&&&&&&&&&&&&&&&&&      &&&&&&&&&&&&&&&              \n");
    printf("                                                                                                         &&&&&&&&&&&&&&    &&&&&&&&&&&&&&&&&    &&&&       \n");
    printf("                                                                                         &&&&&&&&&&&&&&&&&&  &&&&&&&&&  &&&&&&&&&&&&&&&&&&&   &&&&&&&      \n");
    printf("                                                                                          &&&&&&&&&&&&&&&&&&&   &&&&&                     &&&&&&&&&&&&     \n");
    printf("                                                                                              &&&&&&&&&&&&&&&&                         &&&&&&&&&&&&&&&&    \n");
    printf("                                                                                              &&&&&&&&&&&&&&&&&                     &&&&&&&&&&&&&&&&&&&&   \n");
    printf("                                                                                             &&&&&&&&&&&&&&&&&&&                     &&&&&&&&&&&&&&&&&&&&  \n");
    printf("                                                                                            &&&&&&&&&&&&&&&&&&&&&                     &&&&&&&&&&&&&&&&&&&& \n");
    printf("                                                                                           &&&&&&&&&&&&&&&&&&&&&&&                 &   &&&&&&&&&&&&&&&&&&&&\n");
    printf("                                                                                         &&&&&&&&&&&&&&&&&&&&&&&&&               &&&   &&&&&&&&&&&&&&&&&&&\n");
    printf("                                                                                          &&&&&&&&&&&&&&&&&    &&&&&            &&&&    &&&&&&&&&&&&&&&&&&\n");
    printf("                                                                                            &&&&&&&&&&&&&&&                     &&&&&     &&&&&&&&&&&&&&&& \n");
    printf("                                                                                             &&&&&&&&&&&&&                     &&&&&&      &&&&&&&&&&&&&&  \n");
    printf("                                                                                              &&&&&&&&&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&&&&&&&&&   \n");
    printf("                                                                                               &&&&&&&&&&&&&&&&&&&&&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&&&    \n");
    printf("                                                                                                &&&&&&&&&&&&&&&&&&&&&&&&&   &&&&&&&&&&&&&&&&&&&&&&&&&&     \n");
    printf("                                                                                                 &&&&&&&&&&&&&&&&&&&&&&&&  &&&&&&&&&&&&&&&&&&&&&&&&&&      \n");
    printf("                                                                                                  &&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&        \n");
    printf("                                                                                                  &&&&&&&&&&&&&&&&&&&&&&&  &&&&&&&&&&&&&&&&&&&&&&&         \n");
    printf("                                                                                                   &&&&&&&&&&&&&&&&&&&&&&   &&&&&&&&&&&&&&&&&&&&&          \n");
    printf("                                                                                                    &&&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&           \n");
    printf("                                                                                                       &&&&&&&&&&&&&&&&&&      &&&&&&&&&&&&&&&             \n");
    printf("                                                                                                                                  &&&&&                   \n");
    printf("                                                                                                                                  &&&&&                   \n");
    printf("                                                                                                                                    &&&                   \n");
    printf("                                                                                                                                      &                     \n");
    printf("                                                                                                           \n");
    printf("                                                                                                                                           \n");
    printf("                                                                                                  --------------------------------------------------                                               \n");
    printf("\n");
    printf("                                                                                $$$$$$$$\\  $$$$$$\\   $$$$$$\\  $$$$$$$\\\\$$$$$$\\ $$\\   $$\\ $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\  \n");
    printf("                                                                                $$  _____|$$  __$$\\ $$  __$$\\ $$  _____\\_$$  _|$$$\\  $$ |$$  __$$\\ $$  _____|$$  __$$\\ \n");
    printf("                                                                                $$ |      $$ /  \\__|$$ /  $$ |$$ |       $$ |  $$$$\\ $$ |$$ |  $$ |$$ |      $$ |  $$ | \n");
    printf("                                                                                $$$$$\\    $$ |      $$ |  $$ |$$$$$\\     $$ |  $$ $$\\$$ |$$ |  $$ |$$$$$\\    $$$$$$$  | \n");
    printf("                                                                                $$  __|   $$ |      $$ |  $$ |$$  __|    $$ |  $$ \\$$$$ |$$ |  $$ |$$  __|   $$  __$$< \n");
    printf("                                                                                $$ |      $$ |  $$\\ $$ |  $$ |$$ |       $$ |  $$ |\\$$$ |$$ |  $$ |$$ |      $$ |  $$ | \n");
    printf("                                                                                $$$$$$$$\\ \\$$$$$$  | $$$$$$  |$$ |     $$$$$$\\ $$ | \\$$ |$$$$$$$  |$$$$$$$$\\ $$ |  $$ | \n");
    printf("                                                                                \\________| \\______/  \\______/ \\__|     \\______|\\__|  \\__|\\_______/ \\________|\\__|  \\__| \n");
    printf("\n                                                                                                 - SISTEMA DE LOCALIZAÇÂO DE MATERIAS RECICLAVEIS -                                                      \n");
    printf("\n                                                                                                                        +                                                   \n");
    printf("\n                                                                                                            DIGITE ENTER PARA CONTINUAR                                                       \n");
    getchar();

}
