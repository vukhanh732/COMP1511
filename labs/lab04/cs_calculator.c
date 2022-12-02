#include <stdio.h>

int main(void) {

    int flag = 0;
    while (flag != EOF) {
        char c;
        printf("Enter instruction: ");
        flag = scanf(" %c", &c);
        if (c == 's') {
            int num1;
            scanf("%d", &num1);
            printf("%d\n", num1 * num1);
        }
        if (c == 'p') {
            int num1, num2;
            int result = 1;
            scanf("%d %d", &num1, &num2);
            for (int i = 0; i < num2; i++) {
                result *= num1;
            }
            printf("%d\n", result);
        } else {
            continue;
        }
    }
}