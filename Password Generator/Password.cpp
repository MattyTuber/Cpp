#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
	srand(time(NULL));
	int leng;
	
	cout << "Inserire Lunghezza --> ";
	cin >> leng;
	
	string password = "";
	
	string alphanum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%&0123456789";
    
    for (int i = 0; i < leng; i++)
    	password += alphanum[rand() % 68];
	
	cout << "\n-----------------------------\n";
    cout << "         Password             \n";
    cout << "------------------------------\n\n";
    cout << password;
	
	return 0;
}
