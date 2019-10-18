#ifndef _LIST
#define _LIST

struct list
{
	PtNode *Start, *Last;
};

typedef struct list *PtList;

PtList Create_List();
void Store_List(PtList List, char* info);
void Print_List(PtList List);
void Delete_list(PtList List, char* info);
void Destroy_List(PtList List);

#endif