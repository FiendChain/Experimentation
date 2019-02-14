#include "readInfo.h"
#include "timing.h"
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

char filename[MAX_FILENAME] = "routine.txt";
char workouts[MAX_WORKOUT][MAX_BUFFER] = {{0}};
int showDebug = FALSE;
int totalColumns = DEFAULT_COLUMNS;
int totalReps = DEFAULT_REP;
int totalSets = DEFAULT_SET;
int totalWorkouts = 0;
int totalArguments = 0;

// Config table
struct configTableEntry configTable[] = {
    {"reps",    &totalReps},
    {"sets",    &totalSets},
    {"rest",    &restTime},
    {"debug",   &showDebug},
    {"columns", &totalColumns}
};

void showHelp();
void changeFilename(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    // Redirect to different file if specified
    changeFilename(argc, argv);

    // Get total arguments at run time
    totalArguments = sizeof(configTable) / sizeof(struct configTableEntry);
    // Check if help has been requested
    if(argc == 2 && strncmp(argv[1], "--help", 6) == 0) {
        showHelp();
        exit(EXIT_FAILURE);
    }

    // Read information from file
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        error(0, 0, "Can't open %s", filename);
        exit(EXIT_FAILURE);
    }
    readFile(fp);
    // Get arguments, override if declared
    scanArguments(argc, argv);
    if(showDebug) {
        printf("[DEBUG]\n");
        showDebugInfo();
    }
    // Show list of workouts read
    showWorkouts();
    // Start routine
    measureTime();

    fclose(fp);

    return EXIT_SUCCESS;
}

void showHelp() {
    printf("[ARGUMENTS]\n");
    for(int i = 0; i < totalArguments; i++) {
        printf("%s\n", configTable[i].argument);
    }
}

void changeFilename(int argc, char *argv[]) {
    char inputBuffer[MAX_BUFFER] = {0};
    char tempFilename[MAX_FILENAME] = {0};
    for(int i = 1; i < argc; i++) {
        strlcpy(inputBuffer, argv[i], MAX_BUFFER);
        if(sscanf(inputBuffer, "file=%s", tempFilename) == 1) {
            strlcpy(filename, tempFilename, MAX_BUFFER);
        }
    }
}

