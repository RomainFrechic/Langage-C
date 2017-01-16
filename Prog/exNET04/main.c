#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char reponse;

  printf("Que voulez-vous faire ?\n");
  printf("q pour quitter\n");
  printf("s pour sauvegarder\n");
  printf("o pour ouvrir un nouveau fichier\n");

  scanf("%c", &reponse);

  switch(reponse){
  case 'q': printf("au revoir\n"); break;
  case 's': printf("sauvegarde \n"); break;
  case 'o': printf("ouverture\n");break;
  default: printf("ce n'est pas un choix valable\n");
  }
}
