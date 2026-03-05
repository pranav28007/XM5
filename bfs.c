#include <stdio.h>

int adj[10][10], visited[10], queue[10];
int front = -1, rear = -1, n;

void enqueue(int v) {
    if (rear == n - 1)
        return;
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = v;
    }
}

int dequeue() {
    int item = queue[front];
    front++;
    return item;
}

void bfs(int start) {
    int i;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}

