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
    return "Wrong input!";
  default:
    return "";
  }
}