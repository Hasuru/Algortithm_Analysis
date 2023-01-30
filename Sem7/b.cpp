#include <algorithm>
#include <iostream>

int main() {
    int c;
    scanf("%d", &c);

    int a[c];
    for (int i = 0; i < c; i++) scanf("%d", &a[i]);

    std::sort(a, a+c);

    int count = 0, value = 0;
    int i = 0;

    while (true) {
        int temp = value;
        if (temp > a[c-1]) break;
        while (temp >= a[i]) {
            temp -= a[i];
            a[i] = 0;
            i++;
        }
        a[i] -= temp;
        temp = 0;
        value++;
        count++;
    }

    printf("%d\n", count-1);

    return 0;
}