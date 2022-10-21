#include "chemin.h"

int main(){
	pts p = creer(5.0,5.0);
	affichage(p); 
	struct point ptn = translation(*p,5.0,5.0);
	affichage(&ptn);
	modifTranslation(&ptn,-5.0,-5.0);
	affichage(&ptn);
	char* a = "Bonjour";
	char* b = "Bonj";
	bool t = superieur_ou_egal(( void *)&a, (void *)&b, &superieur_ou_egal_str);
	if(t){
		printf("true\n");
	}else{
		printf("false\n");
	};
	afficher((void*) a, &afficherStr);
	int c = 45;
	int d = 65;
	int e = 5;
	pts2 p2 = creer2((void*) &c,(void*) &d,sizeof(int));
	afficher2(p2,&affichageInt);
	ch chem = generation(2,1.0,15.0);
	afficherChemin(chem);
	double l = longueur(chem);
	printf("%f\n",l);
	pts2 tr = translation2(p2,(void*) &e, (void*) &e, &transInt);
	afficher2(tr,&affichageInt);
	free(chem->tab);
	free(chem);
	free(p);
	liberer(&p2,&libererInt);
	liberer(&tr,&libererInt);
	return EXIT_SUCCESS;
}
