#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <locale.h>
typedef struct{
	//col 1 ticket
	//col 2 nome
	// col3 idade e acertos
	//col 4 genero
	//col 5 review
	//resto tickets temas
	char col0[100];
	char col1[10000];
    char col2[1000];
    char col3[1000];
    char col4[1000];
    char col5[1000];
    char col6[1000];
    char col7[1000];
    char col8[1000];
    char col9[1000];
    char col10[2];
    char col11[2];
    char col12[2];
    char col13[2];
	
}Leitor;
int linhas;
char nomeArquivo[30];
char nomeOut[5];

char titulos[10][100];
char descricao[10][10000];
char questoes [10][4][1000];
char alternativas [10][4][1000];
int altCorreta[10][4];

char formatado[10000];

void formatador(char texto[10000]) {
	
    int i;
    char compose[10000];
    compose[0] = '\0';
	int caracteresPorLinha = 0;
    //strcat(compose, &texto[0]);

    for (i = 0; i < strlen(texto); i++) {
        if (texto[i] == ';') {
            strcat(compose, ",");
        } else {
            char temp[2] = {texto[i], '\0'};  // Cria uma string temporária com o caractere atual
            strcat(compose, temp);
        }
        caracteresPorLinha++;
        if (caracteresPorLinha >= 110) {
            strcat(compose, "\n");  // Adiciona uma quebra de linha
            caracteresPorLinha = 0;  // Reinicia o contador
        }
    }

    printf("%s\n", compose);
}
void formatarAlt(char texto[1000]){
	int i;
    char compose[10000];
    compose[0] = '\0';	
    //strcat(compose, &texto[0]);

    for (i = 0; i < strlen(texto); i++) {
        if (texto[i] == '/') {
            strcat(compose, "\n");
        } else {
            char temp[2] = {texto[i], '\0'};  // Cria uma string temporária com o caractere atual
            strcat(compose, temp);
        }        
    }
    printf("%s\n", compose);
}

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
		read = fscanf(file,"%99[^,],%9999[^,],%999[^,],%999[^,],%999[^,],%999[^,],%999[^,],%999[^,],%999[^,],%999[^,],%2[^,],%2[^,],%2[^,],%2[^,]",
					                                          
					//lf ler double com 2 digitos
					leitor[records].col0,
					leitor[records].col1,//guardando %4[^,]
					leitor[records].col2,//guardando %49[^,]
					//ARRAY de string n precisa do & pq precisa de pointer
					leitor[records].col3,//guardando %d
					leitor[records].col4,//guardando %c
					leitor[records].col5,//guarda %lf review
					leitor[records].col6,
					leitor[records].col7,
					leitor[records].col8,
					leitor[records].col9,
					leitor[records].col10,
					leitor[records].col11,
					leitor[records].col12,
					leitor[records].col13);
					
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
	if(strcmp(nomeArquivo,"Tema1.csv")==0){
	for(int i = 0; i < records;i++){
		strcpy(titulos[i],leitor[i].col0),
		strcpy(descricao[i],leitor[i].col1),
		strcpy(questoes[i][0],leitor[i].col2),
		strcpy(questoes[i][1],leitor[i].col3),
		strcpy(questoes[i][2],leitor[i].col4),
		strcpy(questoes[i][3],leitor[i].col5),
		strcpy(alternativas[i][0],leitor[i].col6),
		strcpy(alternativas[i][1],leitor[i].col7),
		strcpy(alternativas[i][2],leitor[i].col8),
		strcpy(alternativas[i][3],leitor[i].col9),		
		altCorreta[i][0] = atoi(leitor[i].col10),
		altCorreta[i][1] = atoi(leitor[i].col11),
		altCorreta[i][2] = atoi(leitor[i].col12),
		altCorreta[i][3] = atoi(leitor[i].col13);
		
		}
	}	
	if(strcmp(nomeArquivo,"Tema2.csv")==0){
	for(int i = 0; i < records;i++){
		strcpy(titulos[i],leitor[i].col0),
		strcpy(descricao[i],leitor[i].col1),
		strcpy(questoes[i][0],leitor[i].col2),
		strcpy(questoes[i][1],leitor[i].col3),
		strcpy(questoes[i][2],leitor[i].col4),
		strcpy(questoes[i][3],leitor[i].col5),
		strcpy(alternativas[i][0],leitor[i].col6),
		strcpy(alternativas[i][1],leitor[i].col7),
		strcpy(alternativas[i][2],leitor[i].col8),
		strcpy(alternativas[i][3],leitor[i].col9),		
		altCorreta[i][0] = atoi(leitor[i].col10),
		altCorreta[i][1] = atoi(leitor[i].col11),
		altCorreta[i][2] = atoi(leitor[i].col12),
		altCorreta[i][3] = atoi(leitor[i].col13);
		
		}
	}	
	if(strcmp(nomeArquivo,"Tema3.csv")==0){
	for(int i = 0; i < records;i++){
		strcpy(titulos[i],leitor[i].col0),
		strcpy(descricao[i],leitor[i].col1),
		strcpy(questoes[i][0],leitor[i].col2),
		strcpy(questoes[i][1],leitor[i].col3),
		strcpy(questoes[i][2],leitor[i].col4),
		strcpy(questoes[i][3],leitor[i].col5),
		strcpy(alternativas[i][0],leitor[i].col6),
		strcpy(alternativas[i][1],leitor[i].col7),
		strcpy(alternativas[i][2],leitor[i].col8),
		strcpy(alternativas[i][3],leitor[i].col9),		
		altCorreta[i][0] = atoi(leitor[i].col10),
		altCorreta[i][1] = atoi(leitor[i].col11),
		altCorreta[i][2] = atoi(leitor[i].col12),
		altCorreta[i][3] = atoi(leitor[i].col13);
		
		}
	}	
	
	if(feof(file)==0){
	for(int i=0;i<=linhas;i++){
			strcpy(leitor[i].col0,""),
			strcpy(leitor[i].col1,""),
			strcpy(leitor[i].col2,""),
			strcpy(leitor[i].col3,""),
			strcpy(leitor[i].col4,""),
			strcpy(leitor[i].col5,""),
			strcpy(leitor[i].col6,""),
			strcpy(leitor[i].col7,""),
			strcpy(leitor[i].col8,""),
			strcpy(leitor[i].col9,"");
	}
}


	printf("\n");
	
}
int csvWrite(char *nomeOut, int ticket, int acerto, float avaliacao){
	FILE *file;
	file = fopen(nomeOut, "a");
	fprintf(file,"aaaaaaaaaaaa,%d,%d,%.2f,aaaa,aaaa,aaaa,aaaa\n",ticket,acerto,avaliacao);
	fclose(file);
}
int main(int argc, char *argv[]){
	
	//"Pintada em 1933, a tela Operarios tem tematica social, esta exposta no Palacio Boa Vista e pertence ao Acervo do Governo do Estado de Sao Paulo, feita com a tecnica de pintura a oleo, tem dimensoes grandes (120cm x 205cm) e pertence ao período em que Tarsila do Amaral se dedicou a retratar temas de interesse coletivo e social, apos retornar de uma viagem a Uniao Sovietica.Tarsila, seguindo as caracteristicas modernistas iniciadas apos o evento da Semana da Arte Moderna, deseja denunciar e expor a industrializacao brasileira, momento historico marcado pela migracao de trabalhadores, classe ainda muito vulneravel e explorada, sem leis que a defendem propriamente.\nA tela Operarios e considerada um grande simbolo do periodo de industrializacao brasileira (especialmente do Estado de Sao Paulo).\nEsse foi um momento historico marcado pela migracao de trabalhadores, uma classe ainda muito vulneravel e explorada, sem acesso a leis que a defendesse propriamente.\nAssim, Tarsila exibe nessa obra as distintas feicoes dos trabalhadores e trabalhadoras das fabricas. Sao pessoas de cores e etnias muito diferentes representadas lado a lado. E, apesar dos contrastes, todos carregam feicoes extremamente cansadas e sem esperanca.";
	//={"Questao 1: Qual e a tecnica de pintura utilizada por Tarsila do Amaral na obra\n Os Operarios?\n1) Acrilica\n2) Aquarela\n3) Pintura a oleo\n4) Guache\n","\nQuestao 2: Em que ano foi pintada a obra?\n\n1)1985\n2)1933\n3)1850\n4)2010\n","\nQuestao 3: Qual era o principal objetivo de Tarsila do Amaral ao pintar\nOs Operarios?\n\n1) Celebrar a riqueza da elite brasileira\n2) Representar a diversidade cultural brasileira\n3) Capturar a beleza natural da Amazonia\n4) Denunciar e expor a industrializacao brasileira e a condicao\ndos trabalhadores\n","\nQuestao 4: O que a obra Os Operarios representa em termos de diversidade?\n1) Representa apenas trabalhadores de uma etnia especifica\n2) Mostra trabalhadores de diversas cores e etnias lado a lado\n3) Representa apenas trabalhadores masculinos\n4) Mostra apenas trabalhadoras femininas\n"};
	
	char resposta;
	int i;
	int j;
	int invalido=1;
	int tema;
	int obra;
	int ticket;
	int tickets[1000]={};
	int expor = 1;
	int descrever = 1;
	char traco[160] = "\n------------------------------------------------------------------------------------------------------------------------\n";
	int acerto = 0;
	int acertos[1000]={};
	float avaliacao;
	float avaliacoes[1000]={};
	int index;	
	setlocale(LC_ALL, "Portuguese_Brasil");
	system("chcp 65001");
	system("cls");
	printf("Monitor digite por favor o numero do Tema\n");
	scanf("%d",&tema);
	switch(tema){
		case 1:
			strcpy(nomeArquivo,"Tema1.csv");
			printf("%s\n",nomeArquivo);
			break;
		case 2:
			strcpy(nomeArquivo,"Tema2.csv");
			printf("%s\n",nomeArquivo);
			break;
		case 3:
			strcpy(nomeArquivo,"Tema3.csv");
			printf("%s\n",nomeArquivo);
			break;
		default:
			printf("Digite um valor valido\n");
			break;
	}
	csvRead(nomeArquivo,14);
	
	printf("Monitor digite por favor o numero da obra\n");
	scanf("%d",&obra);
	
	strcat(nomeOut,"T");
	char buffer[1];
	sprintf(buffer,"%d",tema);	
	strcat(nomeOut,buffer);
	strcat(nomeOut,"O");
	sprintf(buffer,"%d",obra);	
	strcat(nomeOut,buffer);
	strcat(nomeOut,".csv");
	printf("%s",nomeOut);	
	obra-=1;
	
	system("cls");
	while(expor==1){
	descrever = 1;
	
		while(descrever==1){
			invalido = 1;
	
	printf("%s\n\n",titulos[obra]);
	formatador(descricao[obra]);
	printf("\n%s\nGostaria de Responder o Questionario? Coloque S para sim ou N para não\n\n",traco);	
			while(invalido==1){
				printf("Digite S ou N\n\n");
				scanf("%s",&resposta);
			    resposta = toupper(resposta);
			switch(resposta)
			{
				case 'S':
					//printf("SIM!\n");
					invalido=0;
					descrever = 0;
					 break;
				case 'N':
					//printf("NAO!\n");
					invalido=0;
					descrever = 1;
					resposta = '\0';					
					system("cls");
					 break;
					 
					 default: 
					 printf("opcao invalida, tente novamente !\n");
					 break;
				
				}	
			}
	}
	invalido = 1;
	system("cls");
	printf("Digite seu numero de ticket\n");
	scanf("%d",&ticket);
	if(ticket == 9999){
		expor = 0;
	}else{
		
	for(i=0;i<1000;i++){
		if(tickets[i]==0){
			tickets[i] = ticket;
			index = i;
		//	printf("Tickets[%d]: %d\n",i,tickets[i]);
			i = 999;
		}
		
	}
	int op;
	
	//printf("%s\n",descricao[obra]); //Quesao 1
	system("cls");
	
	for(i=0;i<=3;i++){
	char alt[1000];
			printf("%s\n%s\n\n",traco,questoes[obra][i]);
			strcpy(alt,alternativas[obra][i]);
			formatarAlt(alt);			
	invalido = 1;	
	while(invalido==1){
	scanf("%d",&op); // resposta das perguntas
	if(op>4||op<1){
	printf("resposta invalida, responda novamente\n");
	 }else{
	invalido=0;
	 }
	}
	if(op==altCorreta[obra][i]){
	printf("resposta correta\n");
	acerto++;}
	else{
	printf("resposta errada\n");
		}        
	 }
	printf("\nVoce acertou %d questões\n",acerto);
	invalido = 1;
	while(invalido == 1){
	printf("Avalie a obra de 0 a 5\n (Para numeros decimais use . ao inves de ,)\n");
	scanf("%f",&avaliacao);
	if(avaliacao > 5 || avaliacao < 0){
		printf("Valor invalido, por favor digite um valor entre 0 e 5\n");
		invalido = 1;
	}else{
		invalido = 0;
	}
	}
	csvWrite(nomeOut,ticket,acerto,avaliacao);
	avaliacoes[index] = avaliacao;
	printf("Acerto: %d",acerto);		
	acertos[index] = acerto;
	
	acerto = 0;
	invalido = 1;
	expor = 1;
	}
	system("cls");	
	}
	for(i=0;i<1000;i++){
		if(tickets[i]!=0){			
			printf("Tickets[%d]: %d Acertos: %d Avaliacao: %.2f\n",i,tickets[i],acertos[i],avaliacoes[i]);			
		}}
	//printf("\n\nSaindo do while\n\n");
	system("pause");
		
	return 0;
   }


