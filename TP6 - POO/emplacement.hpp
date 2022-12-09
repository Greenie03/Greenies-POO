#ifndef EMPLACEMENT_HPP
#define EMPLAMENENT_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

template<typename K,typename V>
class Emplacement{
	private:
		K cle;
		V valeur;
		Emplacement* suivant;		
	public:
		Emplacement(K _cle, V _value);
		Emplacement();
		~Emplacement();
		V& operator[](K _cle);
		Emplacement& operator=(Emplacement<K,V> const & e);
		template<typename C,typename L> friend ostream& operator<<(ostream& os, Emplacement<C,L>& e);
};

#include "emplacement.tcc"

#endif
