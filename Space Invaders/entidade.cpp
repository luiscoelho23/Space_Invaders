#include <iostream>
#include "entidade.h"

void entidade::set_x(int x){
	this->x=x;
}

void entidade::set_y(int y){
	this->y=y;
}

int entidade::get_x()const{
	return x;
}

int entidade::get_y()const{
	return y;
}
