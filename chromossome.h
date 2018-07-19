#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define CHAR_SIZE 35

typedef struct{
  char *string;
  int error;
}Chromossome;
void initialize_string(char **string);
void print_string(Chromossome chromo);
void generate(Chromossome chromo);
void mutate(Chromossome chromo,char mutate);
void delete_chromo(Chromossome chromo);
void error(Chromossome chromo,int *error, char *target);
Chromossome *crossover(Chromossome chromo1, Chromossome chromo2);
#endif
