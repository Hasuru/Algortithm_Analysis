#include <iostream>
#include <string.h>

#define BLACK 0
#define BLUE 1
#define MAX 51

#define setB(a) (memset(a, BLACK, sizeof(a)))
#define setF(a) (memset(a, false, sizeof(a)))

bool flag;
int n;
int paint;
bool m[MAX][MAX];
bool visited[MAX];
int color[MAX];

void dfs(int v, int paint) {
    visited[v] = true;
    color[v] = paint;

    //if (paint == BLUE) printf("dfs(%d,BLUE)\n", v);
    //else printf("dfs(%d,RED)\n", v);

    for (int i = 1; i <= n; i++) {
        if (visited[i] && m[v][i]) {
            if (color[i] == color[v]) {
                flag = false;
                return;
            }
        }
        if (!visited[i] && m[v][i]) dfs(i, -paint);
    }
}

int main() {
    int k;
    scanf("%d", &k);
    
    while (k--) {
        scanf("%d", &n);
        int a;
        scanf("%d", &a);

        setB(color);
        setF(visited);
        setF(m);

        for (int i = 0; i < a; i++) {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            m[v1][v2] = m[v2][v1] = true;
        }

        flag = true;
        paint = 1;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, paint);
                if (!flag)
                    break;
            }
        }

        if (flag) printf("sim\n");
        else printf("nao\n");
    }

    return 0;
}