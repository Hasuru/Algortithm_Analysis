#include <iostream>
#include <string.h>
#include <utility>

#define set0(a) (memset(a, 0, sizeof(a)));
#define ll long long

using namespace std;

int depth;

bool isPossible(int x, int y, int value);

int main() {
    //printf("depth: ");
    scanf("%d", &depth);

    ll badShape[depth][depth];
    set0(badShape);
    for (int j = 0; j < depth; j++) badShape[depth-1][j] = 1;

    int bad;
    //printf("N of bad rocks: ");
    scanf("%d", &bad);

    int row, col;
    //printf("\nBad rocks:\n");
    for (int k = 0; k < bad; k++) {
        //printf("Bad Rock %d# | Row & Col: ", k+1);
        scanf("%d %d", &row, &col);
        badShape[depth-row][col-1] = -1;
    }

    if (badShape[0][0] != -1) {
        for (int i = depth-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (badShape[i][j] != -1) {
                    if (isPossible(i+1,j,badShape[i+1][j])) badShape[i][j] += badShape[i+1][j];
                    if (isPossible(i+1,j+1,badShape[i+1][j+1])) badShape[i][j] += badShape[i+1][j+1];
                }
            }
        }
    } else {
        badShape[0][0] = 0;
    }

    printf("%lld\n", badShape[0][0]);

    return 0;
}

bool isPossible(int x, int y, int value) {
    if (x >= depth || x < 0 || y >= depth || y < 0) return false;
    if (value == -1) return false;
    return true;
}