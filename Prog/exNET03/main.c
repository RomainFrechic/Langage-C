#include <stdio.h>

int main(void){

  long grand_entier;
  int entier_1;
  int entier_2;
  int entier_3;
  short petit_entier;
  unsigned int entier_ns;

  long double tres_grand_reel;
  float reel;

  // lecture des donnees
  printf("entrez trois entiers : ");
  scanf("%d %d %d", &entier_1, &entier_2, &entier_3);
  printf("entrez un grand entier, un petit et un non signe : ");
  scanf("%ld %hd %u", &grand_entier, &petit_entier, &entier_ns);

  printf("entrez un reel et un tres grand reel : ");
  scanf("%f %Lf", &reel, &tres_grand_reel);

  // affichage des donnees
  printf("--------- ENTIERS ---------\n");
  printf("%d\n%d\n%d\n_____\n", entier_1, entier_2, entier_3);
  printf("%5d\n%5d\n%5d\n_____\n", entier_1, entier_2, entier_3);
  printf("%+6d\n%+6d\n%+6d\n_____\n", entier_1, entier_2, entier_3);
  printf("%ld\n%hd\n%u\n", grand_entier, petit_entier, entier_ns);

  printf("\n-------- REELS ----------\n");
  printf("%f\n%.2f\n%+.3f\n_____\n", reel, reel, reel);
  printf("%.9Lf\n%Le\n", tres_grand_reel, tres_grand_reel);

  return 0;
}
