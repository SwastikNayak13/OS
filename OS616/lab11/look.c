#include <stdio.h>
#include <stdlib.h>

void sort(int queue[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (queue[j] > queue[j + 1]) {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

int find(int queue[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (queue[i] == key) {
            return i;
        }
    }
    return -1;
}

int LOOK(int queue[], int n, int header) {
    sort(queue, n);
    printf("ARRAY: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }
    int pos = find(queue, n, header);
    int prev = header;
    int sum = 0;
    for (int i = pos; i >= 0; i--) {
        int temp = (queue[i] - prev);
        if (temp < 0) {
            temp *= -1;
        }
        sum += temp;
        prev = queue[i];
    }
    for (int i = pos + 1; i < n; i++) {
        int temp = (queue[i] - prev);
        if (temp < 0) {
            temp *= -1;
        }
        sum += temp;
        prev = queue[i];
    }
    return sum;
}

int main() {
    int n;
    printf("Enter number of tracks: ");
    scanf("%d", &n);
    int *queue = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter tracks: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    int header;
    printf("Enter header: ");
    scanf("%d", &header);
    queue[n] = header;
    int val = LOOK(queue, n + 1, header);
    printf("\nOverhead time: %d\n", val);
    free(queue);
    return 0;
}