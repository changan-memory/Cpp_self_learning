#include <stdio.h>

#include <math.h>
int* printNumbers(int n, int* returnSize) {
    // write code here
    for (int i = 1; i <= pow(10.00, (double)(n)) - 1; ++i) {
        returnSize[i-1] = i;
    }
    return returnSize;
}

int main() {
    int n = 1;
    int arr[9];
    printNumbers(n, arr);
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}