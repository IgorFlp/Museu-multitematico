#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
typedef struct{
	//col 1 ticket
	//col 2 nome
	// col3 idade e acertos
	//col 4 genero
	//col 5 review
	//resto tickets temas
	char col1[50];
    char col2[5];
    char col3[5];
    char col4[5];
    char col5[5];
    char col6[5];
    char col7[5];
    char col8[5];
	
}Leitor;//Nome da struct, tipo classe
int linhas;

	int	 idades[1000] ={};
	int tickets[1000]={}; 
	int	 ticketsT1[1000]={};
	int	 ticketsT2[1000]={};
	int	 ticketsT3[1000]={};
	char nomes[1000][50]={};
	char tiposTicket[1000][7]={};
	char generos[1000][2]={};

int csvRead(char nomeArquivo[30],int colunas){
		FILE *file; //file pointer *file = start file
	
	file = fopen(nomeArquivo,"r");//abrir arquivo  "r" = modo Read
	if(file == NULL){//se a leitura retornar NULL erro
	printf("Erro ao abrir o arquivo\n");
	return 1; // Retornar 1 é uma forma de inidicar erro ao Shell
	}
	
	Leitor leitor[100];
	
	//array de structs, guardamos 100 objetos Estudante
	//printf("Linhas: %s\n",sizeof(leitor));
	int i;
	int read = 0;//controle de quantas COLUNAS tem no arquivo
	int records = 0;//controle quantos "objetos" lemos do  arquivo
	//printf("arquivo abriu\n");
	
	do{		
		read = fscanf(file,"%49[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,]",
					                                          
					//lf ler double com 2 digitos
					leitor[records].col1,//guardando %4[^,]
					leitor[records].col2,//guardando %49[^,]
					//ARRAY de string n precisa do & pq precisa de pointer
					leitor[records].col3,//guardando %d
					leitor[records].col4,//guardando %c
					leitor[records].col5,//guarda %lf review
					leitor[records].col6,
					leitor[records].col7,
					leitor[records].col8);
					
		//Se linhas lidas == qtd linha CSV record++
		
		//printf("Reads: %d\n",read);
		//printf("Records: %d\n",records);
		
			
		if(read == colunas){
		//printf("Aumentou records\n");
		records++;
		//printf("Aumentou linhas\n");
		linhas++;			
		}  
		//Se linhas lidas != qtd linhas CSV e não chegou no fim do file
		if(read != colunas && !feof(file)){
			printf("Erro na formatação do arquivo.\n");
			return 1;
		}
		//ferror checa erro no arquivo
		if(ferror(file)){
			printf("Erro na leitura do arquivo.\n");
			return 1;
		}
	}while(!feof(file));// ! = not, feof(file) = avisa o fim do arquivo com true
	fclose(file); //fechar arquivo
	linhas = records;
	//imprime quantidade de itens importados
	
	//printf("\n %d itens \n\n",records);
	
	//for pra imprimir cada linha
	int obra = 0;
	int tema = 0;
	if(strcmp(nomeArquivo,"Bilheteria.csv")==0){
	for(int i = 0; i < records;i++){
		tickets[i] = atoi(leitor[i].col2),
		strcpy(nomes[i],leitor[i].col1),			
		idades[i] = atoi(leitor[i].col3),
		strcpy(generos[i],leitor[i].col4),
		ticketsT1[i] = atoi(leitor[i].col6),
		ticketsT2[i] = atoi(leitor[i].col7),
		ticketsT3[i] = atoi(leitor[i].col8);
		}	
	if(feof(file)==0){
	for(int i=0;i<=linhas;i++){
			strcpy(leitor[i].col1,""),
			strcpy(leitor[i].col2,""),
			strcpy(leitor[i].col3,""),
			strcpy(leitor[i].col4,""),
			strcpy(leitor[i].col5,""),
			strcpy(leitor[i].col6,""),
			strcpy(leitor[i].col7,""),
			strcpy(leitor[i].col8,"");
	}
}
	printf("\n");
	
}
}

void csvWrite(char *nomeOut, char nome[50], int ticket, int idade, char genero,int ticketT1,int ticketT2,int ticketT3){
	FILE *file;
	file = fopen(nomeOut, "a");
	//printf("Abriu arquivo\n");
	fprintf(file,"%s,%d,%d,%c,0,%d,%d,%d",nome,ticket,idade,genero,ticketT1, ticketT2, ticketT3);
	//printf("Gravou\n");
	fclose(file);
}
int main(){
	setlocale(LC_ALL, "Portuguese_Brasil");
	system("chcp 65001");
	system("cls");	
	int tema1=0;
	int tema2=0;
	int tema3=0;
	int i;
	int invalido;
	float valor;
	char resposta;
	int ticket;
	char nome[50];
	int idade;
	char tipoTicket[7];
	char genero;
	int vendendo;
	int index;
	int ticketValido;
	char nomeOut[30] = "Bilheteria.csv";
	//ARRAYS	
	printf("Ola monitor, deseja iniciar o modulo de Bilheteria ou de Validação?\n 'B' para bilheteria, ou 'V' para validação\n");
	invalido = 1;
	while(invalido == 1){
	scanf("%s",&resposta);
	resposta = toupper(resposta);
	switch(resposta){
		case 'B':
			vendendo = 1;
			invalido=0;
			printf("Iniciando modulo de vendas\n\n");
			system("timout 3");
			system("cls");
			break;
		case 'V':
			vendendo=0;
			invalido=0;
			printf("Iniciando modulo de verificação\n\n");
			system("timeout 3");			
			system("cls");
			break;
		default:
			 printf("Preencha um valor valido\n\n");
		}	
	}
	int tema=0;
	while(vendendo == 0){
		ticketValido=0;
		
		if(tema==0){
		printf("Monitor, preencha o numero do Tema atual\n");
		scanf("%d",&tema);
		}
		
		printf("Monitor, por favor insira o numero de ticket do visitante\n");
		scanf("%d",&ticket);
		if(ticket==9999){
			printf("Finalizando o módulo\n\n");
			return 0;
		}
		csvRead("Bilheteria.csv",8);
		
		if(tema==1){
			
		for(i=0;i<sizeof(ticketsT1[i]);i++){
			if(ticketsT1[i]==ticket){
				ticketValido = 1;
				printf("Ticket é valido e pertence a: %s\n\n",nomes[i]);
				system("timeout 5");
				system("cls");
				i=sizeof(tickets);
			}
		}
		}
		if(tema==2){
		for(i=0;i<sizeof(ticketsT2[i]);i++){
			if(ticketsT2[i]==ticket){
				ticketValido = 1;
				printf("Ticket é valido e pertence a: %s\n\n",nomes[i]);
				system("timeout 5");
				system("cls");
				i=sizeof(tickets);
			}
		}
		}
		if(tema==3){
		for(i=0;i<sizeof(ticketsT3[i]);i++){
			if(ticketsT3[i]==ticket){
				ticketValido = 1;
				printf("Ticket é valido e pertence a: %s\n\n",nomes[i]);
				system("timeout 5");
				system("cls");
				i=sizeof(tickets);
			}
		}		
		}
		if(ticketValido==0){			
			printf("Ticket não encontrado no arquivo.\n\n");
			system("timeout 5");
			system("cls");
		}		
	}
	
	while(vendendo == 1){
	printf("O visitante deseja comprar o tema 1?\n 'S' para sim\n 'N' para nao\n\n");
	invalido =1;
	while(invalido == 1){
	scanf("%s",&resposta);
	resposta = toupper(resposta);
	switch(resposta){
		case 'S':
			tema1=1;
			invalido=0;
			printf("Tema 1 adicionado ao carrinho\n\n");
			break;
		case 'N':
			tema1=0;
			invalido=0;
			printf("Nao compraremos o tema 1\n\n");
			break;
		default:
			 printf("Comando invalido\n\n");
		}	
	}
	invalido = 1;
	printf("O visitante deseja comprar o tema 2?\n 'S' para sim\n 'N' para nao\n\n");
	while(invalido == 1){
			scanf("%s",&resposta);
			resposta = toupper(resposta);
	switch(resposta){
		case 'S':
			tema2=1;
			invalido=0;
			printf("Tema 2 adicionado ao carrinho\n\n");
			break;
		case 'N':
			tema2=0;
			invalido=0;
			printf("Nao compraremos o tema 2\n\n");
			break;
		default:
			printf("Comando invalido\n\n");
			}
	}
	invalido = 1;
	printf("O visitante deseja comprar o tema 3?\n 'S' para sim\n 'N' para nao\n\n");
	while(invalido == 1){
		scanf("%s",&resposta);
		resposta = toupper(resposta);
	switch(resposta){
		case 'S':
			tema3=1;
			invalido=0;
			printf("Tema 3 adicionado ao carrinho\n\n");
			break;
		case'N':
			tema3=0;
			invalido=0;
			printf("Nao compraremos o tema 3\n\n");
			break;
			
		default:
			printf("Comando invalido\n\n");
			break;
			}
		}
		invalido = 1;
		printf("Preencha o  tipo de ingresso do visitante, e confirme a validade dos documentos\n 'C' para Cheia\n 'M' para Meia\n 'I' para Isento\n");
		valor = (tema1+tema2+tema3)*20;
		while(invalido == 1){
		scanf("%s",&resposta);
	 	resposta = toupper(resposta);
		switch(resposta){
			case 'C':
				printf("CHEIA, R$%0.2f\n\n", valor);
				strcpy(tipoTicket,"Cheia");
				invalido = 0;
			break;
			case 'M':
				valor=valor/2;
				printf("MEIA, R$%0.2f\n\n", valor);
				strcpy(tipoTicket,"Meio");
				invalido = 0;
				break;
			case 'I':
				valor=0;
				printf("ISENTO, R$%0.2f\n\n", valor);
				strcpy(tipoTicket,"Isento");
				invalido = 0;
				break;
			default:
				printf("Por favor preencha uma opção valida\n\n");
				break;
		}
		}
	//	printf("Tipo ticket: %s\n",tipoTicket);
		printf("Vendedor, informe ao visitante\nVALOR TOTAL: R$%0.2f\n\n", valor);
	//system("pause");	                 
		
		invalido=1;
		while(invalido == 1){
		ticket = rand() % 9000 + 1000;
			for(i=0;i<1000;i++){
				if(ticketsT1[i]==0 && ticketsT2[i]==0 && ticketsT3[i]==0){						
					index = i;
					i = 999;
					invalido = 0;
				}
			}
		}
		
		if(tema1 == 1){
			ticketsT1[index] = ticket;
		}else{
			ticketsT1[index] = 0;
		}
		if(tema2 == 1){
			ticketsT2[index] = ticket;
		}else{
			ticketsT2[index] = 0;
		}
		if(tema3 == 1){
			ticketsT3[index] = ticket;
		}else{
			ticketsT3[index] = 0;
		}
		
		//printf("Tema1: %d  Tema2: %d  Tema 3: %d\n",tema1,tema2,tema3);
		//printf("TicketT1[%d]: %d\nTicketT2[%d]: %d\nTicketT3[%d]: %d\n",index,ticketsT1[index],index,ticketsT2[index],index,ticketsT3[index]);
		//printf("%d\n",ticket);
		//printf("Ticket:%d\n\n Vendedor, informe ao visitando o valor total a pagar, R$%0.2f\n\n", ticket, valor );
		printf("\n\nPreencha o nome do visitante\n\n");
		scanf("%s",&nome);
		
		printf("\n\nPergunte o genero do visitante\n 'F' feminino, 'M' masculino, 'O' outros', 'N' Prefiro não informar.\n\n");	
		invalido =1;
		while(invalido == 1){
		scanf("%s",&genero);
		genero = toupper(genero);
		switch(genero){
		case 'F':
			printf("Feminino\n\n");
			invalido = 0;
			break;
		case 'M':
			printf("Masculino\n\n");
			invalido = 0;
			break;
		case'O':
			printf("Outros\n\n");
			invalido = 0;
			break;
		case 'N':
			printf("Prefiro não informar\n\n");
			invalido = 0;
			break;
		default:
			printf("Preencha uma opção valida\n\n");
			break;	
		}
		}	
		
		printf("\n\nPreencha a idade do visitante\n");
		scanf("%d",&idade);		
		printf("idade %d",idade);
		printf("Tipo ticket: %s\n",tipoTicket);
		printf("\n#------------------------Ingresso-------------------------#\n Nº Ticket: %d \n Nome: %s\n Idade: %d \n#---------------------------------------------------------#\n",ticket,nome,idade);
		
		csvWrite(nomeOut,nome,ticket,idade,genero,ticketsT1[index], ticketsT2[index], ticketsT3[index]);
		//system("pause");
		system("pause");
		system("cls");
		printf("Vamos continuar as vendas? 'S' para sim, 'N' para não\n"); 	
		
		invalido = 1;
		while(invalido == 1){
		scanf("%s",&resposta);
		resposta = toupper(resposta);
			switch(resposta){
				case 'S':					
					printf("Iniciando proxima compra\n\n");
					system("timeout 3");
					system("cls");
					invalido = 0;
					break;
				case'N':
					system("cls");
					printf("Encerrando seção de vendas\n");
					invalido = 0;
					vendendo = 0;								
					break;
				default:
					printf("Comando invalido\n\n");
					break;
				}
	}
	}
	
		return 0;
}
