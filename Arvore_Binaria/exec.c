#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void main(){
	PtTree Root  = NULL;
	int *pt_number, option, key;
	do{
		system("clear");
		printf("\n\t-----Tree------");
		printf("\n\n\t1. Insert an integer number");
		printf("\n\t2. Search an integer number");
		printf("\n\t3. Remove an integer number");
		printf("\n\t4. Show in Order");
		printf("\n\t5. Show PreOrder");
		printf("\n\t6. Show PosOrder");
		printf("\n\t7. Exit");
		do{
			printf("\n\n\tType your option: ");
			scanf("%i", &option);
			scanf("%*[^\n]"); scanf("%*c");
		}while(option < 1 && option > 7);
		switch(option){
			case 1:
				pt_number = (int*)malloc(sizeof(int));
				printf("\n\tType the integer number: ");
				scanf("%i", pt_number);
				scanf("%*[^\n]"); scanf("%*c");
				if(!Root) Root = Subtree(Root,Root,pt_number);
				else Subtree(Root,Root,pt_number);
				break;
			case 2:
				printf("\n\tType the integer number you wish to be found: ");
				scanf("%i", &key);
				scanf("%*[^\n]"); scanf("%*c");
				if(Search_Tree(Root,&key)) printf("\n\n\tThe number %i was found.", key);
				else printf("\n\n\tThe number %i was not found.", key);
				break;
			case 3:
				printf("\n\tType the integer number you wish to remove: ");
				scanf("%i", &key);
				scanf("%*[^\n]"); scanf("%*c");
				Root = Remove_Tree(Root, &key);
				break;
			case 4:
				printf("\n\n\t-------Order-------\n\n");
				Order(Root);
				break;
			case 5:
				printf("\n\n\t-------PreOrder-------\n\n");
				PreOrder(Root);
				break;
			case 6:
				printf("\n\n\t-------PosOrder-------\n\n");
				PosOrder(Root);
				break;
		}
		if(option != 7){
			printf("\n\n\tType a key to continue: ");
			scanf("%*c");
		}
	}while(option != 7);
	Destroy_Tree(Root, Root, Root);
}