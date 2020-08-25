//
// Created by User on 8/5/2020.
//

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
  double *members;
  uint32_t width;
  uint32_t height;
} Matrix;

ErrorCode matrix_create(PMatrix *matrix, uint32_t height, uint32_t width) {
  if (matrix == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  *matrix = (Matrix *)malloc(sizeof(Matrix));
  if (*matrix == NULL) {
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  (*matrix)->members = (double *)calloc(height * width, sizeof(double));
  if ((*matrix)->members == NULL) {
    free(*matrix);
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  (*matrix)->width = width;
  (*matrix)->height = height;
  return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix *result, CPMatrix source) {
  if (source == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  if (!error_isSuccess(matrix_create(result, source->height, source->width))) {
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  for (int i = 0; i < source->height; ++i) {
    for (int j = 0; j < source->width; ++j) {
      (*result)->members[i * (*result)->width + j] =
          source->members[i * source->width + j];
    }
  }
  return ERROR_SUCCESS;
}

void matrix_destroy(PMatrix matrix) {
  free(matrix->members);
  free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t *result) {
  if (matrix == NULL || matrix->height <= 0) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  *result = matrix->height;
  return ERROR_SUCCESS;
}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t *result) {
  if (matrix == NULL || matrix->width <= 0) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  *result = matrix->width;
  return ERROR_SUCCESS;
}

ErrorCode matrix_setValue(PMatrix matrix, const uint32_t rowIndex,
                          const uint32_t colIndex, double value) {
  if (matrix == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  if (rowIndex > matrix->height || rowIndex < 0 || colIndex > matrix->width ||
      colIndex < 0) {
    return ERROR_FAILURE_OUT_OF_BOUNDS;
  }
  matrix->members[rowIndex * (matrix->width) + colIndex] = value;
  return ERROR_SUCCESS;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
                          double *value) {
  if (matrix == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  if (rowIndex < 0 || rowIndex > matrix->height || colIndex < 0 ||
      colIndex > matrix->width) {
    return ERROR_FAILURE_OUT_OF_BOUNDS;
  }
  *value = matrix->members[rowIndex * matrix->width + colIndex];
  return ERROR_SUCCESS;
}

ErrorCode matrix_add(PMatrix *result, CPMatrix lhs, CPMatrix rhs) {
  if (lhs == NULL || rhs == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  if ((lhs->height != rhs->height) || (lhs->width != rhs->width)) {
    return ERROR_FAILURE_MATRIX_CANT_ADD;
  }
  if (result == NULL) {
    if (!error_isSuccess(matrix_create(result, lhs->height, lhs->width))) {
      return ERROR_FAILURE_CANT_ALLOCATE;
    }
  }
  for (int i = 0; i < lhs->height; ++i) {
    for (int j = 0; j < lhs->width; ++j) {
      (*result)->members[i * (lhs->width) + j] =
          lhs->members[i * (lhs->width) + j] +
          rhs->members[i * (rhs->width) + j];
      // according to the laws of matrix addition
    }
  }
  return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyMatrices(PMatrix *result, CPMatrix lhs, CPMatrix rhs) {
  if (lhs == NULL || rhs == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  if (lhs->width != rhs->height) {
    return ERROR_FAILURE_MATRIX_CANT_MULT;
  }
  if (!error_isSuccess(matrix_create(result, lhs->height, rhs->width))) {
    return ERROR_FAILURE_CANT_ALLOCATE;
  }
  for (int i = 0; i < (*result)->height; ++i) {
    for (int j = 0; j < (*result)->width; ++j) {
      double valueToSet = 0.0;
      for (int k = 0; k < lhs->width; ++k) {
        valueToSet += lhs->members[i * (lhs->width) + k] *
                      rhs->members[k * (lhs->width) + j];
        // according to linear algebra rules
      }
      (*result)->members[i * (*result)->width + j] = valueToSet;
    }
  }
  return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
  if (matrix == NULL) {
    return ERROR_FAILURE_INPUT_ERROR;
  }
  for (int i = 0; i < matrix->height; ++i) {
    for (int j = 0; j < matrix->width; ++j) {
      matrix->members[i * matrix->width + j] *= scalar;
      // according to the laws of linear algebra
    }
  }
  return ERROR_SUCCESS;
}
