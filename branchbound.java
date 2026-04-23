import java.util.Scanner;

public class branchbound {

    static int n;
    static int[][] cost;
    static boolean[] visited;
    static int[] bestPath;
    static int[] currPath;

    static int bestCost = Integer.MAX_VALUE;

    // Function to calculate lower bound (minimum edge cost sum approximation)
    static int calculateBound(int currentCost) {
        int bound = currentCost;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int minEdge = Integer.MAX_VALUE;

                for (int j = 0; j < n; j++) {
                    if (i != j && cost[i][j] != 0) {
                        minEdge = Math.min(minEdge, cost[i][j]);
                    }
                }
                bound += minEdge;
            }
        }
        return bound;
    }

    // Branch and Bound Recursive Function
    static void tsp(int level, int currentCity, int currentCost) {

        // If all cities are visited, check returning to start
        if (level == n) {
            if (cost[currentCity][0] != 0) {
                int totalCost = currentCost + cost[currentCity][0];

                if (totalCost < bestCost) {
                    bestCost = totalCost;

                    for (int i = 0; i < n; i++)
                        bestPath[i] = currPath[i];

                    bestPath[n] = 0; // return to start
                }
            }
            return;
        }

        // Try all next cities
        for (int nextCity = 0; nextCity < n; nextCity++) {

            if (!visited[nextCity] && cost[currentCity][nextCity] != 0) {

                visited[nextCity] = true;
                currPath[level] = nextCity;

                int newCost = currentCost + cost[currentCity][nextCity];

                // Calculate Bound
                int bound = calculateBound(newCost);

                // Prune if bound is worse than best cost
                if (bound < bestCost) {
                    tsp(level + 1, nextCity, newCost);
                }

                visited[nextCity] = false;
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of cities: ");
        n = sc.nextInt();

        cost = new int[n][n];
        visited = new boolean[n];
        bestPath = new int[n + 1];
        currPath = new int[n];

        System.out.println("Enter cost adjacency matrix (0 if no path): ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = sc.nextInt();
            }
        }

        // Start from city 0
        visited[0] = true;
        currPath[0] = 0;

        tsp(1, 0, 0);

        System.out.println("\n===== OUTPUT =====");
        if (bestCost == Integer.MAX_VALUE) {
            System.out.println("No solution exists (graph disconnected).");
        } else {
            System.out.println("Minimum Cost = " + bestCost);
            System.out.print("Best Path = ");

            for (int i = 0; i <= n; i++) {
                System.out.print(bestPath[i] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
