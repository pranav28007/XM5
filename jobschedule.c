#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

void sortJobs(struct Job jobs[], int n) {
    struct Job temp;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(jobs[i].profit < jobs[j].profit) {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

int main() {

    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    for(int i = 0; i < n; i++) {
        printf("Enter deadline and profit for job %d: ", i + 1);
        jobs[i].id = i + 1;
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    sortJobs(jobs, n);

    int maxDeadline = 0;
    for(int i = 0; i < n; i++) {
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline];
    for(int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for(int i = 0; i < n; i++) {

        for(int j = jobs[i].deadline - 1; j >= 0; j--) {

            if(slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs:\n");

    for(int i = 0; i < maxDeadline; i++) {
        if(slot[i] != -1)
            printf("Job %d ", slot[i]);
    }

    printf("\nMaximum Profit = %d", totalProfit);

    return 0;
}

