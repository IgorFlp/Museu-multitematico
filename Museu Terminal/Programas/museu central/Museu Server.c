#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

char nomeArquivo[30]={};
char tickets[100][5];
char nomes[10][50]={};
int idades[10];
char generos[10][2];
char ticketsT1[100][5];
char ticketsT2[100][5];
char ticketsT3[100][5];

char ticketsTerminal[3][10][100][5];
int acertos[3][10][10];
double avaliacoes[3][10][10]={};

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
	int read = 0;//controle de quantas COLUNAS tem no arquivo
	int records = 0;//controle quantos "objetos" lemos do  arquivo
	printf("arquivo abriu\n");
	
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
		printf("Reads: %d\n",read);
		printf("Records: %d\n",records);
		
			
		if(read == colunas){
		printf("Aumentou records\n");
		records++;
		printf("Aumentou linhas\n");
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
	printf("\n %d itens \n\n",records);
	//for pra imprimir cada linha
	int obra = 0;
	int tema = 0;
	if(strcmp(nomeArquivo,"csvbilheteria.csv")==0){
	for(int i = 0; i < records;i++){
		strcpy(tickets[i],leitor[i].col2),
		strcpy(nomes[i],leitor[i].col1),			
		idades[i] = atoi(leitor[i].col3),
		strcpy(generos[i],leitor[i].col4),
		strcpy(ticketsT1[i],leitor[i].col6),
		strcpy(ticketsT2[i],leitor[i].col7),
		strcpy(ticketsT3[i],leitor[i].col8);
		}
	}
	if (strstr(nomeArquivo,"T1") != NULL) {
		tema = 0;
	}
	if (strstr(nomeArquivo,"T2") != NULL) {
		tema = 1;
	}
	if (strstr(nomeArquivo,"T3") != NULL) {
		tema = 2;
	}
    //if(strcmp(nomeArquivo,)==0){
	    if (strstr(nomeArquivo,"O1") != NULL) {
	    	obra = 0;
	    }
	    if (strstr(nomeArquivo,"O2") != NULL) {
	    	obra = 1;
	    }
	    if (strstr(nomeArquivo,"O3") != NULL) {
	    	obra = 2;
	    }
	    if (strstr(nomeArquivo,"O4") != NULL) {
	    	obra = 3;
	    }
	    if (strstr(nomeArquivo,"O5") != NULL) {
	    	obra = 4;
	    }
	    if (strstr(nomeArquivo,"O6") != NULL) {
	    	obra = 5;
	    }

		if (strstr(nomeArquivo,"O7") != NULL) {
	    	obra = 6;
	    }
	    if (strstr(nomeArquivo,"O8") != NULL) {
	    	obra = 7;
	    }
	    if (strstr(nomeArquivo,"O9") != NULL) {
	    	obra = 8;
	    }
		if (strstr(nomeArquivo,"O9") != NULL) {
	    	obra = 8;
	    }	    	    
	
			for(int i = 0; i < records;i++){		
				strcpy(ticketsTerminal[tema][obra][i],leitor[i].col2),
				acertos[tema][obra][i] = atoi(leitor[i].col3),
				avaliacoes[tema][obra][i]=atof(leitor[i].col4);
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
int main(){
	int i;
	int j;
	int r;
	double medias[3][10];
	
	int size = sizeof avaliacoes / sizeof *avaliacoes;
	
	printf("\n\nINICIA CSVBILHETERIA\n\n");
	strcpy(nomeArquivo,"csvbilheteria.csv");
	csvRead(nomeArquivo,8);
	
	for(i=0;i < linhas;i++){
		printf("\n\nTicket:%s\nNome:%s\nIdade:%d\nGenero:%s\nTicketT1:%s\nTicketT2:%s\nTicketT3:%s\n\n",tickets[i],nomes[i],idades[i],generos[i],ticketsT1[i],ticketsT2[i],ticketsT3[i]);
	}
	
	for(i=0;i < 10;i++){
		char ntema[30] = "T1O";
		char data[20] ="081023.csv";
		char ichar;
		sprintf(ichar, "%d", i);
		strcat(ntema,ichar);
		printf("ntema: %s",ntema);
	}
	
	printf("\n\nINICIA T1O1\n\n");
	strcpy(nomeArquivo,"T1O1081023.csv");	
	csvRead(nomeArquivo,8);
	
	printf("\n\nINICIA T1O2\n\n");
	strcpy(nomeArquivo,"T1O2081023.csv");	
	csvRead(nomeArquivo,8);
	
	printf("\n\nINICIA T1O3\n\n");
	strcpy(nomeArquivo,"T1O3081023.csv");	
	csvRead(nomeArquivo,8);
	
	for(i=0;i < linhas;i++){
		printf("\n\nTicket:%s\nAcertos:%d\nAvalicao:%.2f\n\n\n",ticketsTerminal[i],acertos[i],avaliacoes[0][0][i]);
	}
	
		//calcular media das notas
		//for i < 3 temas
	for(i=0;i<3;i++){
		//for j< qtd obra 
		for(j=0;j<10;j++){
			double soma = 0;
			double media;
			int qtd = 0;
			//for r < qtd de reviews
			for(r=0;r<size;r++){
				if(avaliacoes[i][j][r] != 0){
				soma +=	avaliacoes[i][j][r];
				printf("soma:%.2f \n",soma);
				qtd++;
								
				}											
			}
		printf("Soma:%.2f Quantidades: %d\n",soma,qtd);
		media = soma/qtd;
		printf("Media atual:%f\n",media);
		medias[i][j] = soma / qtd;
		
		printf("%.2f",medias[i][j]);
		soma = 0;
		qtd = 0;
		printf("\n\n");
		
	}	
	}
	for(i=0;i<3;i++){
		printf("Medias Tema %d\n",i);
		for(j=0;j<10;j++){
			printf("Media Obra%d: %.2f\n",j,medias[i][j]);			
		}
	}	
	
	int media;
	//Oganizar baseado na media
	for(i=0;i<size;i++){
		if(avaliacoes[i] != 0){
			if(avaliacoes[1][1][i] > media){			
			printf("A avaliacao acima da media:%f\n",avaliacoes[1][i]);
			}else if(avaliacoes[1][1][i] == media){
			printf("A avaliacao na media:%f\n",avaliacoes[1][i]);
			}else{
			printf("A avaliacao abaixo da media:%f\n",avaliacoes[1][i]);
			}		
	}
	}
	
}
