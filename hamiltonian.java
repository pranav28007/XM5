import java.util.Scanner;

public class hamiltonian {

    static int n;
    static int[][] G;
    static int[] x;
    static int count = 0;

    // NextValue(k) function
    static void nextValue(int k) {
        while (true) {
            x[k] = (x[k] + 1) % (n + 1);

            if (x[k] == 0)
                return;

            // Check if there is an edge between previous vertex and current vertex
            if (G[x[k - 1]][x[k]] != 0) {

                int j;
                // Check for distinctness
                for (j = 1; j <= k - 1; j++) {
                    if (x[j] == x[k])
                        break;
                }

                // If distinct vertex
                if (j == k) {
                    // If last vertex, check edge back to first vertex
                    if (k < n || (k == n && G[x[n]][x[1]] != 0))
                        return;
                }
            }
        }
    }

    // Hamiltonian(k) function
    static void hamiltonian(int k) {
        while (true) {
            nextValue(k);

            if (x[k] == 0)
                return;

            if (k == n) {
                count++;
                System.out.print("Hamiltonian Cycle " + count + ": ");
                for (int i = 1; i <= n; i++) {
                    System.out.print(x[i] + " ");
                }
                System.out.println(x[1]); // print starting node again to show cycle
            } else {
                hamiltonian(k + 1);
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices (n): ");
        n = sc.nextInt();

        G = new int[n + 1][n + 1];
        x = new int[n + 1];

        System.out.println("Enter adjacency matrix (" + n + "x" + n + "):");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = sc.nextInt();
            }
        }

        // Start at node 1
        x[1] = 1;

        System.out.println("\nHamiltonian Cycles are:");
        hamiltonian(2);

        if (count == 0) {
            System.out.println("No Hamiltonian Cycle exists.");
        } else {
            System.out.println("\nTotal Hamiltonian Cycles = " + count);
        }

        sc.close();
    }
}
