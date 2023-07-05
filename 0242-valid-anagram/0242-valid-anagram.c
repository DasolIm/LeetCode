#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
	return *(const char*)a - *(const char*)b;
}

bool isAnagram(char* s, char* t) 
{
	int lenS = strlen(s);
	int lenT = strlen(t);

	if (lenS != lenT) return false;

	qsort(s, lenS, sizeof(char), compare);
	qsort(t, lenT, sizeof(char), compare);

	if (strcmp(s, t) == 0)
		return true;
	else
		return false;
}
