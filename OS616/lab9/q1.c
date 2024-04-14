#include <stdio.h>
#include <stdlib.h>

void bestFit(int *blocks, int m, int *processes, int n) {
    int *alloc = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++) {
        alloc[i] = -1;
    }
    for(int i=0; i<n; i++) {
        int best = -1;
        for(int j=0; j<m; j++) {
            if (blocks[j] >= processes[i]) {
                if (best == -1 || blocks[best] > blocks[j])
                    best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            blocks[best] -= processes[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0; i<n; i++) {
        printf("   %d\t\t%d\t\t", i + 1, processes[i]);
        if (alloc[i] != -1)
            printf("%d", alloc[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

void firstFit(int *blocks, int m, int *processes, int n) {
    int *alloc = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++) {
        alloc[i] = -1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (blocks[j] >= processes[i]) {
                alloc[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0; i<n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processes[i]);
        if (alloc[i] != -1)
            printf("%d", alloc[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter number of processes: ");
    scanf("%d", &m);

    int *blocks = (int *)malloc(n * sizeof(int));
    int *processes = (int *)malloc(m * sizeof(int));

    for(int i=0; i<n; i++) scanf("%d", &blocks[i]);
    for(int i=0; i<m; i++) scanf("%d", &processes[i]);

    bestFit(blocks, m, processes, n);
    firstFit(blocks, m, processes, n);
    return 0;
}
