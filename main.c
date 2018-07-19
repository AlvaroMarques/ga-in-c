#include "population.h"


int main(){
  srand(time(NULL));
  Chromossome population;
  start_living(&population, "The Dirk Gently's Holistic Agency", 200000);
  return 0;
}
