#include<stdio.h>
int main()
{
    int n,t;
    printf("enter n:");
    int sum = 0;
    for(int t = 1; t < n; t++)
    {
        if(n % t == 0)
        {
            sum += t;
        }
    }

    if(sum == n)
    {
        printf("n is sum of its divisors");
    }
    else{
        printf("n is sum of its divisors");
    }


    return 0;
}