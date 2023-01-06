#include "kmeans.hpp"

Kmeans::Kmeans(int nombre_points,int nombre_clusters) {
    this->nombre_clusters = nombre_clusters;
    for(int i = 0; i < nombre_points; ++i) {
        Point x(rand()%30, rand()%30);
        this->donnees.push_back(x);
    }
}

Kmeans::~Kmeans() {
}

void Kmeans::initialiser() {
    /* Copie du vecteur de Point (les données) */
    vector<Point> init(this->donnees);
    /* Mélange aléatoire en place */
    random_shuffle(init.begin(), init.end());
    /* On récupère les k premiers points */
    for(int i = 0; i < this->nombre_clusters; i++)
        this->centroides.push_back(init[i]);
}

/* Les Point sont passés par référence (pour éviter la copie) 
 * et sont déclarés const car la fonction ne doit pas les modifier. 
 * En conséquence, les accesseurs _doivent_ être const dans la classe Point
 */
static double distance_point(const Point& p, const Point& p1) {
    double px = p.get_x();
    double py = p.get_y();
    double p1x = p1.get_x();
    double p1y = p1.get_y();
    return sqrt((px - p1x) * (px - p1x) + (py - p1y) * (py - p1y));
}

/* Fonction statique (accessible uniquement depuis ce fichier) 
 * Ce n'est pas une méthode de classe car elle ne doit pas être 
 * utilisée sur un objet de type Kmeans
 */
static void iteration(const vector<Point>& donnees, const vector<Point>& centroides, map<int,int> &clusters) {
    for(size_t p = 0 ; p < donnees.size(); p++) {
        int min_centroide = 0;
        double min_distance = distance_point(donnees[p],centroides[0]);
        for(size_t i = 1; i < centroides.size(); i++) {
            double dist = distance_point(donnees[p], centroides[i]); 
            if(dist < min_distance) {
                min_distance = dist;
                min_centroide = i;
            }
        }
        clusters[p] = min_centroide; 
    }
}

void Kmeans::calculer(int iter) {
    for(int a = 0; a < iter; a++) {
        /* L'algorithme sera répété iter fois */
        /* Pour chaque point, calculer le centroide dont il est le plus proche */
        iteration(this->donnees, this->centroides, this->clusters_par_point);

        /* Mise à jour des centroides 
         */
        vector<int> points_par_cluster(this->nombre_clusters,0);
        vector<int> abscisses_par_cluster(this->nombre_clusters,0);
        vector<int> ordonnees_par_cluster(this->nombre_clusters,0);

        for(map<int,int>::iterator it = this->clusters_par_point.begin(); 
                it != this->clusters_par_point.end(); it++) {
            points_par_cluster[it->second]++;
            abscisses_par_cluster[it->second] += this->donnees[it->first].get_x();
            ordonnees_par_cluster[it->second] += this->donnees[it->first].get_y();
        }
        for(int i = 0; i < this->nombre_clusters; i++) {
            double moyenne_x = abscisses_par_cluster[i] / points_par_cluster[i];
            double moyenne_y = ordonnees_par_cluster[i] / points_par_cluster[i];
            /* Le nouveau centroide est la moyenne des points du cluster */
            Point tmp(moyenne_x, moyenne_y);
            this->centroides[i] = tmp;
        }
    }

    /* Ultime mise à jour des clusters */
    iteration(this->donnees, this->centroides, this->clusters_par_point);
}

void Kmeans::afficher(int length){
	bool hasPoint = false;
	vector<char> symbols;
	int noHashtag = 0;
	for(int h = 0; h < this->nombre_clusters; h++){
		if(h + 33 == 35){
			noHashtag += 1;
		}
		symbols.push_back((char) (h + 33 + noHashtag));
	}
	for(int i = 0; i <= length; i++){
		for(int j = 0; j <= length; j++){
			for(long unsigned int k = 0; k < (this->donnees).size();k++){
				if((this->donnees)[k].get_x() == i && (this->donnees)[k].get_y() == j){
					hasPoint = true;
					cout << symbols[this->clusters_par_point[k]] << " ";
					break;
				}
			}
			if(!hasPoint){
				if (i == 0 || i == length){
		        		cout << "# ";
		        	}else if (j == 0 || j == length){
		        		cout << "# ";
		        	}else{
		        		cout << "  ";
		        	}
                	}
                	hasPoint = false;
		}
		cout << endl;
	}
	
}

int Kmeans::qualite(){
	int quali=0;
	for(int i = 0; i<this->nombre_clusters; i++){
		for(long unsigned int j = 1; j < (this->donnees).size(); j++){
			if(i==this->clusters_par_point[j]){
			quali += distance_point((this->donnees)[j], (this->centroides)[i]) * distance_point((this->donnees)[j], (this->centroides)[i]);
            		}
        	}
    	}
    	return quali;
}
