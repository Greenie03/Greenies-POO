#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <vector>

class Point {

    private: // Par défaut 
        double x;
        double y;
    public:
        Point(); // Aucun type de retour
        Point(double, double); // Surcharge du constructeur
        Point(const Point &); // Constructeur par recopie : pour illustrer son utilisation
        ~Point(); // Destructeur
      
        /* Cette méthode pourrait être externe à la classe et 
         * prendre deux Point comme arguments. 
         * Le deuxième point est une référence constante :  
         * on veut empêcher toute modification au sein de la fonction.
         */
        std::vector<Point*> droite(const Point &p1);
        void afficher();

        int get_x() { return x; }
        int get_y() { return y; }

        /* Les versions constantes de ces méthodes sont nécessaires 
         * pour être utiliser sur un objet de type const Point
         */
        int get_x() const { return x; }
        int get_y() const { return y; }

};

#endif
