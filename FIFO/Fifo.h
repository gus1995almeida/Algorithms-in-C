#ifndef _FIFO
#define _FIFO

struct Fifo{
	PtNode Fifo_Tail, Fifo_Head;
	int Count_Elements;
};

typedef struct Fifo* PtFifo;

PtFifo Fifo_Create();
void  Fifo_In(PtFifo Fifo, void* Pt_Data);
void Fifo_Out(PtFifo Fifo);
void Fifo_Destroy(PtFifo Fifo);

#endif
