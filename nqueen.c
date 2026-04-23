#include <stdio.h>
#include <stdlib.h>

int x[20];   // x[k] stores column position of queen in row k
int count = 0;

int place(int k, int i)
{
    for(int j = 1; j <= k-1; j++)
    {
        // Same column or same diagonal
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void nQueens(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                count++;
                printf("\nSolution %d:\n", count);

                for(int row = 1; row <= n; row++)
                {
                    for(int col = 1; col <= n; col++)
                    {
                        if(x[row] == col)
                            printf(" Q ");
                        else
                            printf(" . ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if(n < 1 || n > 20)
    {
        printf("Enter n between 1 and 20.\n");
        return 0;
    }

    nQueens(1, n);

    if(count == 0)
        printf("\nNo solutions exist for %d queens.\n", n);
    else
        printf("\nTotal solutions = %d\n", count);

    return 0;
}

