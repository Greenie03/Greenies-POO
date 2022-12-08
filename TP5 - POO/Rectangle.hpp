#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

class Rectangle{
	private:
		int longueur;
		int largeur;
		
	public:
	
		Rectangle(int lo, int la);
		
		bool operator<(Rectangle const r) const;
		
		bool operator>(Rectangle const r) const;
		
		bool operator<=(Rectangle const r) const;
		
		bool operator>=(Rectangle const r) const;
		
		bool operator==(Rectangle const r) const;
		
		friend std::ostream& operator<< (std::ostream& ost , Rectangle const & m );
};
#endif
