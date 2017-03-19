#include "solution.h"
#include <string.h>

int hasDuplicateChar(char* s) {
	char* traverse = s;

	while (*traverse != '\0') {
		if (strchr(traverse + 1, *traverse)) {
			return 1;
		}
		else {
			traverse++;
		}
	}

	return 0;
}

int lengthOfLongestSubstring(char* s) {

	int finalLength = 0;
	while (*s != '\0') {
		if (strlen(s) < finalLength) {
			break;
		}
		char* sub = (char*)malloc(sizeof(char)*finalLength + sizeof(char));
		strncpy(sub, s, finalLength);
		sub[finalLength] = '\0';
		int duplicated = hasDuplicateChar(sub);
		if (duplicated) {
			++s;
			continue;
		}
		char* found = strchr(sub, *(s + finalLength));
		if (!found) {
			++finalLength;
		}
		else {
			++s;
		}
		free(sub);
	}
	return finalLength;
}