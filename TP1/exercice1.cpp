#include <iostream>

/* Echange par passage par référence : la signature de la fonction, 
 * avec les &, permet de préciser qu'une référence sur les arguments 
 * sera utilisée, et non pas la valeur des arguments. 
 */
void echanger(int &a, int &b) {
    b=a+b;
    a=b-a;
    b=b-a;
}

using namespace std;

int main() {
    int a=10;
    int b=10;
    
    cout << "Saisir deux valeurs au clavier" << endl;
    cin >> a >> b;
    echanger(a,b);
    
    cout << "Valeurs saisies après échange : " << a << " et " << b << endl;

    return 0;
}
