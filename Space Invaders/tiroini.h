#ifndef TIROINI_H
#define TIROINI_H

#include <iostream>
#include "entidade.h"

class tiroini:public entidade{
	
	public:
		tiroini(int,int);
		
		void update_y(int);
		void set_ativo(int);	
		
		int get_ativo()const;
		
	private:
		int ativo;
};

#endif
