#include <stdio.h>

int main()
{
    int n, i, j;

    // Step 2: Accept number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n], burst[n], priority[n];
    int waiting[n], turnaround[n];
    int total_wt = 0, total_tat = 0;

    // Step 3: Accept process ID, burst time and priority
    for(i = 0; i < n; i++)
    {
        process[i] = i + 1;
        printf("\nProcess %d\n", i + 1);

        printf("Enter Burst Time: ");
        scanf("%d", &burst[i]);

        printf("Enter Priority: ");
        scanf("%d", &priority[i]);
    }

    // Step 4: Sort according to priority (smaller number = higher priority)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(priority[i] > priority[j])
            {
                // Swap priority
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap burst time
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                // Swap process ID
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Step 5: First process waiting time = 0
    waiting[0] = 0;
    turnaround[0] = burst[0];

    // Step 6 & 7: Calculate waiting and turnaround times
    for(i = 1; i < n; i++)
    {
        waiting[i] = waiting[i-1] + burst[i-1];
        turnaround[i] = waiting[i] + burst[i];
    }

    // Step 8: Calculate totals
    for(i = 0; i < n; i++)
    {
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    // Display results
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               process[i], priority[i], burst[i],
               waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    // Step 9: Stop
    return 0;
}

