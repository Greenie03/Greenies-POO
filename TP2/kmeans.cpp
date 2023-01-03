#include "kmeans.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

Kmeans::Kmeans(int k){
	this->k = k;
	for(int i = 0; i < 50; i++){
		Point p = *(new Point((double) (rand()%31),(double) (rand()%31)));
		(this->v).push_back(p);
	}
}

void Kmeans::initialiser(){
	for(int i = 0; i < (this->k); i++){
		int r = rand()%50;
		(this->tab).push_back((this->v)[r]);
	} 

}

void Kmeans::calculer(int iter){
	for(int k = 0; k < iter; k++){ 
		for (int i; i < (int)((this->v).size());i++){
			double d = sqrt(pow((((double)((this->v)[i]).get_x())-(double)(((this->tab)[0]).get_x())),2)+pow((((double)((this->v)[i]).get_y())-(double)((this->tab)[0]).get_y()),2));
			int ind;
			for(int j; j < (int)((this->tab).size());j++){
				if(d > sqrt(pow((((double)((this->v)[i]).get_x())-(double)(((this->tab)[j]).get_x())),2)+pow((((double)((this->v)[i]).get_y())-(double)((this->tab)[j]).get_y()),2))){
					d = sqrt(pow((((double)((this->v)[i]).get_x())-((this->tab)[j]).get_x()),2)+pow((((double)((this->v)[i]).get_y())-((this->tab)[j]).get_y()),2));
					ind = j;
				}
			}
			(this->m)[i] = ind;
		}
	}
}
