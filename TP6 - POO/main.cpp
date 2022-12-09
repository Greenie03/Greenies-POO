#include "hashtable.hpp"

int main (){

	Emplacement<int,float> e(5,5.0);
	Emplacement<int, float> f(2,2.5);
	cout << e << endl;
	cout << f << endl;
	
	Hashtable<int, float> h(5);
	return 0;
}
