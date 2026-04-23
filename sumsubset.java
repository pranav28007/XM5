import java.util.Scanner;
import java.util.Arrays;

public class sumsubset {

    static int[] w;      // weights / set elements
    static int[] x;      // solution vector (0/1)
    static int n, m;
    static boolean found = false;

    // Function to print subset
    static void printSubset(int k) {
        System.out.print("Subset: { ");
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1)
                System.out.print(w[i] + " ");
        }
        System.out.println("}");
    }

    // Backtracking function (SumOfSub algorithm)
    static void sumOfSub(int s, int k, int r) {

        // Generate left child
        x[k] = 1;

        if (s + w[k] == m) {
            found = true;
            printSubset(k);
        }
        else if (k + 1 < n && (s + w[k] + w[k + 1] <= m)) {
            sumOfSub(s + w[k], k + 1, r - w[k]);
        }

        // Generate right child
        if (k + 1 < n && (s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
            x[k] = 0;
            sumOfSub(s, k + 1, r - w[k]);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements (n): ");
        n = sc.nextInt();

        w = new int[n];
        x = new int[n];

        System.out.println("Enter elements of set (positive integers):");
        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }

        System.out.print("Enter required sum (m): ");
        m = sc.nextInt();

        // Sort elements (important for algorithm)
        Arrays.sort(w);

        // Total sum of all elements
        int r = 0;
        for (int i = 0; i < n; i++)
            r += w[i];

        System.out.println("\nSorted Set: " + Arrays.toString(w));

        // Condition check
        if (w[0] > m || r < m) {
            System.out.println("No solution exists.");
        } else {
            System.out.println("\nSolutions:");
            sumOfSub(0, 0, r);

            if (!found) {
                System.out.println("No solution exists.");
            }
        }

        sc.close();
    }
}
