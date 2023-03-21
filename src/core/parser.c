#include "main.h"

int parserFile(char *filePath, dataStruct *data) {
  int error = OK;
  FILE *f = fopen(filePath, "r");
  data->idxVertex = 0;
  data->idxPolygon = 0;
  // выделили для массива Вертекс 1 ячейку типа дабл
  data->vertexArray = calloc(1, sizeof(double));
  // выделили для массива Полигон 1 ячейку типа инт
  data->polygonArray = calloc(1, sizeof(unsigned));

  if (f == NULL) {
    error = FAIL;
    // printf("FILE IS NOT OPENED: <WRONG PATH>\n");
  } else {
    // printf("FILE IS OPENED\n");
    char c, tmp;
    while (!feof(f)) {
      c = fgetc(f);  // 1st iteration char c == 'v'
      tmp = c;       // char tmp == c ---> tmp == 'v'
      if (tmp == 'v') {  // зашли сюда и вызвали вертекс парс
        vertexParser(f, data);
      } else if (tmp == 'f') {
        polygonParser(f, data);
      }
    }
  }
  if (!data->idxVertex) free(data->vertexArray);
  if (!data->idxPolygon) free(data->polygonArray);
  fclose(f);
  return error;
}

/*
1.добавили памяти в указатель на 3 ячейки типа дабл // realloc(data->vertex)

2.прошли циклом 3 раза и заполнили нулями все 3 ячейки массива вертекс по
индексу вертекса; etc: vertexArray[0(idxV-0), 0(idxV-1), 0(idxV-2)]
//for(int i; i<3; i++)

3.взяли из файла строчку и перевели все вершины в дабл записав массив вертекс по
индесу вертекса; etc: vertexArray[0(idxV-0),0(idxV-1),(idxV-2)]  // fscanf

4.индекс вертекса увеличили на 3: etc: idxVertex вначале равен 0 в конце функции
он увеличивается на 3 // idx +=3
*/

int vertexParser(FILE *f, dataStruct *data) {
  int error = OK;
  data->vertexArray =
      realloc(data->vertexArray, (data->idxVertex + 3) * sizeof(double));
  if (data->vertexArray == NULL) {
    error = FAIL;
  }
  for (unsigned int i = 0; i < 3; i++) {
    data->vertexArray[data->idxVertex + i] = 0;
  }
  fscanf(f, "%lf %lf %lf", &data->vertexArray[data->idxVertex],
         &data->vertexArray[data->idxVertex + 1],
         &data->vertexArray[data->idxVertex + 2]);
  data->idxVertex += 3;
  return error;
}

int polygonParser(FILE *f, dataStruct *data) {
  int error = OK;
  data->polygonArray =
      realloc(data->polygonArray, (data->idxPolygon + 6) * sizeof(unsigned));
  if (data->polygonArray == NULL) {
    error = FAIL;
  }

  for (unsigned int i = 0; i < 6; i++) {
    data->polygonArray[data->idxPolygon + i] = 0;
  }
  int x, y, z;
  fscanf(f, "%d %d %d", &x, &y, &z);
  data->polygonArray[data->idxPolygon] = x - 1;      // 4
  data->polygonArray[data->idxPolygon + 1] = y - 1;  // 2
  data->polygonArray[data->idxPolygon + 2] = y - 1;  // 2
  data->polygonArray[data->idxPolygon + 3] = z - 1;  // 0
  data->polygonArray[data->idxPolygon + 4] = z - 1;  // 0
  data->polygonArray[data->idxPolygon + 5] = x - 1;  // 0
  data->idxPolygon += 6;

  //  data->polygonArray[data->idxPolygon] = x - 1;      // 4
  // data->polygonArray[data->idxPolygon + 1] = y - 1;  // 2
  // data->polygonArray[data->idxPolygon + 2] = z - 1;  // 2
  // data->idxPolygon += 3;

  return error;
}
