#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void verif_et_recup_arg(int nb, char *arguments[], int nb_souhaite, char *chaine)
{
  if(nb != nb_souhaite){
    printf("Usage : annuaire nom_fichier\n");
    exit(1);
  }

  strcpy(chaine, arguments[1]);
}

int main(int argc, char *argv[])
{
  FILE *fic;
  int nb_lignes, t1, t2, t3, t4, t5;
  char nom_fic[255], nom[255], prenom[255], mail[255];

  verif_et_recup_arg(argc, argv, 2, nom_fic);

  // ouverture du fichier
  fic = fopen(nom_fic, "r"); // ouvrir en lecture
  if(fic == NULL){
      printf("Impossible d'ouvrir le fichier %s\n", nom_fic);
      exit(1);
  }
  printf(".............. Ouverture du fichier %s\n\n", nom_fic);

  // recuperer les donnees de l'annuaire
  nb_lignes = 0;
  while(fscanf(fic, "%s %s %d %d %d %d %d %s", nom, prenom,\
               &t1, &t2, &t3, &t4, &t5, mail) != EOF){
    printf("\tnom = %s\n \tprenom = %s\n \ttel = %.2d %.2d %.2d %.2d %.2d\n \tmail = %s\n\n",\
	       nom, prenom, t1, t2, t3, t4, t5, mail);
    nb_lignes++;
  }
  printf("le fichier %s comporte %d lignes\n", nom_fic, nb_lignes);

  // fermeture du fichier
  if(fclose(fic) == EOF){
      printf("Probleme de fermeture du fichier %s", nom_fic);
      exit(1);
  }
  printf(".............. Fermeture du fichier %s\n", nom_fic);

  return 0;
}
