#include <iostream>
using namespace std;

#define PRINT_JOE
#define PRINT_BOB

int main() {
	#ifdef PRINT_JOE
	cout << "Printing Joe" << endl;
	#endif
	#ifdef PRINT_BOB
	cout << "Printing Bob" << endl;
	#endif
	
	return 0;
}
