#include "main.h"

/**
 * PrintEnv - prints the environment
 * @Environment: environment variables
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int PrintEnv(char **Environment)
{
	int i = 0;

	while (Environment[i])
	{
		if (ShearchStr(Environment[i], '='))
		{
			write(STDOUT_FILENO, Environment[i], StringLen(Environment[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		i++;
	}

	return (EXIT_SUCCESS);
}
