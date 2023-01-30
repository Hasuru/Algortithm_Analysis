#include <iostream>

int fib(int value);

int main() {
    char another;
    int value;
    do {
        printf("Value: ");
        scanf("%d", &value);
        printf("fib(%d) = %d\n", value, fib(value));

        printf("\nDo you wish to continue [y/n]: ");
        scanf(" %c", &another);
        printf("\n");
    } while (another == 'y');
    return 0;
}

int fib(int value) {
    if (value == 0 || value == 1) return value;
    int f;
    int f1 = 1;
    int f2 = 0;
    for (int i = 2; i <= value; i++) {
        f = f1+f2;
        f2 = f1;
        f1 = f;
    }
    return f;
}