// Arquivo: Cliente.cpp

#include <stdio.h>
#include <string.h>

#include "ContaBancaria.h"

//***********************************
// ao implementar cada metodo, 
// SUBSTITUIR o codigo DISPONIBILIZADO
// pelo codigo ADEQUADO 
//***********************************


//***********************************
// Cliente
//***********************************

Cliente* vetorCli[10];
 
int Cliente::qtdClientes = 0;


//***********************************
// Metodos primitivos 
//***********************************

Cliente::Cliente (char cpfTitular  [12]) {
		
		fflush(stdin);
	  	strcpy(cpf, cpfTitular );
	  	printf("\n Informe os dados do cliente: ");
  		printf("\n	Nome: ");
  		scanf("%s", nome);
  		fflush(stdin);
  		printf("	Endereco: ");
  		scanf("%s", endereco);
  		fflush(stdin);
  		printf("	Data de Nascimento: ");
  		printf("\n		Dia: ");
  		scanf("%d", &dtNascDia);
  		printf("		Mes: ");
  		scanf("%d", &dtNascMes);
  		printf("		Ano: ");
  		scanf("%d", &dtNascAno);
  		fflush(stdin);
}

int Cliente::VerificarCliente (char cpfTitular [12]) {
	
	if(strcmp(cpfTitular, cpf)==0)
		return 1;
	else
		return 0;

}

int Cliente::RecuperarQtdClientes (void) {
	
	return Cliente::qtdClientes;

}	  

void Cliente::IncrementarQtdClientes (void) {
	
		Cliente::qtdClientes++;
	
}

void Cliente::RecuperarCliente (char cliCpf[12], char cliNome[60], 
			                    int* cliNascDia, int* cliNascMes, int* cliNascAno, 
								char cliEnder[60])  {
									
	strcpy( cliCpf, cpf);
	strcpy( cliNome, nome);
	strcpy( cliEnder, endereco);
    *cliNascDia =  dtNascDia;
    *cliNascMes =  dtNascMes;
    *cliNascAno =  dtNascAno;
    
		
									
}

//***********************************
// Metodos derivados 
//***********************************

Cliente* Cliente::VerificarExistenciaCliente (char cpfTitular [12]) {
		Cliente* titular=NULL;
		int qtd;
		int achou;
		
		qtd =  Cliente::RecuperarQtdClientes();
		
		for(int i = 0; i < qtd; i++){
			achou = vetorCli[i]->VerificarCliente(cpfTitular);
			if(achou){
				titular = vetorCli[i];
				break;
			}	
		}
	
	return titular;    
      	
}
     
Cliente* Cliente::ObterCliente (void) {
	
	// este m√©todo cria objeto do tipo cliente
	// e insere cliente no respectivo vetor
	
	char cpfTitular[12];
	Cliente *titular = NULL;
	int qtdClientes;
	int i;
	
	fflush(stdin);
	printf("\n Informe o CPF do titular: ");
	scanf("%s", cpfTitular);
	fflush(stdin);
	
	qtdClientes=Cliente::RecuperarQtdClientes();
	if(qtdClientes !=0){
		titular=Cliente::VerificarExistenciaCliente(cpfTitular);
	}
	
	if(titular==NULL && qtdClientes ==10){
		printf("\n N„o estamos aceitando clientes no momento. Obrigado! \n");
//		system("PAUSE");
		return NULL;
	}
	
	if(titular==NULL && qtdClientes<10){
		titular= new Cliente(cpfTitular);
		
		i = qtdClientes;
		vetorCli[i]=titular;
		Cliente::IncrementarQtdClientes();
	}
	return titular;
}
     	 	  	  
