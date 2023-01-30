#include <iostream>

int read_array(int* array, int size);
int binarySearch(int low, int high, int array[], int size, int d);
bool check(int value, int array[], int size, int d);

int main() {
    int n;
    scanf("%d", &n);
    int distance[n], total;
    total = read_array(distance,n);

    int quantity, d;
    scanf("%d", &quantity);
    while (quantity--) {
        scanf("%d", &d);
        int target = binarySearch(0, total, distance, n, d);
        printf("%d\n", target);
    }

    return 0;
}

int read_array(int* array, int size) {
    int val, sum = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &val);
        array[i] = val;
        sum += array[i];
    }
    return sum;
}

int binarySearch(int low, int high, int array[], int size, int d) {
    int best = high;
    while (low < high) {
        int middle = low + (high-low)/2;
        if (check(middle, array, size, d)) {
            if (middle <= best) {
                best = middle;
            }
            high = middle;
        }
        else low = middle+1;
    }
    return best;
}

bool check(int value, int array[], int size, int d) {
    int sum = 0, b= 0;
    while (d >0) {
        if (sum + array[b] > value) {
            sum = 0;
            d--;
        } else {
            sum += array[b];
            b++;
        }
    }
    return !(b < size);
}