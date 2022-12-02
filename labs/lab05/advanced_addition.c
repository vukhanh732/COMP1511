// Add two numbers together, but in an array.

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 101

int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE] = {0};

    // Get the array size.
    int num_digits, num_rows;
    printf("Enter the number of rows (excluding the last): ");
    scanf("%d", &num_rows);
    assert(num_rows > 0 && num_rows < 100);

    printf("Enter the number of digits on each row: ");
    scanf("%d", &num_digits);
    assert(num_digits > 0 && num_digits < MAX_SIZE);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < num_rows) {
        int j = 0;
        while (j < num_digits) {
            assert(scanf("%d", &array[i][j]) == 1);
            if (array[i][j] < 0 || array[i][j] > 9) {
                printf("You entered a value not between 0 and 9.\n");
                return 1;
            }
            j++;
        }
        i++;
    }

    int carry = sum(num_rows, num_digits, array);

    int j = 0;
    while (j < num_digits) {
        printf("%d ", array[num_rows][j]);
        j++;
    }
    printf("\n");

    if (carry > 0) {
        printf("Carried over: %d\n", carry);
    }

    return 0;
}

// Put the sum of the lines in the array into the last line
// accounting for carrying. Return anything you did not carry.
//
// NOTE: num_lines is the number of lines you are adding together. The
// array has an extra line for you to put the result.
int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]) {
    int carry = 0;
    // Loop from row 0 to num_lines
    for (int i = 0; i < num_lines; i++){
        // Loop from right to left. Start at array[num_lines][num_digits - 1] and
        // end at array[num_lines][1].
        for (int j = num_digits - 1; j >= 0; j--) {
            array[num_lines][j] += (array[i][j] + carry);
            if (array[num_lines][j] >= 10 && j != 0) {
                carry = array[num_lines][j] / 10;
                array[num_lines][j] = array[num_lines][j] % 10;
            } else {
                carry = 0;
            }
        
        }
    }
    
    if (array[num_lines][0] >= 10) {
        carry = array[num_lines][0] / 10;
        array[num_lines][0] = array[num_lines][0] % 10;
        return carry;
    }
    
    return carry;   
}
