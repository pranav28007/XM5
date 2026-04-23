#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int finalPath[MAX];
int tempPath[MAX];

int finalCost = INT_MAX;

// Function to find minimum edge cost from a city
int firstMin(int i)
{
    int min = INT_MAX;
    for(int k = 0; k < n; k++)
    {
        if(cost[i][k] < min && i != k)
            min = cost[i][k];
    }
    return min;
}

// Function to find second minimum edge cost from a city
int secondMin(int i)
{
    int first = INT_MAX, second = INT_MAX;

    for(int j = 0; j < n; j++)
    {
        if(i == j)
            continue;

        if(cost[i][j] <= first)
        {
            second = first;
            first = cost[i][j];
        }
        else if(cost[i][j] < second && cost[i][j] != first)
        {
            second = cost[i][j];
        }
    }
    return second;
}

// Branch and Bound recursive function
void TSPRec(int currBound, int currWeight, int level, int currPath[])
{
    if(level == n)
    {
        if(cost[currPath[level - 1]][currPath[0]] != 0)
        {
            int currRes = currWeight + cost[currPath[level - 1]][currPath[0]];

            if(currRes < finalCost)
            {
                for(int i = 0; i < n; i++)
                    finalPath[i] = currPath[i];

                finalPath[n] = currPath[0];
                finalCost = currRes;
            }
        }
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(cost[currPath[level - 1]][i] != 0 && visited[i] == 0)
        {
            int tempBound = currBound;
            currWeight += cost[currPath[level - 1]][i];

            if(level == 1)
                currBound -= ((firstMin(currPath[level - 1]) + firstMin(i)) / 2);
            else
                currBound -= ((secondMin(currPath[level - 1]) + firstMin(i)) / 2);

            // If promising
            if(currBound + currWeight < finalCost)
            {
                currPath[level] = i;
                visited[i] = 1;
                TSPRec(currBound, currWeight, level + 1, currPath);
            }

            // Backtrack
            currWeight -= cost[currPath[level - 1]][i];
            currBound = tempBound;

            for(int j = 0; j < n; j++)
                visited[j] = 0;

            for(int j = 0; j < level; j++)
                visited[currPath[j]] = 1;
        }
    }
}

// Main TSP function
void TSP(int start)
{
    int currPath[MAX];

    int currBound = 0;
    for(int i = 0; i < n; i++)
        currBound += (firstMin(i) + secondMin(i));

    currBound = (currBound % 2) ? (currBound / 2 + 1) : (currBound / 2);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    currPath[0] = start;

    TSPRec(currBound, 0, 1, currPath);
}

int main()
{
    int start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter starting city (0 to %d): ", n-1);
    scanf("%d", &start);

    TSP(start);

    printf("\nMinimum Cost = %d\n", finalCost);
    printf("Optimal Path: ");
    for(int i = 0; i <= n; i++)
        printf("%d ", finalPath[i]);

    printf("\n");

    return 0;
}

