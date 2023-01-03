
#include "emplacement.hpp"

template<typename K, typename V>
Emplacement<K,V>::Emplacement(K _cle, V _value){
	this->cle = _cle;
	this->valeur = _value;
	this->suivant = NULL;
}

template<typename K,typename V>
Emplacement<K,V>::Emplacement(){
	this->cle = K();
	this->valeur = V();
	this->suivant = NULL;
}

template<typename K, typename V>
Emplacement<K,V>::~Emplacement(){
	delete[] suivant;
}

template<typename K, typename V>
V& Emplacement<K,V>::operator[](K _cle){
	Emplacement* pt = &this;
	while((*pt)->suivant != NULL){
		if(this->cle == _cle){
			return this->value;
		}else{
			pt = &(*pt)->suivant;
		}
	}
	return NULL;
}

template<typename C, typename L> ostream& operator<<(ostream& os, Emplacement<C,L>& e){
	os << e.cle << " : " << e.valeur << " -> ";
	Emplacement<C,L>* pt = &e;
	while(pt->suivant != NULL){
		os << pt->cle << " : " << pt->valeur << " -> ";
        pt = pt->suivant;
	}
	os << "NULL";
	return os;
}

template<typename K, typename V>
Emplacement<K,V>& Emplacement<K,V>::operator=(Emplacement<K,V> const& e){
	this->cle = e.cle;
	this->valeur = e.valeur;
	this->suivant = e.suivant;
	Emplacement<K,V>* pt = e.suivant;
	Emplacement<K,V>* pt2 = this->suivant;
	while(pt->suivant != NULL){
		pt = pt->suivant;
		pt2->suivant = pt;
	}
	return *this;
	
}

template<typename K, typename V>
Emplacement<K, V> *Emplacement<K, V>::get_suivant() {
    return this->suivant;
}

template<typename K, typename V>
void Emplacement<K, V>::ajouter_fin(Emplacement<K, V>* e) {
    Emplacement<K,V>* pt = e;
    while (pt->suivant != NULL){
        pt = pt->suivant;
    }
    pt->suivant = e;

}
