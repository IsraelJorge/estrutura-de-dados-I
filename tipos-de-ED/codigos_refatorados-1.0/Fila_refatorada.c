#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct { 
    int inicio;
    int fim;
    int nItens;
    int dados[SIZE];
} TFila;

TFila fila;

void enqueue(TFila *f,int info, int tamanho){
    
    if(f->nItens == tamanho){
        printf("\nFila Cheia!!!\n");
        return;
    }

    f->fim = (f->fim + 1) % tamanho;
    f->dados[f->fim] = info;
    f->nItens++;

}

void dequeue(TFila *f, int tamanho){
    int i;
    
    if(f->nItens == 0){
        printf("\nFila Vazia!!!\n");
        return;   
    }
    
    f->inicio = (f->inicio + 1) % tamanho;
    f->nItens--;

    printf("\nElemento Removido da Fila!!!");
    
}

void listar(TFila *f, int tamanho){
    int i, n;

    i = f->inicio;

    printf("\n\nListando\n");
    printf("\nElementos da Fila: ");
    
    for (n = 0; n < f->nItens; n++){
        printf("[%d] --> %d  |",i, f->dados[i]);

        i = (i + 1) % tamanho;
    }    
}

int buscar(TFila *f,int chave, int tamanho){
    int n;
    int i = f->inicio;
    
    for(n = 0 ; n < f->nItens; n++){
        
        if(f->dados[i] == chave){
            return i; 
        }
        i = (i + 1) % tamanho;
    }
    return -1;
}

int main(int argc, char** argv) {

    int leitura, key, opc;
    fila.inicio = 0;
    fila.fim = -1;
    fila.nItens = 0;

    do{
        printf("\n====== EXEMPLO DE UMA FILA ======\n\n");
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n4 - Buscar Elemento\n0 - Sair\n\nOpcao? ");
        scanf("%d", &opc);

        switch (opc){

        case 1:
            printf("\nInforme o valor: ");
            scanf("%d", &leitura);

            enqueue(&fila,leitura, SIZE);
            break;

        case 2:
            dequeue(&fila,SIZE);
            break;

        case 3:
            listar(&fila,SIZE);
            break;

        case 4:
            printf("\nInforme a chave da busca: ");
            scanf("%d", &key);

            int posicao = buscar(&fila,key,SIZE);
            if (posicao == -1)
                printf("Chave da busca não encontrada na pilha\n\n");
            else
                printf("Chave encontrada na posição: %d\n\n", posicao);
            break;

        case 0:
            printf("\nFinalizando o Sistema...");
            break;

        default:
            printf("\nOpcao Invalida\n\n");

        }
    
   }while(opc != 0);



    return (EXIT_SUCCESS);
}