//
// Created by User on 8/5/2020.
//
#include "ErrorCode.h"

bool error_isSuccess(ErrorCode code) {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Reformatted ErrorCode.h
  if (code == ERROR_SUCCESS) {
    return true;
  }
  return false;
<<<<<<< HEAD
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
=======
    if (code == ERROR_SUCCESS) {
        return true;
    }
    return false;
}
const char* error_getErrorMessage(ErrorCode code) {
    switch (code) {
        case ERROR_FAILURE_CANT_ALLOCATE:
            return "Couldn't allocate memory";
        case ERROR_FAILURE_INPUT_ERROR:
            return "One or more of the parameters is causing an error";
        case ERROR_FAILURE_LOGIC:
            return "Math error";
        case ERROR_SUCCESS:
            return "Success";
        case ERROR_FAILURE:
            return "Failure";
    }
>>>>>>> moved all source code to src folder
=======
}
const char *error_getErrorMessage(ErrorCode code) {
  switch (code) {
  case ERROR_FAILURE_CANT_ALLOCATE:
    return "Couldn't allocate memory";
  case ERROR_FAILURE_INPUT_ERROR:
    return "One or more of the parameters is causing an error";
  case ERROR_FAILURE_LOGIC:
    return "Math error";
  case ERROR_SUCCESS:
    return "Success";
  case ERROR_FAILURE:
    return "Failure";
  }
>>>>>>> Reformatted ErrorCode.h
}