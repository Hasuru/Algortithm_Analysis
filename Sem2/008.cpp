#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <array>

int max(int v1, int v2) {
    if (v1 > v2) return v1;
    return v2;
}

int kadane1D(int array[], int n) {
    int localMax = 0;
    int globalMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        localMax = max(array[i], array[i] + localMax);
        if (localMax > globalMax) globalMax = localMax;
    }
    return globalMax;
}

int main() {
    int rows, cols, value;
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &value);
            matrix[i][j] = value;
        }
    }

    // Kadane 2D
    int maxSum = INT_MIN, temp[rows], sum;
    for (int left = 0; left < cols; left++) {
        memset(temp, 0, sizeof(temp));
        for (int right = left; right < cols; right++) {
            for (int i = 0; i < rows; i++) {
                temp[i] += matrix[i][right];
            }
            sum = kadane1D(temp, rows);
            if (sum > maxSum) maxSum = sum;
        }
    }

    printf("%d\n", maxSum);
    return 0;
}