#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	struct no{
		int dado;
		struct no *prox;
	};
	struct no *lista, *p,*q,*aux;
	int sn;
	int ant;
	lista = NULL;
	
	// Inserção a direita em LSE
	do{
	
		if(lista==NULL){
			p = malloc(sizeof(struct no));
			scanf("%d",&p->dado);
			p->prox = lista;
			lista = p;
		}
		else{
			p = malloc(sizeof(struct no));
			scanf("%d",&p->dado);
			aux=lista;
			
			while(aux->dado != ant && aux->prox)
            aux=aux->prox;
            p->prox= aux->prox;
            aux->prox=p;
        }
        
        printf("Deseja inserir outro no no meio? 0-sim  1-nao ");
        scanf("%d",&sn);
    }while(sn==0);

    printf("Lista \n\n\n");
    p=lista;

    while(p!=NULL){
        printf("%d",aux->dado);
        p = aux->prox;


            return 0;

        }

 }
