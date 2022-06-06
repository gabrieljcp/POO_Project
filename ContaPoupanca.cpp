// Arquivo: ContaPoupanca.cpp

#include <stdio.h>
#include <stdlib.h>

#include "ContaBancaria.h"

//***********************************
// ao implementar cada metodo, 
// SUBSTITUIR o codigo DISPONIBILIZADO
// pelo codigo ADEQUADO 
//***********************************



//***********************************
// ContaPoupanca
//***********************************

ContaPoupanca* vetorCp[10];

float ContaPoupanca::txRendimento = 0.5; 
int   ContaPoupanca::qtdContas = 0; 



//***********************************
// Metodos primitivos 
//***********************************


ContaPoupanca::ContaPoupanca (Cliente* titular):ContaBancaria(titular) {
		printf("\n Informe os dados da poupanca: ");
		printf("\n		Dia de rendimento: ");
		scanf("%d", &diaRendimento);		
  		
}

 float ContaPoupanca::ObterTxRendimento (void) {
  		
  		return ContaPoupanca::txRendimento;

}

int ContaPoupanca::RecuperarQtdContas (void) {
	
  		return ContaPoupanca::qtdContas;

}	  

void ContaPoupanca::IncrementarQtdContas (void) {
	
  		ContaPoupanca::qtdContas++;
		  	
}


//***********************************
// Metodos derivados 
//***********************************

	  
void ContaPoupanca::RecuperarConta (int* ag, int* ct, 
                                    int* dAbDia, int* dAbMes, int* dAbAno,
                                    float* sdo, 
								    char titCpf [12], char titNome [60],             
                                    int* titNascDia, int* titNascMes, int* titNascAno, 
                                    char titEndereco [60], 
									int* diaRend, float* taxa) {

		*diaRend = diaRendimento;		
  		*taxa = ContaPoupanca::ObterTxRendimento();
		
		ContaBancaria::RecuperarConta(ag, ct, dAbDia, dAbMes, dAbAno, sdo, titCpf, titNome, titNascDia, titNascMes, titNascAno, titEndereco);

}  
      
 void ContaPoupanca::AbrirConta (Cliente* titular)  {
 	
	// este método cria objeto do tipo ContaPoupanca
	// e insere Conta Poupanca no respectivo vetor

	int i =ContaPoupanca::RecuperarQtdContas ();
 	vetorCp[i]= new ContaPoupanca(titular);
 	ContaPoupanca::IncrementarQtdContas ();
	
}

void ContaPoupanca::AberturaConta (void) {

	Cliente *titular=NULL;	
	int qtdContas = ContaPoupanca::RecuperarQtdContas();
		
	if (qtdContas==10){
		printf("\nNao estamos abrindo contas desse tipo no momento \n");
		system("PAUSE");
		return;
	}
		
  	titular = Cliente::ObterCliente();
	if(titular!= NULL){
	 	
	 	ContaPoupanca::AbrirConta(titular);
    }	

}
    
void ContaPoupanca::Listagem (void)   {
	
	int qtdContas = ContaPoupanca::RecuperarQtdContas();
	
	int numAgencia, numConta, dAbDia, dAbMes, dAbAno, titNascDia, titNascMes, titNascAno, diaRend;
    char titCpf[12], titNome[60], titEndereco[60] ;
	float  saldo, txRendimento;
		    
	
	if(qtdContas == 0){
		printf("\n Nao ha contas desse tipo no momento \n");
		system("PAUSE");
		return;
	}
 	
	
	for(int i = 0; i < qtdContas; i++) {
	
	    vetorCp[i]->RecuperarConta(&numAgencia, &numConta, &dAbDia, &dAbMes, &dAbAno, &saldo, titCpf, titNome, &titNascDia, &titNascMes, &titNascAno, titEndereco, &diaRend, &txRendimento);
	    
	   	printf("\n---------------------\n");
	    printf("\n>>>Dados Da Conta<<<");
	    printf("\n	Agencia = %i ", numAgencia);
	    printf("\n	Conta = %i ", numConta);
	    printf("\n	Data da Abertura = %i/%i/%i ", dAbDia, dAbMes, dAbAno);
	    printf("\n	Saldo = R$%.2f ", saldo);
	    printf("\n	Dia de Rendimento = %i ", diaRend);
	    printf("\n	Taxa de Rendimento = %.2f ", txRendimento);
	    
	   	printf("\n\n>>>Dados Do Cliente<<<");
	    printf("\n	CPF = %s ", titCpf);
	    printf("\n	Nome = %s ", titNome);
	    printf("\n	Data de Nascimento = %i/%i/%i ", titNascDia, titNascMes, titNascAno);
	    printf("\n	Endereco = %s ", titEndereco);
	}	  
}

