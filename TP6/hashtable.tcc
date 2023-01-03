
#include "hashtable.hpp"

template<typename T, typename U>
Hashtable<T,U>::Hashtable(size_t _taille){
	this->taille = _taille;
	this->table = new Emplacement<T,U>[taille];
	for (size_t i = 0; i<taille; i++){
		this->table[i] = *(new Emplacement<T,U>());
	}
}

template<typename T, typename U>
Hashtable<T,U>::Hashtable(){
	this->taille = 0;
	this->table = NULL;
}

template<typename T, typename U>
Hashtable<T,U>::~Hashtable(){
    delete[] this->table;
}

template<typename T, typename U>
bool Hashtable<T, U>::acces(const T &cle, U* val) {
    if (this->table[hashFunction(cle)] != NULL) {
        Emplacement<T,U>* e = this->table[hashFunction(cle)];
        while (e->get_suivant() != NULL) {
            if (e[cle] != NULL){
                val = e[cle];
                return true;
            }
            e = e->get_suivant();
        }
    }
    return false;
}

template<typename T, typename U>
bool Hashtable<T, U>::acces(const T &cle) {
    if (this->table[hashFunction((int &) cle)] != NULL) {
        Emplacement<T,U>* e = this->table[hashFunction(cle)];
        while (e->get_suivant() != NULL) {
            if (e[cle] != NULL){
                return true;
            }
            e = e->get_suivant();
        }
    }
    return false;
}

template<typename T, typename U>
T Hashtable<T, U>::hashFunction(T &key) {
    return (this->taille)%key;
}

template<typename T, typename U>
void Hashtable<T, U>::inserer(const T &cle, const U &value) {
    if (this->acces(cle)){
        (this->table[this->hashFunction((int &) cle)]).ajouter_fin(new Emplacement<T, U>(cle, value));
    }else{
        this->table[this->hashFunction((int &) cle)] = *(new Emplacement<T,U>(cle,value));
    }
}
