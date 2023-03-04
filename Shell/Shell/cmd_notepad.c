
#include "cmd_notepad.h"

#define NOTEPAD_PATH_NUM 2

void notepad(char** input) {
	if (!strcmp(input[1], "notepad")) {				// if shell command is notepad
		int idx = 0, err = 0;
		char path[NOTEPAD_PATH_NUM][CLSIZE] = {
			"C:\\Windows\\System32\\", 
			"C:\\Windows\\" 
		};
		// check for posible notepad locations
		for (unsigned i = 0; i < NOTEPAD_PATH_NUM; i++) {
			idx = sprintf_s(input[0], CLSIZE, "%s%s.exe", path[i], input[1]);
			if ((err = _access_s(input[0], F_OK)) == 0) break;	// if find notepad path then break loop
			else if (i == NOTEPAD_PATH_NUM - 1) {	// if having checked all posible patha but not found
				perror("Notepad not found.\n\n");
				memset(input[0], 0, idx);
				return;
			}
			memset(input[0], 0, idx);				// if i != NOTEPAD_PATH_NUM - 1
		}
		char* param = 0, * next = 0, * tmp = 0;
		param = strtok_s(input[2], " ", &tmp);
		next = strtok_s(NULL, " ", &tmp);
		if (param == NULL) {
			_spawnlp(_P_WAIT, input[0], input[0], NULL);
			memset(input[0], 0, idx);
			return;
		}
		else {
			if (!strcmp(param, "&")) {
				(next == NULL) ? _spawnlp(_P_NOWAIT, input[0], input[0], NULL) : 
								 printf("Incorrect command syntax, do you mean \"notepad &\"?\n\n");
				memset(input[0], 0, idx);
				return;
			}
			int nameidx = 0;
			char* ret = 0, filename[CLSIZE] = { 0 };
			nameidx = sprintf_s(filename, CLSIZE, "%s", param);
			param = next;
			while (param != NULL) {
				if (!strcmp(param, "&")) {
					next = strtok_s(NULL, " ", &tmp);
					(next == NULL) ? _spawnlp(_P_NOWAIT, input[0], input[0], filename, NULL) :
						printf("Incorrect command syntax, do you mean \"notepad [filename] &\"?\n\n");
					memset(input[0], 0, idx);
					return;
				}
				if ((ret = strchr(param, '&')) != NULL) {
					printf(
						"Incorrect command syntax:\n"
						"  notepad &\n"
						"  notepad [(optional)filename] &\n\n"
					);
					memset(input[0], 0, idx);
					return;
				}
				nameidx += sprintf_s(filename + nameidx, CLSIZE - nameidx - 1, " %s", param);
				param = strtok_s(NULL, " ", &tmp);
			}
			if ((ret = strchr(filename, '&')) != NULL) {
				printf(
					"Incorrect command syntax:\n"
					"  notepad &\n"
					"  notepad [(optional)filename] &\n\n"
				);
				memset(input[0], 0, idx);
				return;
			}
			_spawnlp(_P_WAIT, input[0], input[0], filename, NULL);
		}
		memset(input[0], 0, idx);
	}
	return;
}
