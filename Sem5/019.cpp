#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>

#define set0(a) (memset(a,0,sizeof(a)))
#define max(a,b) ((a > b)? a : b)

using namespace std;

int lcs(string s1, string s2, int n);

int main() {
    // N of cases
    int n;
    scanf("%d", &n);

    string num;
    // catch \n
    getline(cin, num);
    for (int k = 0; k < n; k++) {
        getline(cin, num);
        
        int size = num.size();
        string rev(num);
        reverse(rev.begin(), rev.end());

        printf("%d\n", size-lcs(num,rev,size));
    }
    return 0;
}

int lcs(string s1, string s2, int n) {
    int S[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) S[i][j] = 0;
            else if (s1[i-1] == s2[j-1]) S[i][j] = 1 + S[i-1][j-1];
            else S[i][j] = max(S[i-1][j], S[i][j-1]);
        }
    }
    return S[n][n];
}