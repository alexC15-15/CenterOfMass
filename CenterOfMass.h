#ifndef CENTER_OF_MASS_H
#define CENTER_OF_MASS_H

typedef struct{
  char type;  // 'a', 'b', 'c', etc.
  union {
    struct { double x, y, A; } point;
    struct { double width, height; } square;
    struct { double radius, length, circumference; } arc;
  } data;
} VecLHA;

void overallCentroid(VecLHA* vectors, int n, double* x_centroid, double* y_centroid, char typeGeometry);

#endif
