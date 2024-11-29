#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//

char userInsert[50], passwordInsert[50];

int loginColetor(char user[],char password[]){
    FILE *file2;
    file2 = fopen("cadastroColetor.txt","rb");

   
    char username[50], pass[50];

    
    userInsert[strcspn(userInsert, "\n")] = '\0';
    passwordInsert[strcspn(passwordInsert, "\n")] = '\0';

    while (fscanf(file2,"%s %s",username,pass) != EOF) {
        if (strcmp(userInsert, username) == 0 && strcmp(passwordInsert, pass) == 0) {
            fclose(file2);
            return 1;
        }
    }
    fclose(file2);

    return 0;

}

typedef struct {
    char neighborhood[50];
    char street[50];
    char number[50];
    char enderecoConcat[100];
} Address; // struct of address data

typedef struct {
    char user[50];
    char password[50];
    int userNumber;
    
} Login; // struct about login



void cadastroColetor() {
    FILE *file;
    file = fopen("cadastroColetor.txt", "ab");

    Login cad;

    printf("Enter your name: ");
    fgets(cad.user, 50, stdin);

    printf("Enter your password: ");
    fgets(cad.password, 50, stdin);

    cad.user[strcspn(cad.user, "\n")] = '\0';
    cad.password[strcspn(cad.password, "\n")] = '\0';

    fprintf(file, "%s %s\n", cad.user, cad.password);

    fclose(file);
}

void change() {
    FILE *file;
    file = fopen("enderCads.txt", "r+b");
    Address end;

    int index = 1;
    // fseek(file, index * sizeof(Address), SEEK_SET);
}

void registration() {
    int random, min = 0, max = 100;

    FILE *file;
    file = fopen("userCads.txt", "ab");

    Login cads;

    printf("Enter username: ");
    fgets(cads.user, 50, stdin);

    printf("Enter password: ");
    fgets(cads.password, 50, stdin);

    srand(time(NULL));
    random = (min + (rand() % (max - min + 1)));

    cads.userNumber = random;

    cads.user[strcspn(cads.user, "\n")] = '\0';
    cads.password[strcspn(cads.password, "\n")] = '\0';

    fprintf(file, "%s %s \n", cads.user, cads.password);

    fclose(file);
}

int logarUsuario(char user[], char password[]) {
    FILE *file;
    file = fopen("userCads.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
   

    
    char username[50], pass[50];

    printf("Enter username: ");
    fgets(userInsert, 50, stdin);

    printf("Enter password: ");
    fgets(passwordInsert, 50, stdin);

    userInsert[strcspn(userInsert, "\n")] = '\0';
    passwordInsert[strcspn(passwordInsert, "\n")] = '\0';

    while (fscanf(file, "%s %s", username, pass) != EOF) {
        if (strcmp(userInsert, username) == 0 && strcmp(passwordInsert, pass) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    return 0;
}

void query() {
    FILE *file;
    file = fopen("enderCads.txt", "r");

    char lines[200];
    printf("Available collection points:\n");
    while (fgets(lines, sizeof(lines), file) != NULL) {
        printf("%s", lines);
    }

    printf("\n");

    fclose(file);
}

void cadAddress() {
    FILE *file;
    file = fopen("enderCads.txt", "a");

    Address rbn;

    printf("Enter your home neighborhood: ");
    fgets(rbn.neighborhood, 50, stdin);

    printf("Enter the street of your house: ");
    fgets(rbn.street, 50, stdin);

    printf("Enter house number: ");
    fgets(rbn.number, 50, stdin);

    rbn.neighborhood[strcspn(rbn.neighborhood, "\n")] = '\0';
    rbn.street[strcspn(rbn.street, "\n")] = '\0';
    rbn.number[strcspn(rbn.number, "\n")] = '\0';

    strcat(rbn.enderecoConcat,rbn.neighborhood);
    strcat(rbn.enderecoConcat,", ");
    strcat(rbn.enderecoConcat,rbn.street);
    strcat(rbn.enderecoConcat,", ");
    strcat(rbn.enderecoConcat,rbn.number);

    fprintf(file, "%s\n", rbn.enderecoConcat);

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    system("clear");
    Login cads;
    int login, choice, acesso;

    printf("(1) General Registration\n(2) Login\n(3) Collector Registration\n");
    scanf("%d", &login);
    getchar();

    switch (login) {
        case 1:
            registration();
            break;

        case 2: {
            int authenticator = 0;
            while (authenticator != 1) {
                if (logarUsuario(cads.user, cads.password) == 0) {
                    if(loginColetor(cads.user,cads.password) == 1){
                        authenticator = 1;
                    
                    }else {
                    system("clear");
                    printf("Incorrect login or password, try again.\n");
                }
                }else{
                    authenticator = 1;
                }
            }
            break;
        }

        case 3:
            cadastroColetor();
            break;
    }

    system("clear");

    printf("Choose an option:\n(1) Register address\n(2) Make a call\n(3) View calls\n(4) Change addresses\n");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            system("clear");
            cadAddress();
            break;

        case 2:
            printf("Not implemented\n");
            break;

        case 3:
            system("clear");
            query();
            break;

        case 4:
            break;

        default:
            printf("Not implemented\n");
            break;
    }
}
