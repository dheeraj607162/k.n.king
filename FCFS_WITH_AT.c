#include<stdio.h>

int main() {
    int n, b[10], arrivalTime[10], processOrder[10];
    int ct = 0, wt = 0, tat = 0;
    int i,j,k;
    int tempArrival,tempBurst,tempOrder;
    float awt, atat;
    
    int temp = 0, temp1 = 0;

    printf("Enter no of processes:\n");
    scanf("%d", &n);

    printf("\nEnter the Arrival Time\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &arrivalTime[i]);
        processOrder[i] = i;
    }

    printf("\nEnter burst time:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    //Sorting processes based on arrival time
    for (j = 1; j <= n; j++) {
        for (k = 1; k <= n - j; k++) {
            if (arrivalTime[k] > arrivalTime[k + 1]) {
                // Swap Arrival Time
                tempArrival = arrivalTime[k];
                arrivalTime[k] = arrivalTime[k + 1];
                arrivalTime[k + 1] = tempArrival;

                // Swap Burst Time
                tempBurst = b[k];
                b[k] = b[k + 1];
                b[k + 1] = tempBurst;

                // Swap Process Order
                tempOrder = processOrder[k];
                processOrder[k] = processOrder[k + 1];
                processOrder[k + 1] = tempOrder;
            }
        }
    }

    printf("\nGantt Chart::\n\n");
    printf("------------------------------------------\n");
    for (i = 1; i <= n; i++)
        printf("P%d\t| ", processOrder[i]);
    printf("\n------------------------------------------\n");

    printf("\nTable form::");
    printf("\n-----------------------------------------------------");
    printf("\nProcess|   AT   |   BT  | |  CT    |   WT   |   TAT  |\n");
    printf("-----------------------------------------------------\n");

    for (i = 1; i <= n; i++) {
        ct = ct + b[i];
        tat = ct - arrivalTime[i];
        wt = tat - b[i];
        printf("P%d    |   %d   |   %d   |   %d     |   %d   |  %d   |\n", processOrder[i], arrivalTime[i], b[i], ct, wt, tat);
        temp = temp + wt;
        temp1 = temp1 + tat;
    }
    printf("-----------------------------------------------------\n");

    awt = (float)temp / n;
    atat = (float)temp1 / n;
    printf("\n Average Waiting Time(AWT)= %f", awt);
    printf("\n Average Turn Around Time(ATAT)= %f", atat);
    return 0;
}
