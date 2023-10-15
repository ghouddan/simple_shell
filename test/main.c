#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
	char *buffer = NULL;
	pid_t childe;
	char *bin = "/bin/";
	size_t size = 0;
	int i = 0, j;

	while (1)
	{
		childe = fork();
		if (childe == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (childe == 0)
		{

			printf("#cisfun ");
			getline(&buffer,& size, stdin);
			size_t lent = strlen(buffer);
			size_t lent_bin = strlen(bin);
			if (buffer[lent - 1] == '\n')
				buffer[lent - 1] = '\0';
			/*while (bin[i] != '\0')
				i++;
			while (buffer[j] != '\0')
			{
				bin[i] = buffer[j];
				i++;
				j++;
			}
			bin[i] = '\0';*/
			printf("%s\n",bin);
			char full_cmd[100];
			strcpy(full_cmd, bin);
			strcat(full_cmd, buffer);
			printf("%s\n",full_cmd);
			size_t full_lent = strlen(full_cmd);
			if (full_cmd[full_lent - 1] == '\n')
				full_cmd[full_lent -1] = '\0';	
			char *args[] = {full_cmd, buffer,  NULL};
			char *env[] = {NULL};

			printf("%s\n",buffer);
			execve(full_cmd, args,env);
			perror("Exeve failed");
			return (1);
		}
		else
		{
			int status;
			waitpid(childe, &status, 0);
		}
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
    char *buffer = NULL;
    pid_t child;
    size_t size = 0;
    char *args[] = {NULL};
    char *evn[] = {NULL};
    while (1)
    {
        printf("#cisfun ");
        getline(&buffer, &size, stdin);

        // Check for EOF or empty line
        if (feof(stdin) || buffer[0] == '\n')
        {
            free(buffer); // Free allocated memory
            break;
        }

        child = fork();
        if (child == -1)
        {
            perror("Error: ");
            free(buffer); // Free allocated memory
            return (1);
        }

        if (child == 0)
        {
	    printf("%s\n",buffer);
            execve(buffer, args, evn);
            perror("Execve failed");
            free(buffer); // Free allocated memory
            return (1);
        }
        else
        {
            int status;
            waitpid(child, &status, 0);
        }

        free(buffer); // Free allocated memory
    }

    return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    char *command = NULL;
    size_t bufsize = 0;
    char *env[] = {NULL}; 

    while (1) {
        // Print prompt and get user input
        printf("$ ");
        getline(&command, &bufsize, stdin);
	char *args[] = {command, NULL};
        // Remove newline character
        command[strlen(command) - 1] = '\0';

        // Create a child process
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            free(command);
            exit(1);
        }

        if (child_pid == 0) {
            // Child process
            if (execve(command, args, env) == -1) {
                perror("Execve failed");
                free(command);
                exit(1);
            }
        } else {
            // Parent process
            int status;
            waitpid(child_pid, &status, 0);
        }
    }

    // Free allocated memory (this part is never reached in this program)
    free(command);

    return 0;
}
*/
