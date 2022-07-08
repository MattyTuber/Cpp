#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i;

	while(true)
	{
		system("cmd /c start notepad.exe christmas.txt");
		i++;
	}
	
	return 0;
}

