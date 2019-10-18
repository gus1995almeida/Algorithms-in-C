#ifndef _NODE
#define _NODE

struct Node{
	void* Information;
	struct Node *Back_Node, *Front_Node;
};

typedef struct Node *PtNode;

PtNode Node_Create(void* Pt_Data);

#endif
