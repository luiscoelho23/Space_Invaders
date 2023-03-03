#include "Menu.h"
#include "Run.h"
#include "hero.h"

#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Menu::Menu(){
	this->corJogo=4;
	this->keypressed=0;
	this->position=0;
	this->position1=1;
}

Menu::Menu(int a){
	this->corJogo=a;
	this->keypressed=0;
	this->position=0;
	this->position1=1;
}

void Menu::detalhes(int position1){//Cout dos detalhes
	position=1;
	system("cls");
	keypressed=0;
	cout << "\tComandos:" << endl << endl;
	SetConsoleTextAttribute(hConsole, 15);
	int key=0;
	if(position1==1){
	cout << " ESC: para sair"<< endl << endl;
	cout << " Disparar:SETA CIMA" << endl << endl;
	cout << " Escudo: C" << endl << endl;
	cout << " TiroBOOST: B" << endl << endl;
	cout << " Esquerda:SETA DIREITA" << endl << endl;
	cout << " Direita:SETA ESQUERDA" << endl << endl << endl;
	SetConsoleTextAttribute(hConsole, corJogo);
	cout << "\tJogo Desenvolvido por:\n\n" ;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "->Joao Silva-91962\n\n";
	cout << "->Joao Oliveira-91926\n\n";
	cout << "->Luis Coelho-91973\n\n";
	cout << "->Luis Varajao-91976\n\n";
	cout << "->Marcos Novo-91979\n\n";
	
	
	}else{ 
	cout << " ESC para salir"<< endl << endl;
	cout << " Disparar:FLECHA CIMA" << endl << endl;
	cout << " Escudo: C" << endl << endl;
	cout << " TiroBOOST: B" << endl << endl;
	cout << " Izquierda:FLECHA IZQUIERDA" << endl << endl;
	cout << " Direcha:FLECHA DIRECHA" << endl << endl << endl;
	SetConsoleTextAttribute(hConsole, corJogo);
	cout << "\t\tJuego Desarrollado por:\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "->Joao Silva-91962\n\n";
	cout << "->Joao Oliveira-91926\n\n";
	cout << "->Luis Coelho-91973\n\n";
	cout << "->Luis Varajao-91976\n\n";
	cout << "->Marcos Novo-91979\n\n";
	}
	
	while(key==0){
		 if(GetKeyState(VK_ESCAPE) & 0x8000) { key=1;}
	}
}
//metodo fundamental para movimeto do cursor em todos os menus
void Menu::Arrow ( int realPosition, int arrowPosition) {
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(realPosition == arrowPosition)
	{
		if(realPosition == 6)
		{
			SetConsoleTextAttribute(hConsole, 6);
		}
		else{
		SetConsoleTextAttribute(hConsole, corJogo);
		}
		
		cout << "    -->";
	}else{
		if(realPosition==6)
		{
			SetConsoleTextAttribute(hConsole, 0);
		}else SetConsoleTextAttribute(hConsole, 15); 
		cout << "     ";
		}
}

int Menu::getIdioma() {//metodo para definir um idioma
	
	position=1;
	system("cls");
	keypressed=0;
	while(keypressed!=13)
	{
		Sleep(105);
		system("cls");
		cout << endl << endl << endl;
		Arrow(1,position1); cout << "\t||Portugues||" << endl << endl ;
		Arrow(2,position1); cout << "\t||Espanhol||" << endl ;
		getCursor();
		if( keypressed == 80 && position1 !=2){//logica que complementa o metodo arrow
		position1++;
		}else if(keypressed == 72 && position1 !=1){
		position1--;
		}else position1=position1;	
		
		if(keypressed==13){
		}else this->keypressed=0;
		
	}
	SetConsoleTextAttribute(hConsole, corJogo);
	return position1;
		
}
//metodo para selecionar o que fazer dentro do jogo
void Menu::Escolha(int position1, int corJogo){
	position=1;
	system("cls");
	keypressed=0;
      
	while (keypressed != 13){
	    
		system("cls");
		SetConsoleTextAttribute(hConsole, corJogo);
		cout << "\n\t\tSPACE INVADERS";
	    SetConsoleTextAttribute(hConsole, corJogo);
		cout << endl << endl << endl;
	    Arrow(1,position);if(position1==1){ cout << "||Novo Jogo||" << endl;
		}else cout << "||Nuevo Juego||" << endl;
		cout << endl;
	    Arrow(2,position); if(position1==1){ cout << "||Carregar Jogo||" << endl;
		}else cout << "||Cargar Juego||" << endl;
		cout << endl;
	    Arrow(3,position); cout << "||Scores||" << endl;
		cout << endl;
		Arrow(4,position); if(position1==1){ cout << "||Configuracoes e Detalhes||" << endl;
		}else cout << "||Ajustes y Detalles||" << endl;
		cout << endl;
	    Arrow(5,position); cout << "||Exit||" << endl << endl;
		Arrow(6,position); cout << "||YOU FOUND ME||" << endl;
		getCursor();
		if(keypressed == 80 && position != 6){//logica que complementa o metodo arrow
			++position;
		}else position=position;
		if(keypressed == 72 && position != 1){
			--position;
		}
		if(keypressed==13){
			keypressed=13;
		}else this->keypressed=0;
		Sleep(105);
	}
	SetConsoleTextAttribute(hConsole, corJogo);
}
//metodo que nos da acesso ás configuraçoes dentro do jogo e nos dá acesso aos detalhes
void Menu::Configuracoes (int position1){
	system("cls");
	keypressed=0;
	position=1;
	
	while(keypressed!=13&&keypressed!=27){
		system("cls");
		cout<<("\n\n\n\t");
		Arrow(1,position);
		if(position1==1) { cout << "||Cores do Jogo||" << endl;
		}else cout << "||Colores del Juego||" << endl;
		cout<<("\n\t");
		Arrow(2,position);if(position1==1) { cout << "||Detalhes||" << endl;
		}else cout << "||Detalles||" << endl;
		cout<<("\n\t");
        Arrow(3,position);if(position1==1) { cout << "||Hero||" << endl;
        }else cout << "||Herroe||" << endl;
        cout<<("\n\t");
        Arrow(4,position);if(position1==1) { cout << "||Inimigo||" << endl;
        }else cout << "||Enemigo||" << endl;
		
		getCursor();
			
		if(keypressed == 80 && position != 4){//logica que complementa o metodo arrow
			++position;
		}else position=position;
		if(keypressed == 72 && position != 1){
			--position;
		}
		if(keypressed==27){
			keypressed=27;
		}
		if(keypressed==13){
			keypressed=13;
		}else if(keypressed==27){
			keypressed=27;
		}else this->keypressed=0;
	Sleep(105);
	}
	SetConsoleTextAttribute(hConsole, corJogo);
	if(keypressed==27){
		position=0;
	}
}
// metodo que nos primite definir uma cor para o nosso jogo inteiro
void Menu::PosicaoJogoCor (int position1){
	int cor=corJogo;
	position=1;
	system("cls");
	keypressed=0;
	while(keypressed!=13&&keypressed!=27){	
			system("cls");
			cout<<"\n\n\n\t";
		    Arrow(1,position);	cout << "||Azul||" << endl;
			cout<<"\n\t";
		    Arrow(2,position);	cout << "||Verde||" << endl;
			cout<<"\n\t";
		    Arrow(3,position);
			if(position1==2) {	cout << "||Rojo||" << endl;
			}else cout << "||Vermelho||" << endl;
		    cout<<"\n\t";
			Arrow(4,position);
			if(position1==1) {	cout << "||Roxo||" << endl;
			}else cout << "||Morado||" << endl;
			cout<<"\n\t";
		    Arrow(5,position);
			if(position1==2) {	cout << "||Amarillo||" << endl;
			}else cout << "||Amarelo||" << endl;
			cout<<"\n\t";
			getCursor();
			if(keypressed == 80 && position != 5){//logica que complementa o metodo arrow
			++position;
		}else position=position;
		if(keypressed == 72 && position != 1){
			--position;
		}
		if(keypressed==13){
			keypressed=13;
		}else if(keypressed==27){
			keypressed=27;
		}else this->keypressed=0;
	Sleep(105);
	}
	if(keypressed==13){//parte da implementaçao da cor no jogo
		switch(position){
			case 1:{
				cor=1;
				
				break;
			}
			case 2:{
				cor=2;
				break;
			}
			case 3:{
				cor=4;
				break;
			}
			case 4:{
				cor=5;
				break;
			}
			case 5:{
				cor=14;
				break;
			}
		}
	}
	this->corJogo=cor;
}
//metodo que nos deixa alterar o char dos inimigos
void Menu::Inimigo(int position1){
    char inimigo1=207;
    char inimigo2=248;
    char inimigo3=208;
    char inimigo4=231;
    position=1;
    system("cls");
    keypressed=0;
    while(keypressed!=13 && keypressed!=27){
        system("cls");
        cout<<"\n\n\n\t";
        Arrow(1,position);
        cout << "|| " <<inimigo1<< " ||" << endl;
        cout<<"\n\t";
        Arrow(2,position);
        cout << "|| " <<inimigo2<< " ||" << endl;
        cout<<"\n\t";
        Arrow(3,position);
        cout << "|| " <<inimigo3<< " ||" << endl;
        cout<<"\n\t";
        Arrow(4,position);
        cout << "|| " <<inimigo4<< " ||" << endl;
        cout<<"\n\t";
        getCursor();
        if(keypressed == 80 && position != 4){//logica que complementa o metodo arrow
        ++position;
        }else position=position;
        if(keypressed == 72 && position != 1){
            --position;
        }
        if(keypressed==13){
            keypressed=13;
        }else if(keypressed==27){
            keypressed=27;
        }else this->keypressed=0;
    Sleep(105);
    }
    if(keypressed==13){//parte da implementacao do char
        switch(position){
            case 1:{
                ini=inimigo1;
                break;
            }
            case 2:{
                ini=inimigo2;
                break;
            }
            case 3:{
                ini=inimigo3;
                break;
            }
            case 4:{
                ini=inimigo4;
                break;
            }
        }
    }
}
//metodo que nos deixa mudar o char do hero 
void Menu::Nave(int position1){
    char heroc1=206;
    char heroc2=209;
    char heroc3=197;
    char heroc4=202;
    position=1;
    system("cls");
    keypressed=0;
    while(keypressed!=13 && keypressed!=27){
        system("cls");
        cout<<"\n\n\n\t";
        Arrow(1,position);
        cout << "|| " <<heroc1<< " ||" << endl;
        cout<<"\n\t";
        Arrow(2,position);
        cout << "|| " <<heroc2<< " ||" << endl;
        cout<<"\n\t";
        Arrow(3,position);
        cout << "|| " <<heroc3<< " ||" << endl;
        cout<<"\n\t";
        Arrow(4,position);
        cout << "|| " <<heroc4<< " ||" << endl;
        cout<<"\n\t";
        getCursor();
        if(keypressed == 80 && position != 4){//logica que complementa o metodo arrow
        ++position;
        }else position=position;
        if(keypressed == 72 && position != 1){
            --position;
        }
        if(keypressed==13){
            keypressed=13;
        }else if(keypressed==27){
            keypressed=27;
        }else this->keypressed=0;
    Sleep(105);
    }
    if(keypressed==13){//parte da implementacao do char
        switch(position){
            case 1:{
                nave=heroc1;
                break;
            }
            case 2:{
                nave=heroc2;
                break;
            }
            case 3:{
                nave=heroc3;
                break;
            }
            case 4:{
                nave=heroc4;
                break;
            }
        }
    }
}

int Menu::getCursor(){//metodo que deteta a tecla primida e retorna ás funçoes
   while(keypressed==0){
    if(GetKeyState(VK_DOWN) & 0x8000) { keypressed = 80; }
    if(GetKeyState(VK_UP) & 0x8000) { keypressed = 72; }
	if(GetKeyState(VK_RETURN) & 0x8000) { keypressed = 13; }
	if(GetKeyState(VK_ESCAPE) & 0x8000) { keypressed = 27; }
	}
    return keypressed;
}
//metodo que cria o em si jogo e atribui valores a determinadas variaveis de algumas classes
void Menu::set_info1(){
	string nome;
	int a;
	int x;
	int y;
	int nivel;
	int vidas,boosts,pontos;
	int counter;
	nome="";
	a=0;
	x=15;
	y=15;
	nivel=1;
	vidas=3,boosts=10,pontos=0;
	counter=0;
	system("cls");
	cout<<"\n\tEles estao a caminho!!!\n\n  ";
	system("pause");
	cout<<"\n\n  Nome:";
	while(nome==""){
		getline(cin,nome);
	}	
	system("cls");
	cout<<"\n\n\n\n\n\tLEVEL 1";
	Sleep(2000);
	Run run(counter,nivel,hero(nome,x,y,vidas,boosts,pontos));
	run.set_corJogo(corJogo);//outra parte da implementacao da cor no jogo
	run.set_hero(nave);//outra parte da implementacao do char hero no jogo
	run.set_ini(ini);//outra parte da implementacao do char inimigo no jogo
	run.RunGame();//iniciaçao do jogo em si
	nome="";
	a=0;
	x=15;
	y=15;
	nivel=1;
	vidas=3,boosts=10,pontos=0;
	counter=0;
}
//semelhante ao metodo anterior mas carrega valores de um jogo ja jogado ou seja carrega um jogo antigo
void Menu::set_info2(){
	string nome="";
	int x=15;
	int y=15;
	int nivel=1;
	int vidas=3,boosts=10,pontos=0;
	int counter=0;
	int vetor[8];
	int i=0;
	string linha;
	ifstream arquivo;
	arquivo.open("temp.txt");
	if(arquivo.is_open()){
		while(!arquivo.eof()){
			getline(arquivo,linha);
			if(i==2){
				nome=linha;
			}
			istringstream(linha)>>vetor[i];	
			i++;
		}
	}else{
	cerr<<"Arquivo naa encontrado";
	system("pause");
	} 
	if(nivel==1&& counter!=0){
	}else{
	counter=vetor[0];
	nivel=vetor[1];
	x=vetor[3];
	y=vetor[4];
	vidas=vetor[5];
	boosts=vetor[6];
	pontos=vetor[7];
	}
	arquivo.close();
	if(vidas!=0){
	Run run(counter,nivel,hero(nome,x,y,vidas,boosts,pontos));
	run.set_corJogo(corJogo);
	run.set_hero(nave);
	run.set_ini(ini);
	run.RunGame();
	}	
}
//metodo que faz os menus funcionar e dá print a alguns elementos 
int Menu::printMenu(){	
	
	ifstream ani;
	string linha; 
	ifstream fp;
	string desenho;
	cout<<"\n\n  Seta para baixo para ver a historia.\n\n";
	cout<<"\t   Enter para passar\n\n";
	cout<<"  (Enter if you do not Understand)";
	while(keypressed==0){
	if(GetKeyState(VK_DOWN) & 0x8000) { keypressed = 80;}
	if(GetKeyState(VK_RETURN) & 0x8000) { keypressed = 13;}
	}
	system("cls");
	ani.open("texto.txt");
	
	if(!ani){
		cout<<"Nao foi possivel abrir ficheiro"<<endl;
				}
	
	if(keypressed==80){		
		while(getline(ani,linha)){
			  cout<< linha<<endl;
				  Sleep(500);} }
			else if(keypressed==13){
 	ani.close();
	}
	
	fp.open("image.txt");
	
	if(!fp){
		cout<<"Nao foi possivel abrir ficheiro"<<endl;
	}
    if(keypressed==80){
		while(getline(fp,desenho)){				  
			cout<< desenho<<endl;
			Sleep(250);
			if(keypressed==13){
			fp.close();
			}
		} 
	}
	if(keypressed==13){
 	fp.close();
    }
    //modagem da janela
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a;
    a.X = 60;
    a.Y = 60;
    SMALL_RECT rect;
    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = 27;
    rect.Right = 41;
    SetConsoleScreenBufferSize(handle, a);
    SetConsoleWindowInfo(handle, 1, &rect);
    
	position1=getIdioma();
	system("cls");
	Escolha (position1, corJogo);
	
	do{	//do while que faz os menus funcionarem 
		switch(position){
			case 1:{
				set_info1();
				Escolha (position1,corJogo);
				break;
			}
			case 2:{
				set_info2();
				Escolha (position1,corJogo);
				break;
			}
			case 3:{
				s.mostra_score();
				system("pause");
				Escolha (position1,corJogo);
				break;
			}
			case 4:{
				Configuracoes(position1);
				if(position==1){
					PosicaoJogoCor (position1);
				}else if(position==2){
					detalhes(position1);
				}else if(position==3){
					Nave(position1);
				}else if(position==4){
					Inimigo(position1);
				}
				Escolha (position1,corJogo);
				break;
			}
			case 6:{
				PlaySound("Sounds/egg.wav",NULL,SND_SYNC);
				Escolha (position1,corJogo);
				break;
			}
		}
	}while(position!=5);
	PlaySound("Sounds/fim.wav",NULL,SND_SYNC);
}
