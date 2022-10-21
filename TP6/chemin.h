#include "fonctions.h"

#ifndef CHEMIN_H
#define CHEMIN_H

struct chemin{
	pts tab;
	int nbSommets;
};

typedef struct chemin* ch;

ch generation(int n,double min, double max);
void afficherChemin(ch c);
double longueur(ch c);

#endif
