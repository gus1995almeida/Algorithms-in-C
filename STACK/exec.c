#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"

void Stack_Show(PtStack PS){        
    PtNode Help_Node;
    if((PS->Top_Node) != NULL){
    	Help_Node = PS->Top_Node;
    	while(Help_Node->Next_Node != NULL){
        	printf("\n %i", *(int*)(Help_Node->Information));
        	Help_Node = Help_Node->Next_Node;
    	}
    	printf("\n %i", *(int*)(Help_Node->Information));
    }else printf("\n\tThe Stack is empty.");
}

int main(){
	PtStack Stack;
	int option, *return_number, *pt_number;
	Stack = Stack_Create();
	do{
		system("clear");
		printf("\t------Stack------\n\n");
		printf("\t1. Insert a integer number\n");
		printf("\t2. Pop a integer number\n");
		printf("\t3. Show the Stack\n");
		printf("\t4. Exit\n");
		do{
			printf("\n\tType your option: ");
			scanf("%i", &option);
			scanf("%*[^\n]"); scanf("%*c");
		}while(option < 1 && option > 4);
		switch(option){
			case 1:
				pt_number = (int*)malloc(sizeof(int));
				printf("\n\tType a integer number: ");
				scanf("%i", pt_number);
				scanf("%*[^\n]"); scanf("%*c");
				Stack_Push(Stack, (void*)pt_number);
				break;
			case 2: 
				return_number = Stack_Pop(Stack);
				if(return_number != NULL) printf("\n\n\tThe number is %i", *(int*)(return_number));
				else printf("\n\n\tThe Stack is empty."); 
				break;
			case 3: Stack_Show(Stack); break;
		}
		if(option != 4){
			printf("\n\n\tType a key to continue: "); 
			scanf("%*c");
		}
	}while(option != 4);
	Stack_Destroy(Stack);
	return 0;
}