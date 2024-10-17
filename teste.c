#include <stdio.h>

int main() {
    FILE *file = fopen("arquivo.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char buffer[256];  // Buffer para armazenar o conteúdo da linha
    int linha_atual = 1;
    int linha_desejada = 6;  // Linha que você deseja ler

    // Loop para ler o arquivo linha por linha
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (linha_atual == linha_desejada) {
            printf("Conteúdo da linha %d: %s", linha_desejada, buffer);
            break;
        }
        linha_atual++;
    }

    // Verifica se a linha foi encontrada
    if (linha_atual < linha_desejada) {
        printf("O arquivo tem menos de %d linhas.\n", linha_desejada);
    }

    fclose(file);  // Fecha o arquivo
    return 0;
}
