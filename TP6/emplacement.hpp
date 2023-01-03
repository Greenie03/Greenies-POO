#ifndef EMPLACEMENT_HPP
#define EMPLACEMENT_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

template<typename K,typename V>
class Emplacement{
	private:
		K cle;
		V valeur;
		Emplacement<K,V>* suivant;
	public:
		Emplacement(K _cle, V _value);
		Emplacement();
		~Emplacement();
        Emplacement<K,V>* get_suivant();
		V& operator[](K _cle);
		Emplacement<K,V>& operator=(Emplacement<K,V> const& e);
		template<typename C,typename L> friend ostream& operator<<(ostream& os, Emplacement<C,L>& e);
        void ajouter_fin(Emplacement<K,V>* e);
};

#include "emplacement.tcc"

#endif
