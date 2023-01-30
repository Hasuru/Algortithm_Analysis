#include <iostream>
#include <algorithm> 

typedef struct {
    char appearance;
    int frequency;
    int position;
} letter;

struct compare {
    bool operator() (const letter l1, const letter l2) {
        if (l1.frequency > l2.frequency) return true;
        if (l1.frequency == l2.frequency && l1.position < l2.position) return true;
        return false;
    }
};

int main() {
    char phrase[10001];
    letter alphabet[26];
    for (int i = 0; i < 26; i++) alphabet[i].position = -1;
    fgets(phrase, sizeof(phrase), stdin);

    int n, i;
    for (i = 0; phrase[i] != '\0'; i++) {
        n = phrase[i]-'A';
        alphabet[n].frequency++;
        alphabet[n].appearance = phrase[i];
        if (alphabet[n].position == -1) alphabet[n].position = i;
    }

    std::sort(alphabet, alphabet+26, compare());
    for (int j = 0; alphabet[j].frequency != 0; j++) {
        printf("%c %d\n", alphabet[j].appearance, alphabet[j].frequency);
    } 

    return 0;
}