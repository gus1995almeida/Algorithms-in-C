#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list_single.h"

#define TAM 20

void main(){
	PtList List = Create_List();
	int option;
	char *info;
	do{
		system("clear");
		printf("\n\t-----List------");
		printf("\n\n\t1. Insert a word");
		printf("\n\t2. Print the List");
		printf("\n\t3. Remove a word");
		printf("\n\t4. Exit");
		do{
			printf("\n\n\tType your option: ");
			scanf("%i", &option);
			scanf("%*[^\n]"); scanf("%*c");
		}while(option < 1 && option > 4);
		switch(option){
			case 1:
				info = (char*)malloc(TAM * sizeof(char));
				printf("\n\tType the word: ");
				fgets(info,TAM,stdin);
				scanf("%*[^\n]"); scanf("%*c");
				Store_List(List,info);
				break;
			case 2:
				printf("\n\n");
				Print_List(PtList List);
				break;
			case 3:
				printf("\n\tType the word: ");
				fgets(info,TAM,stdin);
				scanf("%*[^\n]"); scanf("%*c");
				Delete_List(List,info);
				break;
		}
		if(option != 4){
			printf("\n\n\tType a key to continue: ");
			scanf("%*c");
		}
	}while(option != 4);
	Destroy_List(List);
}