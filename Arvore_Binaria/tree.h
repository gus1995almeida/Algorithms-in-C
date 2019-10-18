#ifndef _TREE
#define _TREE

struct tree
{
	int* info;
	struct tree *right, *left;
};

typedef struct tree *PtTree;

PtTree Subtree(PtTree Root, PtTree R, int* info);
int Search_Tree(PtTree Root, int* key);
void Destroy_Tree(PtTree Root, PtTree R, PtTree Help_R);
PtTree Remove_Tree(PtTree Root, int* key);
void Order(PtTree Root);
void PreOrder(PtTree Root);
void PosOrder(PtTree Root);

#endif