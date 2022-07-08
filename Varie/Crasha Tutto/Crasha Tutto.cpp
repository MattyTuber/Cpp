#include <cstdlib>
#include <ctime>
int main ()
{
	srand(time(NULL));
	system("color a");
	
	while (true) 
	{
		system("cmd /c start iexplore.exe");
		system("cmd /c start chrome.exe");
		system("cmd /c start https://www.corriere.it/");
		system("cmd /c start firefox.exe");
		
	}
	
	return 0;
}

