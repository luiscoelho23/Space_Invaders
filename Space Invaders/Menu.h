#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include "Run.h"
#include "scoreboard.h" 

using namespace std;

class Menu{
	public:
		
		Menu();
		Menu(int);
		
		int getIdioma();
		void Escolha(int, int);
		int getCursor();
		void Configuracoes (int);
		int getNovoJogo();
		void PosicaoJogoCor (int);
		
		void Inimigo(int);
		void Nave(int);
		void Arrow(int,int);
		void detalhes(int);
		void set_info1();
		void set_info2();
		
		int printMenu();

	protected:	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		scoreboard s;
		int corJogo;
		int position;
		int position1;
		int keypressed;
		char nave=206;
		char ini=207;
		
};

#endif

