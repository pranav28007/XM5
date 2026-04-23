#include <stdio.h>

int w[50], x[50], n, m;
int found = 0;

void sumOfSub(int s, int k, int r)
{
    x[k] = 1;

    // Left child (include w[k])
    if (s + w[k] == m)
    {
        found = 1;
        printf("Subset: { ");
        for (int i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("}\n");
    }
    else if (k < n && (s + w[k] + w[k + 1] <= m))
    {
        sumOfSub(s + w[k], k + 1, r - w[k]);
    }

    // Right child (exclude w[k])
    if (k < n && (s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        sumOfSub(s, k + 1, r - w[k]);
    }
}

int main()
{
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in increasing order:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("Enter required sum: ");
    scanf("%d", &m);

    if (w[1] > m || sum < m)
    {
        printf("No solution exists.\n");
        return 0;
    }

    printf("\nSolutions are:\n");
    sumOfSub(0, 1, sum);

    if (!found)
        printf("No solution exists.\n");

    return 0;
}

