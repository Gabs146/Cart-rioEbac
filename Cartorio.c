#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca da String

int registro()//Função responsável por cadastrar os usuarios do sistema

{
	//Inicio da criacao de variaveis (strings , String = conjunto de variáveis)
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final da criacao de variaveis (strings , String = conjunto de variáveis)
   
   FILE *file; //Cria o arquivo
   printf("Escolha o CPF a ser cadastrado:  ");//Coletando informação do usuario
   scanf("%s", cpf);// Função para salvar dentro de uma String // %s refere-se a string
   
   strcpy(arquivo, cpf); //Responsável por copiar os valores das Strings
   
   
   file = fopen(arquivo, "w"); // Função para abrir arquivo // "w" vem de Write
   fprintf(file,cpf); //Salvar o valor
   fclose(file); //Fechar arquivo
   
   file = fopen (arquivo, "a");// "a" é uma atualização no arquivo
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado:  ");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file, nome);
   fclose(file);
   
   file = fopen (arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado:  ");
   scanf("%s", sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file, sobrenome);
   fclose(file);
   
   file = fopen (arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado:   ");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese");//Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	printf("Digite o cpf a ser consultado:  ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" vem da palavra Read
	
	if(file == NULL) // "Null" vem de nulo
	{
	printf("Não foi possivel abrir o arquivo, não localizado!\n");
	
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
	fclose(file);
	system("pause");
}

int deletar ()
{
   char cpf[40];
   char conteudo[200];
   printf("Digite o cpf do usuário a ser deletado:   ");
   scanf("%s", cpf);	
   
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
    printf("O usuário não se encontra no sistema!.\n");	
    system("pause");
  
    
   }
}



int main ()//Função principal do programa// Essa função sempre abre primeiro
{	
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)//Definindo repetição
	{//Repetição começa aqui
	
	system ("cls"); //Responsavel por limpar a tela

	setlocale (LC_ALL, "Portuguese");//Definindo linguagem
	
	printf ("### Cartório da EBAC ###\n\n");// Inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");//Opções do menu
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção:");//Fim do menu
	
	scanf("%d",&opcao); //Inserir opção na variável
	
	system("cls"); //Limpar todas as mensagens que haviam antes para melhorar aspecto visual
	
	switch (opcao)//Uma alternativa melhor que o "if" //Inicio da seleção do menu
	{
		case 1:
		registro();//chamada de funções
		break;
		
		case 2:
	    consulta();
		break;
		
	    case 3:
	    deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Esta opção não está disponivel!\n");//Fim da seleção
	    system("pause");
	    break;
		
	
	}//Fim da seleção do menu
	
}

}
	

  
  
    


