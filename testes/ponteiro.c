#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x = 10;
   double y = 20.50;
   char z = 'a';

   int *px = &x;
   double *py = &y;
   char *pZ = &z;

    int *soma;
    soma = &x; 

   printf("VAlor = %d - \n",*soma);

/* ponteiro com asterisco mostra o endereço de memória,
    já  o sem asterisco, mostra oque esta armazenado no endereço de memória
*/



    

    return 0;
}
