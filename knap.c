#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, m;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int p[n+1], w[n+1];

    printf("Enter profit of each item:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter weight of each item:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    int dp[n+1][m+1];

    // DP table initialization
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(w[i] <= j)
                dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j - w[i]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][m]);

    // Traceback to find selected items
    int x[n+1];
    for(int i = 1; i <= n; i++)
        x[i] = 0;

    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        i--;
    }

    printf("\nSelected Items (1 means selected, 0 means not selected):\n");
    for(int i = 1; i <= n; i++)
        printf("Item %d -> %d\n", i, x[i]);

    return 0;
}

