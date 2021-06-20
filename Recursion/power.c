#include<stdio.h>

int Rpower(int m,int n) {
    if(n> 0) 
        return m*Rpower(m,n-1);
    return 1;
}

int REpower(int m ,int n) {
    if (n==0)
    {
        return 1;
    }
    else if (n%2 == 0)
    {
        return REpower(m*m, n/2);
    }
    else {
        return m*REpower(m, n-1);
    }
}

int LEpower(int m, int n) {
    int pow = m;
    int flag = 1;
    while (n>0)
    {
        if (n%2 != 0)
        {
            pow = pow*m;
            n--;
        }
        else {
            if(flag == 1)
            {
                pow = pow*pow;
                n = n/2;
                flag = 0;
            }
        }
        
    }

    return pow;
    
}

int Lpower(int m, int n) {
    int pow =1;
    for (int i = n; i > 0; i--)
    {
        pow = pow*m;
    }
    
    return pow;
}

int main() {
    printf("%d\n", Rpower(5, 10));
    printf("%d\n", Lpower(5, 2));
    printf("%d\n", REpower(5, 2));
    printf("%d\n", LEpower(5, 3));
}