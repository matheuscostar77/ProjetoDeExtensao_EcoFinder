//melhoramento da interface ususario e sistema
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int contexto=3;
int teste_coletas_disponiveis=0; //variavel para que caso nao tenha pontos de coletas disponiveis, na funcao reservar nao aparece a funcao "verchamados"
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

void escreverArquivo() {
    FILE *file;
    remove("enderCads.txt");

    file = fopen("enderCads.txt", "a+b");

    int i = 0; 

    while (i < posicao) {
        if (strcmp(end[i].material, "\0") == 0) {
            fprintf(file, "%d - %s, %s, %s\n", i, end[i].bairro, end[i].rua, end[i].numero);
        } else if (strcmp(end[i].material, "RESERVADO") == 0) {
            fprintf(file, "%d - %s, %s, %s       %s\n", i, end[i].bairro, end[i].rua, end[i].numero, end[i].material);
        } else {
            fprintf(file, "%d - %s, %s, %s  MATERIAL DISPONÍVEL: %s", i, end[i].bairro, end[i].rua, end[i].numero, end[i].material);
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
        
        system("clear");

        for(int i =1; i <= 7;i++){
            printf("\n");
        }

        printf("\n                                           Sem pontos de coletas cadastrados até o momento %s, Volte uma outro momento :( ", nomemenu);
        printf("\n                                                           digite enter para voltar ao menu   ");
        getchar();
        return teste_coletas_disponiveis;
    }
    
    system("clear");
    char linhas[200];
    for(int i =1; i <= 7;i++){
        printf("\n");
    }
   
    printf("\n                                                        ----- Pontos de coleta Disponiveis -----\n");
    while (fgets(linhas, sizeof(linhas), file) != NULL) {
        printf("\n                                                           %s", linhas);
        
    }
    printf("\n");
    fclose(file);
    
    if(contexto == 1 )
    {
    printf("\n                               OK! Agora que já visualizou os IDs dos chamados, pressione ENTER para dar continuidade com à reserva! ");
    printf("\n                                                             digite ENTER para prosseguir   ");
    }else{
    printf("\n                                                             digite ENTER para prosseguir   ");
    }
    getchar();
    return 0;
 }

void reservar() {
    int i = 0, reserva;
    int instru_coletador=0;
    if(verChamados() == 1){///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      teste_coletas_disponiveis = 0;
       return; 
       
    }
    
    else{
        system("clear");
        contexto=1;
        verChamados();
        contexto=0;
        system("clear");
        
        for(int i =1; i <= 7;i++){
        printf("\n");
        }  
        printf("\n                                                                          °                                  ");
        printf("\n                                              -- OK! Siga as instruções e reserve o chamado que deseje --    ");
        printf("\n                                                                          _                                  ");
        printf("\n");
        printf("\n                                                 Digite o ID do endereço que deseja realizar a coleta: ");
        scanf("%d", &reserva);

        if(end[reserva].bairro == '\0' && end[reserva].rua == '\0' && end[reserva].numero == '\0'){
            printf("                                               ID incorreto. Aperte enter para digitar novamente!\n");
            getchar();
        }
        else{
            strcpy(end[reserva].material, "RESERVADO");
            
            while (getchar() != '\n'); 
            
            escreverArquivo();
            
            system("clear");
            for(int i =1; i <= 7;i++){
                printf("\n");
            }
            printf("\n                                             Perfeito Coletor(a) %s, chamado reservado com sucesso! :) ", nomemenu);
            printf("\n                                                           digite enter para voltar ao menu   ");
            getchar();
            system("clear");
            
        }
    
    }
}

void fazerChamado(int senhaEndereco) {
    int escolha, i = 0;

    system("clear");
    
    for(int i =1; i <= 8; i++){
        printf("\n");
    }
    printf("\n                     --- Nesta etapa especifique qual o tipo de material será recolhido no endereço posteriormente cadastrado  ---   ");
    printf("\n                                            - -   Digite o número de identificação do tipo de material   - - ");    
    printf("\n                                              !(Caso digite uma Opção invalida, o programa retorna ao menu)! ");
    printf("\n");
    printf("\n                                                            (1) Vidro   (2) Vidro       ");
    printf("\n                                                            (3) Papel   (4) Plástico    ");
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
            printf("                                                          Opção inválida.");
    }
    system("clear");
    for(int i =1; i <= 10;i++){
        printf("\n");
        }
    printf("\n                                          material especificado com sucesso! para visualiza-lo volte ao menu e digite (3) ");
    printf("\n                                                           digite enter para voltar ao menu   ");
    getchar();
    getchar();

    escreverArquivo();
}  

void mudarEndereco(int senhaEnd) {
    int i = 0;

    getchar();
    printf("\n                                                            Digite o seu bairro: ");
    fgets(end[senhaEnd].bairro, 50, stdin);

    printf("\n                                                            Digite a sua rua: ");
    fgets(end[senhaEnd].rua, 50, stdin);

    printf("\n                                                            Digite o número do endereço: ");
    fgets(end[senhaEnd].numero, 50, stdin);
    
    system("clear");
    
    for(int i =1; i <= 9;i++){
        printf("\n");
        }
    printf("\n                                          Endereço alterado com sucesso! para visualiza-lo volte ao menu e digite (3) ");
    printf("\n                                                           digite enter para voltar ao menu   ");
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
        printf("                                                          Erro ao abrir o arquivo.");
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

int conferir_usuario(const char *usuario, int qual) {
    FILE *file;
    Login conf;

    file = fopen("cadastroColetor.txt", "r");
    if (file == NULL) {
        printf("                                                          Erro ao abrir o arquivo");
        return 0;
    }

    while (fscanf(file, "%s %s", conf.user, conf.senha) != EOF) {
        if (strcmp(usuario, conf.user) == 0) {
            printf("                                                          Nome de usuário já existente.\nAperte qualquer tecla para cadastrar novamente");
            fclose(file);
            return 0;
        }
        
    }
    strcpy(nomemenu, conf.user);//copiando o nome digitado na string menu, que sera exibida apos o usuario entrar no sistema/
    fclose(file);
    return 1;
}

int cadastroColetor() {
    FILE *file;
    file = fopen("cadastroColetor.txt", "ab");
    if (file == NULL) {
        printf("                                                          Erro ao abrir o arquivo");
        return 0;
    }
    
    Login cad;

    printf("                                                                   Digite seu nome de usuário:  ");
    fgets(cad.user, 50, stdin);

    printf("                                                                        Digite sua senha: ");
    fgets(cad.senha, 50, stdin);

    strcpy(nomemenu, cad.user);//copiando o nome digitado na string menu, que sera exibida apos o usuario entrar no sistema
    nomemenu[strcspn(nomemenu, "\n")] = '\0';
    cad.user[strcspn(cad.user, "\n")] = '\0';
    cad.senha[strcspn(cad.senha, "\n")] = '\0';
    
 
    fprintf(file, "%s %s\n", cad.user, cad.senha);
    fclose(file);

    return 1;
}   ///////////////////////////////////////////////////////////////// feito////////////

void cadastroUsuario() {
    FILE *file;
    file = fopen("userCads.txt", "ab");
    if (file == NULL) {
        printf("                                                          Erro ao abrir o arquivo.");
        return;
    }

    Login cads;
 
    printf("                                                                  Digite seu nome de usuário: ");
    fgets(cads.user, 50, stdin);

    printf("                                                                       Digite sua senha: ");
    fgets(cads.senha, 50, stdin); 

    strcpy(nomemenu, cads.user);//copiando o nome digitado na string menu, que sera exibida apos o usuario entrar no sistema
    nomemenu[strcspn(nomemenu, "\n")] = '\0';
    cads.user[strcspn(cads.user, "\n")] = '\0';
    cads.senha[strcspn(cads.senha, "\n")] = '\0';

    fprintf(file, "%s %s \n", cads.user, cads.senha);
    fclose(file);
}  ///////////////////////////////////////////////////////////////// feito////////////

int logarUsuario(char user[], char password[]) {
    FILE *file;
    file = fopen("userCads.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    Login rbn;

    printf("\n                                                            Digite seu nome de usuário: ");
    fgets(userInsert, 50, stdin);

    printf("\n                                                            Digite sua senha: ");
    fgets(senhaInsert, 50, stdin);

    userInsert[strcspn(userInsert, "\n")] = '\0';
    senhaInsert[strcspn(senhaInsert, "\n")] = '\0';

    while (fscanf(file, "%s %s", rbn.user, rbn.senha) != EOF) {
        if (strcmp(userInsert, rbn.user) == 0 && strcmp(senhaInsert, rbn.senha) == 0) {
            strcpy(nomemenu, userInsert);//copiando o nome digitado na string menu, que sera exibida apos o usuario entrar no sistema

            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}  ///////////////////////////////////////////////////////////////// feito////////////

void cadastroEndereco() {
    FILE *file;
    file = fopen("enderCads.txt", "a");
    if (file == NULL) {
        printf("                                                          Erro ao abrir o arquivo.\n");
        return;
    }
    
    for(int i =1; i <= 9;i++){
        printf("\n");
    }
    printf("\n                                                                    °                      ");
    printf("\n                                                -- Agora preencha as informações abaixo  --");
    printf("\n                                                                    -                      ");
    printf("\n                                                   Digite o seu bairro: ");
    fgets(end[posicao].bairro, 50, stdin);

    printf("\n                                                   Digite a sua rua: ");
    fgets(end[posicao].rua, 50, stdin);

    printf("\n                                                   Digite o número do endereço: ");
    fgets(end[posicao].numero, 50, stdin);

    end[posicao].bairro[strcspn(end[posicao].bairro, "\n")] = '\0';
    end[posicao].rua[strcspn(end[posicao].rua, "\n")] = '\0';
    end[posicao].numero[strcspn(end[posicao].numero, "\n")] = '\0';

    fprintf(file, "%d - %s, %s, %s\n", posicao, end[posicao].bairro, end[posicao].rua, end[posicao].numero);
    fclose(file);
    
    
    system("clear");
    for(int i =1; i <= 9;i++){
        printf("\n");
    }
    printf("\n                                          Endereço cadastrado com sucesso! o ID do endereço é: %d\n", posicao);
    printf("\n                                                    digite enter para voltar ao menu   ");
    getchar();
    posicao++;
    
}  ///////////////////////////////////////////////////////////////// feito////////////
void paginainicial(){
      
     
    printf("   \n");
    printf("                                                                                                  °                       \n");
    printf("                                                                                      &&&&&&&&&&&&&&&&&&&&&&&&&&                    \n");
    printf("                                                                                     &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                 \n");
    printf("                                                                                   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                \n");
    printf("                                                                                  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&     &&        \n");
    printf("                                                                                  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&        \n");
    printf("                                                                                 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&         \n");
    printf("                                                                                &&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&          \n");
    printf("                                                                              &&&&&&&&&&&&&&&&&&&&&   &&&&&&&&&&&&&&&&&&&           \n");
    printf("                                                                             &&&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&             \n");
    printf("                                                                               &&&&&&&&&&&&&&&&&&      &&&&&&&&&&&&&&&              \n");
    printf("                                                                                  &&&&&&&&&&&&&&    &&&&&&&&&&&&&&&&&    &&&&       \n");
    printf("                                                                  &&&&&&&&&&&&&&&&&&  &&&&&&&&&  &&&&&&&&&&&&&&&&&&&   &&&&&&&      \n");
    printf("                                                                   &&&&&&&&&&&&&&&&&&&   &&&&&                     &&&&&&&&&&&&     \n");
    printf("                                                                       &&&&&&&&&&&&&&&&                         &&&&&&&&&&&&&&&&    \n");
    printf("                                                                       &&&&&&&&&&&&&&&&&                     &&&&&&&&&&&&&&&&&&&&   \n");
    printf("                                                                      &&&&&&&&&&&&&&&&&&&                     &&&&&&&&&&&&&&&&&&&&  \n");
    printf("                                                                     &&&&&&&&&&&&&&&&&&&&&                     &&&&&&&&&&&&&&&&&&&& \n");
    printf("                                                                    &&&&&&&&&&&&&&&&&&&&&&&                 &   &&&&&&&&&&&&&&&&&&&&\n");
    printf("                                                                  &&&&&&&&&&&&&&&&&&&&&&&&&               &&&   &&&&&&&&&&&&&&&&&&&\n");
    printf("                                                                   &&&&&&&&&&&&&&&&&    &&&&&            &&&&    &&&&&&&&&&&&&&&&&&\n");
    printf("                                                                     &&&&&&&&&&&&&&&                     &&&&&     &&&&&&&&&&&&&&&& \n");
    printf("                                                                      &&&&&&&&&&&&&                     &&&&&&      &&&&&&&&&&&&&&  \n");
    printf("                                                                       &&&&&&&&&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&&&&&&&&&   \n");
    printf("                                                                        &&&&&&&&&&&&&&&&&&&&&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&&&    \n");
    printf("                                                                         &&&&&&&&&&&&&&&&&&&&&&&&&   &&&&&&&&&&&&&&&&&&&&&&&&&&     \n");
    printf("                                                                          &&&&&&&&&&&&&&&&&&&&&&&&  &&&&&&&&&&&&&&&&&&&&&&&&&&      \n");
    printf("                                                                           &&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&        \n");
    printf("                                                                           &&&&&&&&&&&&&&&&&&&&&&&  &&&&&&&&&&&&&&&&&&&&&&&         \n");
    printf("                                                                            &&&&&&&&&&&&&&&&&&&&&&   &&&&&&&&&&&&&&&&&&&&&          \n");
    printf("                                                                             &&&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&           \n");
    printf("                                                                                &&&&&&&&&&&&&&&&&&      &&&&&&&&&&&&&&&             \n");
    printf("                                                                                                           &&&&&                   \n");
    printf("                                                                                                           &&&&&                   \n");
    printf("                                                                                                             &&&                   \n");
    printf("                                                                                                               &                     \n");
    printf("                                                                                    \n");
    printf("                                                                                                                    \n");
    printf("                                                                           --------------------------------------------------                                               \n");
    printf("\n");
    printf("                                                         $$$$$$$$\\  $$$$$$\\   $$$$$$\\  $$$$$$$\\\\$$$$$$\\ $$\\   $$\\ $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\  \n");
    printf("                                                         $$  _____|$$  __$$\\ $$  __$$\\ $$  _____\\_$$  _|$$$\\  $$ |$$  __$$\\ $$  _____|$$  __$$\\ \n");
    printf("                                                         $$ |      $$ /  \\__|$$ /  $$ |$$ |       $$ |  $$$$\\ $$ |$$ |  $$ |$$ |      $$ |  $$ | \n");
    printf("                                                         $$$$$\\    $$ |      $$ |  $$ |$$$$$\\     $$ |  $$ $$\\$$ |$$ |  $$ |$$$$$\\    $$$$$$$  | \n");
    printf("                                                         $$  __|   $$ |      $$ |  $$ |$$  __|    $$ |  $$ \\$$$$ |$$ |  $$ |$$  __|   $$  __$$< \n");
    printf("                                                         $$ |      $$ |  $$\\ $$ |  $$ |$$ |       $$ |  $$ |\\$$$ |$$ |  $$ |$$ |      $$ |  $$ | \n");
    printf("                                                         $$$$$$$$\\ \\$$$$$$  | $$$$$$  |$$ |     $$$$$$\\ $$ | \\$$ |$$$$$$$  |$$$$$$$$\\ $$ |  $$ | \n");
    printf("                                                         \\________| \\______/  \\______/ \\__|     \\______|\\__|  \\__|\\_______/ \\________|\\__|  \\__| \n");
    printf("\n                                                                          - SISTEMA DE LOCALIZAÇÂO DE MATERIAS RECICLAVEIS -                                                      \n");
    printf("\n                                                                                                 +                                                   \n");
    printf("\n                                                                                     DIGITE ENTER PARA CONTINUAR                                                       \n");
    getchar();
     
}
 

int main() {
    setlocale(LC_ALL, "Portuguese");
    system("clear");

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
    system("clear");
    while (escolha > 0 || escolha < 0) {
        acesso = 0;
        while(escolha >  3 || escolha < 0){
            system("clear");
            printf("\n");
            printf("\n");  
            printf("\n");
            printf("\n");
            printf("                                                                          .........                \n");
            printf("                                                                        ..#########+. .              \n");
            printf("                                                                        -##############.            \n");
            printf("                                                                       -######.-######+             \n");
            printf("                                                                       ..+###..+######.             \n");
            printf("                                                                       .. ...  ..-###+.             \n");
            printf("                                                                ...+####-               ..          \n");
            printf("                                                                 .#######.          ..+###.         \n");
            printf("                                                                 .#######.          +######.        \n");
            printf("                                                                 +#####.+-        .+.+#####-        \n");
            printf("                                                                 .####--....    .-##..+####.        \n");
            printf("                                                                  .########-  .-##########.         \n");
            printf("                                                                   .#######- .-##########.          \n");
            printf("                                                                     .+#####-    -#######.           \n");
            printf("                                                                                 .+#.               \n");
            printf("                                                                                   ..               \n"); 
            printf("\n");
            printf("\n                                                              +-----------------------------+              ");
            printf("\n                                         *  Para cadastrar-se como usuário comum   - Digite (1)                         *");
            printf("\n                                         *  Para Cadastrar-se como coletor         - Digite (2)                         *");
            printf("\n                                         *  Caso já possua uma conta (seja comum ou de coletor) para login - digite (3) *");
            printf("\n                                         *  Para Sair - Digite (0)                                                      *");
            printf("\n                                                              +-----------------------------+            \n");
            printf("\n                                                                           Opção: ");
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
                                system("clear");

                                for(int i =1; i <= 9;i++){
                                    printf("\n");
                                }
                                printf("\n                                 ----    Ops..sua senha ou nome de usuário podem estar incorretos, tente novamente :( ----");
                                printf("\n                                                          - %d TENTATIVAS RESTANTES! ", tentativas);
                                printf("\n                                                                         °                      ");
                                tentativas--;
                                if(tentativas <0){
                                    printf("\n                                   !  POXA que pena, você atingiu limite de tentativas, seu acesso foi cancelado  ! ");
                                    printf("\n                                                °        Tecle ENTER para sair, até mais :(        ° ");
                                    getchar();  
                                    system("clear");
                                    
                                    escolha = 10;
                                    break;                                
                                }
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

                case 0:
                    system("clear");
                    system("clear");
                    printf("\n");
                    printf("\n");  
                    printf("\n");
                    printf("\n");
                    printf("                                                                          .........                \n");
                    printf("                                                                        ..#########+. .              \n");
                    printf("                                                                        -##############.            \n");
                    printf("                                                                       -######.-######+             \n");
                    printf("                                                                       ..+###..+######.             \n");
                    printf("                                                                       .. ...  ..-###+.             \n");
                    printf("                                                                ...+####-               ..          \n");
                    printf("                                                                 .#######.          ..+###.         \n");
                    printf("                                                                 .#######.          +######.        \n");
                    printf("                                                                 +#####.+-        .+.+#####-        \n");
                    printf("                                                                 .####--....    .-##..+####.        \n");
                    printf("                                                                  .########-  .-##########.         \n");
                    printf("                                                                   .#######- .-##########.          \n");
                    printf("                                                                     .+#####-    -#######.           \n");
                    printf("                                                                                 .+#.               \n");
                    printf("                                                                                   ..               \n"); 
                    printf("\n                                                    OBRIGADO POR USAR O ECO-FINDER! ATÉ A PROXIMA! :) ...\n");
                    return 0;
                
            }
            
        }

        while (escolha != 0) {
            if (acesso == 1) {
         system("clear");
         
        for(int i =1; i <= 9;i++){
            printf("\n");
        }
        printf("\n                                                 OLÁ %s  SEJA BEM VINDO(A) AO ECO-FINDER!! ", nomemenu );
        printf("\n");
        printf("\n                                                                       °                    ");
        printf("\n");
        printf("\n                                                *  Para Visualizar os chamados - Digite (1)    *");
        printf("\n                                                *  Para Reservar um chamado    - Digite (2)    *");
        printf("\n                                                *  Para sair                   - Digite (0)    *");
        printf("\n");  
        printf("\n                                                         °            ---               °     ");
        printf("\n                                                                    Opção: ");
        scanf("%d", &escolha);
                getchar();

                switch (escolha) {
                    case 1:
                        system("clear");
                        verChamados();
                        break;

                    case 2:
                        reservar();
                        break;
                    case 0:
                        system("clear");
                        for(int i = 1; i <= 9;i++){
                            printf("\n");
                        }
                        printf("\n                                                 Obrigado por usar o ECO-FINDER coletor(a) %s!", nomemenu);
                        printf("\n                                     Esperamos que tenhamos ajudado com suas coletas! :) (Digite ENTER para sair) ...");
                        getchar();       
                        default:
                        printf("                                                          Opção invalida..saindo\n");
                        break;
                }
            } else {
                system("clear");
                for(int i =1; i <= 9;i++){
                    printf("\n");
                }
                printf("\n                                                  OLÁ %s  SEJA BEM VINDO(A) AO ECO-FINDER!! ", nomemenu );
                printf("\n");
                printf("\n                                                                       °                                    ");
                printf("\n");
                printf("\n                                         *  Cadastre endereço onde será realizada a coleta - Digite (1)    *");
                printf("\n                                         *  Para informar o tipo de material               - Digite (2)    *");
                printf("\n                                         *  Para visualizar os chamados                    - Digite (3)    *");
                printf("\n                                         *  Caso dejese alterar o endereço cadastrado      - Digite (4)    *");
                printf("\n                                         *  Para sair                                      - Digite (0)    *");
                printf("\n"); 
                printf("\n                                                         °           ---               °             ");
                printf("\n                                                                   Opção: ");
                scanf("%d", &escolha);
                getchar();

                switch (escolha) {
                    case 1:
                        system("clear");
                        cadastroEndereco();
                        break;

                    case 2:
                        printf("\n                                                           Digite a ID do endereço: ");
                        scanf("%d", &senhaEnd);
                        fazerChamado(senhaEnd);
                        break;

                    case 3:
                        system("clear");
                        verChamados();
                        break;

                    case 4:
                        system("clear");
                        for(int i =1; i <= 9;i++){
                            printf("\n");
                        }
                        printf("\n                                                                           °                      ");
                        printf("\n                                               -- Preencha as informações que deseja alterar abaixo  --");
                        printf("\n                                                                           -                      ");
                        printf("\n                                                            Digite a ID de seu endereço: ");
                        scanf("%d", &senhaEnd);
                        mudarEndereco(senhaEnd);
                        break;
                        
                        case 0:
                        system("clear");
                        for(int i =1; i <= 9;i++){
                            printf("\n");
                        }
                        printf("\n                                 Obrigado por usar o ECO-FINDER %s até a proxima! :) (Digite ENTER para sair) ...", nomemenu);
                        getchar();                   
                        break;
                }
            }
        }
        escolha = 10;
    }
    return 0;
}