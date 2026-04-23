import java.util.Scanner;

public class nqueen {

    static int[] x;          // x[k] stores column position of queen in row k
    static int count = 0;

    // Place function: checks if queen can be placed at row k and column i
    static boolean place(int k, int i) {
        for (int j = 1; j <= k - 1; j++) {
            // Same column or same diagonal
            if (x[j] == i || Math.abs(x[j] - i) == Math.abs(j - k))
                return false;
        }
        return true;
    }

    // NQueens function: places queens row by row
    static void nQueens(int k, int n) {
        for (int i = 1; i <= n; i++) {
            if (place(k, i)) {
                x[k] = i;

                if (k == n) {
                    count++;
                    System.out.print("Solution " + count + ": ");
                    printSolution(n);
                } else {
                    nQueens(k + 1, n);
                }
            }
        }
    }

    // Print solution in terms of array
    static void printSolution(int n) {
        System.out.print("[ ");
        for (int i = 1; i <= n; i++) {
            System.out.print(x[i] + " ");
        }
        System.out.println("]");

        // Print board format also
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (x[i] == j)
                    System.out.print(" Q ");
                else
                    System.out.print(" . ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of queens (n): ");
        int n = sc.nextInt();

        x = new int[n + 1];

        System.out.println("\nSolutions for " + n + "-Queens Problem:\n");

        nQueens(1, n);

        if (count == 0)
            System.out.println("No solution exists.");

        System.out.println("Total number of solutions = " + count);

        sc.close();
    }
}
