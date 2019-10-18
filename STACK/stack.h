#ifndef _STACK
#define _STACK

struct stack{
    int Count_Elements;
    PtNode Top_Node;
};

typedef struct stack* PtStack;

PtStack Stack_Create();
void Stack_Push(PtStack PS, void* Pt_Data);
void* Stack_Pop(PtStack PS);
void Stack_Destroy(PtStack PS);

#endif
