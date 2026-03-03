#include <stdio.h>

int main()
{
    int total_blocks, block_size;
    int n, i;
    int process_size;
    int allocated_blocks = 0;
    int total_wastage = 0;

    // Step 1: Start

    // Step 3: Enter total number of blocks and block size
    printf("Enter total number of blocks: ");
    scanf("%d", &total_blocks);

    printf("Enter size of each block (in KB): ");
    scanf("%d", &block_size);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Step 4: Allocate blocks to processes
    for(i = 1; i <= n; i++)
    {
        printf("\nEnter memory required for Process %d (in KB): ", i);
        scanf("%d", &process_size);

        if(process_size <= block_size && allocated_blocks < total_blocks)
        {
            allocated_blocks++;
            total_wastage += (block_size - process_size);

            printf("Process %d allocated to Block %d\n", i, allocated_blocks);
        }
        else if(allocated_blocks >= total_blocks)
        {
            printf("Process %d cannot be allocated (No free blocks available)\n", i);
        }
        else
        {
            printf("Process %d cannot be allocated (Process size exceeds block size)\n", i);
        }
    }

    // Step 5 & 6: Calculate and display wastage and remaining blocks
    printf("\nTotal Internal Fragmentation (Wastage): %d KB\n", total_wastage);
    printf("Remaining Free Blocks: %d\n", total_blocks - allocated_blocks);

    // Step 7: Stop
    return 0;
}

