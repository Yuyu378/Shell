// 
// winshell.h
// 
//		Declare the detail for execution function
// 

#pragma once

#define	F_OK	0	/* Check for file existence		*/
#define	X_OK	1	/* Check for execute permission	*/
#define	W_OK	2	/* Check for write permission	*/
#define	R_OK	4	/* Check for read permission	*/

#define CLSIZE	256	/* Size of command line			*/

#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <stdbool.h>
#include <Windows.h>

char* argGetter(void);

void executor(char* commandLine);
