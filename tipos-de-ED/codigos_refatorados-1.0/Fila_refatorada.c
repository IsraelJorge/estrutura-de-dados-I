#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct { 
    int fim;
    int dados[SIZE];
} TFila;

TFila fila;

void enqueue(int info, int tamanho){
    if (fila.fim == tamanho - 1){
        printf("\nFila cheia\n\n");
        return; 
    }

    fila.dados[++(fila.fim)] = info;
}

void dequeue(){
    int i;
    
    if(fila.fim == -1){
        printf("\nFila Vazia\n");
        return;
    
    }else{
    
        for (i = 0; i < fila.fim; i++){
            fila.dados[i] = fila.dados[i + 1];
        }
        fila.fim--;

        printf("\nElemento Removido da Fila!!");
    }
}

void listar(){
    int i;
    printf("\n\nListando\n");
    printf("\nElementos da Fila: ");
    
    for (i = 0; i <= fila.fim; i++){
            printf("\n[%d] --> %d  \n",i, fila.dados[i]);
    }    
}

int buscar(int chave){
    int i;
    
    for(i = 0 ; i <= fila.fim; i++){
        
        if(fila.dados[i] == chave){
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

            enqueue(leitura, SIZE);
            break;

        case 2:
            dequeue(SIZE);
            break;

        case 3:
            listar();
            break;

        case 4:
            printf("\nInforme a chave da busca: ");
            scanf("%d", &key);

            int posicao = buscar(key);
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