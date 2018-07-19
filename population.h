#ifndef POPULATION_H
#define POPULATION_H

#include "chromossome.h"

#define POPULATION_SIZE 10

void generate_population(Chromossome **population_pointer);
void mutations(Chromossome *population, char mutation_p);
void get_errors(Chromossome *population, char *target);
void sorted_values(Chromossome *population, char *target);
void start_living(Chromossome *population, char *target, int ngens);

#endif
