#include "point.hpp"

using namespace std;

Point::Point() {
    this->x = 0.;
    this->y = 0.;
    std::cout << "Constructeur par défaut Point " << std::endl;
}

Point::Point(double x, double y) {
    (*this).x = x;
    (*this).y = y;
    std::cout << "Constructeur par arguments Point " << std::endl;
}

Point::Point(const Point &p) {
    this->x = p.get_x();
    this->y = p.get_y();
    std::cout << "Constructeur par recopie Point " << std::endl;
}

Point::~Point() {
    std::cout << "Destructeur Point " << std::endl;
}

void Point::afficher() {
    cout << "[" << (*this).x << "," << (*this).y << "]" << endl;
}
