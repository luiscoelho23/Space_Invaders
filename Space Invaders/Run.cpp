#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Run.h"
#include "ufo.h"
#include "Boss.h"
#include "Menu.h"
#include "scoreboard.h"
#include "inimigos.h"
#include "hero.h"


using namespace std;

Run::Run(int counter,int nivel,hero hero1){//construtor que literalmente constroi o jogo 
	
	if(nivel==4){
		boss1.set_vivo();
	}
	this->gameover=0;
	this->nivel=nivel;
	this->counterinimigos=0;
	this->jaandou=0;
	this->direcao=1;
	this->is=0;
	this->fs=0;	
	this->xfs=0;
	this->xi=1+nivel;
	this->yi=5;
	this->xf=xi+5;
	this->yf=yi+11;
	this->movyi=2;
	this->counter=counter;
	this->velocidade=10;
	this->hero1.set_hero(hero1.get_nome(),hero1.get_x(),hero1.get_y(),hero1.get_vidas(),hero1.get_boosts(),hero1.get_pontos());
	
	if(nivel<4){
		for(int i=0;i<11;i++){
			for(int j=0;j<5;j++){
				if(j%2==0&&i%2==0){
					vinimigos.push_back(inimigos(i,j));
				}
			}
		}	
	}
	for(int i=1;i<16;i++){
		for(int j=1;j<30;j++){
			if(j==1||j==29){
			gotoxy(j,i);
			cout<<219;
			}
		}
	}
}

void Run::gotoxy(int x,int y){//forma de renderizaçao atraves da posiçao do cursor
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void Run::CreateGame(){//metodo que complemeta o construtor
	if(nivel==4){
		boss1.set_vivo();
	}
	this->gameover=0;
	this->nivel=nivel;
	this->counterinimigos=0;
	this->jaandou=0;
	this->direcao=1;
	this->is=0;
	this->fs=0;	
	this->xi=2+nivel;
	this->yi=5;
	this->xf=xi+3;
	this->yf=yi+11;
	this->movyi=0;
	this->counter=counter;
	this->velocidade=10;
	this->hero1.set_hero(hero1.get_nome(),hero1.get_x(),hero1.get_y(),hero1.get_vidas(),hero1.get_boosts(),hero1.get_pontos());
	if(nivel<4){
		for(int i=0;i<11;i++){
			for(int j=0;j<5;j++){
				if(j%2==0&&i%2==0){
					vinimigos.push_back(inimigos(i,j));
				}
			}
		}	
	}
	SetConsoleTextAttribute(hConsole, corJogo);
	for(int i=1;i<16;i++){
		for(int j=1;j<30;j++){
			if(j==1||j==29){
			gotoxy(j,i);
			cout<<parede;
			}
		}
	}
		gotoxy(33,10);
		cout<<"_";
		gotoxy(34,11);
		cout<<"|";
		gotoxy(34,12);
		cout<<"|";
		gotoxy(34,13);
		cout<<"|";
		gotoxy(34,14);
		cout<<"|";
		gotoxy(34,15);
		cout<<"|";
		gotoxy(32,11);
		cout<<"|";
		gotoxy(32,12);
		cout<<"|";
		gotoxy(32,13);
		cout<<"|";
		gotoxy(32,14);
		cout<<"|";
		gotoxy(32,15);
		cout<<"|";
	SetConsoleTextAttribute(hConsole, 15);
}
//metodo que finalmente implementa a cor no jogo
void Run::set_corJogo(int a){
	this->corJogo=a;
}
//metodo que finalmente implementa o char hero no jogo
void Run::set_hero(int a) {
	this->heroc=a;
}
//metodo que finalmente implementa o char inimigo no jogo
void Run::set_ini(int a){
    this->inimigo=a;
}
//metodo que faz todo o jogo funcionar
void Run::RunGame(){
	system("cls");
	tiros.clear();
	vinimigos.clear();
	tirosini.clear();
	this->gamestate=1;
	CreateGame();
	while(gamestate==1){//estados do jogo
		updategame();
		nextstate();
		rendergame();
	}	
	
	ofstream temp;
	temp.open("temp.txt");
	
	if(gamestate==-1){//quando o jogo acaba
		if(resultado==1 && nivel==4){//caso de vitoria nivel 4
			hero1.update_pontos(-(counter*3));
			hero1.update_pontos(hero1.get_vidas()*250);
			hero1.update_pontos(hero1.get_boosts()*100);
			s.novo_jogador(hero1.get_nome(),hero1.get_pontos());
			system("cls");
			Sleep(500);
			SetConsoleTextAttribute(hConsole, 6);
			cout<<"\n\n\n\n\n\t  YOU WON\n";
			cout<<"\n\n\tPontos:"<<hero1.get_pontos()<<endl<<endl<<"  ";
			PlaySound("Sounds/win.wav",NULL,SND_SYNC);
			system("pause");
		}
		if(resultado==1 && nivel==3){//caso de vitoria nivel 3
			nivel++;
			temp<<counter<<endl<<nivel<<endl<<hero1.get_nome()<<endl<<hero1.get_x()<<endl<<hero1.get_y()
			<<endl<<hero1.get_vidas()<<endl<<hero1.get_boosts()<<endl<<hero1.get_pontos();
			ufo1.set_vivo();
			system("cls");
			SetConsoleTextAttribute(hConsole, corJogo);
			cout<<"\n\n\n\n\n\n\tFINAL LEVEL";
			PlaySound("Sounds/lvl3-4.wav",NULL,SND_SYNC);
			system("cls");
			RunGame();
		}
		if(resultado==1 && nivel<3){//caso de vitoria nivel 1-2
			temp<<counter<<endl<<nivel<<endl<<hero1.get_nome()<<endl<<hero1.get_x()<<endl<<hero1.get_y()
			<<endl<<hero1.get_vidas()<<endl<<hero1.get_boosts()<<endl<<hero1.get_pontos();
			system("cls");
			nivel++;
			SetConsoleTextAttribute(hConsole, corJogo);
			if(nivel==2){
				cout<<"\n\n\n\n\n\n\tLEVEL 2";
			}
			if(nivel==3){
				cout<<"\n\n\n\n\n\n\tLEVEL 3";
			}
			PlaySound("Sounds/levelup.wav",NULL,SND_SYNC);
			Sleep(1000);
			system("cls");
			RunGame();
		}
		if(resultado==-1){//caso de derrota
			if(gameover==0){
			gameover=1;
			boss1.set_morto();
			hero1.update_pontos(-counter);
			hero1.update_pontos(hero1.get_boosts()*100);
			SetConsoleTextAttribute(hConsole, corJogo);
			system("cls");
			cout<<"\n\n\n\n\n\n\t GAME OVER\n\n";
			cout<<"\tPontos:"<<hero1.get_pontos()<<endl<<endl<<" ";
			PlaySound("Sounds/gameover.wav",NULL,SND_SYNC);
			system("pause");
			system("cls");
			s.novo_jogador(hero1.get_nome(),hero1.get_pontos());
			}
		}
	}else if(resultado==0){//caso de jogo pausado
			system("cls");
			SetConsoleTextAttribute(hConsole, corJogo);
			cout<<"\n\n\n\n\n\n\tGAME PAUSED";
			Sleep(2000);
			system("cls");
		if(nivel==4){
			cout<<"\n\n\n\n\n\t Does Not Save.";
			Sleep(1000);
			}else{	
			temp<<counter<<endl<<nivel<<endl<<hero1.get_nome()<<endl<<hero1.get_x()<<endl<<hero1.get_y()
			<<endl<<hero1.get_vidas()<<endl<<hero1.get_boosts()<<endl<<hero1.get_pontos();
		}
	}
	temp.close();
}

void Run::set_gamestate(int a){
	this->gamestate=a;
}

void Run::set_resultado(int a){
	this->resultado=a;
}

int Run::get_gamestate()const{
	return this->gamestate;
}

int Run::get_resultado()const{
	return this->resultado;
}
//metddo que dá reset a algumas posiçoes  xy do jogo
void Run::reset(){
	this->jaandou=0;
	this->counterinimigos=0;
	for(int i=2;i<29;i++){
			gotoxy(i,1);
			cout<<" ";
	}
	for(int i=2;i<29;i++){
			gotoxy(i,16);
			cout<<" ";
	}
	if(counter%3==0){
		gotoxy(2,2);
		cout<<" ";
	}
	SetConsoleTextAttribute(hConsole, corJogo);
	gotoxy(29,2);
	cout<<parede;
	SetConsoleTextAttribute(hConsole, 15);
}
//metodo que contem toda a logica do movimneto do jogo
void Run::updategame(){
	reset();	
	counter++;
	hero1.update_shot();
	counterinimigos=0;
	if(counter%3==0){		//atualiza a posição dos tiros dos inimigos
		for(int i=0;i<tirosini.size();i++){
			if(tirosini[i].get_ativo()){
				gotoxy(tirosini[i].get_x(),tirosini[i].get_y()-1);
				cout<<" ";
				gotoxy(tirosini[i].get_x(),tirosini[i].get_y());
				cout<<".";	
				tirosini[i].update_y(1);	
			}	
		}
	}
	for(int i=2;i<29;i++){//limpa a ultima linha do mapa do jogo devido aos tirosdos inimigos
		gotoxy(i,16);
		cout<<" ";
	}					
	for(int i=0;i<tiros.size();i++){
		if(tiros[i].get_ativo()){	//atualiza a posição dos tiros do hero
			gotoxy(tiros[i].get_x(),tiros[i].get_y()+1);
			cout<<" ";
			gotoxy(tiros[i].get_x(),tiros[i].get_y());
			cout<<"^";	
			tiros[i].update_y(1);	
		}	
	}
	if(counter%150==0 && ufo1.get_vivo()==0){//revive o ufo
		ufo1.set_vivo();
	}
	if(ufo1.get_vivo()==1){//atualiza a posição do ufo
		gotoxy(ufo1.get_y(),ufo1.get_x());
		cout<<ufoc;
		if(ufo1.get_y()<28){
		gotoxy(ufo1.get_y()+1,ufo1.get_x());
		cout<<" ";
		}
		gotoxy(ufo1.get_y(),ufo1.get_x());
		cout<<ufoc;
		if(counter%3==0){
			ufo1.update_y();
		}
	}
	
	for(int i=0;i<tiros.size();i++){//atualiza informaçoes e verifica se os tiros acertaram no ufo
			if(tiros[i].get_ativo()){	
				if(ufo1.get_vivo()){
					if(ufo1.get_x()==tiros[i].get_y()){
						if(ufo1.get_y()==tiros[i].get_x()){
							tiros[i].set_ativo(0);
							ufo1.set_morto();
							hero1.update_vidas(-1);
							hero1.update_boosts(3);
							hero1.update_pontos(500);
							for(int i=2;i<29;i++){
								for(int j=2;j<4;j++){
									gotoxy(i,j);
									cout<<" ";
								}
							}		
						}
						if(ufo1.get_y()==tiros[i].get_x()+1){
							tiros[i].set_ativo(0);
							hero1.update_vidas(-1);
							ufo1.set_morto();
							hero1.update_boosts(3);
							hero1.update_pontos(500);
							for(int i=2;i<29;i++){
								for(int j=2;j<4;j++){
									gotoxy(i,j);
									cout<<" ";
								}
							}		
						}
					}
				}	
			}	
		}	
	
	for(int i=0;i<16;i++){//faz com que os inimigos possam disparar
		random=rand()%200;
		for(int j=i;j<i+3;j++){
			if(j==i&&!vinimigos[j+1].get_morto()&&!vinimigos[j+2].get_morto()&&vinimigos[j].get_morto()&&random<7){
				vinimigos[j].enable_shots(1);
			}
			if(!vinimigos[j+1].get_morto()&&vinimigos[j].get_morto()&&random<7){
				vinimigos[j].enable_shots(1);
			} 
			if(i==j-2&&vinimigos[j].get_morto()&&random<7){
				vinimigos[j].enable_shots(1);
			}
			if(nivel==4&&random<14){
				tirosini.push_back(tiroini(boss1.get_y()-1,boss1.get_x()+2));
				tirosini.push_back(tiroini(boss1.get_y(),boss1.get_x()+2));
				tirosini.push_back(tiroini(boss1.get_y()+1,boss1.get_x()+2));
			}   
		}
		i+=2;
	}
	
	for(int i= 0;i<tiros.size();i++){//atualiza informaçoes e verifica se os tiros acertaram nos tiros inimigos
		if(tiros[i].get_ativo()){
			for(int j=0;j<tirosini.size();j++){
				if(tirosini[j].get_ativo()){
					if(tirosini[j].get_x()==tiros[i].get_x()){
						if(tirosini[j].get_y()==tiros[i].get_y()-1){
							tirosini[j].set_ativo(0);
							tiros[i].set_ativo(0);
							gotoxy(tirosini[j].get_x(),tirosini[j].get_y()-1);
							cout<<" ";
							gotoxy(tirosini[j].get_x(),tirosini[j].get_y()+2);
							cout<<" ";
						}
						if(tirosini[j].get_y()==tiros[i].get_y()){
							gotoxy(tirosini[j].get_x(),tirosini[j].get_y()-1);
							cout<<" ";
							gotoxy(tirosini[j].get_x(),tirosini[j].get_y()+1);
							cout<<" ";							
							tirosini[j].set_ativo(0);
							tiros[i].set_ativo(0);
						}
					}
				}
			}
		}
	}
	if(nivel==4){	//atualiza informaçoes e verifica se os tiros acertaram no boss
		for(int i=0;i<tiros.size();i++){
			if(tiros[i].get_ativo()){
				if(tiros[i].get_x()==boss1.get_y()-1 && tiros[i].get_y()==boss1.get_x()-2){
					tiros[i].set_ativo(0);
					gotoxy(tiros[i].get_y(),tiros[i].get_x());
					cout<<" ";
					boss1.update_vida(-250);
					hero1.update_pontos(250);
				}
				if(tiros[i].get_x()==boss1.get_y() && tiros[i].get_y()==boss1.get_x()-2){
					tiros[i].set_ativo(0);
					gotoxy(tiros[i].get_y(),tiros[i].get_x());
					cout<<" ";
					boss1.update_vida(-250);
					hero1.update_pontos(250);
				}
				if(tiros[i].get_x()==boss1.get_y()+1 && tiros[i].get_y()==boss1.get_x()-2){
					tiros[i].set_ativo(0);
					gotoxy(tiros[i].get_y(),tiros[i].get_x());
					cout<<" ";
					boss1.update_vida(-250);
					hero1.update_pontos(250);
				}
			}
		}
	}
	for(int i=0;i<tirosini.size();i++){//atualiza informaçoes e verifica se os tiros inimigos acertaram no hero
		if(tirosini[i].get_ativo()){
			if(tirosini[i].get_y()==hero1.get_y()&&tirosini[i].get_x()==hero1.get_x()){
				tirosini[i].set_ativo(0);
				if(escudo1.get_ativo()){
					escudo1.set_ativo(0);
				}else hero1.update_vidas(1);
				gotoxy(hero1.get_x(),14);
				cout<<" ";
			}
		}
	}
		
	for(int i=0;i<tiros.size();i++){//atualiza informaçoes e verifica se os tiros acertaram nos inimigos
		if(tiros[i].get_ativo()){
			for(int j=0;j<vinimigos.size();j++){
				if(vinimigos[j].get_morto() && yi+vinimigos[j].get_x()+movyi == tiros[i].get_x() && xi+vinimigos[j].get_y()==tiros[i].get_y()+1){
					hero1.update_pontos(250);
					tiros[i].set_ativo(0);
					vinimigos[j].set_morto();	
					for(int i1=2;i1<29;i1++){
						for(int j1=3;j1<14;j1++){
						gotoxy(i1,j1);
						cout<<" ";
						}
					}
				}
				if(direcao==1&&vinimigos[j].get_morto() && yi+vinimigos[j].get_x()+1+movyi == tiros[i].get_x() && xi+vinimigos[j].get_y()==tiros[i].get_y()+1){
					tiros[i].set_ativo(0);
					hero1.update_pontos(250);
					vinimigos[j].set_morto();
					for(int i1=2;i1<29;i1++){
						for(int j1=3;j1<14;j1++){
						gotoxy(i1,j1);
						cout<<" ";
						}
					}
					
				}
				if(direcao==-1&&vinimigos[j].get_morto() && yi+vinimigos[j].get_x()-1+movyi == tiros[i].get_x() && xi+vinimigos[j].get_y()==tiros[i].get_y()+1){
					tiros[i].set_ativo(0);
					hero1.update_pontos(250);
					vinimigos[j].set_morto();
					for(int i=2;i<29;i++){
						for(int j=3;j<14;j++){
						gotoxy(i,j);
						cout<<" ";
						}
					}
				}
			}
		}
	}
	for(int i=0;i<vinimigos.size();i++){//atualiza o mapa de jogo e coloca os inimigos no mesmo
		if(vinimigos[i].get_morto()==1){
			gotoxy(vinimigos[i].get_x()+yi+movyi,vinimigos[i].get_y()+xi);
			cout<<" ";			
		
			gotoxy(vinimigos[i].get_x()+yi+movyi,vinimigos[i].get_y()+xi);
			cout<<inimigo;
			
			gotoxy(vinimigos[i].get_x()+yi+movyi,vinimigos[i].get_y()+xi-1);
			cout<<" ";

			if(yi>2){
			gotoxy(vinimigos[i].get_x()+yi-1+movyi,vinimigos[i].get_y()+xi);
			cout<<" ";
			}
			if(yf<29){
			gotoxy(vinimigos[i].get_x()+yi+1+movyi,vinimigos[i].get_y()+xi);
			cout<<" ";
			}
		}
		if(vinimigos[i].get_enable_shots()){//cria os tiros inimigos
			tirosini.push_back(tiroini(vinimigos[i].get_x()+yi+movyi,vinimigos[i].get_y()+xi+1));
			vinimigos[i].enable_shots(0);
		}
	}
	//atualiza o limite do movimento dos inimigos
	if(!vinimigos[0].get_morto()&&!vinimigos[1].get_morto()&&!vinimigos[2].get_morto()&&!vinimigos[3].get_morto()&&!vinimigos[4].get_morto()&&
		!vinimigos[5].get_morto()&&!vinimigos[6].get_morto()&&!vinimigos[7].get_morto()&&!vinimigos[8].get_morto()&&!vinimigos[9].get_morto()&&
		!vinimigos[10].get_morto()&&!vinimigos[11].get_morto()&&!vinimigos[12].get_morto()&&!vinimigos[13].get_morto()&&!vinimigos[14].get_morto()&&is<5){
		yi+=2;
		movyi-=2;
		is++;
		}else if(!vinimigos[0].get_morto()&&!vinimigos[1].get_morto()&&!vinimigos[2].get_morto()&&!vinimigos[3].get_morto()&&
		!vinimigos[4].get_morto()&&!vinimigos[5].get_morto()&&!vinimigos[6].get_morto()&&!vinimigos[7].get_morto()&&
		!vinimigos[8].get_morto()&&!vinimigos[9].get_morto()&&!vinimigos[10].get_morto()&&!vinimigos[11].get_morto()&&is<4){
		movyi-=2;
		yi+=2;
		is++;
		}else if(!vinimigos[0].get_morto()&&!vinimigos[1].get_morto()&&!vinimigos[2].get_morto()&&!vinimigos[3].get_morto()&&
		!vinimigos[4].get_morto()&&!vinimigos[5].get_morto()&&!vinimigos[6].get_morto()&&!vinimigos[7].get_morto()&&!vinimigos[8].get_morto()&&is<3){
		movyi-=2;
		yi+=2;
		is++;
		}else if(!vinimigos[0].get_morto()&&!vinimigos[1].get_morto()&&!vinimigos[2].get_morto()&&
		!vinimigos[3].get_morto()&&!vinimigos[4].get_morto()&&!vinimigos[5].get_morto()&&is<2){
		movyi-=2;
		yi+=2;
		is++;
		}else if(!vinimigos[0].get_morto()&&!vinimigos[1].get_morto()&&!vinimigos[2].get_morto()&&is<1){
		movyi-=2;
		yi+=2;
		is++;
		}
		
		if(!vinimigos[1].get_morto()&&!vinimigos[4].get_morto()&&!vinimigos[7].get_morto()&&
		!vinimigos[10].get_morto()&&!vinimigos[13].get_morto()&&!vinimigos[16].get_morto()&&!vinimigos[2].get_morto()&&!vinimigos[5].get_morto()&&!vinimigos[8].get_morto()&&
		!vinimigos[11].get_morto()&&!vinimigos[14].get_morto()&&!vinimigos[17].get_morto()&&xfs<2){
			xf-=2;
			xfs++;
		}else	if(!vinimigos[2].get_morto()&&!vinimigos[5].get_morto()&&!vinimigos[8].get_morto()&&
		!vinimigos[11].get_morto()&&!vinimigos[14].get_morto()&&!vinimigos[17].get_morto()&&xfs<1){
			xf-=2;
			xfs++;
		}
		
	//atualiza o limite do movimento dos inimigos	
	if(!vinimigos[3].get_morto()&&!vinimigos[4].get_morto()&&!vinimigos[5].get_morto()&&!vinimigos[6].get_morto()&&!vinimigos[7].get_morto()&&
		!vinimigos[8].get_morto()&&!vinimigos[9].get_morto()&&!vinimigos[10].get_morto()&&!vinimigos[11].get_morto()&&!vinimigos[12].get_morto()&&
		!vinimigos[13].get_morto()&&!vinimigos[14].get_morto()&&!vinimigos[15].get_morto()&&!vinimigos[16].get_morto()&&!vinimigos[17].get_morto()&&fs<5){
		yf-=2;
		fs++;
	}else if(!vinimigos[6].get_morto()&&!vinimigos[7].get_morto()&&!vinimigos[8].get_morto()&&!vinimigos[9].get_morto()&&
		!vinimigos[10].get_morto()&&!vinimigos[11].get_morto()&&!vinimigos[12].get_morto()&&!vinimigos[13].get_morto()&&
		!vinimigos[14].get_morto()&&!vinimigos[15].get_morto()&&!vinimigos[16].get_morto()&&!vinimigos[17].get_morto()&&fs<4){
		yf-=2;
		fs++;
	}else if(!vinimigos[9].get_morto()&&!vinimigos[10].get_morto()&&!vinimigos[11].get_morto()&&!vinimigos[12].get_morto()&&
		!vinimigos[13].get_morto()&&!vinimigos[14].get_morto()&&!vinimigos[15].get_morto()&&!vinimigos[16].get_morto()&&!vinimigos[17].get_morto()&&fs<3){
		yf-=2;
		fs++;
	}else if(!vinimigos[12].get_morto()&&!vinimigos[13].get_morto()&&!vinimigos[14].get_morto()&&
		!vinimigos[15].get_morto()&&!vinimigos[16].get_morto()&&!vinimigos[17].get_morto()&&fs<2){
		yf-=2;
		fs++;
	}else if(!vinimigos[15].get_morto()&&!vinimigos[16].get_morto()&&!vinimigos[17].get_morto()&&fs<1){
		yf-=2;
		fs++;
		}
		
		if(nivel==4){//movimento do Boss
			if(counter%3==0){
				if(boss1.get_y()>25){
					direcao*=-1;
				}
				if(boss1.get_y()<5){
					direcao*=-1;
				}
				if(direcao==1){
					boss1.update_y(1);						
				}else {
					boss1.update_y(-1);
				}
			}
		}
		
		if(nivel<4){//movimento dos inimigos
			if(counter%(velocidade-nivel)==0){	
				if(yf<29&&direcao==1){
					jaandou=1;
					yi++;
					yf++;
					}else if(yi>2&&direcao==-1){
					jaandou=1;
					yi--;
					yf--;
				}else if(yi<=2){
						jaandou=1;
						xi++;
						xf++;
						direcao*=-1;
						}else if(yf>=29){
						jaandou=1;
						xi++;
						xf++;
						direcao*=-1;
					}
				}
			if(counter%(velocidade-nivel)==0 &&jaandou==0){ //para poder escostar ao fim da matriz
				if(yf<29&&direcao==1){
					yi++;
					yf++;
				}else if(yi>2&&direcao==-1){
					yi--;
					yf--;
				}
			}
			
		}
}
//metodo que dá informaçoes sobre o proximo frame
void Run::nextstate(){
	this->counterinimigos=0;
	
	for(int i=0;i<vinimigos.size();i++){
			if(vinimigos[i].get_morto()){
				counterinimigos++;
			}
	}
	if(counterinimigos<20){
		velocidade=9;
	}
	if(counterinimigos<10){
		velocidade=7;
	}
	if(counterinimigos<3){
		velocidade=5;
	}
	
	//condições de vitoria ou derrota
	if(xf>=14){
		set_gamestate(-1);
		set_resultado(-1);
	}

	if(hero1.get_vidas()<=0){
		set_gamestate(-1);
		set_resultado(-1);
	}
	if(counterinimigos==0 && boss1.get_vida()<=0 ){
		set_gamestate(-1);
		set_resultado(1);
	}
	//deteta a tecla primida pelo utilizador
	if(kbhit()){
		if((GetKeyState(VK_RIGHT) & 0x8000) && hero1.get_x()<28){
			hero1.update_x(1);
			if(hero1.get_x()>2){gotoxy(hero1.get_x()-1,hero1.get_y());
			cout<<" ";}
			if(hero1.get_x()>3){gotoxy(hero1.get_x()-2,hero1.get_y());
			cout<<" ";}
		}
		if((GetKeyState(VK_LEFT) & 0x8000) && hero1.get_x()>2){
			hero1.update_x(-1);
			if(hero1.get_x()<28){gotoxy(hero1.get_x()+1,hero1.get_y());
			cout<<" ";}
			if(hero1.get_x()<27){gotoxy(hero1.get_x()+2,hero1.get_y());
			cout<<" ";}
		}
		if((GetKeyState(VK_UP) & 0x8000)&& hero1.can_shot()){
			tiros.push_back(tiro(hero1.get_x(),hero1.get_y()-1));
		}
		if((GetKeyState('B') & 0x8000)&& hero1.get_boosts()>4){
			hero1.update_boosts(-5);
			if(hero1.get_x()<25){tiros.push_back(tiro(hero1.get_x()+3,hero1.get_y()-1));}
			if(hero1.get_x()<26){tiros.push_back(tiro(hero1.get_x()+2,hero1.get_y()-1));}
			if(hero1.get_x()<27){tiros.push_back(tiro(hero1.get_x()+1,hero1.get_y()-1));}
			tiros.push_back(tiro(hero1.get_x(),hero1.get_y()-1));
			if(hero1.get_x()>3){tiros.push_back(tiro(hero1.get_x()-1,hero1.get_y()-1));}
			if(hero1.get_x()>4){tiros.push_back(tiro(hero1.get_x()-2,hero1.get_y()-1));}
			if(hero1.get_x()>5){tiros.push_back(tiro(hero1.get_x()-3,hero1.get_y()-1));}
		}
		if(GetKeyState(VK_ESCAPE) & 0x8000){
			set_gamestate(0);
			set_resultado(0);
		}
		if((GetKeyState('C') & 0x8000)&& hero1.get_boosts()>1&&!escudo1.get_ativo()){
			escudo1.set_ativo(1);
			hero1.update_boosts(-2);
		}
	}
}
//dá render a parte do mapa de jogo sendo que parte é feita pelo metodo update
void Run::rendergame(){
		SetConsoleTextAttribute(hConsole, corJogo);
	if(nivel==4){
		gotoxy(boss1.get_y()-1,boss1.get_x()-1);cout<<"x";gotoxy(boss1.get_y(),boss1.get_x()-1);cout<<"_";gotoxy(boss1.get_y()+1,boss1.get_x()-1);cout<<"x";
		gotoxy(boss1.get_y()-1,boss1.get_x());cout<<"|";gotoxy(boss1.get_y(),boss1.get_x());cout<<"O";gotoxy(boss1.get_y()+1,boss1.get_x());cout<<"|";
		gotoxy(boss1.get_y()-1,boss1.get_x()+1);cout<<"x";gotoxy(boss1.get_y(),boss1.get_x()+1);cout<<"_";gotoxy(boss1.get_y()+1,boss1.get_x()+1);cout<<"x";
		if(direcao==1){
			gotoxy(boss1.get_y()-2,boss1.get_x()-1);
			cout<<" ";
			gotoxy(boss1.get_y()-2,boss1.get_x());
			cout<<" ";
			gotoxy(boss1.get_y()-2,boss1.get_x()+1);
			cout<<" ";				
			}else {
			gotoxy(boss1.get_y()+2,boss1.get_x()-1);
			cout<<" ";
			gotoxy(boss1.get_y()+2,boss1.get_x());
			cout<<" ";
			gotoxy(boss1.get_y()+2,boss1.get_x()+1);
			cout<<" ";
			}
	}
	if(escudo1.get_ativo()){
		if(hero1.get_x()>2){gotoxy(hero1.get_x()-1,hero1.get_y());
		cout<<"(";}
		if(hero1.get_x()<28){gotoxy(hero1.get_x()+1,hero1.get_y());
		cout<<")";}
	}
	gotoxy(hero1.get_x(),hero1.get_y());
	cout<<heroc;
	gotoxy(1,17);
	cout<<"Pontos:"<<hero1.get_pontos();
	gotoxy(15,17);
	cout<<"       ";
	gotoxy(15,17);
	if(nivel<4){
	cout<<nivel;
	}else cout<<boss1.get_vida();
	gotoxy(20,17);
	cout<<" Vidas:"<<hero1.get_vidas();
	gotoxy(31,2);
	cout<<"Boosts:";
	gotoxy(31,3);
	cout<<"   ";
	gotoxy(31,3);
	cout<<hero1.get_boosts();
	if(hero1.get_shot()==0){
		gotoxy(33,11);
		cout<<" ";
		gotoxy(33,12);
		cout<<" ";
		gotoxy(33,13);
		cout<<" ";
		gotoxy(33,14);
		cout<<" ";
		gotoxy(33,15);
		cout<<" ";
	}
	if(hero1.get_shot()==1){
		gotoxy(33,11);
		cout<<" ";
		gotoxy(33,12);
		cout<<" ";
		gotoxy(33,13);
		cout<<" ";
		gotoxy(33,14);
		cout<<" ";
		gotoxy(33,15);
		cout<<"+";
	}
	if(hero1.get_shot()==2){
		gotoxy(33,11);
		cout<<" ";
		gotoxy(33,12);
		cout<<" ";
		gotoxy(33,13);
		cout<<" ";
		gotoxy(33,14);
		cout<<"+";
		gotoxy(33,15);
		cout<<"+";
	}
	if(hero1.get_shot()==3){
		gotoxy(33,10);
		cout<<"_";
		gotoxy(33,11);
		cout<<" ";
		gotoxy(33,12);
		cout<<" ";
		gotoxy(33,13);
		cout<<"+";
		gotoxy(33,14);
		cout<<"+";
		gotoxy(33,15);
		cout<<"+";
	}
	if(hero1.get_shot()==4){
		gotoxy(33,11);
		cout<<" ";
		gotoxy(33,12);
		cout<<"+";
		gotoxy(33,13);
		cout<<"+";
		gotoxy(33,14);
		cout<<"+";
		gotoxy(33,15);
		cout<<"+";
	}
	if(hero1.get_shot()==5){
		gotoxy(33,11);
		cout<<"+";
		gotoxy(33,12);
		cout<<"+";
		gotoxy(33,13);
		cout<<"+";
		gotoxy(33,14);
		cout<<"+";
		gotoxy(33,15);
		cout<<"+";
	}
	SetConsoleTextAttribute(hConsole, 15);
	Sleep(25);
}
