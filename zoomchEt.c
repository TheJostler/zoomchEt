#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int usage(char *basename) {
	char *version = "Zoom ChEt v1.0 by Josjuar Lister 2022";
	char *usage = "%s\n%s [options]\n"
		"\tsleep\t send zoom to sleep\n"
		"\twake\t wake zoom from sleep\n"
		"\tbye\t say goodbye and kill Zoom\n";
	fprintf(stderr, usage, version, basename);
}

int main (int argc, char **argv) {
	if (argc >= 2) {
		
		FILE *PIDfh = popen("ps -as | grep zoom/zoom/zoom | grep -v grep | cut -d ' ' -f 5", "r");
		char PID[12];
	
		if (fgets(PID, sizeof(PID), PIDfh) == NULL) {
		    pclose(PIDfh);
		    printf("couldn't get PID\n");
		}
		else {
			pclose(PIDfh);
			printf("Zoom PID is: %s", PID);

			char *command = argv[1];
			printf("|%s|\n", command);
			char *sleep = strstr(command, "sleep");
			char *wake = strstr(command, "wake");
			char *bye = strstr(command, "bye");
			char kill[50];
			if (sleep) {
				strcpy(kill, "kill -n 19 ");
				strcat(kill, PID);
			}
			else if (wake) {
				strcpy(kill, "kill -n 18 ");
				strcat(kill, PID);
			}
			else if (bye) {
				strcpy(kill, "kill ");
				strcat(kill, PID);
			}
			else {
				printf("%s is not a valid option\n", command);
				usage(argv[0]);
				exit(1);
			}
			return system(kill);
		}
	}
	usage(argv[0]);
	return 0;
}