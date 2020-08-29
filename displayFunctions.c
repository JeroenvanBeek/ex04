/******************************************************************************
 * File:         displayFunctions.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2:  function definitions for display.c
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "displayFunctions.h"
#include "syntaxCheck.h"

// Check the command-line parameters:
ErrCode SyntaxCheck(int argc, char **argv) {
  ErrCode errCode = NO_ERR;
  if(argc != NUM_OF_PARS) {
    errCode = ERR_PARS;
  } else {
    errCode = TestNr(argv[3]);  // Test whether argument 3 contains only one character (print character)
    if(errCode != NO_ERR) errCode = ERR_NICE; 
  }
  return errCode;
}

// Print an error message:
void DisplayError(ErrCode errCode) {
  switch(errCode) {
  case ERR_PARS:
    printf("\nNumber of command-line parameters is not equal to six.\n");
    break;
  case ERR_NICE:
    printf("\nNice increment is not a positive integer.\n");
    break;
  default:
    printf("\nUnknown error code!\n");
  }
  printf("\nCorrect syntax:\n");
  printf("  ./parent <print type> <number of times> <nice increment> <print character 1> [<print character 2>  <...>]\n\n");
  printf("  first parameter <print type>: e, p or w\n");
  printf("  second parameter <number of times>: positive integer\n");
  printf("  third parameter <nice increment>: positive integer\n");
  printf("  fourth parameter <print character>: a single character\n");
  printf("  optional print characters: list of space-separated single characters\n");
  printf("\n");  // Newline at end
  
 exit(1);
}


