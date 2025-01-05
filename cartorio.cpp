#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de aloção de espaço de memoria
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel porcuidar das string

int registro() //função responasavel por cadastrar o usuario no sistema
{
	//inicio crição de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da crição de variaveis/string

	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
	
	FILE *file; //criar o arquivo
	file = fopen(arquivo, "w");// o "w" significa escrever
	fprintf(file, cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// o "a" significa atualizar 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("Usuario registrado!!");
	
	system("pause");
	
}

int consulta()

	{setlocale(LC_ALL, "Portuguese");//definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];

	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // o "r" significa ler então ele le o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o aquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as intormações do usuario: \n");
		printf("%s", conteudo );
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usuario a ser deletado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file =fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O usuario nâo se encontra no siatema!!. \n");
			system("pause");
		}else
		{
			printf("Usuario deletado!!");
			system("pause");
		}

		remove(cpf);
			
}

int main()
	{
		int opcao=0; //Definindo variaveis

		int laco=1;
		
		for(laco=1;laco=1;)
		{
		
			system("cls"); //limpar a tela
			
			setlocale(LC_ALL, "Portuguese");//definindo a linguagem 
		
			printf("### Cartório da EBAC ###\n\n");//inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema \n\n");
			printf("Opção: ");//fim do menu
			
			scanf("%d", &opcao);//armazenando escolha do usuario
		
			system("cls");//apagar o que tem na tela limpar
			
			switch(opcao) //inicio da sekleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigada por usar o sistema! \n");
				return 0;
				break;
				

				default:
				printf("Esta opção não está disponivel! \n");
				system("pause");
				break;
			} //fim da seleção
		}
	}
