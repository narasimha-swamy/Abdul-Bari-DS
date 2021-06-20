#include<stdio.h>

int Rfact(int n) {
    if(n>0) 
        return Rfact(n-1)*n;
    return 1;
}

int Lfact(int n) {
    int fact=1;

    for (int i = n; i > 0; i--)
    {
        fact= fact*i;
    }
    
}

int main() {
    printf("%d\n", Rfact(5));
    printf("%d\n", Lfact(5));
}