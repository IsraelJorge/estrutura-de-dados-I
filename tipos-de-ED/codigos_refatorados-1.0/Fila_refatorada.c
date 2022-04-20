#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct { 
    int fim;
    int dados[SIZE];
} TFila;

TFila fila;

void enqueue(TFila *f,int info, int tamanho){
    if (f->fim == tamanho - 1){
        printf("\nFila cheia\n\n");
        return; 
    }

    f->dados[++(f->fim)] = info;
}

void dequeue(TFila *f){
    int i;
    
    if(f->fim == -1){
        printf("\nFila Vazia\n");
        return;
    
    }else{
    
        for (i = 0; i < f->fim; i++){
            f->dados[i] = f->dados[i + 1];
        }
        (f->fim)--;

        printf("\nElemento Removido da Fila!!");
    }
}

void listar(TFila *f){
    int i;
    printf("\n\nListando\n");
    printf("\nElementos da Fila: ");
    
    for (i = 0; i <= f->fim; i++){
            printf("[%d] --> %d  |",i, f->dados[i]);
    }    
}

int buscar(TFila *f,int chave){
    int i;
    
    for(i = 0 ; i <= f->fim; i++){
        
        if(f->dados[i] == chave){
            return i; 
        }
    }
    return -1;
}

int main(int argc, char** argv) {

    int leitura,key,opc;
    fila.fim = -1;
    

    do
    {
        printf("\n====== EXEMPLO DE UMA FILA ======\n\n");
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n4 - Buscar Elemento\n0 - Sair\n\nOpcao? ");
        scanf("%d", &opc);

        switch (opc)
        {

        case 1:
            printf("\nInforme o valor: ");
            scanf("%d", &leitura);

            enqueue(&fila,leitura, SIZE);
            break;

        case 2:
            dequeue(&fila);
            break;

        case 3:
            listar(&fila);
            break;

        case 4:
            printf("\nInforme a chave da busca: ");
            scanf("%d", &key);

            int posicao = buscar(&fila,key);
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