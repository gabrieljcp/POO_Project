// Arquivo: ContaCorrente.cpp

#include <stdio.h>
#include <stdlib.h>

#include "ContaBancaria.h"

//***********************************
// ao implementar cada metodo, 
// SUBSTITUIR o codigo DISPONIBILIZADO
// pelo codigo ADEQUADO 
//***********************************


//***********************************
// ContaCorrente
//***********************************

ContaCorrente* vetorCc[10];

int ContaCorrente::qtdContas = 0; 


//***********************************
// Metodos primitivos 
//***********************************

ContaCorrente::ContaCorrente (Cliente* titular):ContaBancaria(titular) {
		
		    		
}

int ContaCorrente::RecuperarQtdContas (void) {
	
  	return ContaCorrente::qtdContas;
  	
}	  

void ContaCorrente::IncrementarQtdContas (void) {
	
	 ContaCorrente::qtdContas++;	

}

//***********************************
// Metodos derivados 
//***********************************

void ContaCorrente::AbrirConta (Cliente* titular) {
	
	// este método cria objeto do tipo ContaCorrente
	// e insere Conta Corrente no respectivo vetor
		
	int i = ContaCorrente::RecuperarQtdContas ();
	vetorCc[i] = new ContaCorrente (titular);
	ContaCorrente::IncrementarQtdContas();
		
}
      	
void ContaCorrente::AberturaConta (void) {
	
	Cliente *titular = NULL;
    int qtdContas = ContaCorrente::RecuperarQtdContas();
	 
	if (qtdContas == 10){
	    printf("\nNao estamos abrindo contas desse tipo no momento");
	    system("PAUSE");
	 	return;
	}
	 
	titular = Cliente::ObterCliente();
	if(titular!= NULL){
	 	
	 	ContaCorrente::AbrirConta(titular);
    }	
	 
}

void ContaCorrente::Listagem (void)   {
	
	int qtdContas = ContaCorrente::RecuperarQtdContas();
	
	int numAgencia, numConta, dAbDia, dAbMes, dAbAno, titNascDia, titNascMes, titNascAno;
    char titCpf[12], titNome[60], titEndereco[60] ;
	float  saldo;
		    
	
	if(qtdContas == 0){
		printf("\n Nao ha contas desse tipo no momento \n");
		system("PAUSE");
		return;
	}
 	
	
	for(int i = 0; i < qtdContas; i++) {
	
	    vetorCc[i]->RecuperarConta(&numAgencia, &numConta, &dAbDia, &dAbMes, &dAbAno, &saldo, titCpf, titNome, &titNascDia, &titNascMes, &titNascAno, titEndereco);
	    
	    printf("\n---------------------\n");
	    printf("\n>>>Dados Da Conta<<<\n");
	    printf("	Agencia = %d ", numAgencia);
	    printf("\n	Conta = %d ", numConta);
	    printf("\n	Data de Abertura = %d/%d/%d ", dAbDia, dAbMes, dAbAno);
	    printf("\n	Saldo = R$%.2f ", saldo);
	    
	    printf("\n\n>>>Dados Do Cliente<<<");
	    printf("\n	CPF = %s ", titCpf);
	    printf("\n	Nome = %s ", titNome);
	    printf("\n	Data de Nascimento = %d/%d/%d ", titNascDia, titNascMes, titNascAno);
	    printf("\n	Endereco = %s  ", titEndereco);
	}	  
}
