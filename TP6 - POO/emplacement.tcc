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
	throw std::invalid_argument( "la clé ne correspond à aucune valeur de l'emplacement" );
}

template<typename C, typename L> ostream& operator<<(ostream& os, Emplacement<C,L>& e){
	os << e.cle << " : " << e.valeur << " -> ";
	Emplacement<C,L>* pt = &e;
	while(pt->suivant != NULL){
		os << pt->cle << " : " << pt->valeur << " -> ";
	}
	os << "NULL";
	return os;
}

template<typename K, typename V>
Emplacement& operator=(Emplacement<K,V> const & e){
	this->cle = e.cle;
	this->valeur = e.valeur;
	this->suivant = e.suivant;
	Emplacement* pt = &(e->suivant);
	Emplacement* pt2 = this->suivant;
	while(pt->suivant != NULL){
		pt = pt->suivant;
		pt2->suivant = pt;
	}
	return *this;
	
}
