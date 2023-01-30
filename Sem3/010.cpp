#include <iostream>
#include <algorithm>

void readVals(int* array, int size) {
    int val;
    for (int i = 0; i < size; i++) {
        scanf("%d", &val);
        *(array+i) = val;
    }
}

int abs(int a) {
    if (a<0) return -a;
    return a;
}

int check(int goal, int v1, int v2, int sum[]) {
    if (v1 < 0) return 2;
    if (abs(goal - sum[v1]) == abs(goal - sum[v2])) return 0;
    if (abs(goal - sum[v1]) < abs(goal - sum[v2])) return 1;
    return 2;
}

void bSearch(int low, int high, int goal, int sum[]) {
    while (low < high) {
        int middle = low + (high-low)/2;
        if (sum[middle] > goal) high = middle;
        else low = middle+1;
    }
    
    switch (check(goal, low-1, low, sum))
    {
        case 0:
            printf("%d %d\n", sum[low-1], sum[low]);
            break;
        case 1:
            printf("%d\n", sum[low-1]);
            break;
        case 2:
            printf("%d\n", sum[low]);
            break;
    }
}

int main() {
    // read array values
    int n;
    scanf("%d", &n);
    int v[n];
    readVals(&v[0], n);

    // calculate all sums possible within array
    int s = 0;
    int sum[n/2*(n-1)];
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            sum[s] = v[i] + v[j];
            s++;
        }
    }
    std::sort(sum, sum + s);

    // read range search values
    int q;
    scanf("%d", &q);
    int pares[q];
    readVals(&pares[0], q);

    // binary search through the target array
    for (int i = 0; i < q; i++) {
        bSearch(0, s-1, pares[i], sum);
    }

    return 0;
}