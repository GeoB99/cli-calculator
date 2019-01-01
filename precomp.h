/* Simple Calculator
 *
 * Module: precomp.h
 * 
 * Purpose: A precompiled header with included headers and function prototypes
 * 
 * Created by: Bișoc George (Fraizeraust)
 * 
*/

/* INCLUDES */

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/* PROTOTYPES */

int PrintString(const char *Message, ...);
int CalcInit(void);
int CalcEngine(void);

/* DEFINES */

#define MAX_NUM     1000
#define MAX_BUFF    256

/* EOF */
