#include <iostream>
#include <list>
#include <string>
#include <cmath>

#define MAX 27 // n de letras no alfabeto

using namespace std;

list<int> order;
bool matrix[MAX][MAX];
bool exists[MAX];
bool visited[MAX];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < MAX; i++) {
        if (!visited[i] && matrix[v][i]) dfs(i);
    }
    order.push_front(v);
}

void checkLinks(string s1, string s2) {
    int size = (int) min(s1.size(), s2.size());
    int n1,n2;
    for (int i = 0; i < size; i++) {
        n1 = s1.at(i) - 'A';
        n2 = s2.at(i) - 'A';
        if (n1 != n2) {
            if (!matrix[n1][n2]) {
                matrix[n1][n2] = true;
                exists[n1] = true;
            }
            return;
        }
    }
}

int main() {
    for (int i = 0; i < MAX; i++) visited[i] = false;

    int p;
    scanf("%d", &p);

    string prev, cur;
    getline(cin, prev); // apanhar '\n'

    getline(cin, prev);
    for (int i = 1; i < p; i++) {
        getline(cin, cur);
        checkLinks(prev, cur);
        prev = cur;
    }

    for (int i = 0; i < MAX; i++) {
        if (exists[i] && !visited[i]) dfs(i);
    }

    for (auto const o : order) {
        printf("%c", o+'A');
    }
    putchar('\n');

    return 0;
}