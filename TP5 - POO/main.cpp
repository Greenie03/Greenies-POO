#include "liste.hpp"
#include "point.hpp"

int main() {
    Liste<int> liste_entiers(5);
    Liste<Point> liste_points;

    int valeurs[5] = { 2, 8, 42, 3, 15 };

    for(int i = 0; i < 5; ++i) {
        liste_entiers.ajouter_fin(valeurs[i]);
        liste_points.ajouter_fin(Point(valeurs[i],valeurs[2])); 
    }

    std::cout << liste_entiers << std::endl;
    std::cout << liste_points << std::endl;

    for(int i = 0; i < 4; ++i) {
        liste_entiers.supprimer_fin();
        liste_points.supprimer_fin(); 
    }

    return 0;
}
