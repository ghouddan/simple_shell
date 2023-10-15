#include "main.h"

/**
 * execute - executes a command
 * @tokens: tokens to execute
 * @environment: environment variables
 * @bin: name of program
 * Return: void
 */
void execute(char **tokens, char **environment, char *bin)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(tokens[0], tokens, environment) == -1)
			perror(bin);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror(bin);
	else
	{
		wait(&status);
	}
}

/**
 * ReadLine - reads a line from stander input
 * @prompt: prompt to display
 * Return: line
 */
char *ReadLine(char *prompt)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	prompt = isatty(STDIN_FILENO) ? prompt : "";

	write(STDOUT_FILENO, prompt, StringLen(prompt));

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[0] == '\n')
		return (line);

	line[StringLen(line) - 1] = '\0';

	return (line);
}

/**
 * main - entry point
 * @av: number of arguments
 * @ac: arguments
 * @env: environment variables
 *
 * Return: 0 on success
 */
int main(__attribute__((unused))int ac, char **av, char **env)
{
	char **tokens = NULL;
	char *line = NULL;
	int LineCount = 0;

	while (1337)
	{
		line = ReadLine("$ ");
		LineCount++;
		if (!line)
			break;
		if (line[0] == '\n')
		{
			free(line);
			line = NULL;
			continue;
		}
		tokens = StrTok(line, ' ');
		if (!tokens)
		{
			free(line);
			line = NULL;
			continue;
		}
		if (StringCmp(tokens[0], "exit") == 0)
		{
			FreeResources(&line, &tokens);
			exit(0);
		}
		else if (StringCmp(tokens[0], "env") == 0)
			PrintEnv(env);
		else if (access(tokens[0], F_OK) != -1)
			execute(tokens, env, av[0]);
		else
			Error(av[0], tokens[0], "not found", LineCount);
		FreeResources(&line, &tokens);
	}
	return (0);
}
