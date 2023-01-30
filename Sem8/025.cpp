#include <iostream>
#include <string.h>

#define setF(a) (memset(a, false, sizeof(a)))
#define MAX 101

int n;
bool matrix[MAX][MAX];
bool visited[MAX];

void dfs(int v) {
    visited[v] = true;
    for (int i = 1; i <= n; i++) {
        if (matrix[v][i] && !visited[i]) dfs(i);
    }
}

int main() {
    scanf("%d", &n);
    // vars globais ja inicializam a false, mas so para confirmar
    setF(matrix);
    setF(visited);

    int a;
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        matrix[v1][v2] = matrix[v2][v1] = true;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}