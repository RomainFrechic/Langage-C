#include <iostream>
using namespace std;

int main()
{
    int ageUtilisateur(18); //Une variable pour contenir l'�ge de l'utilisateur

    int& maReference(ageUtilisateur); //Et une r�f�rence sur la variable 'ageUtilisateur'

    //On peut utiliser � partir d'ici
    //'ageUtilisateur' ou 'maReference' indistinctement
    //Puisque ce sont deux �tiquettes de la m�me case en m�moire

    cout << "Vous avez " << ageUtilisateur << "  ans. (via variable)" << endl;
    //On affiche, de la mani�re habituelle

    cout << "Vous avez " << maReference << " ans. (via reference)" << endl;
    //Et on affiche en utilisant la r�f�rence

    return 0;
}
