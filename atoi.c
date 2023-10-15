#include "main.h"

/**
 * NumberLen - lenght of a number
 * @numb: number to get
 * Return: lenght
 */
int NumberLen(int numb)
{
		int i = 0;

		if (numb == 0)
			return (1);
		if (numb < 0)
		{
			numb *= -1;
			i++;
		}
		while (numb)
		{
			numb /= 10;
			i++;
		}
		return (i);
}

/**
 * StrRev - reverses a string
 * @String: string to reverse
 * Return: reversed string
 */
char *StrRev(char *String)
{
	int first = 0, last = StringLen(String) - 1;
	char temp;

	while (first < last)
	{
		temp = String[first];
		String[first++] = String[last];
		String[last--] = temp;
	}

	return (String);
}

/**
 * ABS - computes the absolute value of an integer
 * @numb: integer to compute
 * Return: absolut of numb
*/
ssize_t ABS(ssize_t numb)
{
	return (numb < 0 ? -numb : numb);
}
/**
 * _itoa -  integer to a string
 * @integer: integer to convert
 * @base: base to convert to
 * Return: pointer to the converted string
 */
char *_itoa(ssize_t integer, char *base)
{
	char *result, *ReversedStr;
	ssize_t quotient, i = 0;
	int BaseLen;

	BaseLen = StringLen(base);
	if (BaseLen < 2 || BaseLen > 16)
		return (NULL);
	quotient = ABS(integer);
	result = malloc(NumberLen(integer) + 1);
	do {
		result[i++] = base[quotient % BaseLen];
		quotient /= BaseLen;
	} while (quotient);
	if (integer < 0 && BaseLen == 10)
		result[i++] = '-';

	ReversedStr = StrRev(result);
	result[i] = '\0';
	return (ReversedStr);
}
