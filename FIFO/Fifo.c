#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Fifo.h"

PtFifo Fifo_Create(){
	PtFifo New_Fifo = (PtFifo)malloc(sizeof(struct Fifo));
	New_Fifo->Fifo_Tail = NULL;
	New_Fifo->Fifo_Head = NULL;
	New_Fifo->Count_Elements = 0;
	return (New_Fifo);
}

void Fifo_In(PtFifo Fifo, void* Pt_Data){
	PtNode New_Node;
	New_Node = Node_Create(Pt_Data);
	if((Fifo->Fifo_Tail) != NULL){
		New_Node->Front_Node = Fifo->Fifo_Tail;
		Fifo->Fifo_Tail->Back_Node = New_Node;
		Fifo->Fifo_Tail = New_Node;
	}else{
		Fifo->Fifo_Tail = New_Node;
		Fifo->Fifo_Head = New_Node;
	}
	Fifo->Count_Elements++;
}

void Fifo_Out(PtFifo Fifo){
	PtNode Help_Node;
	if((Fifo->Fifo_Head) != NULL){
		if((Fifo->Fifo_Head->Back_Node) != NULL){
			Help_Node = Fifo->Fifo_Head;
			Fifo->Fifo_Head = Help_Node->Back_Node;
			Fifo->Fifo_Head->Front_Node = NULL;
			free(Help_Node);
		}else{
			Help_Node = Fifo->Fifo_Head;
			Fifo->Fifo_Head = NULL;
			Fifo->Fifo_Tail = NULL;
			free(Help_Node);
		}
		Fifo->Count_Elements--;
	}else printf("\n\n\tThe Fifo is empty.");
}

void Fifo_Destroy(PtFifo Fifo){
	PtNode Help_Node;
	if((Fifo->Fifo_Head) != NULL){
		while((Fifo->Fifo_Head->Back_Node) != NULL){
			Fifo_Out(Fifo);
		}
		Help_Node = Fifo->Fifo_Head;
		free(Help_Node);
		free(Fifo);
	}
}