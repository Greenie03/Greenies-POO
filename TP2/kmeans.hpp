#ifndef KMEANS_HPP
#define KMEANS_HPP

#include "point.hpp"
#include <cstdlib>      // std::rand, std::srand
#include <algorithm>
#include <vector>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <fstream>

using namespace std;

class Kmeans {
    private:
        vector<Point> donnees;
        /* NOTE --- une map<Point,int> ne peut pas être utilisée ici : en effet, le conteneur map 
         * a besoin de comparer les clés, ce qu'on ne sait pas (encore) faire pour des objets de type 
         * Point. On passe donc un entier (le numéro du Point) en clé.
         */
        map<int,int> clusters_par_point;
        int nombre_clusters;
        vector<Point> centroides;
    public:
        Kmeans() {;}
        Kmeans(int,int);
        ~Kmeans();

        void initialiser();
        void calculer(int);

        vector<Point> get_donnees() { return donnees; }
        
        void afficher(int length);
        
        int qualite();
};

#endif
