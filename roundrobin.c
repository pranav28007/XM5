#include <stdio.h>

int main()
{
    int n, i, time = 0, remain, tq;

    // Step 2 & 3: Declare array size and get number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], remaining[n], waiting[n], turnaround[n];
    int total_wt = 0, total_tat = 0;

    // Step 4: Get burst time
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];   // copy burst time
    }

    // Step 6: Define Time Quantum
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    // Step 8–11: Circular execution
    while(remain != 0)
    {
        for(i = 0; i < n; i++)
        {
            if(remaining[i] > 0)
            {
                if(remaining[i] <= tq)
                {
                    time += remaining[i];
                    waiting[i] = time - burst[i];
                    remaining[i] = 0;
                    remain--;
                }
                else
                {
                    time += tq;
                    remaining[i] -= tq;
                }
            }
        }
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++)
    {
        turnaround[i] = burst[i] + waiting[i];
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    // Step 12: Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i+1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    // Step 13: Stop
    return 0;
}

