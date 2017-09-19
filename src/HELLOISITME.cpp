//============================================================================
// Name        : HELLOISITME.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "math.h"
using namespace std;

uint64_t read_input(uint64_t input)
{
    bool valid= false;
    do
    {
        if (cin.good() )
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(INT_MAX,'\n');
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);

    return (input);
    cin.clear();
    cin.ignore(INT_MAX,'\n');
}
uint64_t logpow10Func(uint64_t VarIn, uint8_t basein) {
	uint64_t logpowOut;
	logpowOut = pow(basein,(uint64_t)((log(VarIn))/log(basein))+1);
	return logpowOut;
}
uint64_t concatFunc(uint64_t a, uint64_t b, uint64_t c, uint8_t basecheck) {
	uint base;
    switch (basecheck)
        {
        case 0:
        	base = 2;
            break;
        case 1:
        	base = 8;
            break;
        case 2:
        	base = 10;
            break;
        case 3:
        	base = 16;
        	break;
        default:
           base = 10;
        }
	uint64_t cat;
	uint64_t logb= logpow10Func(b, base);
	uint64_t logc = logpow10Func(c, base);
	cat = a*logb*logc+b*logc+c;
    return cat;
}
uint64_t catinput(){
	uint8_t base = 0;
	uint64_t a,b,c;

	cout << "please choose your base" << endl;
    cout  << "0: bin\n" <<  "1: octal" << endl;
	cout << "2: dec" << endl << "3: hex" << "\n";

	cin >> base;
	read_input(base);
	cout << endl << "please enter your 3 values to be concactinated \n";

	cout << endl << "1st	"<< endl;
	cin >> dec >> a;
	read_input(a);

	cout << "2rd   " << endl;
	cin >> dec >> b;

	read_input(b);
	cout << "3nd	" << endl;
	cin >> dec >> c;

	read_input(c);
	uint64_t cat1;
	cat1 = concatFunc(a,b,c, base);
	return cat1;
}

int main() {

	while(1)
	{
	cout << dec << catinput() << "\n";
	cout << flush;
	}

}
