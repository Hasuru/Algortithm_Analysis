#include <iostream>
#include <string.h>

#define max(a,b) ((a>b) ? a : b)
#define setNeg(a) (memset(a, -1, sizeof(a)))

int main() {
    int depth;
    printf("depth: ");
    scanf("%d", &depth);
    int p[depth][depth];
    setNeg(p);

    printf("Tree values: ");
    int values;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &values);
            p[i][j] = values;
        }
    }

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("calculating path:\n");
    for (int i = depth-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            p[i][j] = p[i][j] + max(p[i+1][j], p[i+1][j+1]);
        }
    }
    printf("Path with biggest sum -> %d\n", p[0][0]);

    return 0;
}