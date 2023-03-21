#include "main.h"

int main() {
  dataStruct data;
  parserFile("core/objects/cube.obj", &data);

  for (unsigned int i = 0; i < data.idxVertex; i++) {
    printf("%f ", data.vertexArray[i]);
    if (!((i + 1) % 3)) printf("\n");
  }

  printf("\n");

  for (unsigned int j = 0; j < data.idxPolygon; j++) {
    printf("%d ", data.polygonArray[j]);
    if (!((j + 1) % 6)) printf("\n");
    // if (!((j + 1) % 3)) printf("\n");
  }
  // printf("\n");

  // findMinMax(&data);
  // for (int k = 0; k < 1; k++) {
  //   printf("|max = %f, min = %f|\n", data.maxMinX[0], data.maxMinX[1]);
  //   printf("|max = %f, min = %f|\n", data.maxMinY[0], data.maxMinY[1]);
  //   printf("|max = %f, min = %f|\n", data.maxMinZ[0], data.maxMinZ[1]);
  // }
  // printf("\n");

  // moveToCenter(&data);
  // for (int i = 0; i < data.idxVertex; i++) {
  //   printf("%f ", data.vertexArray[i]);
  //   if (!((i + 1) % 3)) printf("\n");
  // }
  // printf("\n");

  // move_z(&data, 2);
  // for (int i = 0; i < data.idxVertex; i++) {
  //   printf("%f ", data.vertexArray[i]);
  //   if (!((i + 1) % 3)) printf("\n");
  // }

  // double get = getMaximumDistance(&data);
  // printf("%f \n" ,get);

  // resizeValue(&data, 2);
  //   for (int i = 0; i < data.idxVertex; i++) {
  //     printf("%f ", data.vertexArray[i]);
  //     if (!((i + 1) % 3)) printf("\n");
  //   }

  return 0;
}
