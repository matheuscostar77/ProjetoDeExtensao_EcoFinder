#include <stdio.h>
#include <locale.h>

struct horario { //A struct deve obrigatoriamente ser declarada fora da função principal, é como se ela fosse uma variável global
	//Se a struct estiver dentro da função principal, ela não será visível para as funções externas
	int horas, minutos, segundos;
	double x;
	char letra;
};

struct horario funcao(struct horario x);
//tipo de retorno nome(tipo parâmetro 1);
//struct horario é um tipo de dado
//Por exemplo:
//[int] contador;
//[struct horario] contador;
//A palavra struct deve fazer parte da declaração do tipo, ou seja, o tipo deve ser escrito como struct, seguido do nome da estrutura e do nome da variável 

int main(void) {
	struct horario agora;
	
	setlocale(LC_ALL, "Portuguese");
	agora.horas = 18;
	agora.minutos = 20;
	agora.segundos = 42;
	
	struct horario retornoDaFuncao; //Criando uma outra variável do tipo struct horario chamada retornoDaFuncao
	
	//retornoDaFuncao é uma variável do tipo struct horario 
	//Ela recebe o retorno da função "funcao":
	retornoDaFuncao = funcao(agora); //Invocando a função "funcao" e passando uma variável chamada "agora" do tipo struct horario como argumento
	
	printf("Exibindo os dados da variável \ do tipo struct horario:\nhoras == %d\nminutos == %d\nx = %.2f", retornoDaFuncao.horas, retornoDaFuncao.minutos, retornoDaFuncao.x);
	
	getchar();
	return 0;
}

//A função "funcao" recebe uma variável do tipo struct horario como parâmetro e retorna uma variável do tipo struct horario:
struct horario funcao(struct horario x) {
	printf("    Dentro da Função\n%d:%d:%d\n\n", x.horas, x.minutos, x.segundos);
	x.horas = 22;
	x.minutos = 50;
	x.x = 8950.55;
	return x;
}