#include <stdio.h>

int main()
{
    int total_memory, os_memory;
    int user_memory, n, i;
    int process_size, total_allocated = 0;

    // Step 1: Start

    // Step 3: Enter total memory size
    printf("Enter Total Memory Size (in KB): ");
    scanf("%d", &total_memory);

    // Step 4: Allocate memory for OS
    printf("Enter Memory allocated for OS (in KB): ");
    scanf("%d", &os_memory);

    user_memory = total_memory - os_memory;

    // Step 2 & 5: Declare variables and allocate memory to processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter memory required for Process %d (in KB): ", i);
        scanf("%d", &process_size);

        if(total_allocated + process_size <= user_memory)
        {
            total_allocated += process_size;
            printf("Process %d allocated successfully.\n", i);
        }
        else
        {
            printf("Process %d cannot be allocated (Not enough memory).\n", i);
        }
    }

    // Step 6: Display memory usage and wastage
    printf("\nTotal Memory       : %d KB", total_memory);
    printf("\nOS Memory          : %d KB", os_memory);
    printf("\nUser Memory        : %d KB", user_memory);
    printf("\nTotal Allocated    : %d KB", total_allocated);
    printf("\nMemory Wastage     : %d KB\n", user_memory - total_allocated);

    // Step 7: Stop
    return 0;
}

