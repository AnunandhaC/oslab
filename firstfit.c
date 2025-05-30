#include <stdio.h>

#define FREE 0
#define BUSY 1

void main() {
    struct process {
        int id, psize, blockno;
    } p[10] = {0};

    struct block {
        int num, bsize, fragment, status;
    } b[10] = {0};

    int nump, numb, i, j, totfrag = 0;

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &nump);

    printf("Enter number of blocks: ");
    scanf("%d", &numb);

    printf("Enter process sizes:\n");
    for (i = 1; i <= nump; i++) {
        scanf("%d", &p[i].psize);
        p[i].id = i;
        p[i].blockno = 0;  // Default to unallocated
    }

    printf("Enter block sizes:\n");
    for (i = 1; i <= numb; i++) {
        scanf("%d", &b[i].bsize);
        b[i].num = i;
        b[i].status = FREE;
    }

    // First Fit Allocation
    printf("\n--- FIRST FIT ---\n");
    for (i = 1; i <= nump; i++) {
        for (j = 1; j <= numb; j++) {
            if (b[j].status == FREE && p[i].psize <= b[j].bsize) {
                b[j].status = BUSY;
                b[j].fragment = b[j].bsize - p[i].psize;
                p[i].blockno = j;
                break;
            }
        }
    }

    // Output
    printf("\nProcess\t\tSize\t\tBlock No\tBlock Size\tFragment\n");
    for (i = 1; i <= nump; i++) {
        if (p[i].blockno != 0) {
            int blk = p[i].blockno;
            printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].psize,
                   blk, b[blk].bsize, b[blk].fragment);
            totfrag += b[blk].fragment;
        }
    }

    printf("Total internal fragmentation: %d\n", totfrag);

    // Show unallocated processes
    printf("\nUnallocated Processes:\n");
    for (i = 1; i <= nump; i++) {
        if (p[i].blockno == 0) {
            printf("P%d (size %d) could not be allocated\n", p[i].id, p[i].psize);
        }
    }

    // Optional: Show final block status
    printf("\nBlock Status:\n");
    for (i = 1; i <= numb; i++) {
        printf("Block %d: %s, Size: %d, Fragment: %d\n", i,
               b[i].status == BUSY ? "BUSY" : "FREE",
               b[i].bsize,
               b[i].status == BUSY ? b[i].fragment : -1);
    }
}
