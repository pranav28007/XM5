#include <stdio.h>

int G[20][20], x[20];
int n;

void nextValue(int k)
{
    while (1)
    {
        x[k] = (x[k] + 1) % (n + 1);

        if (x[k] == 0)
            return;

        // Check if there is an edge between x[k-1] and x[k]
        if (G[x[k - 1]][x[k]] != 0)
        {
            int j;
            // Check if vertex is already included
            for (j = 1; j <= k - 1; j++)
            {
                if (x[j] == x[k])
                    break;
            }

            // If vertex is distinct
            if (j == k)
            {
                // If last vertex, check if it connects to first vertex
                if ((k < n) || (k == n && G[x[n]][x[1]] != 0))
                    return;
            }
        }
    }
}

void hamiltonian(int k)
{
    while (1)
    {
        nextValue(k);

        if (x[k] == 0)
            return;

        if (k == n)
        {
            printf("Hamiltonian Cycle: ");
            for (int i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("%d\n", x[1]);  // complete the cycle
        }
        else
        {
            hamiltonian(k + 1);
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    // Start from vertex 1
    x[1] = 1;
    for (int i = 2; i <= n; i++)
        x[i] = 0;

    printf("\nHamiltonian Cycles are:\n");
    hamiltonian(2);

    return 0;
}

