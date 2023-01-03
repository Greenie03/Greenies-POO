template< typename T >
Liste<T>::Liste() {
    this->tete = NULL;
    this->queue = NULL;
    this->taille = 0;
}

template< typename T >
Liste<T>::Liste(T _valeur) {
    /* A COMPLETER */
}

template< typename T >
Liste<T>::~Liste() {
    /* A COMPLETER */
}

template< typename T >
void Liste<T>::ajouter_fin(T _valeur) {
    /* Si la liste est vide, création de l'élément de tête */
    if(this->taille==0) {
        this->tete = new struct Noeud<T>(_valeur);
        this->queue = this->tete;
    }
    else{ 
        /* A COMPLETER */
    }
    ++this->taille;
}

template< typename T >
void Liste<T>::supprimer_fin() {
    assert(this->taille > 0);
    /* A COMPLETER */
}

template< typename T >
T& Liste<T>::operator[](size_t i) {
    assert(i>=0 && i < this->taille);
    /* A COMPLETER */
}

/* Hypothèse : T n'est pas un pointeur */
template< typename T >
std::ostream& operator<<(std::ostream &os, const Liste<T> &l) {
    struct Noeud<T> *parcours = l.tete;
    /* A COMPLETER */
    return os;
}
