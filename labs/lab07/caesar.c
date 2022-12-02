#include <stdio.h>
#include <string.h>

void encrypt(char ch[], int shift);

int main(void){
    char ch[100];
    int shift;
    scanf("%d ", &shift);
    if (shift < 0) {
        shift = 26 + shift;
    }
    if (shift > 26) shift = shift % 26;
    while (fgets(ch, 100, stdin) != NULL) {
        encrypt(ch, shift);
    }
}

void encrypt(char ch[], int shift) {
    for (int i = 0; i < strlen(ch); i++) {
        if (ch[i] >= 'A' && ch[i] <= 'Z') {
            ch[i] = ch[i] + shift;
            if (ch[i] > 'Z') {
                ch[i] = ch[i] - 26;
            }
        }
        else if (ch[i] >= 'a' && ch[i] <= 'z') {
            ch[i] = ch[i] + shift;
            if ((unsigned char)ch[i] > 'z') {
                ch[i] = ch[i] - 26;
            }
        }
    }
    printf("%s", ch);
}