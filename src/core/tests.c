#include <check.h>

#include "main.h"

void run_tests(void);

START_TEST(parserFile_fail) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    ck_assert_double_eq_tol(data.vertexArray[0], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 1, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(parserFile_vertex) {
  dataStruct data;

  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    ck_assert_double_eq_tol(data.vertexArray[0], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 1, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(parserFile_polygon) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    ck_assert_uint_eq(data.polygonArray[0], 4);
    ck_assert_uint_eq(data.polygonArray[1], 2);
    ck_assert_uint_eq(data.polygonArray[2], 2);
    ck_assert_uint_eq(data.polygonArray[3], 0);
    ck_assert_uint_eq(data.polygonArray[4], 0);
    ck_assert_uint_eq(data.polygonArray[5], 4);

    ck_assert_uint_eq(data.polygonArray[6], 2);
    ck_assert_uint_eq(data.polygonArray[7], 7);
    ck_assert_uint_eq(data.polygonArray[8], 7);
    ck_assert_uint_eq(data.polygonArray[9], 3);
    ck_assert_uint_eq(data.polygonArray[10], 3);
    ck_assert_uint_eq(data.polygonArray[11], 2);

    ck_assert_uint_eq(data.polygonArray[12], 6);
    ck_assert_uint_eq(data.polygonArray[13], 5);
    ck_assert_uint_eq(data.polygonArray[14], 5);
    ck_assert_uint_eq(data.polygonArray[15], 7);
    ck_assert_uint_eq(data.polygonArray[16], 7);
    ck_assert_uint_eq(data.polygonArray[17], 6);

    ck_assert_uint_eq(data.polygonArray[18], 1);
    ck_assert_uint_eq(data.polygonArray[19], 7);
    ck_assert_uint_eq(data.polygonArray[20], 7);
    ck_assert_uint_eq(data.polygonArray[21], 5);
    ck_assert_uint_eq(data.polygonArray[22], 5);
    ck_assert_uint_eq(data.polygonArray[23], 1);

    ck_assert_uint_eq(data.polygonArray[24], 0);
    ck_assert_uint_eq(data.polygonArray[25], 3);
    ck_assert_uint_eq(data.polygonArray[26], 3);
    ck_assert_uint_eq(data.polygonArray[27], 1);
    ck_assert_uint_eq(data.polygonArray[28], 1);
    ck_assert_uint_eq(data.polygonArray[29], 0);

    ck_assert_uint_eq(data.polygonArray[30], 4);
    ck_assert_uint_eq(data.polygonArray[31], 1);
    ck_assert_uint_eq(data.polygonArray[32], 1);
    ck_assert_uint_eq(data.polygonArray[33], 5);
    ck_assert_uint_eq(data.polygonArray[34], 5);
    ck_assert_uint_eq(data.polygonArray[35], 4);

    ck_assert_uint_eq(data.polygonArray[36], 4);
    ck_assert_uint_eq(data.polygonArray[37], 6);
    ck_assert_uint_eq(data.polygonArray[38], 6);
    ck_assert_uint_eq(data.polygonArray[39], 2);
    ck_assert_uint_eq(data.polygonArray[40], 2);
    ck_assert_uint_eq(data.polygonArray[41], 4);

    ck_assert_uint_eq(data.polygonArray[42], 2);
    ck_assert_uint_eq(data.polygonArray[43], 6);
    ck_assert_uint_eq(data.polygonArray[44], 6);
    ck_assert_uint_eq(data.polygonArray[45], 7);
    ck_assert_uint_eq(data.polygonArray[46], 7);
    ck_assert_uint_eq(data.polygonArray[47], 2);

    ck_assert_uint_eq(data.polygonArray[48], 6);
    ck_assert_uint_eq(data.polygonArray[49], 4);
    ck_assert_uint_eq(data.polygonArray[50], 4);
    ck_assert_uint_eq(data.polygonArray[51], 5);
    ck_assert_uint_eq(data.polygonArray[52], 5);
    ck_assert_uint_eq(data.polygonArray[53], 6);

    ck_assert_uint_eq(data.polygonArray[54], 1);
    ck_assert_uint_eq(data.polygonArray[55], 3);
    ck_assert_uint_eq(data.polygonArray[56], 3);
    ck_assert_uint_eq(data.polygonArray[57], 7);
    ck_assert_uint_eq(data.polygonArray[58], 7);
    ck_assert_uint_eq(data.polygonArray[59], 1);

    ck_assert_uint_eq(data.polygonArray[60], 0);
    ck_assert_uint_eq(data.polygonArray[61], 2);
    ck_assert_uint_eq(data.polygonArray[62], 2);
    ck_assert_uint_eq(data.polygonArray[63], 3);
    ck_assert_uint_eq(data.polygonArray[64], 3);
    ck_assert_uint_eq(data.polygonArray[65], 0);

    ck_assert_uint_eq(data.polygonArray[66], 4);
    ck_assert_uint_eq(data.polygonArray[67], 0);
    ck_assert_uint_eq(data.polygonArray[68], 0);
    ck_assert_uint_eq(data.polygonArray[69], 1);
    ck_assert_uint_eq(data.polygonArray[70], 1);
    ck_assert_uint_eq(data.polygonArray[71], 4);

    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(parserFile_structData) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    findMinMax(&data);

    ck_assert_uint_eq(data.idxVertex, 24);
    ck_assert_uint_eq(data.idxPolygon, 72);

    ck_assert_double_eq_tol(data.maxMinX[0], 1, 1e-6);
    ck_assert_double_eq_tol(data.maxMinY[0], 1, 1e-6);
    ck_assert_double_eq_tol(data.maxMinZ[0], 1, 1e-6);

    ck_assert_double_eq_tol(data.maxMinX[1], -1, 1e-6);
    ck_assert_double_eq_tol(data.maxMinY[1], -1, 1e-6);
    ck_assert_double_eq_tol(data.maxMinZ[1], -1, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(scale_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    scale(&data, 3);
    ck_assert_double_eq_tol(data.vertexArray[0], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -3, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -3, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 3, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 3, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -3, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -3, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 3, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -3, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 3, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(resizeValue_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    resizeValue(&data, 2);
    ck_assert_double_eq_tol(data.vertexArray[0], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -2, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -2, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 2, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 2, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -2, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -2, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 2, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -2, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 2, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(rotateX_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    rotate_x(&data, 2);
    ck_assert_double_eq_tol(data.vertexArray[0], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -1.034290, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -0.964491, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 0.964491, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1.034290, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1.034290, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -0.964491, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 0.964491, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 1.034290, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(rotateY_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    rotate_y(&data, 2);
    ck_assert_double_eq_tol(data.vertexArray[0], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -0.964491, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -0.964491, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 1.034290, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1.034290, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1.034290, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -1.034290, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 0.964491, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 0.964491, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(rotateZ_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    rotate_z(&data, 2);
    ck_assert_double_eq_tol(data.vertexArray[0], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1.034290, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -0.964491, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 1, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(moveX_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    move_x(&data, 2);
    ck_assert_double_eq_tol(data.vertexArray[0], 3.00000, 1e-7);
    ck_assert_double_eq_tol(data.vertexArray[1], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 3.00000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 3.00000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 3.00000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], 1.00000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], 1.00000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], 1.00000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], 1.00000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 1, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(moveY_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    move_y(&data, 2);
    ck_assert_double_eq_tol(data.vertexArray[0], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 3.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], 1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 3.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], 1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 3.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], 1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 3.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], 1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 1, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(moveZ_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    move_z(&data, 2);
    ck_assert_double_eq_tol(data.vertexArray[0], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[1], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], 1.000000, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], 1.000000, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 3.000000, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 3.000000, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], 1.000000, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], 1.000000, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 3.000000, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -1.000000, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 3.000000, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(move_vertexZero) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    move_x(&data, 0);
    move_y(&data, 0);
    move_z(&data, 0);
    ck_assert_double_eq_tol(data.vertexArray[0], 1, 1e-7);
    ck_assert_double_eq_tol(data.vertexArray[1], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[2], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[3], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[4], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[5], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[6], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[7], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[8], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[9], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[10], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[11], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[12], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[13], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[14], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[15], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[16], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[17], -1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[18], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[19], 1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[20], 1, 1e-6);

    ck_assert_double_eq_tol(data.vertexArray[21], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[22], -1, 1e-6);
    ck_assert_double_eq_tol(data.vertexArray[23], 1, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

START_TEST(parserFile_empty) {
  dataStruct data;
  int err = parserFile("core/none.obj", &data);
  if (err == FAIL) {
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}

START_TEST(parser_emptyFile) {
  dataStruct data;
  data.polygonArray = NULL;
  int err = parserFile("core/objects/empty.obj", &data);
  if (err == OK) {
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}

START_TEST(getMaximumDistance_vertex) {
  dataStruct data;
  int err = parserFile("core/objects/cube.obj", &data);
  if (err == OK) {
    findMinMax(&data);
    double res = getMaximumDistance(&data);
    ck_assert_double_eq_tol(res, 2.000000, 1e-6);
    free(data.vertexArray);
    free(data.polygonArray);
    printf(COLOR_GREEN "TEST --> OK\n" COLOR_RESET);
  } else {
    printf(COLOR_RED "TEST --> FAIL // ERROR_CODE = [%d]\n", err);
    printf(COLOR_RESET);
  }
}
END_TEST

Suite *suite_parserFile() {
  Suite *s = suite_create("suite_parserFile");
  TCase *tc = tcase_create("parserFile");

  tcase_add_test(tc, parserFile_fail);
  tcase_add_test(tc, parserFile_vertex);
  tcase_add_test(tc, parserFile_polygon);
  tcase_add_test(tc, parserFile_structData);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_scale() {
  Suite *s = suite_create("suite_scale");
  TCase *tc = tcase_create("scale");

  tcase_add_test(tc, scale_vertex);
  tcase_add_test(tc, resizeValue_vertex);

  suite_add_tcase(s, tc);

  return s;
}
Suite *suite_rotate() {
  Suite *s = suite_create("suite_rotate");
  TCase *tc = tcase_create("rotate");

  tcase_add_test(tc, rotateX_vertex);
  tcase_add_test(tc, rotateY_vertex);
  tcase_add_test(tc, rotateZ_vertex);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_move() {
  Suite *s = suite_create("suite_move");
  TCase *tc = tcase_create("move");

  tcase_add_test(tc, moveX_vertex);
  tcase_add_test(tc, moveY_vertex);
  tcase_add_test(tc, moveZ_vertex);
  tcase_add_test(tc, move_vertexZero);

  tcase_add_test(tc, getMaximumDistance_vertex);
  suite_add_tcase(s, tc);

  return s;
}
Suite *suite_parserEmptyFile() {
  Suite *s = suite_create("suite_parserFile");
  TCase *tc = tcase_create("parserFile");

  tcase_add_test(tc, parserFile_empty);
  tcase_add_test(tc, parser_emptyFile);
  suite_add_tcase(s, tc);

  return s;
}

int main(void) {
  run_tests();

  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {
      suite_parserFile(),      suite_scale(), suite_rotate(), suite_move(),
      suite_parserEmptyFile(), NULL};  // Массив куда передаются функции Suite

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}