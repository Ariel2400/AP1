//
// Created by User on 8/5/2020.
//

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
  double **member;
  int width;
  int height;
} Matrix;

ErrorCode matrix_create(PMatrix *matrix, uint32_t height, uint32_t width) {
<<<<<<< HEAD
  if (matrix == NULL) {
=======
  if (matrix != NULL) {
>>>>>>> moved all source code to src folder
    return ERROR_FAILURE_INPUT_ERROR;
  }
  *matrix = (Matrix *)malloc(sizeof(Matrix));
  if (matrix == NULL) {
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  (*matrix)->width = width;
  (*matrix)->height = height;
  (*matrix)->member = (double **)malloc((*matrix)->height * sizeof(double *));
  if ((*matrix)->member == NULL) {
    free(*matrix);
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  for (int i = 0; i < (*matrix)->height; i++) {
<<<<<<< HEAD
    (*matrix)->member[i] = (double *)calloc((*matrix)->width, sizeof(double));
=======
    (*matrix)->member[i] =
        (double *)calloc((*matrix)->width, (*matrix)->width * sizeof(double));
>>>>>>> moved all source code to src folder
    if ((*matrix)->member[i] == NULL) {
      free((*matrix)->member);
      free(*matrix);
      return ERROR_FAILURE_CANT_ALLOCATE;
    }
  }
  return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix *result, CPMatrix source) {
  if (source == NULL) {
<<<<<<< HEAD
    return ERROR_FAILURE_INPUT_ERROR;
  }
  matrix_create(result, source->height, source->width);
  if (result == NULL) {
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  for (int i = 0; i < source->height; i++) {
    for (int j = 0; j < source->width; j++) {
      matrix_setValue(*result, i, j, source->member[i][j]);
    }
  }
  return ERROR_SUCCESS;
}

=======
    error_getErrorMessage(ERROR_FAILURE_INPUT_ERROR);
    return ERROR_FAILURE;
  }
  if (!error_isSuccess(matrix_create(result, source->height, source->width))) {
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  for (int i = 0; i < (*result)->height; i++) {
    for (int j = 0; j < (*result)->width; j++) {
      matrix_setValue(*result, i, j, source->member[i][j]);
    }
  }
}
>>>>>>> moved all source code to src folder
void matrix_destroy(PMatrix matrix) {
  for (int i = 0; i < matrix->height; i++) {
    free(matrix->member[i]);
  }
  free(matrix->member);
  free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t *result) {
  if (matrix == NULL || matrix->height <= 0) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  *result = (int)matrix->height;
  return ERROR_SUCCESS;
}
<<<<<<< HEAD

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t *result) {
  if (matrix == NULL || matrix->height <= 0) {
=======
ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t *result) {
  if (matrix == NULL || matrix->height <= 0) {

>>>>>>> moved all source code to src folder
    return ERROR_FAILURE_INPUT_ERROR;
  }
  *result = (int)matrix->width;
  return ERROR_SUCCESS;
}
<<<<<<< HEAD

=======
>>>>>>> moved all source code to src folder
ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
                          double value) {
  if (matrix == NULL || rowIndex > matrix->height || rowIndex < 0 ||
      colIndex > matrix->width || colIndex < 0) {
<<<<<<< HEAD
=======

>>>>>>> moved all source code to src folder
    return ERROR_FAILURE_INPUT_ERROR;
  }
  (matrix)->member[rowIndex][colIndex] = value;
  return ERROR_SUCCESS;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
                          double *value) {
  if (matrix == NULL || rowIndex < 0 || rowIndex >= matrix->height ||
      colIndex < 0 || colIndex >= matrix->width) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  *value = matrix->member[rowIndex][colIndex];
  return ERROR_SUCCESS;
}

ErrorCode matrix_add(PMatrix *result, CPMatrix lhs, CPMatrix rhs) {
  if ((lhs->height != rhs->height) || (lhs->width != rhs->width) ||
      lhs == NULL || rhs == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  if (result == NULL) {
    matrix_create(result, lhs->height, lhs->width);
  }
  for (int i = 0; i < lhs->height; i++) {
    for (int j = 0; j < lhs->width; ++j) {
<<<<<<< HEAD
      matrix_setValue(
          *result, i, j,
          lhs->member[i][j] +
              rhs->member[i][j]); // according to the laws of matrix addition
=======
      matrix_setValue(*result, i, j, lhs->member[i][j] + rhs->member[i][j]);
>>>>>>> moved all source code to src folder
    }
  }
  return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyMatrices(PMatrix *result, CPMatrix lhs, CPMatrix rhs) {
<<<<<<< HEAD
  if (lhs == NULL || rhs == NULL ||
      lhs->width != rhs->height) { // checks if the input is correct
    return ERROR_FAILURE_INPUT_ERROR;
  }
  ErrorCode success = matrix_create(result, lhs->height, rhs->width);
  if (!error_isSuccess(success)) {
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
=======
  if (lhs == NULL || rhs == NULL || lhs->width != rhs->height) {
    return ERROR_FAILURE;
  }
  matrix_create(result, lhs->height, rhs->width);
>>>>>>> moved all source code to src folder
  for (int i = 0; i < (*result)->height; i++) {
    for (int j = 0; j < (*result)->width; j++) {
      double valueToSet = 0;
      for (int k = 0; k < lhs->width; k++) {
<<<<<<< HEAD
        valueToSet +=
            lhs->member[i][k] *
            rhs->member[k][j]; // according to the laws of matrix multiplication
=======
        valueToSet = +lhs->member[i][k] * rhs->member[k][j];
>>>>>>> moved all source code to src folder
      }
      matrix_setValue(*result, i, j, valueToSet);
    }
  }
  return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
  if (matrix == NULL) {
<<<<<<< HEAD
    return ERROR_FAILURE_INPUT_ERROR;
  }
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      matrix_setValue(
          matrix, i, j,
          scalar *
              matrix->member[i][j]); // according to the laws of linear algebra
=======
    return ERROR_FAILURE;
  }
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      matrix_setValue(matrix, i, j, scalar * matrix->member[i][j]);
>>>>>>> moved all source code to src folder
    }
  }
  return ERROR_SUCCESS;
}
