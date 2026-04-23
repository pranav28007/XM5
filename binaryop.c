#include <stdio.h>
#include <limits.h>

int findRoot(int c[20][20], int r[20][20], int i, int j)
{
    int min = INT_MAX;
    int l = -1;

    for(int m = r[i][j-1]; m <= r[i+1][j]; m++)
    {
        if(c[i][m-1] + c[m][j] < min)
        {
            min = c[i][m-1] + c[m][j];
            l = m;
        }
    }
    return l;
}

int main()
{
    int n;
    printf("Enter number of identifiers: ");
    scanf("%d", &n);

    float p[20], q[20];
    float w[20][20], cost[20][20];
    int r[20][20];

    printf("Enter successful search probabilities p[1..%d]:\n", n);
    for(int i = 1; i <= n; i++)
        scanf("%f", &p[i]);

    printf("Enter unsuccessful search probabilities q[0..%d]:\n", n);
    for(int i = 0; i <= n; i++)
        scanf("%f", &q[i]);

    // Initialization
    for(int i = 0; i <= n-1; i++)
    {
        w[i][i] = q[i];
        cost[i][i] = 0;
        r[i][i] = 0;

        w[i][i+1] = q[i] + q[i+1] + p[i+1];
        cost[i][i+1] = w[i][i+1];
        r[i][i+1] = i + 1;
    }

    w[n][n] = q[n];
    cost[n][n] = 0;
    r[n][n] = 0;

    // DP Computation
    for(int m = 2; m <= n; m++)
    {
        for(int i = 0; i <= n-m; i++)
        {
            int j = i + m;

            w[i][j] = w[i][j-1] + p[j] + q[j];

            int k = findRoot((int (*)[20])cost, r, i, j);

            cost[i][j] = w[i][j] + cost[i][k-1] + cost[k][j];
            r[i][j] = k;
        }
    }

    printf("\nOptimal Cost c[0][%d] = %.2f\n", n, cost[0][n]);
    printf("Optimal Weight w[0][%d] = %.2f\n", n, w[0][n]);
    printf("Optimal Root r[0][%d] = %d\n", n, r[0][n]);

    printf("\nRoot Table (r[i][j]):\n");
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            printf("%3d ", r[i][j]);
        printf("\n");
    }

    printf("\nCost Table (c[i][j]):\n");
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            printf("%6.2f ", cost[i][j]);
        printf("\n");
    }

    return 0;
}

