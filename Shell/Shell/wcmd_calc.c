
#include "wcmd_calc.h"

void calc(char** input) {
	if (!strcmp(input[1], "calc")) {	// if shell command is calc
		int idx = 0, err = 0;
		// Save the absolute position to input[0]
		idx = sprintf_s(input[0], CLSIZE, "C:\\Windows\\System32\\%s.exe", input[1]);
		// check if C:\Windows\System32\calc.exe not exist
		if ((err = _access_s(input[0], F_OK)) != 0) {
			perror("Calc not found.\n\n");
			memset(input[0], 0, idx);
			return;
		}
		char* logpath[CLSIZE];			// variable store tmp.log path
		err = _get_pgmptr(logpath);		// get the location of its own executable file (Shell.exe location)
		if (err != 0) {					// if get Shell.exe path failed
			perror("Failed to get log file, only call but not listen.\n\n");
			system(input[0]);
			memset(input[0], 0, idx);
			return;
		}
		char* lastSlash = strrchr(*logpath, '\\');				// find last slash
		if (lastSlash != NULL) memset(lastSlash + 1, 0, 9);		// replace "Shell.exe" (9 charachers) to 0
		char syscall[CLSIZE] = { 0 };							// store the command which shows process
		sprintf_s(*logpath, CLSIZE, "%stmp.log", *logpath);		// complete log path
		sprintf_s(syscall, CLSIZE, "tasklist | findstr /i %s > %s", input[1], *logpath);	// complete syscall
		char* param = 0, * next = 0, * tmp = 0;
		param = strtok_s(input[2], " ", &tmp);
		next = strtok_s(NULL, " ", &tmp);
		if (param == NULL) {
			/* 
			 * The calc.exe is a launcher that launch CalculatorApp.exe,
			 * and the process of calc.exe will be automatically destory 
			 * after lunch CalculatorApp.exe successful.
			 * 
			 * If we want the shell to keep waiting until calculator is closed, 
			 * then the function _spawnlp(_P_WAIT, ...) could not achieve our goal.
			 */
			_spawnlp(_P_NOWAIT, input[0], input[0], NULL);		// execute calc.exe in no-wait mode
			int bytesread = 0;
			do {
				system(syscall);		// use cmd to get the process data and write in tmp.log
				int file = 0;
				char buffer[CLSIZE];
				if (_sopen_s(&file, *logpath, _O_RDONLY, _SH_DENYNO, 0)) {	// if open failed
					perror("Open failed on log file, only call but not listen.\n\n");
					memset(input[0], 0, idx);
					return;
				}
				if ((bytesread = _read(file, buffer, CLSIZE)) < 0) {		// if read failed
					perror("Problem reading file");
				}
				Sleep(1);
				_close(file);
			} while (bytesread > 0);	// while tmp.log has data
			char dellog[CLSIZE] = { 0 };
			sprintf_s(dellog, CLSIZE, "del %s", *logpath);
			system(dellog);
		}
		else {
			if (!strcmp(param, "&") && next == NULL) {
				_spawnlp(_P_NOWAIT, input[0], input[0], NULL);
			}
			else printf("Incorrect command syntax, do you mean \"calc &\"?\n\n");
		}
		memset(input[0], 0, idx);
	}
	return;
}
