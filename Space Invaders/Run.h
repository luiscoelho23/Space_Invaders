#ifndef RUN_H
#define RUN_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "hero.h"
#include "escudo.h"
#include "Boss.h"
#include "ufo.h"
#include "tiro.h"
#include "tiroini.h"
#include "inimigos.h"
#include "scoreboard.h"


using namespace std;

class Run{
		public:
	
		Run(int=0,int=0,hero=hero("",0,0,0,0,0));
		
		void RunGame();
		
		void set_corJogo(int);
		void set_hero(int);
		void set_ini(int); 
		
		void gotoxy(int,int);

		void set_gamestate(int);
		void set_resultado(int);
		
		int get_resultado()const;
		int get_gamestate()const;
		
		void CreateGame();
		void updategame();
		void rendergame();
		void nextstate();
		void reset();
			
	private:
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		vector<tiro> tiros;
		vector<inimigos> vinimigos; 
		vector<tiroini> tirosini;
		hero hero1;
		ufo ufo1;
		escudo escudo1;
		Boss boss1;
		char ufoc='O';
		char parede=219;
		char heroc;
		char inimigo;
		int corJogo,gameover;
		int xi,xf,yi,yf,movyi,direcao,jaandou,counterinimigos,random;
		int is,fs,xfs;
		scoreboard s;
		int counter,velocidade,nivel;
		int gamestate,resultado;
};

#endif
