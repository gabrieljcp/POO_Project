// Arquivo: ContaBancaria.cpp

#include <stdio.h>

#include "ContaBancaria.h"

//***********************************
// ao implementar cada metodo, 
// SUBSTITUIR o codigo DISPONIBILIZADO
// pelo codigo ADEQUADO 
//***********************************


//***********************************
// ContaBancaria
//***********************************

int ContaBancaria::qtdContas = 0; 

//***********************************
// Metodos primitivos 
//***********************************

ContaBancaria::ContaBancaria (Cliente* cliPonteiro)  {
	  	titular    = cliPonteiro;
	  	printf("---------------------\n");
  		printf("\n Informe os dados da Conta Bancaria: ");
  		
  		printf("\n	Agencia: ");
  		scanf("%d", &numAgencia);
  		printf("	Numero da conta: ");
  		scanf("%d", &numConta);
  		printf("	Saldo: ");
  		scanf("%f", &saldo);
  		printf("	Data da Abertura: \n");
  		printf("		Dia: ");
  		scanf("%d", &dtAbDia);
  		printf("		Mes: ");
  		scanf("%d", &dtAbMes);
  		printf("		Ano: ");
  		scanf("%d", &dtAbAno);
  		fflush(stdin);
}

//***********************************
// Metodos primitivos 
//***********************************

void ContaBancaria::IncrementarQtdContas() {
	
	ContaBancaria::qtdContas++;
	
}


//***********************************
// Metodos derivados 
//***********************************

void ContaBancaria::RecuperarConta (int* ag, int* ct, 
		                            int* dAbDia, int* dAbMes, int* dAbAno, 
								    float* sdo, char titCpf[12], char titNome[60],  
								    int* titNascDia, int* titNascMes, int* titNascAno, 
								    char titEndereco[60])   {							
						    	
  	*ag = numAgencia;
	*ct = numConta;
	*dAbDia = dtAbDia;
	*dAbMes = dtAbMes;
	*dAbAno = dtAbAno;
	*sdo = saldo;
	
	titular-> RecuperarCliente(titCpf, titNome, titNascDia, titNascMes, titNascAno, titEndereco);

 }
   	

