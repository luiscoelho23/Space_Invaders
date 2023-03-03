#ifndef	ENTIDADE_H
#define ENTIDADE_H

#include <iostream>

using namespace std;

class entidade{//class pai de quase todas as estruturas "classes"
	public:
		
		void set_x(int);
		void set_y(int);
		
		int get_x()const;
		int get_y()const;
		
	protected:
	
		 int x,y;
		
};

#endif
