#include <stdio.h>
int main()
{
    int t, n, sum, minSum, startInd, endInd;
    scanf("%d", &t);
    while (t-- > 0)
    {
        int i, j, k;
        scanf("%d", &n);
        long int coins[n];
        for (i = 0; i < n; i++)
        {
            scanf("%ld", &coins[i]);
        }
        printf("\n");
        int workers[n];

        for (i = 0; i < n; i++)
        {
            scanf(" %d", &workers[i]);
        }

        long int min1 = 100000, min2 = 100000, min3 = 100000;
        for (i = 0; i < n; i++)
        {
            if (workers[i] == 1)
            {
                if (coins[i] < min1)
                    min1 = coins[i];
            }
            else if (workers[i] == 2)
            {
                if (coins[i] < min2)
                    min2 = coins[i];
            }

            if (workers[i] == 3)
            {
                if (coins[i] < min3)
                    min3 = coins[i];
            }
        }
        if ((min1 + min2) > min3)
        {
            printf("%ld\n", min3);
        }
        else
        {
            printf("%ld\n", (min1 + min2));
        }

        return 0;
    }
}