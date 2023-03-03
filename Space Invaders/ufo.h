#ifndef UFO_H
#define UFO_H

#include <iostream>
#include "entidade.h"

using namespace std;

class ufo:public entidade{
	public:
		ufo();
		
		void set_vivo();
		void set_morto();
		void update_y();
		
		int get_vivo()const;

	private:
		int vivo;	 
		
};

#endif
