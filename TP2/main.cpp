#include "kmeans.hpp"

int main(){
	Kmeans* k = new Kmeans(50,5);
	(*k).initialiser();
	(*k).calculer(100);
	(*k).afficher(32);
	cout << (*k).qualite() << endl;
	delete k;
	return EXIT_SUCCESS;
}
