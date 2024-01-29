#include<stdio.h>
int main()
{
    int at[10], bt[10], rt[10], completionTime, i, smallest = 0;
    int remain = 0, n, t, sum_wait = 0, sum_turnaround = 0;
    printf("Enter no of Processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter arrival time for Process P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("\n\nProcessID\t| Arrival Time\t | Burst Time\t | Completion Time\t | Turnaround Time\t | Waiting Time\n\n");
    for(t = 0; remain != n; t++)
    {
        smallest = -1;
        for(i = 0; i < n; i++)
        {
            if(at[i] <= t && rt[i] && (smallest == -1 || rt[i] < rt[smallest]))
            {
                smallest = i;
            }
        }
        if(smallest == -1)
        {
            continue;
        }
        rt[smallest]--;
        if(rt[smallest] == 0)
        {
            remain++;
            completionTime = t + 1;
            printf("P[%d]\t | %d\t\t\t | %d\t\t\t | %d\t\t\t | %d\t\t\t | %d\n", smallest + 1, at[smallest], bt[smallest], completionTime, completionTime - at[smallest], completionTime - bt[smallest] - at[smallest]);
            sum_wait += completionTime - bt[smallest] - at[smallest];
            sum_turnaround += completionTime - at[smallest];
        }
    }
    printf("\n\nAverage waiting time = %lf\n", sum_wait * 1.0 / n);
    printf("Average turn around time = %lf\n", sum_turnaround * 1.0 / n);
    return 0;
}
/*This code only works when there is no CPU idleness (arrival time starts from 0)*/
