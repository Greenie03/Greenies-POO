#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "emplacement.hpp"

template<typename T, typename U>
class Hashtable{
	private:
		size_t taille;
		Emplacement<T,U>* table;
		
	public:
		Hashtable(size_t _taille);
		Hashtable();
};

#include "hashtable.tcc"

#endif
