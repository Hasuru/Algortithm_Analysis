#include <stdio.h>
#include <array>

int main() {
    int n, value, low, up;
    scanf("%d", &n);
    int array[n], prefixSum[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        array[i] = value;
        if(i != 0) prefixSum[i] = prefixSum[i-1] + array[i];
        else prefixSum[0] = array[0];
    }
    
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &low, &up);
        if (low-2 < 0) {
            printf("%d\n", prefixSum[up-1]);
        } else {
            printf("%d\n", prefixSum[up-1] - prefixSum[low-2]);
        }
    }
    return 0;
}