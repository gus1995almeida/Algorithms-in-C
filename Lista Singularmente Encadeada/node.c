#include <stdio.h>
#include <stdlib.h>
#include "node.h"

PtNode Create_Node(char* info){
	PtNode New_Node = (PtNode)malloc(sizeof(struct node));
	New_Node->info = info;
	New_Node->next = NULL;
	return New_Node;
}