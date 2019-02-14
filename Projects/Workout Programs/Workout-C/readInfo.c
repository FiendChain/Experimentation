#include <bsd/string.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include "readInfo.h"
#include "timing.h"



// Scan config from arguments - Override
void scanArguments(int argc, char *argv[]) {
    char inputBuffer[MAX_BUFFER] = {0};
    for(int i = 1; i < argc; i++) {
        strlcpy(inputBuffer, argv[i], MAX_BUFFER);
        readConfigString(inputBuffer);
    }
}

// Process a configuration string 
void readConfigString(char inputBuffer[MAX_BUFFER]) {
    char argument[MAX_ARGUMENT_LENGTH];
    int tempValue = 0;
    // Replace "=" with space to scan as string and number
    for(int i = 0; i < MAX_BUFFER; i++) {
        if(inputBuffer[i] == '=') inputBuffer[i] = ' ';
        if(inputBuffer[i] == 0) break;
    }
    // Get configuration
    if(sscanf(inputBuffer, "%s %d", argument, &tempValue) == 2) {
        for(int i = 0; i < totalArguments; i++) {
            struct configTableEntry *current = &configTable[i];
            if(strncmp(argument, current->argument, strlen(current->argument)-1) == 0) {
                *(current->value) = tempValue;
            }
        }
    }
}

// Show debugging info
void showDebugInfo() {
    printf("Reading from: %s\n", filename);
    printf("Total reps: %d\n", totalReps);
    printf("Total sets: %d\n", totalSets);
    printf("Rest time: %d\n", restTime);
}

void readFile(FILE *fp) {
    char inputBuffer[MAX_BUFFER] = {0};
    int tempValue = 0;
    int readConfig, readRoutine = FALSE;
    while(fgets(inputBuffer, MAX_BUFFER, fp) != NULL) {
        // Skip empty lines
        if(strnlen(inputBuffer, MAX_BUFFER) == 1) continue;
        // Switch to config reading mode
        if(strncmp(inputBuffer, "[CONFIG]", 8) == 0) {
            readConfig  = TRUE;
            readRoutine = FALSE;
            continue;
        }
        // Switch to routine reading mode
        if(strncmp(inputBuffer, "[ROUTINE]", 9) == 0) {
            readConfig = FALSE;
            readRoutine = TRUE;
            continue;
        }
        // Read the config until flag is lowered
        if(readConfig) readConfigString(inputBuffer);
        // Read the routine until another header is read, or max routines reached
        if(readRoutine) {
            // Get the workout, store and trim
            char *currentWorkout = workouts[totalWorkouts];
            strlcpy(currentWorkout, inputBuffer, MAX_BUFFER);
            currentWorkout[strcspn(currentWorkout, "\n")] = 0;
            // Increment and exit if limit reached
            totalWorkouts++;
            if(totalWorkouts == MAX_WORKOUT) {
                printf("Reached maximum workouts: %d\n", MAX_WORKOUT);
                break;
            }
        }
    }
}

// Print workouts in 'n' columns
void showWorkouts() {
    printf("[%s - %d workouts]\n", filename, totalWorkouts);
    for(int i = 0; i < totalWorkouts; i++) {
        printf("%-20s\t", workouts[i]);
        if((i+1) % totalColumns == 0 || (i+1) == totalWorkouts) printf("\n");
    }
}
