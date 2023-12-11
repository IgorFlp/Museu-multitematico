#include<stdio.h>
#include<stdlib.h>
int main(){
	int tema1=0;
	int tema2=0;
	int tema3=0;
	float valor;
	char resposta;
	char ticket[4];
	char nome[50];
	float idade;
	char genero;
	printf("Deseja comprar o tema 1?\n 'S' para sim\n 'N' para nao\n\n");
	scanf("%s",&resposta);
	switch(resposta){
	case 'S':
		tema1=1;
		printf("Tema 1 adicionado ao carrinho\n\n");
		break;
	case 'N':
		tema1=0;
		printf("Nao compraremos o tema 1\n\n");
		break;
		default:
		 printf("Comando invalido\n\n");
	}
			printf("Deseja comprar o tema 2?\n 'S' para sim\n 'N' para nao\n\n");
			scanf("%s",&resposta);
			switch(resposta){
		case 'S':
			tema2=1;
			printf("Tema 2 adicionado ao carrinho\n\n");
			break;
			case 'N':
				tema2=0;
				printf("Nao compraremos o tema 2\n\n");
				break;
			default:
				printf("Comando invalido\n\n");
	}
	printf("Deseja comprar o tema 3?\n 'S' para sim\n 'N' para nao\n\n");
	scanf("%s",&resposta);
		switch(resposta){
		case 'S':
		tema3=1;
		printf("Tema 3 adicionado ao carrinho\n\n");
		break;
		case'N':
		tema3=0;
		printf("Nao compraremos o tema 3\n\n");
		break;
		default:
			printf("Comando invalido\n\n");
		}
		valor=(tema1+tema2+tema3)*20;
		printf("Entrada cheia 'C'\n\n Entrada meia 'M'\n\n Entrada isenta 'I'\n\n ");
		scanf("%s",&resposta);
		switch(resposta){
			case 'C':
				printf("CHEIA, R$%0.2f\n\n", valor);
			break;
			case 'M':
				valor=valor/2;
				printf("MEIA, R$%0.2f\n\n", valor);
				break;
			case 'I':
				valor=0;
				printf("ISENTO, R$%0.2f\n\n", valor);
				break;
				default:
					printf("Comando invalido\n\n");
		}
		printf("VALOR TOTAL, R$%0.2f\n\n", valor);
		printf("Digite a sequencia do ticket\n\n");
		scanf("%s",&ticket);
		printf("TICKET %s\n\n VALOR A PAGAR, R$%0.2f\n\n", ticket, valor );
		printf("Informe seu nome\n\n");
		scanf("%s",&nome);
		printf("Informe sua idade\n\n");
		scanf("%f",&idade);
		printf("Informe seu genero, 'F' femenino, 'M' masculino, 'O' outros'\n\n");
		scanf("%s",&genero);
		switch(genero){
			case 'F':
			printf("Feminino\n\n");
			break;
			case 'M':
			printf("Masculino\n\n");
			break;
			case'O':
			printf("Outros\n\n");
			break;
			default:
			printf("Comando invalido\n\n");
			break;	
	}
	printf("%s\n\n",nome);
	printf("%1.0f\n\n", idade);
	printf("%c\n\n\n", genero);
		system("pause"); 
		return 0;
}