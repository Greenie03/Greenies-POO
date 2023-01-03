#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "emplacement.hpp"
#include <cmath>

template<typename T, typename U>
class Hashtable{
	private:
		size_t taille;
		Emplacement<T,U>* table;
		T hashFunction(T &key);
	public:
		Hashtable(size_t _taille);
		Hashtable();
        ~Hashtable();
        bool acces(const T &cle, U* val);
        bool acces(const T &cle);
        void inserer(const T &cle, const U &value);
};

#include "hashtable.tcc"

#endif
