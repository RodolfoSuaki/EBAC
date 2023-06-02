#include <stdlib.h> //biblioteca para alocar espaço na memória
#include <stdio.h> //bilioteca de comunicação com o usuário
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar ()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o seu CPF: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //Responsável por copiar o valor da variável cpf para a variável arquivo
	
	
	FILE *file;
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variável
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
	
	printf("Digite o CPF que você gostaria de consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("\n\nNão há nenhum registro com esse número de CPF. \n\n");
	}
	while (fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas são as informações do usuário consultado: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int main ()
{	
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		printf("### Bem vindo ao Cartório EBAC ###\n\n");
		printf("-> Escolha a opção no menu: \n\n");
		printf("\t 1 - Registrar usuário \n");
		printf("\t 2 - Consultar usuário \n");
		printf("\t 3 - Deletar usuário \n\n");
		printf("Digite a opção desejada: ");//fim do menu
		scanf("%d", &opcao);//armazenando a opção do usuário
		
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
				
			printf("Você escolheu a opção Deletar usuário. \n\n");
			system("pause");
			break;
				
			default:
				
			printf("Você escolheu a opção Registrar usuário. \n\n");
			system("pause");
			break;
		}
	}
}	
