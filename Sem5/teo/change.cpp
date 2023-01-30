#include <iostream>

int main() {
    int n;
    printf("How many coins we have: ");
    scanf("%d", &n);
    int value, s[n];
    printf("Coin Value: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        s[i] = value;
    }

    int k;
    printf("Target Value: ");
    scanf("%d", &k);
    int coins[k+1];
    int use[k+1];

    coins[0] = 0;
    use[0] = 0;
    for (int i = 1; i <= k; i++) {
        coins[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (s[j] <= i && (1 + coins[i-s[j]] < coins[i])) {
                use[i] = s[j];
                coins[i] = 1 + coins[i-s[j]];
            }
        }
    }

    printf("%d used %d coins: ", k, coins[k]);
    while (k != 0) {
        printf("%d ", use[k]);
        k = k - use[k];
    }
    printf("\n");

    return 0;
}