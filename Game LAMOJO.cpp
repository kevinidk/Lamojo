#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#include <stdlib.h> 
#include <fstream>
using namespace std;

string nama;

int x = 1;
int y = 1;
int v_x = 0;
int v_y = 0;
int coin = 39;
int score = 0;
char inputControl;
bool gameover = false;
char Maps[11][18]={
	 "[=^=^=^=^=^=^=^=]",
	 "|P|O|O|O|O|O|O|O|",
	 "<=#=#=#=#=#=#=#=>",
	 "|O|O|O|O|O|O|O|O|",
	 "<=#=#=#=#=#=#=#=>",
	 "|O|O|O|O|O|O|O|O|",
	 "<=#=#=#=#=#=#=#=>",
	 "|O|O|O|O|O|O|O|O|",
	 "<=#=#=#=#=#=#=#=>",
	 "|O|O|O|O|O|O|O|O|",
	 "(=%=%=%=%=%=%=%=)"};

void move();
void actionTrigger();
void renderMap();
void countdown();
void win();
void lose();
void printHighscore();
void control(char key);

main() 
{
	bool firsttime;
	while(!gameover){
		if(!firsttime) {
			renderMap();
			firsttime = true;
		}
	
		if(kbhit()){
			inputControl = getch();
			control(inputControl);
			system("cls");
			renderMap();
		}
	}
}

void renderMap(){
	
	cout<<"Score: "<<score<<endl;
	
	for(int i=0; i<11; i++){
		for(int j=0; j<18; j++){
			char t=Maps[i][j];
		if(t == '=')
		cout<<char(205);
	else if(t == '|')
		cout<<char(186);
	else if(t == '#')
		cout<<char(206);
	else if(t == '^')
		cout<<char(203);
	else if(t == '<')
		cout<<char(204);
	else if(t == '>')
		cout<<char(185);
	else if(t == '%')
		cout<<char(202);
	else if(t == '[')
		cout<<char(201);
	else if(t == ']')
		cout<<char(187);
	else if(t == '(')
		cout<<char(200);
	else if(t == ')')
		cout<<char(188);
	else
		cout<<t;
 
		}
		cout<< endl;
	}
	
}

void control(char key) {
	v_x = 0;
	v_y = 0;
	//
	if(key == 'Q' || key == 'q')
		v_y = -4, v_x= -2;
	//
	else if(key == 'A' || key == 'a')
		v_x = -4, v_y = -2;
	//
	else if(key == 'Z' || key == 'z')
		v_y = 2, v_x = -4;
	//
	else if(key == 'S' || key == 's')
		v_x = -2, v_y = 4;	
	//
	else if(key == 'P' || key == 'p')
		v_x = 2, v_y = -4;
	//
	else if(key == 'L' || key == 'l')
		v_y = -2, v_x = 4;
	//
	else if(key == 'M' || key == 'm')
		v_x = 4, v_y = 2;
	//
	else if(key == 'K' || key == 'k')
		v_y = 4, v_x = 2;
	move();
}

void move() {
	if(v_x != 0 || v_y != 0) {
		if(y + v_y < 0 || x + v_x < 0 || y + v_y > 10 || x + v_x > 16)
			return;
			
		char t = Maps[y + v_y][x + v_x];
		if(t == '=' || t == '|' || t == '^' || t == '%' || t == '<' || t == '>' || t == '[' || t == ']' || t == '(' || t == ')') {
			return;
		 }
		 actionTrigger();
	}
}

void actionTrigger() {
	char nextChar = Maps[y + v_y][x + v_x];
	
	if(nextChar == 'O'){ //Clear
		coin--;
		score++;
		Maps[y][x] = ' ';
		
		x = x + v_x;
		y = y + v_y;
		
		Maps[y][x] = 'P'; //Move
		if(coin < 1)
			win();
	}
	
	else if(Maps[y][x] = ' '){ //Clear
		
		lose();
	}
}

/*void countdown(){
	int i;
	//renderMap();
	for(i=60;i>=1;i-1)
	{
    	cout<<i;
    	--i;
    	Sleep(1000);
    	system("cls");
    	//renderMap();
	}
}*/

void win() {
	gameover = true;
	cout<<"\n\nYOU WIN!!!\n\n";
	ofstream myfile ("SCORE.txt", ios::app);
  	if (myfile.is_open()) {
    	myfile <<nama<<"\n";
		myfile <<score<<"\n";
		myfile.close();
	}
	system("pause");
}

void lose() {
	gameover = true;
	cout<<"\n\nYOU LOSE!!!\n\n";
	printHighscore();
	cout<<"Masukkan nama: ";
	cin>>nama;
	ofstream myfile ("SCORE.txt", ios::app);
  	if (myfile.is_open()) {
    	myfile <<nama<<"\n";
		myfile <<score<<"\n";
		myfile.close();
	}
	system("pause");
}

void printHighscore() {
	string line;
	int i = 0;
	ifstream myfile ("SCORE.txt");
	if (myfile.is_open()) {
	    while ( getline (myfile,line) ) {
	      if(i % 2 == 0) {
	      	cout<<line;
	      }
	      else {
	      	cout<<" ("<<line<<")"<<endl;
	      }
	      i++;
    	}
		myfile.close();
	}
}

