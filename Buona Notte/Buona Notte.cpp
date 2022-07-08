#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

void run()
{
	LPCWSTR songlist[0] = 
	{
		TEXT("C:\\Desktop\\Teo\\Software Developing\\C++\\Buona Notte\\NinnaNanna.wav")
	};
	
	PlaySound(songlist[0], NULL, SND_ASYNC | SND_NODEFAULT );

}


int main(){
	run();
	system("pause");
	
	return 0;
}
