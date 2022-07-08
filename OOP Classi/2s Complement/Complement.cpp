#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class eightbit {
	public:
		eightbit (int n);
		
		eightbit (){
			bin = "00000000";
		}
		
		eightbit (const eightbit& original){
			bin = original.bin;
		}
		
		void c1();
		void c2();
		int binToDec();
		void print();
		
	private:
		string bin;
		string cpl1;
		string cpl2;
};

eightbit::eightbit(int n){
	int tmp;
	bin = "";
	
	if (n < 0){
		bin += '1';
		n *= -1;
	}
	else
		bin += '0';

	for (int i = 6; i >= 0; i--){
		tmp = n >> i;
		
		if (tmp & 1)
			bin += '1';
		else
			bin += '0';
	}
}

void eightbit::c1(){
	cpl1 = "";
	if (bin[0] == '1')
		cpl1 += '1';
	else
		cpl1 += '0';
	
	for (int i = 1; i < 8; i++){
		if (bin [i] == '0')
			cpl1 += '1';
		else
			cpl1 += '0';
	}
}

void eightbit::c2(){
	int i;
	cpl2 = cpl1;
    
	for (i = 7; i >= 0; i--)
    {
        if (cpl1[i] == '1')
            cpl2[i] = '0';
        else
        {
            cpl2[i] = '1';
            break;
        }
    }
    
    if (i == -1)
        cpl2 = '1' + cpl2;
}

int eightbit::binToDec(){
	int dec = 0, cnt = 0;
	
	for (int i = 7; i > 0; i--, cnt++)
		if (bin [i] == '1')
			dec += pow(2, cnt);
	
	if (bin [0] == '1')
		dec *= -1;
	
	return dec;
}

void eightbit::print(){
	cout << "Binary --> " << bin;
	cout << "\n1s Complement --> " << cpl1;
	cout << "\n2s Complement --> " << cpl2;
}

int main(){
	eightbit a (-10);

	a.c1();
	a.c2();
	a.print();
	cout << "\nDecimal --> " << a.binToDec();
	
	return 0;
}
