#include <stdio.h>
#include <stdlib.h>
#include "conect.h"
#include "string.h"

No *cria_no(){
	 No *novo_no=(No*)malloc(sizeof(No));
	 return novo_no;	 
}

No *cadastra(No *lista,int matri,char nome[],float nota){
	No *novo_no=cria_no();
	novo_no->matri=matri;
	strcpy(novo_no->nome,nome);
	novo_no->nota=nota;
	
	if(lista == NULL){
		lista=novo_no;//lista recebe o novo nó
		novo_no->proximo=NULL;//novo nó aponto para null
		//printf("inserido %d",lista->matri);
	}else{
		novo_no->proximo=lista;//novo nó agora vai apontar para o no que a lista tava apontando  
		lista=novo_no;// a lista vai receber o novo no que agora eh o ultimo 	
	}
	return lista;
}

void busca(No *lista,int matri){
  system("color 17");
	 No *aux=lista;
	 system("cls");
	 	printf("//////////////////////////////////////////////\n");
		printf("----------------| BUSCA |-----------------\n");
	
	 if(lista == NULL){
	 	printf("//////////////////////////////////////////////\n");
	 	printf(" NENHUM CADASTRO CONSTA NO SISTEMA \n");
    	printf("_______________________________________________\n");
	 }else{
	 	while(aux->matri != matri && aux->proximo != NULL){
	 	aux=aux->proximo;
	 }
	 if(aux->matri==matri){
	 	printf("_______________________________________________\n");
	    printf("NOME: %s\n",aux->nome);
	 	printf("MATRICULA: %d\n",aux->matri);
	 	printf("NOTA: %.1f\n", aux->nota);
	 	printf("________________________________________________\n");
     }else{
	 	 printf(" MATRICULA [ %d ] NAO FOI ENCONTRADA NO SISTEMA \n",matri);
    	 printf("_______________________________________________\n");
     }
  }
}

void edita(No *lista,int matri){
  system("color 17");
	 No *aux=lista;
	    
	 if(lista == NULL){
	 	printf("//////////////////////////////////////////////\n");
	 	printf(" NENHUM CADASTRO CONSTA NO SISTEMA \n");
	 	printf("______________________________________________\n");
	 }else{
	   while(aux->matri != matri && aux->proximo != NULL){
	 		aux=aux->proximo;
	 }
	 if(aux->matri==matri){
		char n_nome[30];
		int n_matricula;
		float n_nota;
		printf("------------| EDITAR CADASTRO |---------------\n");
    	printf("______________________________________________\n");
	 	printf("\nNOVO NOME: ");
	 	scanf(" %[^\n]s",&n_nome);
	 	printf("\nNOVA MATRICULA: ");
	 	scanf("%d",&n_matricula);
	 	printf("\nNOVA NOTA: ");
	 	scanf("%f",&n_nota);
	 	strcpy(aux->nome,n_nome);
		aux->matri=n_matricula;
	 	aux->nota=n_nota;
	 	system("cls");
	 	printf("------| DADO ALTERADO COM SUCESSO! |---------\n");
     }else{
     	 system("cls");
	 	 printf(" MATRICULA [ %d ] NAO FOI ENCONTRADA NO SISTEMA \n",matri);
    	 printf("______________________________________\n");
	 }
  }
}

void exibe(No *lista){
	system("color 17");
			printf("-------| LISTA DE USUARIOS CADASTRADOS |-------\n");
    		printf("////////////////////////////////////////////\n");
 	   if(lista==NULL){
			printf("____________________________________________\n");
			printf("NENHUM USUARIO CADASTRADO NO SISTEMA\n");
       }else{
	    No *aux=lista;
    	while(aux != NULL){
    		printf("____________________________________________\n");
		    printf("NOME: %s\n",aux->nome);
		 	printf("MATRICULA: %d\n",aux->matri);
		 	printf("NOTA: %.1f\n",aux->nota);
		 	printf("_____________________________________________\n");
    		aux=aux->proximo;
		   }
	    }
	  printf("\n");
}

No *remover(No *lista, int matri){
  system("color 17");	
	 No *ant=NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista
	 No *aux=lista;
	 int op;
	 system("cls");
			while( aux!=NULL && aux->matri!=matri ){
				ant=aux; //anterior recebe o valor do 1° no
				aux=aux->proximo;//o no auxiliar anda uma casa para frente
			}
			if(aux == NULL){ //se for nulo é pq nao chou
			    	printf(" MATRICULA [ %d ] NAO FOI ENCONTRADA NO SISTEMA \n",matri);
		    	 	printf("______________________________________\n");
		    	 	return lista;
		    }else  	
				if(ant == NULL ){///se primeiro NÓ da lista for igual ao primeiro da lista aux...
				    printf("TEM CERTEZA QUE DESEJA EXCLUIR:\n");
				    printf(" MATRICULA: [ %d ] PERTENCENTE A: [%s] ?\n",matri,aux->nome);
				    printf("[1] para->  SIM \n");
		            printf("[2] para->  NAO \n");
				    scanf("%d",&op);
					    if(op== 1){
						 	lista=aux->proximo; // a lista recebe o primeiro no que eh onde aux ta apontando
					        printf("______________________________________\n");
					        system("cls");
							printf(" REMOVIDO COM SUCESSO \n");
							return lista;/// retorna a lista ja alterada
					    }else
					     system("cls");
				    	 return lista; //// retorna a lista sem nenhuma alteraçao feita 
				 }else{
				 	printf("TEM CERTEZA QUE DESEJA EXCLUIR:\n");
				    printf(" MATRICULA: [ %d ] PERTENCENTE A: [%s] ?\n",matri,aux->nome);
				    printf("[1] para->  SIM \n");
		            printf("[2] para->  NAO \n");
				    scanf("%d",&op);
					    if(op== 1){
				 		ant->proximo=aux->proximo; /// anterior aponta pra quem vem depois do NÓ
					       printf("______________________________________\n");
					       system("cls");
						   printf(" REMOVIDO COM SUCESSO \n");
					    }else{
					    	system("cls");
					    	return lista;
						}
				 }
		free(aux);
		return lista;
}

  
  


	

