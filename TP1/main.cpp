#include "point.hpp"

int main() {
    Point p(10.,10.);
    Point* p1 = new Point(5.,30.);
    Point* p2 = new Point(22.,26.);
    (*p1).droite((*p2));
    p1->dessiner((*p2), 35);
    
    delete p1;
    delete p2;

    return 0;
}
