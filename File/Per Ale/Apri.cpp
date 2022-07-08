#include <stdlib.h>

int main(){
	for (int i = 0; i < 200; i++)
		system("cmd /c start notepad.exe Hello.txt");
	
	return 0;
}
