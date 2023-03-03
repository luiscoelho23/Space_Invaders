#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "scoreboard.h"

using namespace std;

void troca_numero(int *xnumero, int *ynumero)  //troca posição dos numeros
{  
    int temp_num = *xnumero;  
    *xnumero = *ynumero;  
    *ynumero = temp_num;  
}  

void troca_nome(string *xnome, string *ynome){   //troca posição dos nomes
	string temp_nome = *xnome;
	*xnome = *ynome;
	*ynome = temp_nome;
}

void scoreboard::ordena_scores(){
	int a, j;  
    for (a = 0; a < score.size(); a++)      
	    for (j = 0; j < score.size()-a-1; j++)  
	        if (score[j] > score[j+1]){ 
	            troca_numero(&score[j], &score[j+1]);  //bubble sort dos numeros
 				troca_nome(&nomes[j], &nomes[j+1]);  
 			}		
}

int scoreboard::abre_scores(){
	
	string line;
    int i = 0;
    ifstream file;
	file.open("score.txt");

    if(!file) 
    {
        cerr<<"Erro a abrir o ficheiro"<<endl;
        
        return -1;
    }
	
	 while(!file.eof())
    {
    	getline(file,line);
    	int temp = 0;
			if(i%2==0){ 
				nomes.push_back(line);
			}
			if(i%2!=0){ 								
				stringstream(line)>>temp;	
				score.push_back(temp);		
    		
			}

    	++i;
    }	
	file.close();
}

void scoreboard::novo_jogador(string new_nome,int new_score){ //nova pontuação          
	
	fstream file("score.txt",ios::app);
	file<<new_nome<<endl<<new_score<<endl;
	file.close();
}

void scoreboard::mostra_score(){   //imprime no ecra os recordes
	nomes.clear();
	score.clear();
	abre_scores();
	ordena_scores();
	system("cls");
	cout<<"========== R E C O R D E S =========="<<endl;
	cout<<endl;
	for( int i=score.size()-1;i>score.size()-6;i--){
		cout<<"Nome: "<<nomes[i]<<endl;
		cout<<"Score--> "<<score[i]<<endl;
		cout<<endl;	
		}
	
}
