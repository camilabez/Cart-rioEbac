#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file - fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
} 	//fim fun��o registro

int consulta() //fun��o respons�vel por consultar os usu�rios no sistema
{
	 setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	 
	//in�cio cria��o de vari�veis/string	 
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); //leitura do arquivo
	
	if(file == NULL)
	{
		printf("N�o localizado!\n"); //mensagem para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mensagem para o usu�rio seguida das info coletadas
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
} //fim da fun��o consultar

int deletar() //fun��o respons�vel por deletar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char cpf[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //a��o de remover arquivo conforme informa��o gerada pelo usu�rio
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n"); //mensagem para o usu�rio
		system("pause");		
	}
		
} 	//fim fun��o deletar

int main () 
{
	int opcao=0;  //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	   
	   system("cls"); //respons�vel por limpar a tela
	
	   setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	   printf("### Cart�rio da EBAC ###\n\n");  //in�cio do menu
	   printf("Escolha a op��o desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");  
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Op��o:"); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	   system("cls");
	   
	   switch(opcao) //in�cio da sele��o do menu
	   {
	     case 1:
		 registro(); //chamada de fun��es
		 break;
		 
		 case 2:
		 consulta(); //chamada de fun��es
		 break;
		 
		 case 3:
		 deletar(); //chamada de fun��es
		 break;
		 
		 case 4:
		 printf("Obrigado por utilizar o sistema!\n");
		 return 0;
		 break;
		 
		 default:
		 printf("Op��o n�o dispon�vel!\n");
		 system("pause");
		 break;	
	   } //fim da sele��o
	
	   
    }
}
