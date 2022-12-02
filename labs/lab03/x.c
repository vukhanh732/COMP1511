#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i + j) == (size - 1) || (i == j))
                printf("*");
            else 
                printf("-");
        }
        printf("\n");
    }

    return 0;
}