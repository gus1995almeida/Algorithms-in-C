#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"

PtStack Stack_Create(){
    PtStack Stack = (PtStack)malloc(sizeof(struct stack));
    Stack->Top_Node = NULL;
    Stack->Count_Elements = 0;
    return Stack;
}

void Stack_Push(PtStack PS, void* Pt_Data){     
    PtNode New_Node;
    New_Node = Node_Create((void*)Pt_Data);
    if(PS == NULL){
        PS->Top_Node = New_Node;
        PS->Count_Elements++;
    }else{
        New_Node->Next_Node = PS->Top_Node;
        PS->Top_Node = New_Node;
        PS->Count_Elements++;
    }
}

void* Stack_Pop(PtStack PS){
    PtNode Help_Node;
    void* return_information;
    if(PS->Top_Node != NULL){
        if(PS->Top_Node->Next_Node == NULL){
            Help_Node = PS->Top_Node;
            return_information = Help_Node->Information;
            PS->Top_Node = NULL;
            free(Help_Node);  
        } 
        else{
            Help_Node = PS->Top_Node;
            return_information = Help_Node->Information;
            PS->Top_Node = Help_Node->Next_Node;
            free(Help_Node);
        }
        PS->Count_Elements--;
        return (return_information);
    }else return (NULL);
}

void Stack_Destroy(PtStack PS){
    PtNode Help_Node;
    if((PS->Top_Node) != NULL){
        while(PS->Top_Node->Next_Node != NULL){
            Help_Node = PS->Top_Node;
            PS->Top_Node = Help_Node->Next_Node;
            free(Help_Node);
        }
        Help_Node = PS->Top_Node;
        PS->Top_Node = Help_Node->Next_Node;
        free(Help_Node);
        free(PS);
    }
}