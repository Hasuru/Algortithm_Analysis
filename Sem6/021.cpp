#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int a,r;
    scanf("%d %d", &a, &r);

    multiset<int, less<int>> set;
    string phr;
    // get \n
    getline(cin, phr);
    for (int i = 0; i < a+r; i++) {
        getline(cin, phr);
        if (phr[2] == 'K') set.insert(stoi(phr.substr(4,6)));
        else if (phr[2] == 'N') {
            printf("%d\n", *set.begin());
            auto min = set.begin();
            if (min != set.end()) set.erase(min);
        } else if (phr[2] == 'X') {
            printf("%d\n", *set.rbegin());
            set.erase(prev(set.end()));
        }
    }

    return 0;
}