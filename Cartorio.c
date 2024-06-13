#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings


int registro() // Função responsavel por cadastrar os usuários no sistema
{
	// inicio da criação de variáveis/strings(conjutos de variaveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); //%s referese a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w"(write) significa escrever
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file=fopen(arquivo, "a"); // Consulta o arquivo "a" para atualizar no arquivo
	fprintf(file,","); // salva no arquivo ","
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,nome); // salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file=fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,",");  // salva no arquivo ","
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", sobrenome); 
	
	file = fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file=fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,","); // salva no arquivo ","
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); // Consulta o arquivo 
	fprintf(file,cargo); // salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	system("pause"); // pausa a execusão para o usuario
	
}

int consulta() // Função responsavel por consutar os usuários do sistema
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	// inicio da criação de variáveis
	char cpf[40];
	char conteudo[200];
	// Final da criação de variaveis
	
	printf("Digite o CPF a ser consultado: "); // Coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file; //Busca o arquivo
	file = fopen(cpf,"r"); // le o arquivo "r"(read) para ler o conteudo 
	
	if(file== NULL) //Validação se o cpf existe
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL) //loop para ler e escrever o conteudo do arquivo para o ussuario
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	} // fim do loop
	
	system("pause"); // pausa a execusão para o usuario
}

int deletar() // Função responsavel por deletar os usuarios do sistema
{
	char cpf[40]; // Variavel de parametro principal (ID principal) do sistema
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coletando informação do usuário
	scanf("%s",cpf);
	
	
	
	FILE *file;	// Busca o arquivo
	file = fopen(cpf,"r"); // // le o arquivo "r"(read) para ler o conteudo 
	fclose(file);
	
	if(file==NULL) // Validação para deletar usuario do sistema caso exista
	{
		printf("O usuário não se encontra no sistema!.\n");
	} 
	else
	{
		remove(cpf); // comando que remove o conteudo da variavel
		printf("Usuário deletado com sucesso!.\n");
	}
	
	system("pause"); // pausa a execusão para o usuario
}


int main()
{
	int opcao=0; // Definindo as variasveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;)
		{
			
			system("cls"); // limpa a tela
		
			setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
		
			printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1- Registrar nomes:\n");
			printf("\t2- Consultar nomes:\n");
			printf("\t3- Deletar nomes:\n\n"); 
			printf("\t4- Sair do sistema\n\n");
			printf("Opcão: ");// Final do menu
		
			scanf("%d", &opcao); // Armazenando  a escolha do usuario
	
			system("cls"); // Limpando a Tela
			
		
			switch(opcao) //Inicio da selação do menu
			{
				case 1:
				registro(); // Chamada da função registro
				break;
			
				case 2:
				consulta(); // Chamada da função consulta
				break;
			
				case 3: 
				deletar(); // Chamada de função deletar
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistama!\n");
				return 0;
				break;
			
			
				default:
				printf("Opção indisponivel\n");
				system("pause");
				break;
			}	//Fim da seleção
		}
	
	}
	
	else
		printf("Senha incorreta!");
}
