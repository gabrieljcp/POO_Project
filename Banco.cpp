//arquivo : Banco.cpp
//implementação do arquivo .h
#include "Banco.h"

#include "ContaBancaria.h"

void Banco::AberturaContaCorrente (void){
  	 ContaCorrente::AberturaConta();	
}
void Banco::ListagemContaCorrente (void){
  	 ContaCorrente::Listagem();	
}
void Banco::AberturaContaPoupanca (void){
  	 ContaPoupanca::AberturaConta();	
}
void Banco::ListagemContaPoupanca (void){
  	 ContaPoupanca::Listagem();	
}
