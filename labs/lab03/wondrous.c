#include <stdio.h>

int main(void) {
    int num;
    printf("What number would you like to see: ");
    scanf("%d", &num);
    if (num == 1)
        return 0;
    for (int i = 0; i < num; i++)
        printf("*");
    
    printf("\n");

    while (num != 2) {
        if (num % 2 == 0) {
            num = num / 2;
            for (int i = 0; i < num; i++)
                printf("*");
        } else {
            num = 3 * num + 1;
            for (int i = 0; i < num; i++)
                printf("*");
        }
        printf("\n");
    }
}