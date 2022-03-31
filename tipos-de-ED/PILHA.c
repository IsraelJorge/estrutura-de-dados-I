#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int pilha[SIZE];

void push(int p[], int info, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        if (p[i] == 0){
            p[i] = info;
            return;
        }
    }
    printf("\n\nPilha cheia\n\n");
}

void listar(int p[], int tamanho){
    int i;
    printf("\n\nListando\n");
    printf("\nElementos da Pilha: ");
    for (i = tamanho -1; i >= 0; i--){
        if (p[i] != 0)
            printf("%d ",p[i]);
    }
}

int buscar(int p[], int tamanho, int chave){
    int i;
    for (i = tamanho - 1; i >= 0; i--){
        if (p[i] == chave)
           return i;
    }
    return -1;
}

void pop(int p[], int tamanho){
    int i;
    for (i = tamanho - 1;i >= 0;i--){
        if (p[i] != 0){
            p[i] = 0;
            return;
        }   
    }
}

int main(int argc, char** argv) {

    int leitura,key,opc;

   do{
       printf("\n====== EXEMPLO DE UMA PILHA ======\n\n");
       printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Pilha\n4 - Buscar Elemento\n0 - Sair\n\nOpcao? ");
       scanf("%d", &opc);

       switch (opc)
       {
       case 1:
           printf("\nInforme o valor: ");
           scanf("%d", &leitura);

           push(pilha,leitura,SIZE);
           break;

       case 2:
           pop(pilha, SIZE);
           printf("\nElemento removido da Pilha.\n");
           break;

       case 3:
           listar(pilha, SIZE);
           break;

       case 4:
           printf("\nInforme a chave da busca: ");
           scanf("%d", &key);

           int posicao = buscar(pilha, SIZE, key);
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