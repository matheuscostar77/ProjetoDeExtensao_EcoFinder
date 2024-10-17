#include <stdio.h>
#include <stdlib.h>

struct horario {
    int horas;
    int min;
    int sec;

};

int main(){

        FILE *file;// para criar txt
        file = fopen("teste.txt","w");

    struct horario tempo;

    tempo.horas = 20;
    tempo.sec = 10;
    tempo.min = 22;

    fprintf(file,"%d:%d:%d\n\n",tempo.horas,tempo.min,tempo.sec);
    fclose(file);
 

    return 0;
}