#include <iostream>
#include "Boss.h"

using namespace std;

Boss::Boss(){
	this->vida=0;
	set_x(5);
	set_y(15);
}

void Boss::set_vivo(){
	this->vida=3500;
}

void Boss::set_morto(){
	this->vida=0;
}

void Boss::update_vida(int a){
	this->vida=vida+a;
}

void Boss::update_y(int a){
	this->y=y+a;
}
		
int Boss::get_vida()const{
	return vida;
}
