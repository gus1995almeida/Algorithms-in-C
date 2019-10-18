#include <stdio.h>
#include <stdlib.h>
#include "node.h"

PtNode Node_Create(void* Pt_Data){
    PtNode New_Node = (PtNode)malloc(sizeof(struct node));
    New_Node->Information = Pt_Data;
    New_Node->Next_Node = NULL;
    return New_Node;
}


