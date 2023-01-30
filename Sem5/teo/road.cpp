#include <iostream>
#include <string.h>

#define set0(a) (memset(a,0,sizeof(a)))
#define setFalse(a) (memset(a,false,sizeof(a)))

int main() {
    int r;
    printf("Rows: ");
    scanf("%d", &r);

    int c;
    printf("\nColumns: ");
    scanf("%d", &c);

    int count[r][c];
    bool obras[r][c];
    set0(count);
    setFalse(obras);

    char rb;
    printf("\nAre there roadblocks [y/n]: ");
    scanf(" %c", &rb);

    int cr, cc;
    while (rb == 'y') {
        printf("\nGive the coords (x,y): ");
        scanf("%d %d", &cr,&cc);
        obras[cr-1][cc-1] = true;

        printf("\nDo you wish to add another roadblock [y/n]: ");
        scanf(" %c", &rb);
    }

    count[r-1][c-1] = 1;
    for (int i = r-1; i >= 0; i--) {
        for (int j = c-1; j >= 0; j--) {
            if (i < r && i+1 < r && !obras[i+1][j]) count[i][j] += count[i+1][j];
            if (j < c && j+1 < c && !obras[i][j+1]) count[i][j] += count[i][j+1];
        }
    }

    //duvida sobre as roadblocks mas resultado final esta em count[0][0]

    return 0;
}