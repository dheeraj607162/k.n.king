#include <stdio.h>

int main() {
    int p[10], at[10], bt[10], wt[10], tat[10], priority[10], i, j, temp, n;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the Process-ID's of %d processes: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the Arrival Time of %d processes: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter the Burst Time of %d processes: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter the Priority of %d processes: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &priority[i]);

    int currentTime = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (at[j] > at[j + 1] || (at[j] == at[j + 1] && priority[j] > priority[j + 1])) {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
                temp = priority[j + 1];
                priority[j + 1] = priority[j];
                priority[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        wt[i] = currentTime;
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        currentTime = tat[i];
    }

    printf("\nTable form::");
    printf("\n-----------------------------------------------------");
    printf("\nProcess|   AT   |   BT   |   Priority   |   WT   |   TAT   |\n");
    printf("-----------------------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("\nP%d    |   %d    |   %d    |   %d           |   %d     |   %d", p[i], at[i], bt[i], priority[i], wt[i], tat[i]);

    atat = atat / n;
    awt = awt / n;
    printf("\n\nAverage Turnaround Time is %.2f", atat);
    printf("\nAverage Waiting Time is %.2f", awt);

    return 0;
}
