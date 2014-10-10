#include "clock.h"

using namespace std;

int main() {

	// Constructor
	Clock c;
	Clock d(12, 34, 56);
	Clock e("12:34:56");
	Clock f(c);

	// << overload
	cout << c << endl;
	c = c+d;
    cout << "Addition: " << c << endl;
    c = c-d;
    cout << "Subtraction: " << c << endl;
    cout << "String constructor (should be 12:34:56): " << e << endl;
    e.setClock("65:43:21");
    cout << "Setting via string (should return 65:43:21): " << e << endl;
    cout << f << endl;
    cout << (c==f ? "c equals f" : "c does not equal f") << endl;
    cout << (c!=f ? "c does not equal f" : "c equals f") << endl;
	return 0;

}
