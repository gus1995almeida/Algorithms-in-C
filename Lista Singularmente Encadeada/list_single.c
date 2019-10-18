#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list_single.h"

PtList Create_List(){
	PtList List = (PtList)malloc(sizeof(struct list));
	List->Start = NULL;
	List->Last = NULL;
	return List;
}

void Store_List(PtList List, char* info){
	PtNode New_Node, Help_Node, Back_Node = NULL;
	New_Node = Create_Node(char* info);
	if(!(List->Start)){							//First Element
		List->Start = New_Node;
		List->Last = New_Node;
		return;
	}
	Help_Node = List->Start;
	while(Help_Node){
		if(strcmp((Help_Node->info),info) < 0){
			Back_Node = Help_Node;
			Help_Node = Help_Node->next;
		}else{
			if(Back_Node){			//middle list
				Back_Node->next = New_Node;
				New_Node->next = Help_Node;
				return;
			}else{
				New_Node->next = Help_Node;
				List->Start = New_Node;
				return;
			}

		}
	}
	Back_Node->next = New_Node;			//last element of the list
	List->Last = New_Node;
}

void Delete_list(PtList List, char* info){
	PtNode Help_Node, Back_Node;
	if(!(List->Start)){
		if(strcmp((List->Start->info),info) == 0){
			Help_Node = List->Start;
			List->Start = Help_Node->next;
			free(Help_Node);
		}else{
			Help_Node = List->Start;
			while(Help_Node){
				if(strcmp((Help_Node->info),info) != 0){
					Back_Node = Help_Node;
					Help_Node = Help_Node->next;
				}else{
					if(!(Help_Node)){
						printf("\n\nThis word is not at the List.\n\n");
						return;
					}
					Back_Node->next = Help_Node->next;
					free(Help_Node);
				}
			}
		}
	}else{
		printf("\nThe List is empty.\n\n");
	}
}

void Print_List(PtList List){
	PtNode Help_Node = List->Start;
	if(!Help_Node){
		printf("\n\n\tList is empty");
		return;
	}
	while(Help_Node){
		printf("\t%s", *(Help_Node->info));
		Help_Node->next;
	}
}

void Destroy_List(PtList List){
	PtNode i, Help_Node = List->Start;
	while(Help_Node){
		i = Help_Node;
		Help_Node = Help_Node->next;
		free(i);
	}
	if(List){
		free(List);
	}
	printf("\n\n\tBye!!!");
}