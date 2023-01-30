#include <iostream>
#include <string.h>

#define MAX 25
#define YELLOW 0
#define ORANGE 1
#define RED 2

#define setF(a) (memset(a, false, sizeof(a)))
#define setyellow(a) (memset(a, YELLOW, sizeof(a)))

int n;
bool m[MAX][MAX];
int color[MAX];
bool flag;

void dfs(int v) {
    color[v] = ORANGE;

    for (int i = 1; i <= n; i++) {
        if (color[i] == ORANGE && m[v][i]) {
            flag = false;
            return;
        }
        if (color[i] == YELLOW && m[v][i]) dfs(i);
    }
    color[v] = RED;
}

int main() {
    int k;
    scanf("%d", &k);
    printf("--------------------------------\n");
    while (k--) {
        scanf("%d", &n);
        int a;
        scanf("%d", &a);

        setyellow(color);
        setF(m);
        for (int i = 0; i < a; i++) {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            m[v1][v2] = true;
        }

        flag = true;
        int stoper = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == YELLOW) dfs(i);
            if (!flag) {
                stoper = i;
                break;
            }
        }

        if (flag) printf("Grafo aciclico!\n");
        else printf("Ciclo encontrado no node %d!\n", stoper);
        printf("--------------------------------\n");
    }

    return 0;
}