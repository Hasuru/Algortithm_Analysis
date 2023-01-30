#include <iostream>
#include <climits>
#include <cmath>

#define MAX 101
#define BILL 5

using namespace std;

int* dp = (int*)malloc(MAX*sizeof(int));

int main() {
    int value;
    scanf("%d", &value);

    int bills[BILL] = {1,5,10,20,100};
    dp[0] = 0;
    for (int i = 1; i <= MAX; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < BILL; j++) {
            if (i >= bills[j] && *(dp+(i-bills[j]))+1 < *(dp+i)) *(dp+i) = *(dp+i-bills[j])+1; 
        }
    }

    int n = value, cnt = 0;
    while (n != 0) {
        n /= 10;
        cnt++;
    }
    int arr[cnt];
    n = value;
    for (int i = 0; i < cnt; i++) {
        arr[i] = n % 10;
        n /= 10;
    }

    int nbills = 0;
    for (int i = 0; i < cnt; i++) {
        if (i >= 2) {
            n = pow(10,i-2);
            nbills += arr[i]*n;
        } else {
            n = pow(10,i);
            nbills += dp[arr[i]*n];
        }
    }

    printf("%d\n", nbills);

    return 0;
}