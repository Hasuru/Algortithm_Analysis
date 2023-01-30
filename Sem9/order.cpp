#include <iostream>
#include <string.h>
#include <list>

using std::list;

#define setF(a) (memset(a, false, sizeof(a)));
#define MAX 26

int n;
bool m[MAX][MAX];
bool visited[MAX];
list<int> order;

void dfs(int v) {
    visited[v] = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && m[v][i]) dfs(i);
    }
    order.push_front(v);
}

int main() {
    scanf("%d", &n);
    int a;
    scanf("%d", &a);

    setF(m);
    setF(visited);

    for (int i = 0; i < a; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        m[v1][v2] = m[v2][v1] = true;
    }

    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs(i);

    printf("DFS order:");
    for (auto i : order) {
        printf(" %d", i);
    }
    putchar('\n');

    return 0;
}