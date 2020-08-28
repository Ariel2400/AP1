//
// Created by User on 8/5/2020.
//
#include "ErrorCode.h"

bool error_isSuccess(ErrorCode code) {
  return code == ERROR_SUCCESS;
}
const char *error_getErrorMessage(ErrorCode code) {
  switch (code) {
  case ERROR_SUCCESS:
    return "Success!";
  case ERROR_FAILURE:
    return "Failure!";
  case ERROR_FAILURE_CANT_ALLOCATE:
    return "Can't allocate!";
  case ERROR_FAILURE_INPUT_ERROR:
    return "An empty matrix is given!";
    case ERROR_FAILURE_MATRIX_CANT_ADD:
    return "Can't add these two matrices, check their height and width!";
    case ERROR_FAILURE_MATRIX_CANT_MULT:
    return "Can't multiply these two matrices. check if they can be multiplied!";
    case ERROR_FAILURE_OUT_OF_BOUNDS:
    return "Can't access out of the bounds of the matrix!";
  default:
    return "";
  }
}