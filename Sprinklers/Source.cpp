//---------------------------------------------
// Name:	Kenneth A. Carmona
// Assg:	Final Exam Part 1
// Row :	3, Version 2
// Date:	Jan. 30, 2020
//---------------------------------------------
#include <iostream>
using namespace std;

short n, front, lft, rgt;

void displayFrLeRi() {
	cout << " Front yard = " << front << "  left side = " << lft << "  right side = " << rgt;
	cout << endl;
}
void displayAX() {
	cout << " AX= ";
}
void outputBase() {
	cout << n << " ";
}
void Base2() {
	short x = 1 << 15, t;
	for (int i = 1; i <= 16; ++i)
	{
		t = n & x;
		if (t == 0) {
			cout << 0;
		}
		else {
			cout << 1;
		}
		if (i % 4 == 0) {
			cout << " ";
		}
		n = n << 1;
	}
	cout << endl;
}

int main() {
	_asm {
		//compute 6,7, and 8 bits for the front yard	
		mov			ax, 0xCFDC;		//ax = 0xCFDC
		and ax, 0x00E0;		//ax = ax & 0xCFDC
		shr			ax, 5;			//shr ax by 5
		mov			front, ax;
		//compute 10, 11, and 12 bits for the left side 
		mov			ax, 0xCFDC;
		and ax, 0x0E00;
		shr			ax, 9;
		mov			lft, ax;
		//compute 14, 15, and 16 bits for the right side
		mov			ax, 0xCFDC;
		and ax, 0xE000;
		shr			ax, 13;
		mov			rgt, ax;
		call		displayFrLeRi;
		//output Base2
		call		displayAX;
		mov			n, 0xCFDC;
		call		Base2;
	}
	cout << endl << endl;
	system("pause");
	return 0;
}