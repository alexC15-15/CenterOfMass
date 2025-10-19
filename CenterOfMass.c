#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "CenterOfMass.h"


void overallCentroid(MassPoint *vectors, int n, double* x_centroid, double* y_centroid){

  double sum_x_weighted = 0.0;
  double sum_y_weighted = 0.0;
  double sum_A = 0.0;

  for(int i = 0; i < n; i++){
    sum_x_weighted += vectors[i].x * vectors[i].A;
    sum_y_weighted += vectors[i].y * vectors[i].A;
    sum_A += vectors[i].A;
  }

  if (sum_A > 0.0) {
        *x_centroid = sum_x_weighted / sum_A;
        *y_centroid = sum_y_weighted / sum_A;
    } else {
        *x_centroid = 0.0;
        *y_centroid = 0.0;
    }

}
