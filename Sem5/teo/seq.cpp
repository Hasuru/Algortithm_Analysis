#include <iostream>

int main() {
    int size;
    printf("sample size: ");
    scanf("%d", &size);
    int num[size], best[size], next[size];

    printf("Values: ");
    int value;
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        num[i] = value;
        best[i] = 1;
        next[i] = -1;
    }

    for (int i = size-2; i >= 0; i--) {
        for (int j = i+1; j < size; j++) {
            if (num[j] > num[i] && (1+best[j]) > best[i]) {
                best[i] = 1 + best[j];
                next[i] = j;
            } 
        }
    }

    int max = 0;
    for (int i = 0; i < size; i++) {
        if (best[i] > max) max = i;
    }
    printf("\nbiggest length for sequence found: %d\n", best[max]);

    printf("Corresponding sequence: ");
    while (next[max] != -1) {
        printf("%d -> ", num[max]);
        max = next[max];
    }
    printf("%d\n\n", num[max]);
    return 0;
}