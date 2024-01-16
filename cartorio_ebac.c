#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file - fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
} 	//fim função registro

int consulta() //função responsável por consultar os usuários no sistema
{
	 setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	 
	//início criação de variáveis/string	 
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); //leitura do arquivo
	
	if(file == NULL)
	{
		printf("Não localizado!\n"); //mensagem para o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); //mensagem para o usuário seguida das info coletadas
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
} //fim da função consultar

int deletar() //função responsável por deletar os usuários no sistema
{
	//início criação de variáveis/string
	char cpf[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");//coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //ação de remover arquivo conforme informação gerada pelo usuário
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n"); //mensagem para o usuário
		system("pause");		
	}
		
} 	//fim função deletar

int main () 
{
	int opcao=0;  //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	   
	   system("cls"); //responsável por limpar a tela
	
	   setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	   printf("### Cartório da EBAC ###\n\n");  //início do menu
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");  
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Opção:"); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usuário
	
	   system("cls");
	   
	   switch(opcao) //início da seleção do menu
	   {
	     case 1:
		 registro(); //chamada de funções
		 break;
		 
		 case 2:
		 consulta(); //chamada de funções
		 break;
		 
		 case 3:
		 deletar(); //chamada de funções
		 break;
		 
		 case 4:
		 printf("Obrigado por utilizar o sistema!\n");
		 return 0;
		 break;
		 
		 default:
		 printf("Opção não disponível!\n");
		 system("pause");
		 break;	
	   } //fim da seleção
	
	   
    }
}
