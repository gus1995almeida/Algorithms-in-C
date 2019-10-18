#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

PtNode Node_Create(void* Pt_Data){
	PtNode New_Node = (PtNode)malloc(sizeof(struct Node));
	New_Node->Back_Node = NULL;
	New_Node->Front_Node = NULL;
	New_Node->Information = Pt_Data;
	return (New_Node);
}
