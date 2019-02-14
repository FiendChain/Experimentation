// For FILE ADT
#include <stdio.h>
#include <stdlib.h>

// Boolean constants
#define FALSE 0
#define TRUE  1

// Symbolic constants
#define DEFAULT_COLUMNS     4
#define DEFAULT_REP         10
#define DEFAULT_SET         3
#define MAX_ARGUMENT_LENGTH 10
#define MAX_BUFFER          100
#define MAX_FILENAME        100
#define MAX_WORKOUT         20

// ADT
struct configTableEntry {
    char argument[MAX_ARGUMENT_LENGTH];
    int *value;
};

// External global variables
extern char filename[MAX_BUFFER];
extern char workouts[MAX_WORKOUT][MAX_BUFFER];
extern int showDebug;
extern int totalArguments;
extern int totalColumns;
extern int totalReps;
extern int totalSets;
extern int totalWorkouts;
extern struct configTableEntry configTable[];

void readConfigString(char inputBuffer[MAX_BUFFER]);
void readFile(FILE *fp);
void scanArguments(int argc, char *argv[]);
void showDebugInfo();
void showWorkouts();


