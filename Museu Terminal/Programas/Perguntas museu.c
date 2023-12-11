#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void imprimirTexto(const char *texto) {
    int larguraTerminal = 80;  // Largura padrão do terminal (ajuste conforme necessário)
    int comprimentoTexto = strlen(texto);

    for (int i = 0; i < comprimentoTexto; i += larguraTerminal) {
        // Imprime uma parte do texto, limitando a largura ao tamanho do terminal
        for (int j = 0; j < larguraTerminal && i + j < comprimentoTexto; j++) {
            printf("%c", texto[i + j]);
        }
        printf("\n");  // Mova para a próxima linha
    }
}

int main(int argc, char *argv[]){
	
	char descricao[10000]="Pintada em 1933, a tela Operarios tem tematica social, esta exposta no Palacio Boa Vista e pertence ao Acervo do Governo do Estado de Sao Paulo, feita com a tecnica de pintura a oleo, tem dimensoes grandes (120cm x 205cm) e pertence ao período em que Tarsila do Amaral se dedicou a retratar temas de interesse coletivo e social, apos retornar de uma viagem a Uniao Sovietica.Tarsila, seguindo as caracteristicas modernistas iniciadas apos o evento da Semana da Arte Moderna, deseja denunciar e expor a industrializacao brasileira, momento historico marcado pela migracao de trabalhadores, classe ainda muito vulneravel e explorada, sem leis que a defendem propriamente.\nA tela Operarios e considerada um grande simbolo do periodo de industrializacao brasileira (especialmente do Estado de Sao Paulo).\nEsse foi um momento historico marcado pela migracao de trabalhadores, uma classe ainda muito vulneravel e explorada, sem acesso a leis que a defendesse propriamente.\nAssim, Tarsila exibe nessa obra as distintas feicoes dos trabalhadores e trabalhadoras das fabricas. Sao pessoas de cores e etnias muito diferentes representadas lado a lado. E, apesar dos contrastes, todos carregam feicoes extremamente cansadas e sem esperanca.";
	char questoes[4][1000]={"Questao 1: Qual e a tecnica de pintura utilizada por Tarsila do Amaral na obra\n Os Operarios?\n\nA) Acrilica\nB) Aquarela\nC) Pintura a oleo\nD) Guache\n","\nQuestao 2: Em que ano foi pintada a obra?\n\nA)1985\nB)1933\nC)1850\nD)2010\n","\nQuestao 3: Qual era o principal objetivo de Tarsila do Amaral ao pintar\nOs Operarios?\n\nA) Celebrar a riqueza da elite brasileira\nB) Representar a diversidade cultural brasileira\nC) Capturar a beleza natural da Amazonia\nD) Denunciar e expor a industrializacao brasileira e a condicao\ndos trabalhadores\n","\nQuestao 4: O que a obra Os Operarios representa em termos de diversidade?\nA) Representa apenas trabalhadores de uma etnia especifica\nB) Mostra trabalhadores de diversas cores e etnias lado a lado\nC) Representa apenas trabalhadores masculinos\nD) Mostra apenas trabalhadoras femininas\n"};
	char altCorreta[4][1]={"C","B","D","B"}; 
	char resposta;
	int i;
	imprimirTexto(descricao);
	//printf("%s\n",descricao);
	printf("\n\nGostaria de Responder o Questionario? Coloque S para sim ou N para nao\n\n");
	scanf("%s",&resposta);
	switch(resposta)
	{
		case 'S':
			printf("SIM!\n");
			 break;
		case 'N':
			printf("NAO!\n");
			 break;
			 
			 default: 
			 printf("opcao invalida, tente novamente !\n");
			 break;
		
		printf("\n\n");
		system("pause");

	}

	
	char op;
	
	printf("\nOs Operarios (1933), de Tarsila do Amaral\n\n"); //Quesao 1
	
	for(i=0;i<=3;i++){
	printf("%s\n",questoes[i]);
	scanf("%s",&op); // resposta das perguntas
	
	switch(op)
	{
		case 'A':
			printf("Errou!\n");
			 break;
		case 'B':
			printf("Errou!\n");
			 break;
		case 'C':
			printf("Correta!\n");
			 break;
		case 'D':
			printf("Errou!\n");
			 break;
			 
			 default: printf("opcao invalida, tente novamente !\n");
	}
	
	char op;
	
	 //Questao 2
	for(i=1;i<=3;i++){
	printf("%s\n",questoes[i]);
	scanf("%s",&op);
	
	switch(op)
	{
		case 'A':
			printf("Errou!\n");
			 break;
		case 'B':
			printf("Correta!\n");
			 break;
		case 'C':
			printf("Errou!\n");
			 break;
		case 'D':
			printf("Errou!\n");
			 break;
			 
			 default: printf("opcao invalida, tente novamente !\n");
	}
	//Questao3
	for(i=2;i<=3;i++){
	printf("%s\n",questoes[i]);
	scanf("%s",&op);
	
	switch(op)
	{
		case 'A':
			printf("Errou!\n");
			 break;
		case 'B':
			printf("Errou!\n");
			 break;
		case 'C':
			printf("Errou!\n");
			 break;
		case 'D':
			printf("Correta!\n");
			 break;
			 
			 default: printf("opcao invalida, tente novamente !\n");
	}
	//Quetao 4
	for(i=3;i<=3;i++){
	printf("%s\n",questoes[i]);
	scanf("%s",&op);
	
	switch(op)
			{
		case 'A':
			printf("Errou!\n");
			 break;
		case 'B':
			printf("Correta!\n");
			 break;
		case 'C':
			printf("Errou!\n");
			 break;
		case 'D':
			printf("Errou!\n");
			 break;
			 
			 default: printf("opcao invalida, tente novamente !\n");
	}
		printf("\n\n");
		system("pause");
		return 0;

	}
   }
  }
 }
}