#include <stdio.h> //tableau a deux dimension//

#define NB_LIGNES 2
#define NB_COLS   3

int main(void)
{
  int cases[NB_LIGNES][NB_COLS] = {1, 2, 3, 4, 5, 6};
  int ind_l, ind_c ; //indices pour parcourir en ligne et col.

  ind_l = 0;
  while(ind_l < NB_LIGNES){
    ind_c = 0;
    while(ind_c < NB_COLS){
      printf("%d ", cases[ind_l][ind_c]);
      ind_c++;
    }
    printf("\n");
    ind_l++;
  }

  return 0;
}
