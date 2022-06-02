#include <stdio.h>
#include <stdlib.h>

//estrutura de dados necessária para a criação de uma fila encadeada
typedef struct SFila {    
    int info; 
    struct SFila * next;
} TFila;

//sentinela
TFila * fila;

void enqueue(int informacao){
    TFila * novo;
    TFila * ultimo;
    novo = malloc(sizeof(TFila));
    novo->info = informacao;
    novo->next = NULL;
    if (fila == NULL){
        fila = novo;
    }else{
        ultimo = fila;
        while (ultimo->next != NULL){
            ultimo = ultimo->next;
        }
        ultimo->next = novo;
    }

    printf("\nElemento inserido da fila.\n");
}

void dequeue(){
    TFila * temp = fila;

    if(temp == NULL){
        printf("Fila vazia!!!");
        return;
    }

    
    fila = fila->next;
    
    free(temp);

    printf("\nElemento removido da fila.\n");
}

void listar(){
    TFila * temp = fila;

    printf("\nListando\n");
    while(temp != NULL){
        printf("[%p] = %d \n",temp, temp->info);
        temp = temp->next;
    }
}

TFila * buscar(int key){
    TFila * temp = fila;

    while(temp != NULL){
        if (temp->info == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main(int argc, char** argv) {

    int leitura,key,opc;
    fila = NULL;

   do{
       printf("\n====== EXEMPLO DE UMA FILA ======\n\n");
       printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n4 - Buscar Elemento\n0 - Sair\n\nOpcao? ");
       scanf("%d", &opc);

       switch (opc)
       {
       case 1:
           printf("\nInforme o valor: ");
           scanf("%d", &leitura);

           enqueue(leitura);
           break;

       case 2:
           dequeue();
           break;

       case 3:
           listar();
           break;

       case 4:
           printf("\nInforme a chave da busca: ");
           scanf("%d", &key);

           TFila * posicao = buscar(key);
           if (posicao == NULL)
               printf("Chave da busca não encontrada na fila\n\n");
           else
               printf("Chave encontrada na posição: %p\n\n", posicao);
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