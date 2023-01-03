#ifndef KMEANS_HPP
#define KMEANS_HPP
#include <iostream>
#include <vector>
#include <map>
#include "point.hpp"

using namespace std;

class Kmeans{
	private:
		int k;
		vector<Point> v;
		map<int,int> m;
		vector<Point> tab;
	public:
		Kmeans(int k);
		void initialiser();
		void calculer(int iter);
		void afficher();
		
};

#endif
