template<typename T, typename U>
Hashtable<T,U>::Hashtable(size_t _taille){
	this->taille = _taille;
	this->table = new Emplacement<T,U>[taille];
	for (size_t i = 0; i<taille; i++){
		this->table[i] = new Emplacement<T,U>();
	}
}

template<typename T, typename U>
Hashtable<T,U>::Hashtable(){
	this->taille = 0;
	this->table = NULL;
}

template<typename T, typename U>
Hashtable<T,U>::~Hashtable(){
	~this->table;
}
