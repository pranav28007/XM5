import java.util.*;

class Edge implements Comparable<Edge> {
    int src, dest, weight;

    public int compareTo(Edge e) {
        return this.weight - e.weight;
    }
}

class Subset {
    int parent, rank;
}

public class KruskalMST {

    int V, E;
    Edge edge[];

    KruskalMST(int v, int e) {
        V = v;
        E = e;
        edge = new Edge[E];

        for (int i = 0; i < E; i++)
            edge[i] = new Edge();
    }

    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    void union(Subset subsets[], int x, int y) {

        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;

        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;

        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    void kruskalMST() {

        Edge result[] = new Edge[V];
        for (int i = 0; i < V; i++)
            result[i] = new Edge();

        Arrays.sort(edge);

        Subset subsets[] = new Subset[V];

        for (int i = 0; i < V; i++) {
            subsets[i] = new Subset();
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        int e = 0;
        int i = 0;

        while (e < V - 1) {

            Edge next = edge[i++];

            int x = find(subsets, next.src);
            int y = find(subsets, next.dest);

            if (x != y) {
                result[e++] = next;
                union(subsets, x, y);
            }
        }

        int totalCost = 0;

        System.out.println("Edges in Minimum Spanning Tree:");

        for (i = 0; i < e; i++) {
            System.out.println(result[i].src + " - " +
                               result[i].dest + " : " +
                               result[i].weight);
            totalCost += result[i].weight;
        }

        System.out.println("Total Cost = " + totalCost);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();

        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();

        KruskalMST graph = new KruskalMST(V, E);

        System.out.println("Enter source, destination and weight:");

        for (int i = 0; i < E; i++) {
            graph.edge[i].src = sc.nextInt();
            graph.edge[i].dest = sc.nextInt();
            graph.edge[i].weight = sc.nextInt();
        }

        graph.kruskalMST();

        sc.close();
    }
}
