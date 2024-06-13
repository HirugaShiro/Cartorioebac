#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings


int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	// inicio da cria��o de vari�veis/strings(conjutos de variaveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s referese a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w"(write) significa escrever
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file=fopen(arquivo, "a"); // Consulta o arquivo "a" para atualizar no arquivo
	fprintf(file,","); // salva no arquivo ","
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,nome); // salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file=fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,",");  // salva no arquivo ","
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", sobrenome); 
	
	file = fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file=fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,","); // salva no arquivo ","
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,cargo); // salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	system("pause"); // pausa a execus�o para o usuario
	
}

int consulta() // Fun��o responsavel por consutar os usu�rios do sistema
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	// inicio da cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	// Final da cria��o de variaveis
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //Busca o arquivo
	file = fopen(cpf,"r"); // le o arquivo "r"(read) para ler o conteudo 
	
	if(file== NULL) //Valida��o se o cpf existe
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL) //loop para ler e escrever o conteudo do arquivo para o ussuario
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	} // fim do loop
	
	system("pause"); // pausa a execus�o para o usuario
}

int deletar() // Fun��o responsavel por deletar os usuarios do sistema
{
	char cpf[40]; // Variavel de parametro principal (ID principal) do sistema
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	
	
	FILE *file;	// Busca o arquivo
	file = fopen(cpf,"r"); // // le o arquivo "r"(read) para ler o conteudo 
	fclose(file);
	
	if(file==NULL) // Valida��o para deletar usuario do sistema caso exista
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
	} 
	else
	{
		remove(cpf); // comando que remove o conteudo da variavel
		printf("Usu�rio deletado com sucesso!.\n");
	}
	
	system("pause"); // pausa a execus�o para o usuario
}


int main()
{
	int opcao=0; // Definindo as variasveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;)
		{
			
			system("cls"); // limpa a tela
		
			setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
		
			printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1- Registrar nomes:\n");
			printf("\t2- Consultar nomes:\n");
			printf("\t3- Deletar nomes:\n\n"); 
			printf("\t4- Sair do sistema\n\n");
			printf("Opc�o: ");// Final do menu
		
			scanf("%d", &opcao); // Armazenando  a escolha do usuario
	
			system("cls"); // Limpando a Tela
			
		
			switch(opcao) //Inicio da sela��o do menu
			{
				case 1:
				registro(); // Chamada da fun��o registro
				break;
			
				case 2:
				consulta(); // Chamada da fun��o consulta
				break;
			
				case 3: 
				deletar(); // Chamada de fun��o deletar
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistama!\n");
				return 0;
				break;
			
			
				default:
				printf("Op��o indisponivel\n");
				system("pause");
				break;
			}	//Fim da sele��o
		}
	
	}
	
	else
		printf("Senha incorreta!");
}
