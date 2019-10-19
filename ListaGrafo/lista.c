#include <stdio.h>
#include <stdlib.h>

struct Tno{
    int vertice;
    struct Tno *no_anterior, *no_proximo;
};

typedef struct  Tno no;

struct TlistaS{
    no *primeiro_no, *ultimo_no;
    struct TlistaS *list_anterior, *list_proximo;
    int vertice_inicial;  
};

typedef struct TlistaS listaS;

struct TlistaP{
    listaS *primeira_list, *ultima_list;    
};

typedef struct TlistaP listaP;

void inicializarListaPrincipal(listaP *lista){
    lista->primeira_list = NULL;
    lista->ultima_list = NULL;
}

void criarListas(listaP *listaP, int vertice, int aux){
    if(aux <= vertice+1){

        listaS *novaListaS;

        novaListaS = (listaS*)malloc(sizeof(listaS));
        novaListaS->primeiro_no = NULL;
        novaListaS->ultimo_no = NULL;
        novaListaS->list_anterior = NULL;
        novaListaS->list_proximo = NULL;
        novaListaS->vertice_inicial = aux;

        if(listaP->primeira_list == NULL){

            listaP->primeira_list = novaListaS;
            listaP->ultima_list = novaListaS;

        }else{

            listaP->ultima_list->list_proximo = novaListaS;
            novaListaS->list_anterior = listaP->primeira_list;
            listaP->ultima_list = novaListaS;

        }
        aux++;
        criarListas(listaP, vertice, aux);
    }
}

void exibirListaSecundaria(listaS *listaS){
    no *noAux;

    if(listaS->primeiro_no != NULL){

        if(listaS->primeiro_no->no_proximo == NULL){

            printf("%d", listaS->primeiro_no->vertice);

        }else{

            noAux = listaS->primeiro_no;

            while(!((noAux->no_proximo) == NULL)){

                printf("%d\t", noAux->vertice);
                noAux = noAux->no_proximo;

            }

        }

    }else{

        printf("Lista Vazia!");

    }

}

void exibirListaPrincipal(listaP *listaP){

    listaS *listaSAux;

    if(listaP->primeira_list == NULL){

        printf("Lista Vazia!");

    }else{

        if(listaP->primeira_list->list_proximo == NULL){

            printf("%d\t", listaP->ultima_list->vertice_inicial);
            exibirListaSecundaria(listaP->primeira_list);

        }else{
            
            listaSAux = listaP->primeira_list;
    
            while(!((listaSAux->list_proximo) == NULL)){

                printf("%d\t", listaSAux->vertice_inicial);
                exibirListaSecundaria(listaSAux);
                listaSAux = listaSAux->list_proximo;
                printf("\n");

            }

        }

    }

}

void criarNo(listaS *listaS, int vertice_final){

    no *novo_no;
    novo_no = (no*)malloc(sizeof(no));
    novo_no->no_anterior = NULL;
    novo_no->no_proximo = NULL;
    novo_no->vertice = vertice_final;
    
    if(listaS->primeiro_no == NULL){

        listaS->primeiro_no = novo_no;
        listaS->ultimo_no = novo_no;

    }else{

        listaS->ultimo_no->no_proximo = novo_no;
        novo_no->no_anterior = listaS->ultimo_no;
        listaS->ultimo_no = novo_no;

    }

}

void inserirArestas(listaP *listaP, int vertice_inicial, int vertice_final){
    listaS *listaSAux;

    if(listaP->primeira_list != NULL){

        if(listaP->primeira_list->vertice_inicial == vertice_inicial){

            criarNo(listaP->primeira_list, vertice_final);

        }else{

            listaSAux = listaP->primeira_list;
            while(!((listaSAux->list_proximo) == NULL)){

                if(listaSAux->vertice_inicial == vertice_inicial){

                    criarNo(listaSAux, vertice_final);

                }

                listaSAux = listaSAux->list_proximo;

            }
            
        }

    }else{

        printf("Lista Vazia!");

    }


}

int main(){
    listaP listaAdj;
    int vertice, aresta, vertice_inicial, vertice_final, aux=1;
    FILE *arquivo;

    inicializarListaPrincipal(&listaAdj);
    arquivo = fopen("Grafo.txt", "r");
    if(arquivo == NULL){
        printf("Arquivo Inexistente");
        return 0;
    }
    fscanf(arquivo, "%d", &vertice);
    fscanf(arquivo, "%d", &aresta);
    criarListas(&listaAdj, vertice, aux);

    while(!(feof(arquivo))){

        fscanf(arquivo, "%d", &vertice_inicial);
        fscanf(arquivo, "%d", &vertice_final);
        inserirArestas(&listaAdj, vertice_inicial, vertice_final);

    }
    
    fclose(arquivo);

    exibirListaPrincipal(&listaAdj);
}
