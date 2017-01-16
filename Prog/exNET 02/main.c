#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int somme, n_premiers_entiers, indice ;

  if(argc != 2){
    printf("usage : somme N\n");
    exit(1);
  }

  n_premiers_entiers = atoi(argv[1]);
  if(n_premiers_entiers == 0){
    printf("vous n'avez pas entre un chiffre ou vous avez entre 0\n");
    exit(1);
  }

  printf("la somme des %d premiers entiers est ", n_premiers_entiers);

  indice = 0;
  somme = 0;
  while(indice <= n_premiers_entiers){
    somme += indice;
    indice++;
  }
  printf("%d\n", somme);

  return 0;
}
