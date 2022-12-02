#include <stdio.h>
#include <string.h>

int main(void) {
    char ch[100];
    printf("Input word: ");
    fgets(ch, 100, stdin);

    printf("\nWord square is:\n");
    for (int i = 0; i < strlen(ch) - 1; i++){
        fputs(ch, stdout);
    }
}