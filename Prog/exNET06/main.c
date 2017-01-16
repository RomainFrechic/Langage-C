#include <stdio.h>

void test (void) {

  int i;

  for(i = 10; i < 100; i+=30)
    printf("\ti dans test vaut %d \n", i);
}

int main(void)
{
  int i = 0;

  for(i = 0; i <= 3; i++){
    printf("i dans main vaut %d et \n", i);
    test();
  }

  return 0;
}
