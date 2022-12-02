// String to Lower
// string_to_lower.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// One line summary of what this exercise does.
//
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

void string_to_lower(char *string);

int main(void) {

    char str[MAX_LEN] = "Hi, mY nAmE iS sPonGEbOb sQuArePanTS.";
    string_to_lower(str);
    printf("%s\n", str);

    return 0;
}

// Convert the characters in `buffer` to lower case
void string_to_lower(char *string) {
    // YOUR CODE GOES HERE!
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        }
    }
}
