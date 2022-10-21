#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifndef FONCTIONS_H
#define FONCTIONS_H

struct point{
	double x;
	double y;
};



typedef struct point* pts;
typedef struct point2* pts2;

void affichage(pts p);
pts creer(double x, double y);
struct point translation(struct point ptn, double dx, double dy);
void modifTranslation(pts ptn, double dx, double dy);
bool superieur_ou_egal( void*, void*, bool (* est_superieur)(void*, void *));
bool superieur_ou_egal_int(void *val_1 , void *val_2);
bool superieur_ou_egal_str(void *val_1 , void *val_2);
void afficher(void* val,void (* print)(void*));
void afficherInt(void* val);
void afficherStr(void* val);
void afficher2(pts2 p,void (* affichage)(pts2));
void affichageInt(pts2 p);
void affichageFloat(pts2 p);
void affichageDouble(pts2 p);
pts2 creer2(void* x, void* y,size_t taille);
pts2 translation2(pts2 ptn, void* dx, void* dy,pts2 (* trans)(pts2, void*, void*));
pts2 transInt(pts2 ptn, void* dx, void* dy);
pts2 transFloat(pts2 ptn, void* dx, void* dy);
pts2 transDouble(pts2 ptn, void* dx, void* dy);
void liberer(pts2* p, void(* liberer_val)(pts2*));
void libererInt(pts2* p);
void libererFloat(pts2* p);
void libererDouble(pts2* p);

#endif
