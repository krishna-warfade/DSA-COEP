#include <stdio.h>

int main()
{
    int i, j, len = 5, newlen = 0;
    double arr[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; i < len; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[i] = -1;
            }
        }
        if (arr[i] != -1) newlen++;
    }

    for (int i = 0; i < newlen; i++)
    {
        printf("%f ", arr[newlen]);
    }
    return 0;
}

// #include<stdio.h>

// int len, num;

// int main() {
//     while (num != -1)
//     {
        
//     }
    
// }