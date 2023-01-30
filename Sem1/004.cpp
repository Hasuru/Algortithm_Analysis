#include <stdio.h>
#include <string.h>
#include <iostream>
#include <array>

#define ll long long

ll arr[17];

// coloca numero no array e calcular a soma ao mesmo tempo
ll into_array_sum(ll num) {
    ll sum = 0;
    for (int i = 0; num > 0; i++) {
        arr[i] = num % 10;
        sum += arr[i];
        num /= 10;
    }
    return sum;
}

// ajusta o numero quando diff e >0
ll higher(int diff) {
    for (int i = 0; diff != 0; i++) {
        if (arr[i] == -1) arr[i] = 0;
        ll rest = 9 - arr[i];

        if (rest > diff) {
            arr[i] += diff;
            diff -= diff;
        } else {
            arr[i] += rest;
            diff -= rest;
        }
    }
    return diff;
}

// ajusta numero quando diff <0
ll lower(int diff) {
    for (int i = 0; diff < 0; i++) {
        diff -= 1-arr[i];
        arr[i] = 0;
        if (arr[i+1] == -1) arr[i+1] = 0;
        arr[i+1] += 1;
        for (int j = i+1; arr[j] >= 10; j++) {
            if (arr[j+1] == -1) arr[j+1] = 0;
            arr[j+1] += 1;
            arr[j] -= 10;
            diff += 9;
        }
    }
    return diff;
}

// transforma num no array para forma int
ll array_to_int() {
    ll temp = 1;
    ll num = 0;
    for (int i = 0; arr[i] != -1 ; i++) {
        num += arr[i] * temp;
        temp = temp*10;
    }
    return num;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        ll num, target, diff;
        memset (arr, -1, sizeof arr);
        scanf("%lld %lld", &num, &target);
        num += 1;
        diff = target - into_array_sum(num);
        while (diff != 0) {
            if (diff > 0) {
                diff = higher(diff);
            }
            else if (diff < 0) {
                diff = lower(diff);
            }
        }
        printf("%lld\n", array_to_int());
    }
    return 0;
}