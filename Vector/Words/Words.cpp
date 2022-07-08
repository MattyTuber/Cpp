#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string input;
	
	vector <string> words;
	
	while(input != "exit"){
		cout << "Inserire Parola --> ";
		cin >> input;
		
		words.push_back(input);
	}
	
	words.pop_back();
	
	for(string w : words)
		cout << w << "\n";
		
	cout << "Dimensione --> " << words.size();
	
	sort(words.begin(), words.end());
	
	for(string w : words)
		cout << "\n" << w;
		
	return 0;
}
