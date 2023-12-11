#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int slctObra(int resp){
	switch(resp){
		case 1:
			return 1;
			break;
		case 2:
			return 2;			
			break;
		case 3:
			return 3;
			
			break;
		case 4:
			return 4;			
			break;
		case 5:
			return 5;			
			break;
		default:
			return 0;
			break;	
		}
		
}
void main(){
	int resp;
	int tema;
	int obra = 0;
	int terminal;
	int ret = 0;
	int avaliar;
	char simnao;
	char nome[50];
	char titulo[100];
	char resumo[1000];
	char titulo1[10][100] = {"Falso","obra 1","obra 2","obra 3"};
	char resumo1[10][1000] = {"Falso","aaaaaaaaaaaaaaa","bbbbbbbb","cccccccccc"};
	char titulo2[10][100] = {"Falso","obra 1","obra 2","obra 3"};
	char resumo2[10][1000] = {"Falso","aaaaaaaaaaaaaaa","bbbbbbbb","ccccccccccc"};
	char titulo3[10][100] = {"Falso","obra 1","obra 2","obra 3"};
	char resumo3[10][1000] = {"Falso","aaaaaaaaaaaaaaa","bbbbbbbb","ccccccccccc"};		
	char ticketlist[1000][5] ={"4799","ER35","1234","ABCD"};
	printf("Ola monitor, por favor, insira o numero do terminal\n");
	scanf("%d",&terminal);
	printf("Por favor selecione o tema do terminal. \n 1) 100 anos da semana de arte moderna // 2) 150 anos de Santos Dumont // 3) Jogos olimpicos de Paris 2024 \n");
	scanf("%d",&resp);
	
	//*ESCOLHE O TEMA*//
	switch(resp){
		case 1:
			printf("Voce selecionou 1) 100 anos da semana de arte moderna \n");
			tema = 1;
			break;
		case 2:
			printf("Voce selecionou 2) 150 anos de Santos Dumont \n");
			tema = 2;
			break;
		case 3:
			printf("Voce selecionou 3) Jogos olímpicos de Paris 2024 \n");
			tema = 3;
			break;
		}
	
	printf("tema: %d \n",tema);
	
	//Escolhe a obra
	if(tema == 1){
		printf("Agora seleciona a obra que sera exposta ao lado do terminal \n1)%s // 2)%s // 3)%s // 4)%s // 5)%s \n",titulo1[1],titulo1[2],titulo1[3],titulo1[4],titulo1[5]);
		while(ret == 0){
		scanf("%d",&resp);
		ret = slctObra(resp);
		if(ret == 0){
			printf("Alternativa escolhida não existe, tente novamente \n");
		}
	}
		system("cls");
		strcpy(titulo, titulo1[ret]);
		strcpy(resumo, resumo1[ret]);
		printf("%s\n",titulo);
		printf("%s\n",resumo);
	}
	if(tema == 2){
		printf("Agora seleciona a obra que sera exposta ao lado do terminal \n1)%s // 2)%s // 3)%s // 4)%s // 5)%s \n",titulo2[1],titulo2[2],titulo2[3],titulo2[4],titulo2[5]);
		while(ret == 0){
		scanf("%d",&resp);
		ret = slctObra(resp);
		if(ret == 0){
			printf("Alternativa escolhida não existe, tente novamente \n");
		}
		}
		system("cls");
		printf("%s\n",titulo2[ret]);
		printf("%s\n",resumo2[ret]);
	}
	if(tema == 3){
		printf("Agora seleciona a obra que sera exposta ao lado do terminal \n1)%s // 2)%s // 3)%s // 4)%s // 5)%s \n",titulo3[1],titulo3[2],titulo3[3],titulo3[4],titulo3[5]);
		while(ret == 0){
		scanf("%d",&resp);
		ret = slctObra(resp);
		if(ret == 0){
			printf("Alternativa escolhida não existe, tente novamente \n");
		}
		}
		system("cls");
		printf("%s\n",titulo3[ret]);
		printf("%s\n",resumo3[ret]);	
		}
		
	printf("Gostaria de fazer um quiz e avaliar a obra? \n Digite S para Sim, e N para nao.\n");
	while(avaliar == 0){	
	scanf("%s",&simnao);
	switch(simnao){
		case 's':
			avaliar = 1;
			break;
		case 'S':
			avaliar = 1;			
			break;
		case 'n':			
			avaliar =0;	
			system("cls");
			printf("%s\n%s\n",titulo,resumo);
			printf("Gostaria de fazer um quiz e avaliar a obra? \n Digite S para Sim, e N para nao.\n");		
			break;
		case 'N':
			avaliar = 0;
			system("cls");
			printf("%s\n%s\n",titulo,resumo);
			printf("Gostaria de fazer um quiz e avaliar a obra? \n Digite S para Sim, e N para nao.\n");			
			break;
		default:
			printf("Resposta invalida, tente novamente\n");
			break;	
		}
}
	if(avaliar == 1){
		char ticket[5];
		printf("Seja bem vindo ao nosso quiz, antes de comecarmos, qual numero do seu ticket?\n");
		scanf("%4s", ticket);
		ticket[4] = '\0';
		printf("o ticket e:%s\n",ticket);
		
	int found = 0;

    for (int i = 0; i < 1000; i++) {
        if (strcasecmp(ticketlist[i], ticket) == 0) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        printf("Ticket valido, continue com o quiz.\nQual é o seu nome?\n");
    } else {
        printf("Ticket invalido. Por favor, verifique o numero do ticket.\n");
    }
	}
}
	

