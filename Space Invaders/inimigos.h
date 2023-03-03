#ifndef INIMIGOS_H
#define INIMIGOS_H

#include <iostream>
#include "entidade.h"

using namespace std;

class inimigos:public entidade{
	
	public:
		
		inimigos(int,int);
		
		void set_morto();
		void enable_shots(int);		
		
		int get_morto()const;
		int get_enable_shots()const;
		
	private:
		
		int vivo, enable_shot;//variavel que deixa um inimigo disparar
};

#endif
