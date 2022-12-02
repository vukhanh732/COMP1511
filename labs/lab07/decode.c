#include <stdio.h>
#include <string.h>
#include <assert.h>

void decrypt(char map[], char text[]);

int main(void) {
    char map[27];
    char text[100];
    printf("Enter mapping:\n");
    scanf(" %s", map);

    printf("Enter text:");
    // Scan in inputs until EOF
    while (fgets(text, 100, stdin) != NULL) { 
        decrypt(map, text);
    }
}

void decrypt(char map[], char text[]) {
    for (int i = 0; i < strlen(text); i++) {
        // If character is belong to mapping 
        if (text[i] >= 'a' && text[i] <= 'z') {
            int j = 0;
            while (text[i] != map[j]) {
                j++;
            }
            text[i] = 'a' + j;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            int j = 0;
            while (text[i] != (map[j] - 32)) {
                j++;
            }
            text[i] = 'A' + j;
        }
    }
    printf("%s", text);   
}