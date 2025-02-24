#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca da String

int registro()//Fun��o respons�vel por cadastrar os usuarios do sistema

{
	//Inicio da criacao de variaveis (strings , String = conjunto de vari�veis)
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final da criacao de variaveis (strings , String = conjunto de vari�veis)
   
   FILE *file; //Cria o arquivo
   printf("Escolha o CPF a ser cadastrado:  ");//Coletando informa��o do usuario
   scanf("%s", cpf);// Fun��o para salvar dentro de uma String // %s refere-se a string
   
   strcpy(arquivo, cpf); //Respons�vel por copiar os valores das Strings
   
   
   file = fopen(arquivo, "w"); // Fun��o para abrir arquivo // "w" vem de Write
   fprintf(file,cpf); //Salvar o valor
   fclose(file); //Fechar arquivo
   
   file = fopen (arquivo, "a");// "a" � uma atualiza��o no arquivo
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
	printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
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
   printf("Digite o cpf do usu�rio a ser deletado:   ");
   scanf("%s", cpf);	
   
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
    printf("O usu�rio n�o se encontra no sistema!.\n");	
    system("pause");
  
    
   }
}



int main ()//Fun��o principal do programa// Essa fun��o sempre abre primeiro
{	
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)//Definindo repeti��o
	{//Repeti��o come�a aqui
	
	system ("cls"); //Responsavel por limpar a tela

	setlocale (LC_ALL, "Portuguese");//Definindo linguagem
	
	printf ("### Cart�rio da EBAC ###\n\n");// Inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");//Op��es do menu
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o:");//Fim do menu
	
	scanf("%d",&opcao); //Inserir op��o na vari�vel
	
	system("cls"); //Limpar todas as mensagens que haviam antes para melhorar aspecto visual
	
	switch (opcao)//Uma alternativa melhor que o "if" //Inicio da sele��o do menu
	{
		case 1:
		registro();//chamada de fun��es
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
		printf("Esta op��o n�o est� disponivel!\n");//Fim da sele��o
	    system("pause");
	    break;
		
	
	}//Fim da sele��o do menu
	
}

}
	

  
  
    


