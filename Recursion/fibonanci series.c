#include <stdio.h>

int fib(int n)
{
    static int index[10000];
    if (index[n] == 0)
    {
        if (n > 1)
        {
            index[n] = fib(n - 1) + fib(n - 2);
            return index[n];
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 0)
        {
            return 0;
        }
    }
    else
    {
        return index[n];
    }
}

int main()
{

    printf("%d", fib(500));

    return 0;
}