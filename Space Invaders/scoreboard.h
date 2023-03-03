#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>

using namespace std;

 class scoreboard{
 	
 	public:
 			
 		friend void troca_numero(int*,int*);
 		friend void troca_nome(string*,string*);
 		
 		int abre_scores();
 		void mostra_score();
 		void novo_jogador(string,int);
 		void ordena_scores();	
 		
 	private:
	    vector<string> nomes;
	    vector<int> score;
 			
 };
 

#endif

