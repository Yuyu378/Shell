// 
// winshell.h
// 
//		Declare the detail for execution function
// 

#pragma once

#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN64
#include <io.h>
#include <share.h>
#include <process.h>
#include <Windows.h>

#define	F_OK	0	/* Check for file existence		*/
#define	X_OK	1	/* Check for execute permission	*/
#define	W_OK	2	/* Check for write permission	*/
#define	R_OK	4	/* Check for read permission	*/
#endif

#ifdef __linux__
#include <unistd.h>
#include <pthread.h>
#endif

#define CLSIZE	256	/* Size of command line			*/

char* argGetter(void);

void executor(char* commandLine);
