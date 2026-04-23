import java.util.Scanner;

public class knap {

    public static void knapsack(int[] wt, int[] val, int W, int n) {

        int[][] dp = new int[n + 1][W + 1];

        // Build DP table
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {

                if (i == 0 || w == 0)
                    dp[i][w] = 0;

                else if (wt[i - 1] <= w)
                    dp[i][w] = Math.max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);

                else
                    dp[i][w] = dp[i - 1][w];
            }
        }

        // Maximum profit
        int maxProfit = dp[n][W];
        System.out.println("\nMaximum Profit = " + maxProfit);

        // Traceback to find selected items
        int w = W;
        System.out.println("Selected Items (weight, profit):");

        for (int i = n; i > 0 && maxProfit > 0; i--) {

            if (maxProfit != dp[i - 1][w]) {
                System.out.println("Item " + i + " -> (" + wt[i - 1] + ", " + val[i - 1] + ")");
                maxProfit -= val[i - 1];
                w -= wt[i - 1];
            }
        }

        // Print DP Table
        System.out.println("\nDP Table:");
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                System.out.print(dp[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        int[] wt = new int[n];
        int[] val = new int[n];

        System.out.println("Enter weights of items:");
        for (int i = 0; i < n; i++)
            wt[i] = sc.nextInt();

        System.out.println("Enter profits/values of items:");
        for (int i = 0; i < n; i++)
            val[i] = sc.nextInt();

        System.out.print("Enter knapsack capacity: ");
        int W = sc.nextInt();

        knapsack(wt, val, W, n);

        sc.close();
    }
}
