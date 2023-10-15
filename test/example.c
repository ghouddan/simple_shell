#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64

void execute_command(char *args[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        _exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        // Parent process
        wait(NULL);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];
    char *token;

    while (1) {
        printf("SimpleShell> ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }

        // Remove newline character from input
        input[strlen(input) - 1] = '\0';

        // Tokenize input
        int arg_count = 0;
        token = strtok(input, " ");
        while (token != NULL && arg_count < MAX_ARG_SIZE - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Handle 'cd' command
        if (strcmp(args[0], "cd") == 0) {
            if (arg_count > 1) {
                if (chdir(args[1]) != 0) {
                    perror("chdir");
                }
            } else {
                fprintf(stderr, "cd: missing argument\n");
            }
        }
        // Handle 'ls' command
        else if (strcmp(args[0], "ls") == 0) {
            execute_command(args);
        }
        // Handle 'exit' command
        else if (strcmp(args[0], "exit") == 0) {
            break;
        }
        // Execute other commands
        else {
            execute_command(args);
        }
    }

    return 0;
}

