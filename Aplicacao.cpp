//Arquivo: Aplicacao.cpp
#include <stdio.h>
#include <stdlib.h>
#include "Banco.h"

void MenuCC();
void MenuCP();


int main(void){
	
	int opcao;
	
	printf(">>> Serasa Bank <<< \n \n");
	printf("-------SysConta------- \n\n");
	do{
		printf("Opcoes: \n");
		printf("1 - Conta Corrente \n");
		printf("2 - Conta Poupanca \n");
		printf("3 - Conta Especial \n");
		printf("4 - Sair \n");
		printf("----------------------");
		printf("\n Escolha uma das opcoes: (1, 2, 3 ou 4): ");
		scanf("%d", &opcao);
		fflush(stdin);
		
		switch(opcao){
			case 1:
				MenuCC();
			break;	
			case 2:
				MenuCP();
			break;		
			case 3:
				printf("\n>>> CONTA ESPECIAL <<< \n \n");
				printf("Em desenvolvimento... \n");
				system("PAUSE");
				system("cls");
			break;
			
			case 4:
				system("cls");
				printf("\n..FIM.. \n");
			break;
			
			default:
				system("cls");
				printf("\nOpcao invalida \n\n");
				system("PAUSE");
		}	
	}while(opcao != 4);
	
	system("pause");
	return EXIT_SUCCESS;
}

void MenuCC(){
	
	int opcao;				
				do{
					system("cls");
					printf(">>> Serasa Bank <<< \n \n");
					printf("-------SysConta------- \n\n");
					printf(">>> MENU CONTA CORRENTE <<< \n \n");
					printf("1 - Abertura Conta Corrente \n");
					printf("2 - Listagem Contas Correntes \n");
					printf("3 - Sair \n \n");
					printf("\n >>>Escolha uma das opcoes: (1, 2 ou 3): ");
					scanf("%d", &opcao);
					
					switch(opcao){
						case 1:
							system("cls");
							printf(">>> Serasa Bank <<< \n \n");
							printf("-------SysConta------- \n\n");
							printf("\n>>> ABERTURA CONTA CORRENTE <<< \n \n");
							Banco::AberturaContaCorrente();					
							printf("\n");
							system("PAUSE");
						break;
						
						case 2:
							system("cls");
							printf("\n>>> LISTAGEM CONTAS CORRENTES <<< \n \n");
							Banco::ListagemContaCorrente();
							printf("\n\n");
							system("PAUSE");
							
						break;
			
						case 3:
							system("cls");
							printf("\n..FIM.. \n");
							printf("\n");
						break;
						
						default:
							printf("\nOpcao invalida \n\n");
							system("PAUSE");
					}	
				}while(opcao != 3);
	
			

}

void MenuCP(){
	
	int opcao;
	
				do{
				system("cls");
					printf(">>> Serasa Bank <<< \n \n");
					printf("-------SysConta------- \n\n");
					printf(">>> MENU CONTA POUPANCA <<< \n \n");
					printf("1 - Abertura Conta Poupanca \n");
					printf("2 - Listagem Contas Poupanca \n");
					printf("3 - Sair \n \n");
					printf("\n >>>Escolha uma das opcoes: (1, 2 ou 3): ");
					scanf("%d", &opcao);
					
					switch(opcao){
						case 1:
							system("cls");
							printf(">>> Serasa Bank <<< \n \n");
							printf("-------SysConta------- \n\n");
							printf("\n>>> ABERTURA CONTA POUPANCA <<< \n \n");
							Banco::AberturaContaPoupanca();
							printf("\n");
							system("PAUSE");
						break;
						
						case 2:
							system("cls");
							printf("\n>>> LISTAGEM CONTAS POUPANCA <<< \n \n");
							Banco::ListagemContaPoupanca();
							printf("\n\n");
							system("PAUSE");
						break;
							
						case 3:
							system("cls");
							printf("\n ** FIM ***\n\n");
							printf("\n\n");
							system("PAUSE");	
						break;
							
						default:
							printf("\nOpcao invalida \n\n");
							system("PAUSE");
					}
				} while (opcao != 3);
			
}
