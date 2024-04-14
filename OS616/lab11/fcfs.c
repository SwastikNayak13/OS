#include <stdio.h>

int FCFS(int queue[], int n, int header) {
    int otime = 0;
    int prev = header;
    for (int i = 0; i < n; i++) {
        int temp = (queue[i] - prev);
        if (temp < 0) {
            temp *= -1;
        }
        otime += temp;
        prev = queue[i];
    }
    return otime;
}

int main() {
    int n;
    printf("Enter number of tracks: ");
    scanf("%d", &n);
    int queue[n];
    printf("Enter tracks: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    int header;
    printf("Enter header: ");
    scanf("%d", &header);
    printf("Overhead time: %d\n", FCFS(queue, n, header));
    return 0;
}