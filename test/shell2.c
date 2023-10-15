#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
    char *buffer = NULL;
    pid_t child;
    char *bin = "/bin/";
    size_t size = 0;

    while (1)
    {
        printf("#cisfun ");
        getline(&buffer, &size, stdin);

        if (buffer == NULL) {
            perror("Error reading input");
            break;
        }

        size_t lent = strlen(buffer);
        if (buffer[lent - 1] == '\n')
            buffer[lent - 1] = '\0';

        /*char full_command[100]; // Adjust the size as needed
        strcpy(full_command, bin);
        strcat(full_command, buffer);;*/

        child = fork();

        if (child == -1)
        {
            perror("Error creating child process");
            free(buffer);
            return (1);
        }

        if (child == 0)
        {
            char *args[] = {buffer,  NULL};
            char *env[] = {NULL};
            execve(buffer, args, env);
            perror("Execve failed");
            free(buffer);
            return (1);
        }
        else
        {
            int status;
            waitpid(child, &status, 0);
        }

        free(buffer);
    }

    return (0);
}

