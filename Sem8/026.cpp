#include <iostream>
#include <string.h>

#define setF(a) (memset(a, false, sizeof(a)))
#define MAX 101
#define FILL '#'
#define DIR 8

int plusx[DIR] = {-1,  0, 0, 1, 1,  1, -1, -1};
int plusy[DIR] = { 0, -1, 1, 0, 1, -1,  1, -1};

int rows, cols;
char matrix[MAX][MAX];
bool visited[MAX][MAX];
int count;

void dfs(int y, int x) {
    if (y < 0 || x < 0 || y >= rows || x >= cols) return; //out of bounds
    if (matrix[y][x] != FILL || visited[y][x]) return;
    visited[y][x] = true;
    count++;
    //printf("dfs(%d,%d) | count: %d\n", x, y, count);
    for (int i = 0; i < DIR; i++)  {
        dfs(y+plusy[i], x+plusx[i]);
    }
}

int main() {
    int k;
    scanf("%d", &k);

    while (k--) {
        setF(visited);
        int max = 0;
        scanf("%d %d", &rows, &cols);

        for (int i = 0; i < rows; i++) scanf("%s", matrix[i]);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == FILL && !visited[i][j]) {
                    count = 0;
                    dfs(i, j);
                    if (count > max) max = count;
                    //printf("------------------------\n");
                }
            }
        }
        printf("%d\n", max);
    }

    return 0;
}