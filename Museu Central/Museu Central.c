#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

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
char nomes[100][50]={};
int idades[100];
char generos[100][2];
char ticketsT1[100][5];
char ticketsT2[100][5];
char ticketsT3[100][5];



char ticketsTerminal[3][5][100][5]={};
int acertos[3][5][100]={};
double avaliacoes[3][5][100]={};

double mediasObras[3][5]={};
double mediasTemas[3]={};
char relMedia[3][5][10];

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
	setlocale(LC_ALL, "Portuguese_Brasil");
	system("chcp 65001");
	system("cls");
	int i;
	int j;
	int r;
	
	
	int size = sizeof avaliacoes / sizeof *avaliacoes;
	
	printf("\nIniciando importação dos arquivos\n");
	strcpy(nomeArquivo,"Bilheteria.csv");
	csvRead(nomeArquivo,8);
	
	for(i=0;i < linhas;i++){
	//	printf("\n\nTicket:%s\nNome:%s\nIdade:%d\nGenero:%s\nTicketT1:%s\nTicketT2:%s\nTicketT3:%s\n\n",tickets[i],nomes[i],idades[i],generos[i],ticketsT1[i],ticketsT2[i],ticketsT3[i]);
	}

	
	//IMPORTAR CSV TEMAS
		char compose[8];		
		char convert[8];
	for(i=1;i <=3;i++){
		
		sprintf(convert,"T%dO",i);	
		strcpy(compose, convert);	
		//printf("Compose:%s\n",compose);	
			for(j=1;j<=5;j++){	
			sprintf(convert,"%d.csv",j);
			strcat(compose, convert);
			//printf("Compose:%s\n",compose);
			//strcat(compose, ".csv");
			//printf("Compose:%s\n",compose);
			strcpy(nomeArquivo,compose);
			csvRead(nomeArquivo,8);
			printf("Abriu %s",nomeArquivo);	
			sprintf(compose,"T%dO",i);		
			//strcpy(compose,"");		
		}
		printf("\n");		
	}
	printf("\n");
	system("pause");
	
	// EXIBINDO MATRIZ DE DADOS
	
//	printf("Checando matriz de dados\n");
	
//	for(int i = 0;i < 3;i++){	
//		printf("Tema %d\n",i);
//			for(int j = 0;j < 5;j++){
//				printf("\n\nTema %d Obra %d\nTicket, Acertos, Avaliação\n",i+1,j+1);
//					for(int r = 0;r < size;r++){	
//					printf("%s	%d	%.2f\n",ticketsTerminal[i][j][r],acertos[i][j][r],avaliacoes[i][j][r]);
//					}
//			}
//	}
		
		//calcular media das notas
		//for i < 3 temas
	printf("Iniciando calculo de médias");
	for(i=0;i<3;i++){
		//for j< qtd obra 
		for(j=0;j<5;j++){
			double soma = 0;
			double media;
			int qtd = 0;
			//for r < qtd de reviews
			for(r=0;r<size;r++){
				if(avaliacoes[i][j][r] != 0){
				soma +=	avaliacoes[i][j][r];
				//printf("soma:%.2f \n",soma);
				qtd++;
								
				}											
			}
		//printf("Soma:%.2f Quantidades: %d\n",soma,qtd);
		media = soma/qtd;
		//printf("Media atual:%f\n",media);
		mediasObras[i][j] = soma / qtd;
		
		//printf("%.2f",mediasObras[i][j]);
		soma = 0;
		qtd = 0;			
		}
				
	}
	
	// Exibir medias
	printf("\n\n");
	for(i=0;i<3;i++){
		printf("\n------------------------------------------\n\nMedias obras Tema %d\n",i+1);
		for(j=0;j<5;j++){
			printf("Media Obra %d: %.2f\n",j+1,mediasObras[i][j]);			
		}
		system ("pause");
	}	
	printf("\n\nCalculando médias dos temas");
	//Calcular media temas
	for(i=0;i<3;i++){
		double soma = 0;
		double media;	
		for(j=0;j<5;j++){
		soma += mediasObras[i][j];
		}
		media = soma/5;
		mediasTemas[i] = media;
		
	}
	for(i=0;i<3;i++){
		printf("\nMedia Tema %d: %.2f\n",i+1,mediasTemas[i]);
		
	}
	system ("pause");
	//Oganizar baseado na media
	
	for(i=0;i<3;i++){
		printf("\n------------------------------------------\nTema %d\n\n",i+1);
		for(j=0;j<5;j++){
				printf("Obra %d %\n",j+1);			
					if(mediasObras[i][j] > mediasTemas[i]){	
					strcpy(relMedia[i][j],"Acima");		
					printf("%s da média: %.2f\n",relMedia[i][j],mediasObras[i][j]);
					}else if(mediasObras[i][j] == mediasTemas[i]){
					strcpy(relMedia[i][j],"Média");
					printf("Na %s: %.2f\n",relMedia[i][j],mediasObras[i][j]);
					}else{
					strcpy(relMedia[i][j],"Abaixo");
					printf("%s da média: %.2f\n",relMedia[i][j],mediasObras[i][j]);
					}
		}
		system ("pause");
	}
	
}
	
	


