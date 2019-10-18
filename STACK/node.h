#ifndef _NODE
#define _NODE

struct node{
    void* Information;
    struct node* Next_Node;
};

typedef struct node* PtNode;

PtNode Node_Create(void* Pt_Data);

#endif