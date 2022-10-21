#include "chemin.h"

struct point2{
	void* x;
	void* y;
};

void affichage(pts p){
	printf("[%4.2f, %4.2f]\n", (*p).x,(*p).y);
};

pts creer(double x, double y){
	pts p = malloc(sizeof(struct point));
	p->x = x;
	p->y = y;
	return p;
};

struct point translation(struct point ptn, double dx, double dy){
	struct point p;
	p.x = ptn.x+dx;
	p.y = ptn.y+dy;
	return p;	
}

void modifTranslation(pts p, double dx, double dy){
	p->x = p->x + dx;
	p->y = p->y + dy;
};

ch generation(int n,double min, double max){
	srand(time(NULL));
	ch c = malloc(sizeof(struct chemin));
	c->nbSommets = n;
	pts tab = malloc((n*sizeof(struct point)));
	for(int i = 0; i < n; i++){
		pts p = creer((rand() % (int)(max - min + 1)) + min,(rand() % (int)(max - min + 1)) + min);
		tab[i] = *(p);
		free(p);
	}
	c->tab = tab;
	return c;
}

void afficherChemin(ch c){
	printf("{");
	for(int i = 0; i < c->nbSommets; i++){
		affichage(&(c->tab[i]));
	}
	printf("}\n");
}

double longueur(ch c){
	double l = 0.0;
	for (int i =0; i < c->nbSommets-1; i++){
		l = l + sqrt(pow((c->tab[i+1].x - c->tab[i].x),2) + pow((c->tab[i+1].y - c->tab[i].y),2));
	}
	return l;
}

bool superieur_ou_egal( void *val_1,void *val_2,bool (* est_superieur)(void*, void *)) {
	return (* est_superieur)(val_1 , val_2);
};

bool superieur_ou_egal_int(void *val_1 , void *val_2){
	int *a = (int*) val_1;
	int *b = (int*) val_2;
	return *a >= *b;
};

bool superieur_ou_egal_str(void *val_1 , void *val_2){
	char *a = (char*) val_1;
	char *b = (char*) val_2;
	return (strcmp(a,b) <= 0);
};

void afficher(void* val,void (* print)(void*)){
	print(val);
}

void afficherInt(void* val){
	printf("%d\n", *((int*) val));
}

void afficherStr(void* val){
	printf("%s\n", (char*) val);
}

void afficher2(pts2 p,void (* affichage)(pts2)){
	affichage(p);
}

void affichageInt(pts2 p){
	printf("[%d, %d]\n", *((int*)(*p).x),*((int*)(*p).y));
};

void affichageFloat(pts2 p){
	printf("[%4.2f, %4.2f]\n", *((float*)(*p).x),*((float*)(*p).y));
};

void affichageDouble(pts2 p){
	printf("[%lf, %lf]\n", *((double*)(*p).x),*((double*)(*p).y));
};

pts2 creer2(void* x, void* y, size_t taille){
	pts2 p = malloc(sizeof(struct point2));
	p->x = malloc(taille);
	p->y = malloc(taille);
	memcpy(p->x,x,taille);
	memcpy(p->y,y,taille);
	return p;
};

pts2 translation2(pts2 ptn, void* dx, void* dy,pts2 (* trans)(pts2, void*, void*)) {
	return (*trans)(ptn,dx,dy);
}

pts2 transInt(pts2 ptn, void* dx, void* dy){
	int x = *((int*) ptn->x) + *((int*) dx);
	int y = *((int*) ptn->y) + *((int*) dy);
	pts2 p = creer2((void*)&x,(void*)&y,sizeof(int));
	return p;
}

pts2 transFloat(pts2 ptn, void* dx, void* dy){
	float x = *((float*) ptn->x) + *((float*) dx);
	float y = *((float*) ptn->y) + *((float*) dy);
	pts2 p = creer2((void*)&x,(void*)&y,sizeof(float));
	return p;
}

pts2 transDouble(pts2 ptn, void* dx, void* dy){
	double x = *((double*) ptn->x) + *((double*) dx);
	double y = *((double*) ptn->y) + *((double*) dy);
	pts2 p = creer2((void*)&x,(void*)&y,sizeof(double));
	return p;
}

void liberer(pts2* p, void(* liberer_val)(pts2*)){
	(*liberer_val)(p);	
}

void libererInt(pts2* p){
	free((int*) (*p) -> x);
	free((int*) (*p) -> y);
	free(*p);
}

void libererFloat(pts2* p){
	free((float*) (*p) -> x);
	free((float*) (*p) -> y);
	free(*p);
}

void libererDouble(pts2* p){
	free((double*) (*p) -> x);
	free((double*) (*p) -> y);
	free(*p);
}




