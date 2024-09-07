#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das Strings

int registro(){ // Fun��o respons�vel por cadastrar os usu�rios do sistema

	//In�cio Cria��o de vari�veis/Strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final Cria��o de vari�veis/Strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //Refere-se  a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e adiciona informa��o com "a"
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
}

int consulta(){ // Fun��o respons�vel por consultar os usu�rios do sistema
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL){
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}
	
int deletar(){ // Fun��o respons�vel por deletar os usu�rios do sistema

	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	fclose(file);
	remove(cpf);

	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema!\n");
	}
	
	system("pause"); 
	
}

int main() {
	
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;){
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo o Idioma
		
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		
		printf("Escolha a op��o desejada do menu: \n\n");
		
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao); //Armazenamento da escolha do usuario
		
		system("cls"); //Limpa a tela
		
		switch(opcao){
			
			case 1:
				registro(); //Chamada de fun��es
				break;
				
			case 2:
				consulta(); //Chamada de fun��es
				break;
				
			case 3:
				deletar(); //Chamada de fun��es
				break;
				
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		}
		
		
	}
	
	//printf("Este � um software de livre uso.\n");
}