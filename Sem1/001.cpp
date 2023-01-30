#include <iostream>

int main() 
{
    int num, n, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        if (num == 42) 
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}