#include "Rectangle.hpp"

using namespace std;

Rectangle::Rectangle(int lo, int la){
	this-> longueur = lo;
	this->largeur = la;
}

bool Rectangle::operator<(Rectangle const r) const{
	return (this->longueur * this-> largeur) < (r.longueur * r.largeur) ? true : false;
}

bool Rectangle::operator>(Rectangle const r) const{
	return (this->longueur * this-> largeur) > (r.longueur * r.largeur) ? true : false;
}

bool Rectangle::operator<=(Rectangle const r) const{
	return (this->longueur * this-> largeur) <= (r.longueur * r.largeur) ? true : false;
}

bool Rectangle::operator>=(Rectangle const r) const{
	return (this->longueur * this-> largeur) >= (r.longueur * r.largeur) ? true : false;
}

bool Rectangle::operator==(Rectangle const r) const{
	return (this->longueur * this-> largeur) == (r.longueur * r.largeur) ? true : false;
}

std::ostream& operator<< (std::ostream& ost , Rectangle const & m ){
	for (int i=0; i < m.longueur; i++){
		for(int j=0; j < m.largeur; j++){
			if(i == 0 || i == m.longueur-1 || j == 0 || j == m.largeur -1){
				ost << "+ ";
			}else{
				ost << "  ";
			}
		}
		ost << endl;
	}
	return ost;
}
