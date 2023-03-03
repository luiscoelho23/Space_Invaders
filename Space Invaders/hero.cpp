#include <iostream>
#include <string>
#include "hero.h"

using namespace std;

hero::hero(string nome,int x,int y,int vidas,int boosts,int pontos){
	this->shot=0;
	this->nome=nome;
	this->x=x;
	this->y=y;
	this->vidas=vidas;
	this->boosts=boosts;
	this->pontos=pontos;
}

void hero::set_hero(string nome,int x,int y,int vidas,int boosts,int pontos){
	this->shot=0;
	this->nome=nome;
	this->x=x;
	this->y=y;
	this->vidas=vidas;
	this->boosts=boosts;
	this->pontos=pontos;
}

void hero::update_shot(){
	if(shot<5){
		shot++;
	}
}

int hero::get_shot()const{
	return shot;
}

int hero::can_shot(){
	if(shot==5){
		shot=0;
		return 1;
	}else return 0;
}

string hero::get_nome()const{
	return nome;
}

void hero::update_boosts(int a){
	this->boosts=boosts+a;
}

void hero::update_pontos(int a){
	this->pontos=pontos+a;				
}

void hero::update_vidas(int a){
	vidas-=a;
}

void hero::update_x(int a){
	x+=a;
}
		
int hero::get_pontos()const{
	return pontos;
}

int hero::get_boosts()const{
	return boosts;
}

int hero::get_vidas()const{
	return vidas;
}
