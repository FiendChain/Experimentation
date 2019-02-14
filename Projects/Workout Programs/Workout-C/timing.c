#include "readInfo.h"
#include "timing.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

int restTime = DEFAULT_REST;

// Start the routine
void measureTime() {
    printf("[Starting workout]\n");
    time_t start = time(NULL);
    int currentWorkout = 0;
    int currentSet = 0;
    while(currentWorkout != totalWorkouts) {
        printf("%s\n", workouts[currentWorkout]);
        while(currentSet != totalSets) {
            time_t setStart = time(NULL);
            char input = getch();
            if(input == 'q') {
                printf("\nExiting workout routine!\n");
                exit(EXIT_FAILURE);
            }
            int elapsedTime = time(NULL) - setStart;
            printf("▫ Set %d: %3d seconds ", currentSet+1, elapsedTime);
            time_t current = time(NULL);
            while(time(NULL) - current <= restTime) {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
            currentSet++;
            printf("\n");
        }
        currentSet = 0;
        currentWorkout++;
    }
    printf("[SUMMARY]\n");
    time_t elapsedTime = time(NULL) - start;
    struct hourMinuteSecond {int hour, minute, second;} HMS;
    HMS.hour = elapsedTime / 3600;
    HMS.minute = (elapsedTime - HMS.hour*3600) / 60;
    HMS.second = elapsedTime - HMS.hour*3600 - HMS.minute*60;
    printf("Time elapsed: %02d:%02d:%02d\n", HMS.hour, HMS.minute, HMS.second);
}


// Wait to get signal input
char getch(void) {
    // BLACK BOX MAGIC
    struct termios org_opts, new_opts;
    tcgetattr(STDIN_FILENO, &org_opts);
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    char c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    // Get elapsed time
    return c;
}
