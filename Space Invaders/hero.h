#ifndef	HERO_H
#define HERO_H

#include <iostream>
#include <string>
#include "entidade.h"

using namespace std;

class hero: public entidade{
	
	public:
		hero(string="",int=0,int=0,int=0,int=0,int=0);
		
		void set_hero(string,int,int,int,int,int);
		void update_pontos(int);
		void update_boosts(int);
		void update_vidas(int);
		void update_x(int);
		void update_shot();
		
		int can_shot();
		
		int get_shot()const;
		string get_nome()const;
		int get_boosts()const;
		int get_pontos()const;
		int get_vidas()const;
		
	private:
		
		int shot;// variavel que permite limitar os tiros/segundo do hero
		string nome;
		int vidas,pontos,boosts;
};

#endif
