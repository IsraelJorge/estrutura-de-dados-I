#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct { 
    int topo; 
    int dados[SIZE];
} TPilha;

TPilha pilha;


void push(int info, int tamanho){
    if (pilha.topo == tamanho - 1){
        printf("\nPilha cheia\n\n");
        return; 
    }

    pilha.dados[++(pilha.topo)] = info;
}

void listar(){
    int i;
    printf("\n\nListando\n");
    printf("\nElementos da Pilha: ");
    for (i = pilha.topo; i >= 0; i--){
            printf("\n[%d] --> %d  \n",i, pilha.dados[i]);
    }
}

int buscar(int chave){
    int i;
    
    for(i = pilha.topo ; i >= 0; i--){
        
        if(pilha.dados[i] == chave){
            return i; 
        }
    }
    return -1;
}

void pop(){
    
    if(pilha.topo == -1){
        printf("\nPilha Vazia!!!\n\n");
        return;
    }
    
    pilha.dados[pilha.topo--];
    printf("\nElemento removido da Pilha.\n");
    
 }

int main(int argc, char** argv) {

    int leitura,key,opc;
    pilha.topo = -1;

   do{
       printf("\n====== EXEMPLO DE UMA PILHA ======\n\n");
       printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Pilha\n4 - Buscar Elemento\n0 - Sair\n\nOpcao? ");
       scanf("%d", &opc);

       switch (opc)
       {
       case 1:
           printf("\nInforme o valor: ");
           scanf("%d", &leitura);

           push(leitura,SIZE);
           break;

       case 2:
           pop();
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