#include "main.h"
/**
 * StringCmp - calculate the length of a string
 * @String1 : string 1
 * @String2 : string 2
 * Return: length of the string
 */
int StringCmp(char *String1, char *String2)
{
	int i = 0;

	while (String1[i] != '\0')
	{
		if (String1[i] != String2[i])
			break;
		i++;
	}
	return (String1[i] - String2[i]);
}

/**
 * ShearchStr - calculate the length of a string
 * @String: string
 * @c : character to shearch
 * Return: length of the string
 */
char *ShearchStr(char *String, char c)
{
	int i = 0;

	while (String[i] != '\0')
	{
		if (String[i] == c)
			break;
		i++;
	}

	if (String[i] == c)
		return (String + i);
	else
		return (0);
}
/**
 * StringLen - calculate the length of a string
 * @String: string
 * Return: length of the string
 */
int StringLen(char *String)
{
	int i = 0;

	while (String[i] != '\0')
		i++;
	return (i);
}

