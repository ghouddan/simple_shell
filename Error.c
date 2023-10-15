#include "main.h"

/**
 * Error - prints an error message for a command
 * @bin: name of program
 * @cmd: command
 * @message: error message
 * @line: line number
 * Return: void
 */
void Error(char *bin, char *cmd, char *message, int line)
{
	char *LineString = NULL;

	LineString = _itoa(line, "0123456789");
	write(STDERR_FILENO, bin, StringLen(bin));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, LineString, StringLen(LineString));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, StringLen(cmd));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, StringLen(message));
	write(STDERR_FILENO, "\n", 1);
	free(LineString);
}
