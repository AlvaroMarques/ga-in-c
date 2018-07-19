#include "chromossome.h"

void initialize_string(char **string){
  *string = malloc(CHAR_SIZE);
  return;
}

void print_string(Chromossome chromo){
  for(char i=0;i<CHAR_SIZE;i++){
    printf("%d ", *(chromo.string+i));
  }
  printf("\n");
}

void generate(Chromossome chromo){
  for(char i = 0 ;i< CHAR_SIZE;i++){
    chromo.string[i] = rand()%128;
  }
}

void mutate(Chromossome chromo, char mutate){
  if(rand()%100<mutate){
    chromo.string[rand()%CHAR_SIZE] = rand()%128;
  }
}

void error(Chromossome chromo,int *error, char *target){
  int sum_error=0;
  for(char i=0;i<CHAR_SIZE;i++){
    sum_error = sum_error + (chromo.string[i] - target[i])*(chromo.string[i] - target[i]);
  }
  *error = sum_error;
}

Chromossome *crossover(Chromossome chromo1, Chromossome chromo2){
  Chromossome *crossed;
  Chromossome children1,children2;

  initialize_string(&children1.string);
  initialize_string(&children2.string);

  char change_point = rand()%CHAR_SIZE;

  for(char i=0;i<CHAR_SIZE;i++){
    if(i<change_point){
      children1.string[i] = chromo1.string[i];
      children2.string[i] = chromo2.string[i];
    }else{
      children1.string[i] = chromo2.string[i];
      children2.string[i] = chromo1.string[i];
    }
  }

  crossed = malloc(2 * sizeof(Chromossome));

  crossed[0] = children1;
  crossed[1] = children2;

  return crossed;
}

















//
