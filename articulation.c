#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX];
int disc[MAX], low[MAX], parent[MAX];
int ap[MAX];
int time = 0, n;

void dfs(int u) {
    int v, children = 0;

    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (v = 0; v < n; v++) {

        if (graph[u][v] == 1) {

            if (!visited[v]) {
                children++;
                parent[v] = u;

                dfs(v);

                if (low[v] < low[u])
                    low[u] = low[v];

                // Case 1: root vertex
                if (parent[u] == -1 && children > 1)
                    ap[u] = 1;

                // Case 2: non-root vertex
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            }

            else if (v != parent[u]) {

                if (disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }
}

int main() {

    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

    printf("Articulation Points:\n");
    for (i = 0; i < n; i++) {
        if (ap[i] == 1)
            printf("%d ", i);
    }

    return 0;
}

