#include <stdlib.h> //biblioteca para alocar espa�o na mem�ria
#include <stdio.h> //bilioteca de comunica��o com o usu�rio
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar ()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o seu CPF: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //Respons�vel por copiar o valor da vari�vel cpf para a vari�vel arquivo
	
	
	FILE *file;
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da vari�vel
	fprintf(file,","); //adiciona o caracter "," para separar os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu nome: \n");
	scanf("%s", nome);
	
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu sobrenome: \n");
	scanf("%s", sobrenome);
	

	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu cargo: \n");
	scanf("%s", cargo);
	

	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file,",");
	fclose(file);
}

int consultar ()
{
	setlocale (LC_ALL,"Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que voc� gostaria de consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("\n\nN�o h� nenhum registro com esse n�mero de CPF. \n\n");
	}
	while (fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio consultado: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int main ()
{	
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		printf("### Bem vindo ao Cart�rio EBAC ###\n\n");
		printf("-> Escolha a op��o no menu: \n\n");
		printf("\t 1 - Registrar usu�rio \n");
		printf("\t 2 - Consultar usu�rio \n");
		printf("\t 3 - Deletar usu�rio \n\n");
		printf("Digite a op��o desejada: ");//fim do menu
		scanf("%d", &opcao);//armazenando a op��o do usu�rio
		
		system("cls");
		
		switch (opcao)
		{
			case 1:
			registrar();
   			system("pause");
			break;
				
			case 2:
				
			consultar();
			break;
				
			case 3:
				
			printf("Voc� escolheu a op��o Deletar usu�rio. \n\n");
			system("pause");
			break;
				
			default:
				
			printf("Voc� escolheu a op��o Registrar usu�rio. \n\n");
			system("pause");
			break;
		}
	}
}	
