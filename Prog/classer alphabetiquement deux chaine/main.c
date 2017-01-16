#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VRAI 1
#define FAUX 0

int main(void)
{
  int indice, fin, taille1, taille2, taille;
  char chaine1[255], chaine2[255];

  // lecture des deux mots
  printf("entrez deux chaines : ");
  scanf("%s %s", chaine1, chaine2);

  // on compare au maximum jusqu'a la taille de la chaine la plus petite
  taille1 = strlen(chaine1);
  taille2 = strlen(chaine2);
  if(taille2 > taille1)
    taille = taille1;
  else
    taille = taille2;

  indice = 0;
  fin = FAUX;
  while( (indice < taille) && (!fin) ){
    if(chaine1[indice] > chaine2[indice])
      { // abricot > abracadabra quand indice vaut 3
	fin = VRAI;
	printf("%s > %s\n", chaine1, chaine2);
      }
    else if (chaine1[indice] < chaine2[indice])
      { // abricot < pomme quand indice vaut 0
	fin = VRAI;
	printf("%s < %s\n", chaine1, chaine2);
      }
    else
      indice++;
  }

  // si les deux chaines sont egales sur la plus petite taille
  if(fin == FAUX){
    if(taille2 < taille1)   // abricot abricots
      printf("%s > %s\n", chaine1, chaine2);
    else {
      if(taille2 > taille1)   // voguer vogue
	printf("%s < %s\n", chaine1, chaine2);
      else   // brownie brownie
	printf("%s = %s\n", chaine1, chaine2);
    }
  }
  return 0;
}
