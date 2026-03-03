#include <stdio.h>

int main()
{
    int n, i;

    // Step 2 & 3: Declare array size and get number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], waiting[n], turnaround[n];
    int total_wt = 0, total_tat = 0;

    // Step 4: Get burst time values
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &burst[i]);
    }

    // Step 5: First process waiting time = 0
    waiting[0] = 0;

    // Calculate waiting time for remaining processes
    for(i = 1; i < n; i++)
    {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    // Step 6: Calculate turnaround time
    for(i = 0; i < n; i++)
    {
        turnaround[i] = waiting[i] + burst[i];
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    // Step 7: Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    // Step 8: Stop
    return 0;
}

