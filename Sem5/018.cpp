#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef struct {
    int initVal;
    int target;
    vector<int> coinList;
} obj;

int n;

obj calc(int* s, int k);

int main() {
    scanf("%d", &n);
    int value, s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        s[i] = value;
    }

    int nVal;
    scanf("%d", &nVal);

    obj answer[nVal];
    int k;
    for (int i = 0; i < nVal; i++) {
        scanf("%d", &k);
        answer[i] = calc(s,k);
    }
    
    for (int i = 0; i < nVal; i++) {
        int size = answer[i].coinList.size();
        printf("%d: [%d] ", answer[i].initVal, answer[i].target);
        for (int j = 0; j < size; j++) {
            if (j == size-1) printf("%d", answer[i].coinList[j]);
            else printf("%d ", answer[i].coinList[j]);
        }
        printf("\n");
    }

    return 0;
}

obj calc(int* s, int k) {
    obj temp;
    temp.initVal = k;
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
    temp.target = coins[k];

    while (k != 0) {
        temp.coinList.push_back(use[k]);
        k = k - use[k];
    }
    return temp;
}