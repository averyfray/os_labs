#include <stdio.h>
#include <stdlib.h>

int at[10], bt[10];

// Function to swap two integers using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort processes by arrival time
void sortProcessesByArrivalTime(int at[], int bt[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
            }
        }
    }
}

void CalculateWaitingTime(int at[], int bt[], int N) {
    int wt[N];

    printf("P.No.\tArrival Time\tBurst Time\tWaiting Time\n");

    // Calculate Completion time
    int CT[N];
    CT[0] = at[0] + bt[0]; 
 
    for (int i = 1; i < N; i++) {
        if (at[i] <= CT[i - 1]) {
            CT[i] = CT[i - 1] + bt[i];
        } else {
            CT[i] = at[i]  + bt[i];  // Start processing when the process arrives if there is idle time
        }
    }

    for (int i = 0; i < N; i++) {
        wt[i] = CT[i] - at[i] - bt[i];
        printf("%d\t\t%5d\t\t%5d\t\t%5d\n", i + 1, at[i], bt[i], wt[i]);
    }

    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += wt[i];
    }

    float average = sum / N;
    printf("Average waiting time = %.2f\n", average);
}

int main() {
    int N;

    printf("Enter the number of processes: ");
    scanf("%d", &N);

    printf("Enter the arrival times of the processes:\n");
    for (int i = 0; i < N; i++) {
        printf("Arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
    }

    printf("Enter the burst times of the processes:\n");
    for (int i = 0; i < N; i++) {
        printf("Burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort processes by arrival time
    sortProcessesByArrivalTime(at, bt, N);

    CalculateWaitingTime(at, bt, N);

    return 0;
}
