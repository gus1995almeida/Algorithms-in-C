#include <stdio.h>
#include <stdlib.h>

#include "complexo.h"

struct complexo{
	float Real, Imag;
};

PtComplexo Inicializar_Complexo(float R, float I){
	PtComplexo PC = (PtComplexo)malloc(sizeof(struct complexo));
	PC->Real = R;
	PC->Imag = I;
	return PC;
}

void Ler_Complexo(PtComplexo PC){
	if(PC == NULL) return;
	printf("Parte Real: ");
	scanf("%f", &PC->Real);
	printf("Parte Imaginaria: ");
	scanf("%f", &PC->Imag);
}

void Escrever_Complexo(PtComplexo PC){
	if(PC != NULL) printf("%f + j %f\n", PC->Real, PC->Imag);
}

PtComplexo Somar_Complexo(PtComplexo PC1,PtComplexo PC2){
	PtComplexo PC = (PtComplexo)malloc(sizeof(struct complexo));
	PC->Real = PC1->Real + PC2->Real;
	PC->Imag = PC1->Imag + PC2->Imag;
	return PC;
}

PtComplexo Subtrair_Complexo(PtComplexo PC1, PtComplexo PC2){
	PtComplexo PC = (PtComplexo)malloc(sizeof(struct complexo));
        PC->Real = PC1->Real - PC2->Real;
        PC->Imag = PC1->Imag - PC2->Imag;
        return PC;
}

PtComplexo Multiplicar_Complexo(PtComplexo PC1, PtComplexo PC2){
        PtComplexo PC = (PtComplexo)malloc(sizeof(struct complexo));
        PC->Real = (PC1->Real * PC2->Real) - (PC1->Imag * PC2->Imag);
        PC->Imag = (PC1->Real * PC2->Imag) + (PC1->Imag * PC2->Real);
        return PC;
}

PtComplexo Dividir_Complexo(PtComplexo PC1, PtComplexo PC2){
	float quo = (PC2->Real * PC2->Real) + (PC2->Imag * PC2->Imag);
        PtComplexo PC = (PtComplexo)malloc(sizeof(struct complexo));
        PC->Real = (PC1->Real * PC2->Real) + (PC1->Imag * PC2->Imag) / quo;
        PC->Imag = (PC1->Real * PC2->Imag) - (PC1->Imag * PC2->Real) / quo;
        return PC;
}

void Apagar_Complexo(PtComplexo *PC){
	PtComplexo TPC = *PC;
	if (TPC == NULL) return;
	*PC = NULL;
	free(TPC);
}

int Complexo_Nulo(PtComplexo PC){
	if(PC->Real == 0 && PC->Imag == 0) return 0;
	else return 1;
}

float Parte_Real(PtComplexo PC){
	return PC->Real;
}

float Parte_Imaginaria(PtComplexo PC){
	return PC->Imag;
}


