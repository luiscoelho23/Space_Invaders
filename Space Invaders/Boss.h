#ifndef BOSS_H
#define BOSS_H
#include <iostream>
#include "entidade.h" 

using namespace std;

class Boss:public entidade{
	public:
		Boss();
		
		void set_vivo();
		void set_morto();
		void update_y(int);
		void update_vida(int);
		
		int get_vida()const;

	private:
		int vida;	 
		
};

#endif
