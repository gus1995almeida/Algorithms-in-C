#ifndef _COMPLEXO
#define _COMPLEXO

typedef struct complexo *PtComplexo;

PtComplexo Inicializar_Complexo(float R,float I);
void Ler_Complexo(PtComplexo PC);
void Escrever_Complexo(PtComplexo PC);
PtComplexo Somar_Complexo(PtComplexo PC1, PtComplexo PC2);
PtComplexo Subtrair_Complexo(PtComplexo PC1, PtComplexo PC2);
PtComplexo Multiplicar_Complexo(PtComplexo PC1,PtComplexo PC2);
PtComplexo Dividir_Complexo(PtComplexo PC1,PtComplexo PC2);
void Apagar_Complexo(PtComplexo *PC);
int Complexo_Nulo(PtComplexo PC);
float Parte_Real(PtComplexo PC);
float Parte_Imaginaria(PtComplexo PC);

#endif
