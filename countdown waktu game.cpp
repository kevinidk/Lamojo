#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{	
	int i;
	for(i=60;i>=1;i-1)
	{
    	cout<<i;
    	--i;
    	Sleep(1000);
    	system("cls");
	}	

}
