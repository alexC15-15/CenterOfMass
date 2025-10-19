#ifndef CENTER_OF_MASS_H
#define CENTER_OF_MASS_H

typedef struct{
  double x;
  double y;
  double A;
} MassPoint;

void overallCentroid(MassPoint* vectors, int n, double* x_centroid, double* y_centroid);

#endif
