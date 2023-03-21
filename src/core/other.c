#include "main.h"

void findMinMax(dataStruct *data) {
  double tmpMax = data->vertexArray[0];
  double tmpMin = data->vertexArray[0];

  for (unsigned int i = 0; i < data->idxVertex; i++) {
    if (data->vertexArray[i] >= tmpMax) {
      tmpMax = data->vertexArray[i];
      data->maxMinX[0] = tmpMax;
      data->maxMinY[0] = tmpMax;
      data->maxMinZ[0] = tmpMax;
    } else if (data->vertexArray[i] <= tmpMin) {
      tmpMin = data->vertexArray[i];
      data->maxMinX[1] = tmpMin;
      data->maxMinY[1] = tmpMin;
      data->maxMinZ[1] = tmpMin;
    }
  }
}

void scale(dataStruct *data, int size) {
  for (unsigned int i = 0; i < data->idxVertex; i++) {
    data->vertexArray[i] *= size;
  }
}

void rotate_x(dataStruct *data, double angle) {
  angle *= PI / 180;
  for (unsigned int i = 1; i < data->idxVertex; i += 3) {
    double y = data->vertexArray[i];
    data->vertexArray[i] = data->vertexArray[i] * cos(angle) +
                           data->vertexArray[i + 1] * sin(angle);
    data->vertexArray[i + 1] =
        data->vertexArray[i + 1] * cos(angle) - y * sin(angle);
  }
}

void rotate_y(dataStruct *data, double angle) {
  angle *= PI / 180;
  for (unsigned int i = 0; i < data->idxVertex; i += 3) {
    double x = data->vertexArray[i];
    data->vertexArray[i] = data->vertexArray[i] * cos(angle) -
                           data->vertexArray[i + 2] * sin(angle);
    data->vertexArray[i + 2] =
        data->vertexArray[i + 2] * cos(angle) + x * sin(angle);
  }
}

void rotate_z(dataStruct *data, double angle) {
  angle *= PI / 180;
  for (unsigned int i = 0; i < data->idxVertex; i += 3) {
    double x = data->vertexArray[i];
    data->vertexArray[i] = data->vertexArray[i] * cos(angle) +
                           data->vertexArray[i + 1] * sin(angle);
    data->vertexArray[i + 1] =
        data->vertexArray[i + 1] * cos(angle) - x * sin(angle);
  }
}

void move_x(dataStruct *data, double step) {
  if (step != 0) {
    for (unsigned int i = 0; i < data->idxVertex; i += 3) {
      data->vertexArray[i] += step;
    }
  }
}

void move_y(dataStruct *data, double step) {
  if (step != 0) {
    for (unsigned int i = 0; i < data->idxVertex; i += 3) {
      data->vertexArray[i + 1] += step;
    }
  }
}

void move_z(dataStruct *data, double step) {
  if (step != 0) {
    for (unsigned int i = 0; i < data->idxVertex; i += 3) {
      data->vertexArray[i + 2] += step;
    }
  }
}

double getMaximumDistance(dataStruct *data) {
  double maxDistance = 0.0, distanceX = 0.0, distanceY = 0.0, distanceZ = 0.0;
  distanceX = data->maxMinX[0] - data->maxMinX[1];
  distanceY = data->maxMinY[0] - data->maxMinY[1];
  distanceZ = data->maxMinZ[0] - data->maxMinZ[1];

  if (distanceX > maxDistance) maxDistance = distanceX;
  if (distanceY > maxDistance) maxDistance = distanceY;
  if (distanceZ > maxDistance) maxDistance = distanceZ;

  return maxDistance;
}

void resizeValue(dataStruct *data, double value) {
  findMinMax(data);
  double maxDistance = getMaximumDistance(data);
  double scale = (value - (value * (-1))) / maxDistance;

  for (unsigned int i = 0; i < data->idxVertex; i++) {
    data->vertexArray[i] *= scale;
  }
}
