#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

using namespace std;

int main(){
	int x, y;
	
	while (!kbhit()){
		x = rand () % 75;
		y = rand () % 20;
		gotoxy(x,y)
		printf("%c", 3);
	}
}
