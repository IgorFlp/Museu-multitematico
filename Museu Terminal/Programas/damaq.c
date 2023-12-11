#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

int main(){
	char pastas[10][64]={"JOSE ANTONIO DA CRUZ", "CLEIDE MARCIANO","JOSIANE APARECIDA","IGOR FELIPE DE OLIVEIRA","RODRIGO BRITO TOLEDO","EGMAR TOLEDO"};
	char pasta[64];
	int psemelhanca[300][1];
	int semelhanca;
	char nome[5][64];
	char *pch;	
	char str[] = "IGOR OLIVEIRA";
	pch = strtok (str," ,.-");
	int i=0;
  while (pch != NULL)
  {
  	strcpy(nome[i],pch);
	printf ("%s\n",pch);    
    pch = strtok (NULL, " ,.-");
    i++;
    
    
} 
int j=0;
	printf("Saiu do while\n");
  	printf("Nome0:%s\nNome1:%s\nNome2:%s\n",nome[0],nome[1],nome[2]);

	for(i=0;i<sizeof(pastas);i++){
		printf("Pasta %d\n",i);
		for(j=0;j<sizeof(nome);j++){
			strcpy(pasta,pastas[i]);
			printf("Pasta:%s\n",pasta);
		if(strstr(pasta,nome[j])==nome[j]){			
			printf("J:%d\nSemelhanca +1\n",j);
			system("TIMEOUT 3\n");
			semelhanca+=1;			
		}
	}
		psemelhanca[i][1]=semelhanca;
	}
	printf("psemelhanças");
	for(i=0;i<sizeof(psemelhanca);i++){
	printf("%s,",psemelhanca[i]);
	}
}
