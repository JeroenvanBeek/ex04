/******************************************************************************
 * File:         display.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2: syntax check
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "displayFunctions.h"

int main(int argc, char *argv[]) 
{ 
  int niceIncr; 
  ErrCode err;
  
  err = SyntaxCheck(argc, argv);  // Check the command-line parameters

if(err != NO_ERR) DisplayError(err); // Print an error message


    niceIncr = (int) strtoul(argv[3], NULL, 10);

    
switch(fork())
{
case -1:
    printf("fork failed.\n");
    exit(1);

//child process
case 0:
    execl("../ex02/display", "display", argv[1], argv[2], argv[4], NULL);
    perror("execl()");  // If you make it here, something went wrong
    exit(1);

default:
switch(fork())
{
case -1:
    printf("fork failed.\n");
    exit(1);
    
case 0:
    nice(niceIncr * 1);
    execl("../ex02/display", "display", argv[1], argv[2], argv[5], NULL);
    perror("execl()");  // If you make it here, something went wrong
    exit(1);

default:
switch(fork())
{
case -1:
    printf("fork failed.\n");
    exit(1);
    
case 0:
    nice(niceIncr * 2);
    execl("../ex02/display", "display", argv[1], argv[2], argv[6], NULL);
    perror("execl()");  // If you make it here, something went wrong
    exit(1);  

default:
      wait(NULL);
      wait(NULL);
      wait(NULL);
break;
}
break;
}
break;    
 } 
return 0;
}
