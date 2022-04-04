
#include <stdio.h>

int main()
{
	int i, j, n, bt[10], ibt[10], wt[10], tat[10], t, max, p[50], g = 0;
	float cwt = 0, ctat = 0, temp = 0;

	printf("Enter the no of processes -- ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nEnter Burst Time for process %d -- ", i);
		scanf("%d", &bt[i]);
		ibt[i] = bt[i];
	}

	printf("\nEnter the size of time slice -- ");
	scanf("%d", &t);
	max = bt[0];

	for (i = 1; i < n; i++)
	{
		if (max < bt[i])
			max = bt[i];
	}

	for (j = 0; j < (max / t) + 1; j++)
		for (i = 0; i < n; i++)
			if (bt[i] != 0)
			{
				if (bt[i] <= t)
				{
					tat[i] = temp + bt[i];
					temp = temp + bt[i];
					bt[i] = 0;
					p[g++] = i;
				}

				else
				{
					bt[i] = bt[i] - t;
					temp = temp + t;
					p[g++] = i;
				}
			}

	for (i = 0; i < n; i++)
	{
		wt[i] = tat[i] - ibt[i];
		ctat += tat[i];
		cwt += wt[i];
	}
	printf("\nThe Average Turnaround time is -- %f", ctat / n);
	printf("\nThe Average Waiting time is -- %f ", cwt / n);

	printf("\n");
	for (i = 0; i < g; i++)
	{
		printf("pid - >%d --", p[i]);
	}

	printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
	for (i = 0; i < n; i++)
		printf("\t%d \t %d \t\t %d \t\t %d \n", i, ibt[i], wt[i], tat[i]);
	return 0;
}
