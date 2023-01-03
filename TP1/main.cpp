#include "point.hpp"

int main() {
    Point p(10.,10.);
    Point* p1 = new Point(3.,5.);
    Point* p2 = new Point(20.,9.);
    (*p1).droite((*p2));
    p1->dessiner((*p2), 25);
    
    delete p1;
    delete p2;

    return 0;
}
