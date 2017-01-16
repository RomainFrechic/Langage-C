#include <stdio.h>

int main(void){

  long grand_entier = 100000;
  int entier_1 = 32767;
  int entier_2 = -6;
  int entier_3 = 15;
  short petit_entier = 128;
  unsigned int entier_ns = 64000;

  long double tres_grand_reel = 1.2e+10 ;
  double grand_reel =  1000000000.0;
  float reel = 12.5;

  char caractere = 'b';

  printf("--------- ENTIERS ---------\n");
  printf("%d\n%d\n%d\n_____\n", entier_1, entier_2, entier_3);
  printf("%5d\n%5d\n%5d\n_____\n", entier_1, entier_2, entier_3);
  printf("%+6d\n%+6d\n%+6d\n_____\n", entier_1, entier_2, entier_3);
  printf("%ld\n%hd\n%u\n", grand_entier, petit_entier, entier_ns);

  printf("\n-------- CHAINES ----------\n");
  printf("%c\n_____\n", caractere);
  printf("%4c\n_____\n", caractere);
  printf("%s\n_____\n", "hello");

  printf("\n-------- REELS ----------\n");
  printf("%f\n%.2f\n%+.3f\n_____\n", reel, reel, reel);
  printf("%f\n%e\n%.2e\n_____\n", grand_reel, grand_reel, grand_reel);
  printf("%Lf\n%Le\n", tres_grand_reel, tres_grand_reel);
  return 0;
}

