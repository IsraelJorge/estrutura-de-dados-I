#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int fila[SIZE];

void enqueue(int f[], int info, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        if (f[i] == 0){
            f[i] = info;
            return;
        }
    }
    printf("\n\nFila cheia\n\n");
}

void dequeue(int f[], int tamanho){
    int i;
    for (i = 0;i < tamanho - 1;i++){
        f[i] = f[i + 1];
    }
    f[tamanho - 1] = 0;
}

void listar(int f[], int tamanho){
    int i;
    printf("\n\nListando\n");
    printf("\nElementos da Fila: ");
    for (i = 0; i < tamanho; i++){
        if (f[i] != 0)
            printf("%d ",f[i]);
    }
}

int buscar(int f[], int tamanho, int chave){
    int i;
    for (i = 0; i < tamanho; i++){
        if (f[i] == chave)
           return i;
    }
    return -1;
}

int main(int argc, char** argv) {

    int leitura,key,opc;

   do{
       printf("\n====== EXEMPLO DE UMA FILA ======\n\n");
       printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n4 - Buscar Elemento\n0 - Sair\n\nOpcao? ");
       scanf("%d", &opc);

       switch (opc)
       {
       case 1:
           printf("\nInforme o valor: ");
           scanf("%d", &leitura);

           enqueue(fila, leitura, SIZE);
           break;

       case 2:
           dequeue(fila, SIZE);
           printf("\nElemento removido da fila.\n");
           break;

       case 3:
           listar(fila, SIZE);
           break;

       case 4:
           printf("\nInforme a chave da busca: ");
           scanf("%d", &key);

           int posicao = buscar(fila, SIZE, key);
           if (posicao == -1)
               printf("Chave da busca não encontrada na fila\n\n");
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