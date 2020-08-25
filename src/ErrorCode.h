#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
  // DON'T CHANGE THIS VALUE!
  ERROR_SUCCESS = 0,
  ERROR_FAILURE = 1,
  ERROR_FAILURE_CANT_ALLOCATE = 2, //allocation error
  ERROR_FAILURE_INPUT_ERROR = 3, //input error, the parameters are wrong
  ERROR_FAILURE_MATRIX_CANT_ADD = 4, //can't add, needs to be the same height and width
  ERROR_FAILURE_MATRIX_CANT_MULT = 5, //can't multiply, the left height needs
                                      //to be equal to the right width
  ERROR_FAILURE_OUT_OF_BOUNDS = 6 //trying to access out of bounds of the matrix
} ErrorCode;

/**
 * @brief Checks if a given error code indicates a success or not.
 *
 * @param[in] code the error code.
 * @return whether the error code indicates a success or not.
 */
bool error_isSuccess(ErrorCode code);

/**
 * @brief gets a textual error message for a given error code.
 *
 * @param[in] code the error code.
 * @return const char* the textual representation of the error code.
 */
const char *error_getErrorMessage(ErrorCode code);