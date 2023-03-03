#include <iostream>
#include "tiroini.h"

using namespace std;

tiroini::tiroini(int x,int y){
	this->x=x;
	this->y=y;
	this->ativo=1;
}

void tiroini::update_y(int a){
	if(y==16){
		set_ativo(0);
	}else y+=a;
}

void tiroini::set_ativo(int a){
	this->ativo=a;
}	
		
int tiroini::get_ativo()const{
	return ativo;
}
