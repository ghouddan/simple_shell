#include "main.h"
/**
 * FreeResources - frees all resources
 * @line: line to free
 * @tokens: tokens to free
 * Return: void
 */
void FreeResources(char **line, char ***tokens)
{
	int i;

	for (i = 0; (*tokens)[i]; i++)
		free((*tokens)[i]);
	free(*tokens);

	free(*line);
	*line = NULL;
	*tokens = NULL;
}
/**
 * FreeWord - frees an array of words
 * @Words: ponter to array of words
 * @WordCount: number of words
 * Return: void
 */
void FreeWord(char **Words, int WordCount)
{
	int i;

	for (i = 0; i < WordCount; i++)
		free(Words[i]);
	free(Words);
}
