#include "chromossome.h"


int main(){
  srand(time(NULL));
  Chromossome c1,c2;
  c1.mutate = 100;
  c2.mutate = 100;
  initialize_string(&c1.string);
  initialize_string(&c2.string);

  generate(c1);
  generate(c2);
  print_string(c1);
  print_string(c2);
  mutate(c1);
  mutate(c2);
  print_string(c1);
  print_string(c2);

  Chromossome *childrens;
  childrens = crossover(c1,c2);

  print_string(childrens[0]);
  print_string(childrens[1]);

  return 0;
}
