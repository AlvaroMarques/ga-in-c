#include "population.h"

void print_population(Chromossome *population){
  for(char i=0;i<POPULATION_SIZE;i++){
    print_string(*(population+i));
  }
}

void get_errors(Chromossome *population,char *target){
  for(char i=0;i<POPULATION_SIZE;i++){
    error(population[i],&population[i].error,target);
  }
}

void generate_population(Chromossome **population_pointer){
  *population_pointer = malloc(POPULATION_SIZE * sizeof(Chromossome));
  Chromossome c;
  for(char i=0;i<POPULATION_SIZE;i++){
    initialize_string(&c.string);
    generate(c);
    (*population_pointer)[i] = c;
  }
  return;
}

void mutations(Chromossome *population, char mutation_p){
  for(char i=0;i<POPULATION_SIZE;i++){
    mutate(*(population+i),mutation_p);
  }
}

void sorted_values(Chromossome *population, char *target){
  get_errors(population,target);
   //insertion sort that i found in https://www.geeksforgeeks.org/insertion-sort/ (yes i'm to lazy to do it myself)
   int i, j;
   Chromossome key;
   for (i = 1; i < POPULATION_SIZE; i++){
       key = population[i];
       j = i-1;
       while (j >= 0 && population[j].error > key.error)
       {
           population[j+1] = population[j];
           j = j-1;
       }
       population[j+1] = key;
   }
  return;
}
void start_living(Chromossome *population, char *target, int ngens){
  generate_population(&population);
  for(int i=0;i<ngens;i++){
    print_population(population);
    mutations(population,3);
    sorted_values(population,target);
    Chromossome *children = crossover(population[0],population[1]);
    population[POPULATION_SIZE-1] = children[0];
    population[POPULATION_SIZE-2] = children[1];
    print_string(population[0]);
    if (strcmp(population[0].string,target) == 0) return;
  }
}
















//
