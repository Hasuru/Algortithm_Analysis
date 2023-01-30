#include <iostream>

bool isPossible(int k, int target, int array[], int size);

int main() {
    int size, val;
    scanf("%d", &size);
    
    int array[size];
    //int sumArray[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &val);
        array[i] = val;
        //if (i == 0) sumArray[i] = array[i];
        //else sumArray[i] = sumArray[i-1] + array[i];
    }

    int k = 4;
    int target = 26;

    printf("Is it possible with %d particions where sum is <= to %d? [%d]\n", k, target, isPossible(k, target, array, size));

    return 0;
}

bool isPossible(int k, int target, int array[], int size) {
    //printf("isPossible Method:\nk:%d  target:%d\n", k,target);
    int blocks = 0, curSum = 0, max = 0;
    for (int i = 0; i < size; i++) {
        if (curSum+array[i] > target) {
            //printf("i %d  /  curSum %d\n", i, curSum);
            if (curSum > max) max = curSum;
            curSum = array[i];
            blocks++;
        } else {
            curSum += array[i];
        }
    }
    blocks += (curSum <= target);
    printf("%d\n", max);
    //printf("Blocks %d\n", blocks);
    return (blocks == k);
}