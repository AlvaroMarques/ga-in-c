#include "population.h"


int main(){
  srand(time(NULL));
  Chromossome *population;
  generate_population(&population);
  printf("\n");
  mutations(population,100);
  sorted_values(population,"abc");
  printf("\n");
  for(char i=0;i<POPULATION_SIZE;i++){
    printf("%d ",population[i].error );
  }
  printf("\n");
  return 0;
}
