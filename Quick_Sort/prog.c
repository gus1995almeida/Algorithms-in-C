#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#define MAX 100

int* create_vector()
{
	int* vector;
	FILE *entry_file = NULL;
	int n;
	char path[MAX];

	printf("\t---Quick Sort---\n\n>>>Type the path: ");
	fgets(path,sizeof(path),stdin);
	//scanf("%*[\n]"); scanf("%*c");
	entry_file = fopen("arq.txt", "r");
	if(entry_file != NULL)
	{
		fscanf(entry_file,"%d", &n);
		if(n > 0)
		{
			vector = (int*)malloc(n * sizeof(int));
			for(int i = 0; i < n; i++)
			{
				fscanf(entry_file, "%d", &vector[i]);
			}
		}
		else
		{
			printf("\n>>> The dimension of vector is less than 0");
			exit(0);
		}
	}
	else
	{
		printf("\n>>> The file don't exists");
		exit(0);
	}
	fclose(entry_file);
	return vector;
}

void show_vector(int* vector, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\n>>> Number %d: %d", i + 1, vector[i]);
	}
}

void main()
{
	int* vector;
	vector = create_vector();
	show_vector(vector, sizeof(vector)-1);
	quick_sort(vector, 0, sizeof(vector)-1);
	printf("\n>>> Sorted:\n");
	show_vector(vector, sizeof(vector)-1);
	printf("\n\n");
}