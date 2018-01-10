#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>
#include <fstream>
using namespace std;

string nama;

int x = 0;
int y = 0;
int point = 0;
char Maps[13][72];

void kalah();
void menang();
void printHighscore();
void Info();
bool checkWin();
main() 
{
	//Maps GAME
	char Maps[13][72]= 
	{"[=^=^=^=^=^=^=^=][====================================================]",
	 "|o|o|o|o|o|o|o|o||                                                    |",
	 "<=#=#=#=#=#=#=#=>|                                                    |",
	 "|o|o|o|o|o|o|o|o||  [     [===]  [====^====]  [====]  [==^==]  [====] |",
	 "<=#=#=#=#=#=#=#=>|  |     |   |  |    |    |  |    |     |     |    | |",
	 "|o|o|o|o|o|o|o|o||  |     <===>  |    |    |  |    <=====#=====>    | |",
	 "<=#=#=#=#=#=#=#=>|  (===%=)   (==)    )    (==%====)  (==)     (====) |",
	 "|o|o|o|o|o|o|o|o||                                                    |",
	 "<=#=#=#=#=#=#=#=>|       Created by; Mayvan, Kevin, Theo              |",
	 "|o|o|o|o|o|o|o|o||                                                    |",
	 "(=%=%=%=%=%=%=%=)(====================================================)",
	 };
	
	int Command = 0;
	if (Command == 0){
		char tampilanAwal[9][72]=
	{"                                                                       ",
	 "                                                                       ",
	 "                                                                       ",
	 "                                                                       ",
	 "                            GAME LAMOJO                                ",
	 "               By; Mayvan G, Kevin IDK, Achamad Theo S                 ",
	 "                                                                       ",
	 "  Game Bergenre Casual Strategi Dimana Player Bergerak Seperti Kuda    ",
	 "          Untuk Menghabiskan Poin-Poin Yang Tersedia Di Maps           ",
	};
	for(int i=0; i<9; i++){
		for(int j=0; j<72; j++){
			char t=tampilanAwal[i][j];
		
		cout<<t;
		}
		cout<< endl;
		
	}
	system("pause");
	system("cls");
}

	
	int jalan[8][2];
	//Masukan nama untuk score
	printHighscore();
	cout<<"Masukkan nama: ";
	cin>>nama;
	
	//Acak posisi awal pemain
	srand (time(NULL));
	x = rand() % 8 + 1;
	y = rand() % 5 + 1;
	Maps[y*2-1][x*2-1] = 'X';
	
	
	while(!checkWin()) {
		system("cls");
		//Menyatukan map
		for(int i=0; i<13; i++){
			for(int j=0; j<72; j++){
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
		//Menampilkan poin player
		cout<<"Point: "<<point<<endl<<endl;
		
		//Menampilkan daftar jalan player
		cout<<"Daftar jalan: \n";
		//y-3>0
		int i = 0;
		//jalan atas sebelah kiri
		if(y-2>0 && x-1>0 && Maps[(y-2)*2-1][(x-1)*2-1] == 'o') {
			jalan[i][0] = x-1;
			jalan[i][1] = y-2;
			cout<<++i<<". Posisi "<<y-2<<", "<<x-1<<endl;
		}
		//jalan atas seblah kanan
		if(y-2>0 && x+1 <= 8 && Maps[(y-2)*2-1][(x+1)*2-1] == 'o') {
			jalan[i][0] = x+1;
			jalan[i][1] = y-2;
			cout<<++i<<". Posisi "<<y-2<<", "<<x+1<<endl;
		}
		//jalan kiri sebelah atas
		if(y-1>0 && x-2>0 && Maps[(y-1)*2-1][(x-2)*2-1] == 'o') {
			jalan[i][0] = x-2;
			jalan[i][1] = y-1;
			cout<<++i<<". Posisi "<<y-1<<", "<<x-2<<endl;
		}
		//jalan kiri sebelah bawah
		if (y+1<=5 && x-2>0 && Maps[(y+1)*2-1][(x-2)*2-1] == 'o'){
			jalan[i][0] = x-2;
			jalan[i][1] = y+1;
			cout<<++i<<". Posisi "<<y+1<<", "<<x-2<<endl;
		}
		//jalan kanan sebelah atas
		if (y-1>0 && x+2<=8 && Maps[(y-1)*2-1][(x+2)*2-1] == 'o'){
			jalan[i][0] = x+2;
			jalan[i][1] = y-1;
			cout<<++i<<". Posisi "<<y-1<<", "<<x+2<<endl;
		}
		//jalan kanan sebelah bawah
		if (y+1<=5 && x+2<=8 && Maps[(y+1)*2-1][(x+2)*2-1] == 'o'){
			jalan[i][0] = x+2;
			jalan[i][1] = y+1;
			cout<<++i<<". Posisi "<<y+1<<", "<<x+2<<endl;
		}
		//jalan bawah sebelah kiri
		if (y+2<=5 && x-1>0 && Maps[(y+2)*2-1][(x-1)*2-1] == 'o'){
			jalan[i][0] = x-1;
			jalan[i][1] = y+2;
			cout<<++i<<". Posisi "<<y+2<<", "<<x-1<<endl;
		}
		//jalan bawah sebelah kanan
		if (y+2<=5 && x+1>0 && Maps[(y+2)*2-1][(x+1)*2-1] == 'o'){
			jalan[i][0] = x+1;
			jalan[i][1] = y+2;
			cout<<++i<<". Posisi "<<y+2<<", "<<x+1<<endl;	
		}
	
		//Input posisi player
		int pilihan;
		cout<<"Masukkan pilihan posisi: ";
		cin>>pilihan;
		
		//Kalah
		if(i < 1) {
			kalah();
		}
		
		//check pilihan player
		if(pilihan > i + 1)
			cout<<"Tidak  valid"<<endl;
		else {
			Maps[y*2-1][x*2-1] = ' ';
			
			x = jalan[pilihan-1][0];
			y = jalan[pilihan-1][1];
			
			if(Maps[y*2-1][x*2-1] == 'o')
				point++;
			
			Maps[y*2-1][x*2-1] = 'X';
		}
	}
	
	menang();
}

//Menampilkan Highscore
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

//Memasukkan hasil score ke file score.txt
void kalah() {
	cout<<"ANDA KALAH";
	ofstream myfile ("SCORE.txt", ios::app);
  	if (myfile.is_open()) {
    	myfile <<nama<<"\n";
		myfile <<point<<"\n";
		myfile.close();
	}
}

//Memasukkan hasil score ke file score.txt
void menang() {
	cout<<"ANDA MENANG";
	ofstream myfile ("SCORE.txt", ios::app);
  	if (myfile.is_open()) {
    	myfile <<nama<<"\n";
		myfile <<point<<"\n";
		myfile.close();
	}
}

//check menang
bool checkWin() {
	bool win = true;
	for(int i = 0; i < 13; i++) {
		for(int j = 0; i < 17; i++) {
			if(Maps[i][j] == 'o')
				win = false;
		}
	}
	
	return false;
}
