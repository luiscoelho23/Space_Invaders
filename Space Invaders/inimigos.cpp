#include <iostream>
#include "inimigos.h"

using namespace std;

inimigos::inimigos(int x ,int y){
	this->x=x;
	this->y=y;
	this->vivo=1;
}

void inimigos::set_morto(){
	this->vivo=0;
	this->enable_shots(0);
}

void inimigos::enable_shots(int a){
	this->enable_shot=a;
}

int inimigos::get_enable_shots()const{
	return enable_shot;
}
		
int inimigos::get_morto()const{
	return vivo;
}


