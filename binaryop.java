import java.util.Scanner;

public class binaryop {

    // Find function (as per algorithm)
    static int find(double[][] c, int[][] r, int i, int j) {
        double min = Double.MAX_VALUE;
        int l = -1;

        for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
            double cost = c[i][m - 1] + c[m][j];
            if (cost < min) {
                min = cost;
                l = m;
            }
        }
        return l;
    }

    static void obst(double[] p, double[] q, int n) {

        double[][] w = new double[n + 1][n + 1];
        double[][] c = new double[n + 1][n + 1];
        int[][] r = new int[n + 1][n + 1];

        // Initialization
        for (int i = 0; i <= n - 1; i++) {
            w[i][i] = q[i];
            c[i][i] = 0;
            r[i][i] = 0;

            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            c[i][i + 1] = w[i][i + 1];
            r[i][i + 1] = i + 1;
        }

        w[n][n] = q[n];
        c[n][n] = 0;
        r[n][n] = 0;

        // Main DP Computation
        for (int m = 2; m <= n; m++) {
            for (int i = 0; i <= n - m; i++) {
                int j = i + m;

                w[i][j] = w[i][j - 1] + p[j] + q[j];

                int k = find(c, r, i, j);

                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }

        // Output Results
        System.out.println("\n===== OBST RESULTS =====");
        System.out.println("Optimal Cost (c[0][" + n + "]) = " + c[0][n]);
        System.out.println("Total Weight (w[0][" + n + "]) = " + w[0][n]);
        System.out.println("Root (r[0][" + n + "]) = " + r[0][n]);

        // Print Tables
        System.out.println("\nCost Table (C):");
        printDoubleTable(c, n);

        System.out.println("\nWeight Table (W):");
        printDoubleTable(w, n);

        System.out.println("\nRoot Table (R):");
        printIntTable(r, n);
    }

    static void printDoubleTable(double[][] a, int n) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                System.out.printf("%.2f\t", a[i][j]);
            }
            System.out.println();
        }
    }

    static void printIntTable(int[][] a, int n) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of identifiers (n): ");
        int n = sc.nextInt();

        double[] p = new double[n + 1]; // p[1..n]
        double[] q = new double[n + 1]; // q[0..n]

        System.out.println("Enter successful search probabilities p[1..n]:");
        for (int i = 1; i <= n; i++) {
            p[i] = sc.nextDouble();
        }

        System.out.println("Enter unsuccessful search probabilities q[0..n]:");
        for (int i = 0; i <= n; i++) {
            q[i] = sc.nextDouble();
        }

        obst(p, q, n);

        sc.close();
    }
}
