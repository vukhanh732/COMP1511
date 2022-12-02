#include <stdio.h>
#include <string.h>
#include <assert.h>

void encrypt(char map[], char text[]);

int main(void) {
    char map[27];
    char text[100];
    printf("Enter mapping:\n");
    scanf(" %s", map);

    printf("Enter text:");
    // Scan in inputs until EOF
    while (fgets(text, 100, stdin) != NULL) { 
        encrypt(map, text);
    }
}

void encrypt(char map[], char text[]) {
    for (int i = 0; i < strlen(text); i++) {
        // If character is belong to mapping 
        if (text[i] >= 'a' && text[i] <= 'z') {
            // text[i] - 'a' == position of the characters in mapping. 
            // e.g. text[i] = 'c', then text[i] - 'a' == 2. Therefore we know
            // that text[i] will be replace by map[2] which map to the letter 'c'.
            text[i] = map[text[i] - 'a'];
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = map[text[i] - 'A'] - 32;
        }
    }
    printf("%s", text);   
}