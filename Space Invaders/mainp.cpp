#include <iostream>
#include "windows.h"
#include "Menu.h"

using namespace std;

int main() {
	//esconde o cursor
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
	cout<<"\n\n\n\t!!Warning--Loud Song!!\n\n  ";
	system("pause");
	system("cls");
	PlaySound("Sounds/inic.wav",NULL,SND_SYNC);
	int keypressed=0,y1=0;
	cout<<"\n\n\tPRESS ENTER\n\n  "<<endl;
	while(keypressed==0){
		if(GetKeyState(VK_RETURN) & 0x8000){
			keypressed=1;
		}
		if(GetKeyState('N') & 0x8000){//parte do easter egg1
			keypressed=2;
		}
	}
	Sleep(250);
	if(keypressed==1){
	system("cls");
	Menu *a=new Menu();
	a->printMenu();
	delete a;
	}else {//outra parte do easter egg 1
		Sleep(100);
		system("pause");
		system("cls");
		cout<<"\n\tSelect a color:\n\n";
		cout<<"\tBLUE-1"<<endl;
		cout<<"\tGREEN-2"<<endl;
		cout<<"\tCYAN-3"<<endl;
		cout<<"\tRED-4"<<endl;
		cout<<"\tMAGENTA-5"<<endl;
		cout<<"\tGOLD-6"<<endl;
		cout<<"\tLIGHTGRAY-7"<<endl;
		cout<<"\tDARKGRAY-8"<<endl;
		cout<<"\tLIGHTBLUE-9"<<endl;
		cout<<"\tLIGHTGREEN-10"<<endl;
		cout<<"\tLIGHTCYAN-11"<<endl;
		cout<<"\tLIGHTRED-12"<<endl;
		cout<<"\tLIGHTMAGENTA-13"<<endl;
		cout<<"\tYELLOW14"<<endl;
		cout<<"\tWHITE-15"<<endl;
		while(y1<1||y1>15){
		cin>>y1;
		}
	system("cls");
	Menu *a1=new Menu(y1);
	a1->printMenu();
	delete a1;
	}
	
}


