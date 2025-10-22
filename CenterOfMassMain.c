#include <stdio.h>
#include <stdlib.h>
#include "CenterOfMass.h"
#include <math.h>

int main(){
  char typeGeometry[10];
  int n=0;
  printf("Welcome user!\n");
  printf("For which kind of body are we searching for?\n a Square\n b Triangle\n c Arc\n d a n-body type of geometry\n");
  scanf("%s", typeGeometry);
  printf("Chosen:%s", typeGeometry);

  VecLHA *vectors = NULL;

  switch(typeGeometry[0]){
    case 'a':
      n = 1;
      vectors = (VecLHA*)malloc(n * sizeof(VecLHA));
      vectors[0].type = 'a';

      printf("Enter width: ");
      scanf("%lf", &vectors[0].data.square.width);
      printf("Enter height: ");
      scanf("%lf", &vectors[0].data.square.height);
      break;

    case 'b':
      n=3;
      vectors = (VecLHA*)malloc(n * sizeof(VecLHA));
      for(int i = 0; i < n; i++){
        vectors[i].type = 'b';
        printf("Please enter the coordinates for point %d [x, y]\n", i + 1);
        printf("x: ");
        scanf("%lf", &vectors[i].data.point.x);
        printf("y: ");
        scanf("%lf", &vectors[i].data.point.y);
      }
      break;

    case 'c':
      vectors = (VecLHA*)malloc(n * sizeof(VecLHA));
      vectors[0].type = 'c';
      printf("What's the radius: ");
      scanf("%lf", &vectors[0].data.arc.radius);
      printf("What's the total length of the arc?\tlength: ");
      scanf("%lf", &vectors[0].data.arc.length);
      printf("What's the circumference *pi: ");
      scanf("%lf", &vectors[0].data.arc.circumference);
      n=1;

    default:
      printf("Invalid choice!\n");
      return 1;
  }

  double x_c, y_c;
  overallCentroid(vectors, n, &x_c, &y_c,typeGeometry[0]);
  printf("The Centroid is at:(%.3f, %.3f)\n", x_c, y_c);
  free(vectors);

  return 0;
}

/**
*To do:
* //in CenterOfMass.c
* // Calculate the total_area also
* //for the case that the arc is centered -> work out how to implement other cases
*
*
**/
