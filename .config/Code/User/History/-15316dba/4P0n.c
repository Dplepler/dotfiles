#include "utils.h"

/*
strlen returns the length of a given char array
Input: Character array
Output: Length of character array
*/
size_t strlen(const char* str) {

	size_t len = 0;
	while (str[len]) { len++; }

	return len;
}

char* itoa(int value, size_t base) {

    static char buf[32] = { 0 };

    

    for (size_t i = 30;)
}