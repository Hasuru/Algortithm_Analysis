#include <iostream>

int amount;

int  choose_player();
int  play(bool* win);
void calcWin(bool* win);
void print_pile();

int main() {
    printf("Amount of rocks: ");
    scanf("%d", &amount);

    bool win[amount+1];
    calcWin(win);

    bool player = (choose_player() == 1);

    //for (int i = 0; i <= amount; i++) printf("[%d] ", win[i]);
    //printf("\n");
    int value;
    while (amount != 0) {
        if (player) {
            printf("\nHow many rocks you want to remove: ");
            scanf("%d", &value);
            while (amount-value < 0) {
                printf("\nInvalid number, try again.");
                printf("\nHow many rocks you want to remove: ");
                scanf("%d", &value);
            }
            printf("You removed %d rocks!\n", value);
        } else {
            value = play(win);
            if (value == 0) {
                printf("\nAI accepts defeat!\n");
                break;
            }
            printf("\nAI removed %d rocks!\n", value);
        }
        player = !player;
        amount -= value;
        print_pile();
    }

    player ? printf("AI won!\n") : printf("You won!\n");

    return 0;
}

int choose_player() {
    printf("Choose player:\n"
    "\t1 - player\n"
    "\t2 - ai\n");
    int player;
    printf("player: ");
    scanf("%d", &player);
    return player;
}

int play(bool* win) {
    int max = 0;
    if (amount >= 1 && !win[amount-1]) max = 1;
    if (amount >= 3 && !win[amount-3]) max = 3;
    if (amount >= 8 && !win[amount-8]) max = 8;
    return max;
}

void calcWin(bool* win) {
    win[0] = false;
    for (int i = 1; i <= amount; i++) {
        if ((i >= 1 && !win[i-1]) || (i >= 3 && !win[i-3]) || (i >= 8 && !win[i-8])) win[i] = true;
        else win[i] = false;
    }
}

void print_pile() {
    if (amount != 0) {
        printf("pile: ");
        for (int i = 0; i < amount; i++) printf("O ");
        printf("\n");
        return;
    }
    printf("\n-=-=-=-=-=-=-=-=-=-\n"
    "pile is empty!\n");
}