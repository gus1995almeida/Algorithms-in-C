#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Fifo.h"

void Fifo_Show(PtFifo Fifo){        
    PtNode Help_Node;
    if((Fifo->Fifo_Head) != NULL){
    	Help_Node = Fifo->Fifo_Head;
    	while(Help_Node->Back_Node != NULL){
        	printf("\n %i", *(int*)(Help_Node->Information));
        	Help_Node = Help_Node->Back_Node;
    	}
    	printf("\n %i", *(int*)(Help_Node->Information));
    }else printf("\n\tThe Stack is empty.");
}

int main(){
	PtFifo Fifo;
	int option, control, *pt_number;
	Fifo = Fifo_Create();
	do{
		system("clear");
		printf("\t------Fifo------\n\n");
		printf("\t1. Insert a integer number\n");
		printf("\t2. Pop a integer number\n");
		printf("\t3. Show the Fifo\n");
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
				Fifo_In(Fifo, (void*)pt_number);
				break;
			case 2: Fifo_Out(Fifo); break;
			case 3: Fifo_Show(Fifo); break;
		}
		if(option != 4){
			printf("\n\n\tType a key to continue: "); 
			scanf("%*c");
		}
	}while(option != 4);
	Fifo_Destroy(Fifo);
	return 0;
}