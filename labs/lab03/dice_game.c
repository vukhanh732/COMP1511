#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int sum = 0;
    int num;
    bool double_next = false;


    printf("Enter numbers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num);

        if (double_next == false)
            sum += num;

        if (double_next == true)
            sum += num * 2;

        if (num == 1)
            double_next = true;
        else
            double_next = false;
        
    }

    printf("The sum of dice rolls is %d.\n", sum);
    

}