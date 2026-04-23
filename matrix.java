import java.util.Scanner;
import java.util.concurrent.*;

public class matrix {

    // Sequential MCM
    public static int matrixChainSequential(int[] p, int n) {
        int[][] m = new int[n][n];

        for (int i = 1; i < n; i++)
            m[i][i] = 0;

        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = Integer.MAX_VALUE;

                for (int k = i; k <= j - 1; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                        m[i][j] = q;
                }
            }
        }
        return m[1][n - 1];
    }

    // Parallel MCM (OpenMP style using ExecutorService)
    public static int matrixChainParallel(int[] p, int n, int threads) throws InterruptedException {
        int[][] m = new int[n][n];

        for (int i = 1; i < n; i++)
            m[i][i] = 0;

        ExecutorService executor = Executors.newFixedThreadPool(threads);

        for (int L = 2; L < n; L++) {

            CountDownLatch latch = new CountDownLatch(n - L);

            for (int i = 1; i < n - L + 1; i++) {
                final int ii = i;
                final int j = ii + L - 1;

                executor.execute(() -> {
                    m[ii][j] = Integer.MAX_VALUE;

                    for (int k = ii; k <= j - 1; k++) {
                        int q = m[ii][k] + m[k + 1][j] + p[ii - 1] * p[k] * p[j];
                        if (q < m[ii][j])
                            m[ii][j] = q;
                    }
                    latch.countDown();
                });
            }

            latch.await();
        }

        executor.shutdown();
        return m[1][n - 1];
    }

    public static void main(String[] args) throws InterruptedException {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of matrices: ");
        int matrices = sc.nextInt();

        int n = matrices + 1;
        int[] p = new int[n];

        System.out.println("Enter dimensions array (p0 p1 p2 ... pn): ");
        System.out.println("(Example: if matrices are 10x20, 20x30, 30x40 then input: 10 20 30 40)");

        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }

        System.out.print("Enter number of threads for parallel execution: ");
        int threads = sc.nextInt();

        // Sequential Time
        long startSeq = System.nanoTime();
        int seqResult = matrixChainSequential(p, n);
        long endSeq = System.nanoTime();
        double seqTime = (endSeq - startSeq) / 1e6;

        // Parallel Time
        long startPar = System.nanoTime();
        int parResult = matrixChainParallel(p, n, threads);
        long endPar = System.nanoTime();
        double parTime = (endPar - startPar) / 1e6;

        // Speedup
        double speedup = seqTime / parTime;

        System.out.println("\n===== OUTPUT =====");
        System.out.println("Minimum number of multiplications (Sequential): " + seqResult);
        System.out.println("Minimum number of multiplications (Parallel): " + parResult);

        System.out.println("\nSequential Execution Time: " + seqTime + " ms");
        System.out.println("Parallel Execution Time: " + parTime + " ms");

        System.out.println("\nSpeed-up = Sequential Time / Parallel Time");
        System.out.println("Speed-up Achieved = " + speedup);

        sc.close();
    }
}
