#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "CenterOfMass.h"


void overallCentroid(VecLHA *vectors, int n, double* x_centroid, double* y_centroid, char typeGeometry){
// Calculate the total_area also
    switch(typeGeometry){
      case 'a':
        *x_centroid = vectors[0].data.square.width / 2.0;
        *y_centroid = vectors[0].data.square.height / 2.0;
        //*total_area = vectors[0].data.square.width * vectors[0].data.square.height;
        break;

      case 'b':
        double sum_x = 0.0;
        double sum_y = 0.0;
        for(int i = 0; i < n; i++){
          sum_x += vectors[i].data.point.x;
          sum_y += vectors[i].data.point.y;
        }

        *x_centroid = sum_x / 3.0;
        *y_centroid = sum_y / 3.0;
        //double area = 0.5 * fabs((vectors[1].x - vectors[0].x) * (vectors[2].y - vectors[0].y) - (vectors[2].x - vectors[0].x) * (vectors[1].y - vectors[0].y));
        //*total_area = area;
        break;
      case 'c'://for the case that the arc is centered -> work out how to implement other cases
        double radius = vectors[0].data.arc.radius;
        double arc_length = vectors[0].data.arc.length;
        double alpha = arc_length / radius;  // angle in radians
        double r_centroid = (radius * sin(alpha / 2.0)) / (alpha / 2.0);// Centroid distance from center along the symmetry axis
        *x_centroid = r_centroid;
        *y_centroid = 0.0;

    }


}
