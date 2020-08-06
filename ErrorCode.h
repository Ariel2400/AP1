#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
<<<<<<< HEAD
<<<<<<< HEAD:src/ErrorCode.h
  // DON'T CHANGE THIS VALUE!
  ERROR_SUCCESS = 0,
  ERROR_FAILURE = 1,
  ERROR_FAILURE_CANT_ALLOCATE = 2, //allocation error
  ERROR_FAILURE_INPUT_ERROR = 3 //input error, the parameters are wrong
=======
    // DON'T CHANGE THIS VALUE!
    ERROR_SUCCESS = 0,ERROR_FAILURE = 1, ERROR_FAILURE_CANT_ALLOCATE = 2,
    ERROR_FAILURE_INPUT_ERROR = 3, ERROR_FAILURE_LOGIC = 4
>>>>>>> Added diffrent error types:ErrorCode.h
=======
  // DON'T CHANGE THIS VALUE!
  ERROR_SUCCESS = 0,
  ERROR_FAILURE = 1,
  ERROR_FAILURE_CANT_ALLOCATE = 2,
  ERROR_FAILURE_INPUT_ERROR = 3,
  ERROR_FAILURE_LOGIC = 4
>>>>>>> Reformatted source files
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