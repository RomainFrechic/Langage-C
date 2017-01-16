#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *fic;
  char nom_fic[255], nom[255], prenom[255], mail[255];
  int t1, t2, t3, t4, t5;

  // stockage des donnees issues de la ligne de commandes
  if(argc != 10){ //10 car num. tel. = 5 blocs d'entiers
    printf("Usage : annuaire nom_fichier nom prenom tel mail\n");
    exit(1);
  }
  strcpy(nom_fic, argv[1]);
  strcpy(nom, argv[2]);
  strcpy(prenom, argv[3]);
  strcpy(mail, argv[9]);
  t1 = atoi(argv[4]);
  t2 = atoi(argv[5]);
  t3 = atoi(argv[6]);
  t4 = atoi(argv[7]);
  t5 = atoi(argv[8]);

  // ouverture du fichier
  fic = fopen(argv[1], "a"); // ouvrir en ajout
  if(fic == NULL){
      printf("Impossible d'ouvrir le fichier %s\n", nom_fic);
      exit(1);
  }

  // ajouter les donnees dans l'annuaire
    fprintf(fic, "\n%s %s %.2d %.2d %.2d %.2d %.2d %s", nom, prenom, t1, t2, t3, t4, t5, mail);

  // fermeture du fichier
  if(fclose(fic) == EOF){
      printf("Probleme de fermeture du fichier %s", nom_fic);
      exit(1);
  }

  printf("Les informations ont ete stockees dans l'annuaire\n");

  return 0;
}
