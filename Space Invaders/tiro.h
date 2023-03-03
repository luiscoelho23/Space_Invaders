#ifndef	TIRO_H
#define TIRO_H

#include <iostream>
#include <vector>
#include "entidade.h"

using namespace std;

class tiro: public entidade{
	
	public:
		
		tiro(int,int);
		
		void update_y(int);
		void set_ativo(int);	
		
		int get_ativo()const;
		
	private:
		int ativo;
		
};

#endif
