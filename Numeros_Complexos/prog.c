#include <stdio.h>
#include "complexo.h"
int main (void)
{
    PtComplexo Comp1, Comp2, Resultado; int Opcao, Oper;
    Comp1 = Inicializar_Complexo (0.0, 0.0);
    Comp2 = Inicializar_Complexo (0.0, 0.0);
do
{
    system("clear");
    printf ("\t1 - Ler o primeiro complexo\n");
    printf ("\t2 - Ler o segundo complexo\n");
    printf ("\t3 - Somar os complexos\n");
    printf ("\t4 - Subtrair os complexos\n");
    printf ("\t5 - Multiplicar os complexos\n");
    printf ("\t6 - Dividir os complexos\n");
    printf ("\t7 - Sair do programa\n");
    do
    {
        printf ("\n\tOpção -> "); scanf ("%d", &Opcao);
        scanf ("%*[^\n]"); scanf ("%*c");
    } while (Opcao<1 && Opcao>7);
    Oper = 0;
    switch (Opcao)
    {
        case 1 : printf("\n\n"); Ler_Complexo(Comp1); break;
        case 2 : printf("\n\n"); Ler_Complexo(Comp2); break;
        case 3 : Resultado = Somar_Complexo(Comp1, Comp2);
            printf("Adição dos complexos -> ");
            Escrever_Complexo (Resultado); Oper = 1; break;
        case 4 : Resultado = Subtrair_Complexo(Comp1, Comp2);
            printf ("Subtracção dos complexos -> ");
            Escrever_Complexo (Resultado); Oper = 1; break;
        case 5 : Resultado = Multiplicar_Complexo(Comp1, Comp2);
            printf ("Multiplicação dos complexos -> ");
            Escrever_Complexo(Resultado); Oper = 1; break;
        case 6 : if ( Complexo_Nulo (Comp2) )
        {
            Resultado = Dividir_Complexo(Comp1, Comp2);
            printf ("Divisão dos complexos -> ");
            Escrever_Complexo (Resultado); Oper = 1;
        }
        else printf ("O divisor é o complexo nulo!!!\n");
        break;
        }
        if (Opcao != 7)
        {
            printf ("Digita uma tecla para continuar\n"); scanf ("%*c");
        }
        if (Oper) Apagar_Complexo (&Resultado);
        } while (Opcao != 7);
        Apagar_Complexo (&Comp1);
        Apagar_Complexo (&Comp2);
        return 0;
    }