#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void only_alphabet(char* arr)
{
	int len = strlen(arr);
	int j = 0;
	char* result = (char*)malloc((len+1)*sizeof(char));
	for (int i = 0; i < len; i++)
	{
		if (isalnum(arr[i]))
		{
			result[j] = tolower(arr[i]);
			j++;
		}
	}
	result[j] = '\0';

	strcpy(arr, result);
	free(result);
}

bool isPalindrome(char* s)
{
	only_alphabet(s);

	int len = strlen(s);
	int i = 0;
	int j = len - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
