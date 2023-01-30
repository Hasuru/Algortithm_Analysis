#include <iostream>
#include <string.h>

#define putF(a) (memset(a, false, sizeof(a)))
#define MAX 25

int v;
bool matrix[MAX][MAX];
bool visited[MAX];

void dfs(int n) {
    visited[n] = true;
    //printf("dfs(%d)\n", n);
    for (int i = 1; i <= v; i++) {
        if (matrix[n][i] && !visited[i]) dfs(i);
    }

}

int main() {
    scanf("%d", &v);
    putF(matrix);
    putF(visited);

    int e;
    scanf("%d", &e);

    while (e--) {
        int v1,v2;
        scanf("%d %d", &v1, &v2);
        matrix[v2][v1] = matrix[v1][v2] = true;
    }
    
    int count = 0;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}