#include <stdio.h>
#include <string.h>

void print_devowel(char ch[]);

int main(void) {
    char ch[100];
    while (fgets(ch, 100, stdin) != NULL) {
        print_devowel(ch);
    }
    
}

void print_devowel(char ch[]) {
    for (int i = 0; i < strlen(ch); i++) {
        if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'o' || ch[i] == 'i' || ch[i] == 'u') {

        } else {
            printf("%c", ch[i]);
        }
    }
}
