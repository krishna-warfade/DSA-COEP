#include <stdio.h>

int main() {
    int num, sum = 0;

    scanf("%d", &num);
    for (int i = 1; i < num; i++)
    {
        if(num % i == 0) sum += i; //sum of all divisors
    }
    if (sum == num)
    {
        printf("Perfect Number\n");
    } else
    {
        printf("Not a Perfect Number\n");
    }  
    
    return 0;
}
