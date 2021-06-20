#include<stdio.h>

int Rsum(int n) {
    if(n>0)
        return Rsum(n-1) + n;
    
    return 0;
}

int Lsum(int n) {
    int sum = 0;
    for (int i = n; i > 0; i--)
    {
        sum = sum + i;
    }
    return sum;
}

int main() {
    // Rsum(5);
    printf("%d\n", Rsum(5));
    printf("%d\n", Lsum(5));
    return 0;
}