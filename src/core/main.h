/**
 * @file main.h
 * @brief Main header file for the program
 */

#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STEP 5.0
#define PI 3.14159265358979323846

#define COLOR_GREEN "\x1B[32m"
#define COLOR_RESET "\x1B[0m"
#define COLOR_RED "\x1B[31m"

enum error {
  FAIL = 0,
  OK = 1,
};

/**
 * @brief structure to fill object
 *
 * @param idxVertex     vertex counter
 * @param idxPolygon    polygon counter
 * @param vertexArray   vertex array
 * @param polygonArray  polygon array
 * @param maxMinX       array with max and min X-value
 * @param maxMinY       array with max and min Y-value
 * @param maxMinZ       array with max and min Z-value
 */

typedef struct data_struct {
  unsigned int idxVertex;      // v
  unsigned int idxPolygon;     // f
  double* vertexArray;         // v[]
  unsigned int* polygonArray;  // f[]

  double maxMinX[2];
  double maxMinY[2];
  double maxMinZ[2];
} dataStruct;

/**
 * @brief Parses a file with .obj format and stores data in a dataStruct
 * variable
 *
 * @param filePath Path to the file to be parsed
 * @param data Pointer to dataStruct variable where parsed data will be stored
 * @return int Returns OK if file was parsed successfully, else returns FAIL
 */
int parserFile(char* filePath, dataStruct* data);

/**
 * @brief Parses the vertex data from an obj file
 *
 * @param f Pointer to the file to be parsed
 * @param data Pointer to dataStruct variable where data is stored
 * @return int Returns OK if data was parsed successfully, else returns FAIL
 */
int vertexParser(FILE* f, dataStruct* data);

/**
* @brief Parses the polygon data from an obj file

* @param f Pointer to the file to be parsed
* @param data Pointer to dataStruct variable where data is stored
* @return int Returns OK if data was parsed successfully, else returns FAIL
*/
int polygonParser(FILE* f, dataStruct* data);

/**
 * @brief Finds the maximum and minimum coordinates of vertices in the
 * dataStruct
 *
 * @param data Pointer to dataStruct variable where data is stored
 */
void findMinMax(dataStruct* data);

/**
 * @brief Calculates the center of mass of the form and sets it as the origin
 *
 * @param data Pointer to dataStruct variable where data is stored
 */
void moveToCenter(dataStruct* data);

/**
 * @brief Resizes the form to fit within a specified size while maintaining
 * proportions
 *
 * @param data Pointer to dataStruct variable where data is stored
 * @param size Value to which the program should resize the form
 */
void scale(dataStruct* data, int size);

/**
 * @brief Rotates the form around the X axis by a specified angle
 *
 * @param data Pointer to dataStruct variable where data is stored
 * @param angle Angle in radians by which to rotate the form around the X axis
 */
void rotate_x(dataStruct* data, double angle);

/**
 * @brief Rotates the form around the X axis by a specified angle
 *
 * @param data Pointer to dataStruct variable where data is stored
 * @param angle Angle in radians by which to rotate the form around the X axis
 */
void rotate_y(dataStruct* data, double angle);

/**
 * @brief Rotates the form around the Z axis by a specified angle
 *
 * @param data Pointer to dataStruct variable where data is stored
 * @param angle Angle in radians by which to rotate the form around the Z axis
 */
void rotate_z(dataStruct* data, double angle);

/**
 * @brief Moves the form along the X axis by a specified step size
 *
 * @param data Pointer to dataStruct variable where data is stored
 * @param step Step size by which to move the form along the X axis
 */
void move_x(dataStruct* data, double step);

/**
 * @brief Moves the form along the Y axis by a specified step size
 *
 * @param data Pointer to dataStruct variable where data is stored
 * @param step Step size by which to move the form along the Y axis
 */
void move_y(dataStruct* data, double step);

/**
 * @brief Moves the form along the Z axis by a specified step size
 *
 * @param data Pointer to dataStruct variable where data is stored
 * @param step Step size by which to move the form along the Z axis
 */
void move_z(dataStruct* data, double step);

/**
 * @brief Calculates the maximum distance between two vertices in a 3D mesh
 *
 * @param data Pointer to the data structure containing the mesh data
 * @return double The maximum distance between two vertices
 */
double getMaximumDistance(dataStruct* data);

/**
 * @brief Resizes the mesh to fit within a given value
 *
 * @param data Pointer to the data structure containing the mesh data
 * @param value The value to resize the mesh to fit within
 */
void resizeValue(dataStruct* data, double value);

#ifdef __cplusplus
}
#endif

#endif  // MAIN_H