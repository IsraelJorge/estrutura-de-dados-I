#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int lista[SIZE]; 

void adicionar(int l[], int pos, int info, int tamanho){
    if ((pos < 0) || (pos >= tamanho))
         printf("\n\nPosição inválida\n\n");

    l[pos] = info;
}

void listar(int l[], int tamanho){
    int i;
    printf("\n\nListando\n");
    for (i = 0; i < tamanho; i++){
        if (l[i] != 0)
            printf("%d ",l[i]);
    }
}

int buscar(int l[], int tamanho, int chave){
    int i;
    for (i = 0; i < tamanho; i++){
        if (l[i] == chave)
           return i;
    }
    return -1;
}

void remover(int l[], int pos, int tamanho){
    if ((pos < 0) || (pos >= tamanho))
         printf("\n\nPosição inválida\n\n");
    l[pos] = 0;
}

int main(int argc, char** argv) {

    int leitura,key,opc,pos;

   do{
       printf("\n====== EXEMPLO DE UMA LISTA ======\n\n");
       printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Lista\n4 - Buscar Elemento\n0 - Sair\n\nOpcao? ");
       scanf("%d", &opc);

       switch (opc)
       {
       case 1:
           printf("\nInforme a posição em que será inserida: ");
           scanf("%d",&pos);
           printf("\nInforme o valor: ");
           scanf("%d", &leitura);

           adicionar(lista, pos, leitura,SIZE);
           break;

       case 2:
           printf("\nInforme a posição que deseja remover: ");
           scanf("%d",&pos);
           remover(lista, pos,SIZE);
           printf("\nElemento removido da Lista.\n");
           break;

       case 3:
           listar(lista, SIZE);
           break;

       case 4:
           printf("\nInforme a chave da busca: ");
           scanf("%d", &key);

           int posicao = buscar(lista, SIZE, key);
           if (posicao == -1)
               printf("Chave da busca não encontrada na lista\n\n");
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