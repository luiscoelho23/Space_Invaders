#include <iostream>
#include "ufo.h"

using namespace std;

ufo::ufo(){
	set_x(2);
	this->vivo=0;
}

void ufo::set_vivo(){
	set_y(28);
	this->vivo=1;
}

void ufo::set_morto(){
	set_y(28);
	this->vivo=0;
}

void ufo::update_y(){
	if(y==2){
		set_vivo();
	}else y--;
}

int ufo::get_vivo()const{
	return vivo;
}
