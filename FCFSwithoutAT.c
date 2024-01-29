#include<stdio.h>
int main()
{
	// Create variable for n process and BT values in integer
	int n,b[10];
	// Create variable for initially CT, TAT and WT are Zero
	int ct=0,wt=0,tat=0;
	// i using "for loop"
	int i;
	// Create variable for ATAT and AWT values in float
	float awt,atat;
	// Create tempariry variables
		// "temp" for sum of WT values but intially "temp" is zero
	   // "temp1" for sum of TAT values but intially "temp1" is zero
	int temp=0,temp1=0;
	
	printf("Enter no of processes:\n");
	scanf("%d",&n);
	
	printf("\nEnter burst time:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	
	printf("\n Note: Assume all process AT is 0.\n");
		
	printf("\nGantt Chart::\n\n");
	printf("--------------------------------------------\n");
	for(i=1;i<=n;i++)
		printf("P%d\t| ",i);
	printf("\n------------------------------------------\n");
		
	printf("\nTable form::");
	printf("\n-----------------------------------------------------");
	printf("\nProcess|   BT  |  CT    |   WT   |   TAT  |\n");
	printf("-----------------------------------------------------\n");
	for(i=1;i<=n;i++)
	{
		ct = ct + b[i];
		tat = ct;   // or tat = tat + b[i];
		wt = tat - b[i];
		printf("P%d    |   %d   |   %d     |   %d   |  %d   |\n",i,b[i],ct,wt,tat);
		temp = temp + wt;
		temp1 = temp1 + tat;
	}
	printf("-----------------------------------------------------\n");
	
	awt = (float)temp/n;
	atat = (float)temp1/n;
	printf("\n Average Waiting Time(AWT)= %f",awt);
	printf("\n Average Turn Arround Time(ATAT)= %f",atat);
	return 0;
}
