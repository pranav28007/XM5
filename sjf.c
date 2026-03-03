#include <stdio.h>

int main()
{
    int n, i, j;

    // Step 2 & 3: Declare array size and get number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], waiting[n], turnaround[n], process[n];
    int total_wt = 0, total_tat = 0;

    // Step 4: Get burst time values
    for(i = 0; i < n; i++)
    {
        process[i] = i + 1;   // Process ID
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Step 4 & 5: Sort processes based on burst time (FCFS if equal)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(burst[i] > burst[j])
            {
                // Swap burst time
                int temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                // Swap process ID
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Step 6: Calculate waiting time
    waiting[0] = 0;

    for(i = 1; i < n; i++)
    {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    // Step 8: Calculate turnaround time
    for(i = 0; i < n; i++)
    {
        turnaround[i] = waiting[i] + burst[i];
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    // Step 9: Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               process[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    // Step 10: Stop
    return 0;
}

