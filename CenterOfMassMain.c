#include <stdio.h>
#include <stdlib.h>
#include "CenterOfMass.h"

int main(){
  int n=3;

  MassPoint *vectors = (MassPoint*)malloc(n * sizeof(MassPoint));
  vectors[0].x = 0.0;  vectors[0].y = 0.0;  vectors[0].A = 10.0;
  vectors[1].x = 2.0;  vectors[1].y = 0.0;  vectors[1].A = 5.0;
  vectors[2].x = 1.0;  vectors[2].y = 2.0;  vectors[2].A = 8.0;

  double x_c, y_c;
  overallCentroid(vectors, n, &x_c, &y_c);
  printf("The Centroid is at:(%.3f, %.3f)\n", x_c, y_c);
  free(vectors);

  return 0;
}
