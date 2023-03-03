#ifndef ESCUDO_H
#define ESCUDO_H
#include <iostream>

using namespace std;

class escudo{
	public:
		escudo();
		
		void set_ativo(int);
		
		int get_ativo()const;

	private:
		int ativo;	 
		
};

#endif
