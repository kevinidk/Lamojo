#include <iostream>
#include <conio.h>
using namespace std;

int x = 1;
int y = 1;
int v_x = 0;
int v_y = 0;
char Maps[6][18];

void move();
void actionTrigger();
main() 
{
	char Maps[6][18]= 
	{"[=^=^=^=^=^=^=^=]",
	 "<=#=#=#=#=#=#=#=>",
	 "<=#=#=#=#=#=#=#=>",
	 "<=#=#=#=#=#=#=#=>",
	 "<=#=#=#=#=#=#=#=>",
	 "(=%=%=%=%=%=%=%=)"};

	for(int i=0; i<6; i++){
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

void kontrol(char key) {
	v_x = 0;
	v_y = 0;
	//
	if(key == 'Q' || key == 'q')
		v_y = -1;
	//
	else if(key == 'A' || key == 'a')
		v_x = -1;
	//
	else if(key == 'Z' || key == 'z')
		v_y = -1;
	//
	else if(key == 'S' || key == 's')
		v_x = -1;	
	//
	else if(key == 'P' || key == 'p')
		v_x = 1;
	//
	else if(key == 'L' || key == 'l')
		v_y = 1;
	//
	else if(key == 'M' || key == 'm')
		v_x = 1;
	//
	else if(key == 'K' || key == 'k')
		v_y = 1;
	move();
}

void move() {
	if(v_x != 0 || v_y != 0) {
		if(y + v_y < 0 || x + v_x < 0)
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
	
	//
	if(Maps[y][x] = ' '){ //Clear
		
		x = x + v_x;
		y = y + v_y;
		
		Maps[y][x] = 'P'; //Move
	}
}
