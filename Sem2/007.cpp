#include <stdio.h>
#include <array>
#include <limits.h>

int max(int v1, int v2) {
    if (v1 > v2) return v1;
    return v2;
}

int kedane(int array[], int n) {
    int local_max = 0;
    int global_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        local_max = max(array[i], array[i] + local_max);
        if (local_max > global_max) global_max = local_max;
    }
    return global_max;
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n], val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        array[i] = val;
    }
    printf("%d\n", kedane(array, n));
}