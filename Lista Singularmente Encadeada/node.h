#ifndef _NODE
#define _NODE

struct node{
	char* info;
	struct node *next;
};

typedef struct node PtNode;

PtNode Create_Node(char* info);

#endif