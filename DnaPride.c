#include <stdio.h>

int main()
{
    int max = 100000;
    long long int t, n,i, valid = 0;
    scanf("%lld", &t);
    while (t--)
    {
        char ch[max];
        scanf("%lld", &n);
        scanf("%s", ch);

        for (i = 0; i < n; i++)
        {
            if (ch[i] == 'A')
                ch[i] = 'T';
            else if (ch[i] == 'T')
                ch[i] = 'A';
            else if (ch[i] == 'G')
                ch[i] = 'C';
            else if (ch[i] == 'C')
                ch[i] = 'G';
            else
            {
                printf("Error RNA nucleobases found!\n");
                valid = 1;
            }
        }
        if(valid!=1){
            printf("%s\n", ch);
        }
    }
    return 0;
}