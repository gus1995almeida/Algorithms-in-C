#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

void quick_sort(int* vector, int p, int r)
{
	int q;
	if(p < r)
	{
		q = partition(vector, &p, &r);
		quick_sort(vector, p, (q-1));
		quick_sort(vector, (q+1), r);
	}
}

int partition(int* vector, int *p, int* r)
{
	int i, j,x, bkp;
	i = (*(int*)(p))-1;
	x = vector[*(int*)(r)];
	for(j = *(int*)(p); j < *(int*)(r); j++)
	{
		if(vector[j] <= x)
		{
			i++;
			bkp = vector[j];
			vector[j] = vector[i];
			vector[i] = bkp;
		}
	}
	bkp = vector[j];
	vector[j] = vector[i+1];
	vector[i+1] = bkp;
	return (i+1);
}
