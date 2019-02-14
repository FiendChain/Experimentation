#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/wait.h>

#define MAX_DIRNAME 100
#define MAX_ARGNAME 100

typedef struct {
    char dir[MAX_DIRNAME];
    char *args[MAX_ARGNAME];
} CommandString;

// Function prototypes
void executeCommand(CommandString cmd, char *output, int size);

int main() {
    char foo[4096];

    CommandString cmd[] = {
        {"/bin/ls", {"ls", "-la"}},
        {"/bin/echo", {"echo", "stupid", "cunts"}},
    };
    
    for(int i = 0; i < sizeof(cmd) / sizeof(CommandString); i++) {
        executeCommand(cmd[i], foo, 4096);
        printf("%s: %s", cmd[i].dir, foo);
        fflush(stdout);
    }

    return EXIT_SUCCESS;
}

void executeCommand(CommandString cmd, char *output, int size) {
    int link[2];
    pid_t pid;

    if(pipe(link)==-1) {
        error(0, 0, "pipe error");
    }

    if((pid = fork()) == -1) {
        error(0, 0, "fork error");
    }

    if(pid == 0) {
        dup2(link[1], STDOUT_FILENO);
        close(link[0]);
        close(link[1]);
        execv(cmd.dir, cmd.args);
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
        close(link[1]);
        int nbytes = read(link[0], output, size);
        close(link[0]);
    }

    fflush(stdin);
    fflush(stdout);
}