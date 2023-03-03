#include <iostream>
#include "escudo.h"

using namespace std;

escudo::escudo(){
	this->ativo=0;
}

void escudo::set_ativo(int a){
	this->ativo=a;
}
		
int escudo::get_ativo()const{
	return ativo;
}
