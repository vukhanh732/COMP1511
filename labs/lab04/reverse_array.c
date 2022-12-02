#include <stdio.h>

#define MAX_NUM 100

int main(void){
    int arr[MAX_NUM];
    int i = 0;
    int flag = 0;

    printf("Enter numbers forwards: \n");
    while (flag != EOF){
        flag = scanf("%d", &arr[i]);
        i++;
    }

    printf("Reversed: \n");

    int j = i - 2;
    while (j >= 0) {
        printf("%d\n", arr[j]);
        j--;
    }
}