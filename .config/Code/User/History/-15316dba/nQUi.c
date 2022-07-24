#include "utils.h"

char* itoa(int value, size_t base) {

    char result[100];
    char ptr[100];
    char begin[100];

    if (base < 2 || base > 36) { return "\0"; }
    if (value < 0 && base == 10) { *ptr++ = '-'; }

    begin = ptr;

    do {

        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    } while (value);

    *ptr-- = '\0';

    while (begin < ptr) {

        char tmp = *begin;
        *begin++ = *ptr;
        *ptr-- = tmp;
    }

    return result;
}