#include <stdio.h>
#include <stdbool.h>

bool contains(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return true;
        }
    }
    return false;
}

int fifo(int nf, int n) {
    int arr[nf];
    for(int i=0; i<nf; i++) {
        arr[i] = -1;
    }
    int page_fault = 0;
    int ref[n];
    int pos = 0;
    printf("Enter reference string: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &ref[i]);
    }
    for(int i=0; i<n; i++) {
        if(!contains(arr, nf, ref[i])) {
            page_fault++;
            arr[pos] = ref[i];
            pos = (pos + 1) % nf;
        }
    }
    return page_fault;
}

int main() {
    int nf, n;
    printf("Enter number of frames: ");
    scanf("%d", &nf);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pf = fifo(nf, n);
    printf("\nNumber of page faults: %d", pf);
    return 0;
}
