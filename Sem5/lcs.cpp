#include <iostream>
#include <string>

#define max(a,b) ((a > b)? a : b)

using namespace std;

string lcs(string s1, string s2, int n, int m);

int main() {
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);

    int n = s1.size();
    int m = s2.size();

    cout << lcs(s1,s2,n,m) << endl;

    return 0;
}

string lcs(string s1, string s2, int n, int m) {
    int S[n+1][m+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) S[i][j] = 0;
            else if (s1[i] == s2[j]) S[i][j] = 1 + S[i-1][j-1];
            else S[i][j] = max(S[i-1][j], S[i][j-1]); 
        }
    }

    int len = S[n][m];
    string path = "";
    for (int i = 0; i < len; i++) {
        path += '$';
    }

    int i = n, j = m, index = len-1;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            path[index--] = s1[i-1];
            i--;
            j--;
        } else if (S[i][j-1] < S[i-1][j]) i--;
        else j--;
    }
    return path;
}