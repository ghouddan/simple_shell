#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * StrLent - returns the length of a string
 * @String: the string to count (size)
 *
 * Return: length of string
 */
static int StrLent(char *String)
{
	int i = 0;

	while (String[i] != '\0')
	{
		if (String[i] == '#' && (i == 0 || String[i - 1] == ' '))
			break;
		i++;
	}
	return (i);
}

/**
 * CopyStr - copies a word from a string
 * @String: string to copy from
 * @start: first index of word
 * @end: last index of word
 *
 * Return: pointer
 */
char *CopyStr(char *String, int start, int end)
{
	char *word;
	int i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);

	for (i = 0; i < end - start; i++)
		word[i] = String[start + i];
	word[i] = '\0';

	return (word);
}

/**
 * WordNumber - counts the number of words
 * @String: string to count
 * @delimi: separator between the word
 *
 * Return: number of words
 */
int WordNumber(char *String, char delimi)
{
	int WordCount = 0, StringLent, i;

	if (!String || !String[0])
		return (0);

	StringLent = StrLent(String);

	for (i = 0; i < StringLent; i++)
	{
		if (String[i] != delimi
				&& (String[i + 1] == delimi || String[i + 1] == '\0'))
			WordCount++;
	}

	return (WordCount);
}
/**
 * StrTok - splits a string into words
 * @String: string to split
 * @delimi: separator between the word
 *
 * Return: array of word
 */
char **StrTok(char *String, char delimi)
{
	int WordCount, StringLen;
	char **Words;
	int start = 0, index = 0;
	int i, end;

	WordCount = WordNumber(String, delimi);
	if (!WordCount)
		return (NULL);

	Words = malloc(sizeof(char *) * (WordCount + 1));
	if (!Words)
		return (NULL);

	StringLen = StrLent(String);
	for (i = 0; i < StringLen; i++)
	{
		if (String[i] != delimi && (String[i + 1] == delimi || !String[i + 1]))
		{
			end = i + 1;
			Words[index] = CopyStr(String, start, end);
			if (!Words[index])
				return (FreeWord(Words, index), NULL);
			index++;
		} else if (String[i] != delimi && String[i + 1] != delimi)
			continue;
		else
			start = i + 1;
	}
	Words[index] = NULL;

	return (Words);
}
