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

std::vector<Point> Point::droite(const Point &p1) {
    float p0x = (*this).x;
    float p0y = (*this).y;
    float e = p1.x - p0x;
    float dx = e*2;
    float dy = (p1.y - p0y) * 2;
    std::vector<Point> points;
    while (p0x <= p1.x){
    	Point* p = new Point(p0x,p0y);
        points.push_back(*(p));
        p0x = p0x + 1;
        e = e - dy;
        
        if (e <= 0){
            p0y = p0y + 1;
            e = e + dx;
        }
        delete p;
    }

    return points;
}

void Point::dessiner(const Point &p1,int length) {
    std::vector<Point>d = this->droite(p1);
    bool hasPoint = false;
    for(int i=0; i <= length; i++){
        for(int j=0; j < length; j++){
            if ((j == this->x && i == this->y) || (j == p1.x && i == p1.y)){
                cout << "O ";
            }else{
                for (int k = 0; k < (int) d.size(); k++) {
                    if (d[k].x == j && d[k].y == i) {
                        cout << "X ";
                        hasPoint = true;
                    }
                }
                if (i == 0 || i == length){
                    cout << "# ";
                }else if (j == 0 || j == length-1){
                    cout << "#";
                }else if (!hasPoint){
                    cout << "  ";
                }
            }
            hasPoint = false;
        }
        cout << endl;
    }
}
