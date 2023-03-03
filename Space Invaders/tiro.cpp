#include <iostream>
#include "tiro.h"

tiro::tiro(int x,int y){	
	this->y=y;
	this->x=x;
	this->ativo=1;
}

void tiro::update_y(int a){
	if(y==1){
		set_ativo(0);
	}else y-=a;	
}

void tiro::set_ativo(int a){
	this->ativo=a;
}

int tiro::get_ativo()const{
	return this->ativo;
}
