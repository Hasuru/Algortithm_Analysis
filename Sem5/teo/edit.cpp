#include <iostream>
#include <string>
#include <utility>

#define min(a,b) ( a < b ? a : b)

using namespace std;

typedef struct {
    pair<char,char> letters;
    char direction;
} path;

int main() {
    string word1; 
    cout << "Word 1: ";
    getline(cin, word1);
    word1.shrink_to_fit();

    string word2;
    cout << "Word 2: ";
    getline(cin, word2);
    word2.shrink_to_fit();

    int size = min(word1.size(), word2.size());

    cout << size << endl;

    int de[size+1][size+1];
    path path[size*size];
    int value, cur = 0;
    for (int i = 0; i <= size; i++) de[i][0] = i;
    for (int j = 0; j <= size; j++) de[0][j] = j;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (word1[i-1] == word2[j-1]) value = 0;
            else value = 1; 
            de[i][j] = min(de[i-1][j-1]+value, min(de[i-1][j]+1, de[i][j-1]+1));
        }
    }
    /* board print
    cout << endl << "  ";
    for (int j = 0; j <= size; j++) {
        if (j != 0) cout << word2[j-1] << " ";
        else cout << "  ";
    }
    cout << endl;
    for (int i = 0; i <= size; i++) {
        if(i != 0) cout << word1[i-1] << " ";
        else cout << "  ";
        for (int j = 0; j <= size; j++) {
            cout << de[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << "Number of transformations: " << de[size][size] << endl;

    return 0;
}