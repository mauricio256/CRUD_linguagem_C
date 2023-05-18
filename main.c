#include <stdio.h>
#include <stdlib.h>
#include "conect.h"

int main(){
	No *lista=NULL;
    system("color 17");
    int op1,op2;
	int matri;
	float nota;
	char nome[30];
	do{
		printf("\t-----------------------------------------------------------------\n");
		printf("\t----------|    SISTEMA DE CADASTRO DE ALUNOS      |--------------\n");
		printf("\t-----------------------------------------------------------------\n\n\n");
		printf("\t---------------------|   MENU    |-------------------------------\n");
		printf("\t\tDigite [1] para->  MOSTRAR TODOS OS CADASTROS \n");
		printf("\t\tDigite [2] para->  CONSULTAR CASDASTRO \n");
		printf("\t\tDigite [3] para->  NOVO CADASTRO \n");
		printf("\t\tDigite [4] para->  EDITAR CADASTRO \n");
		printf("\t\tDigite [5] para->  EXCULIR CADASTRO \n");
		printf("\t\tDigite [6] para->  SAIR \n\n");
		printf("\t\tDigite a opcao desejada: ");
		scanf("%d",&op1);
		switch (op1){
			case 1:{
				system("cls");
				exibe(lista);
				system("pause");
				system("cls");
				op2=1;
				break;
			}
			case 2:{
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("--------------| PAGINA DE BUSCA |-----------------------------\n");
				printf("\nDIGITE A MATRICULA A SER PROCURADA : ");
			 	scanf("%d",&matri);
			 	system("cls");
				busca(lista,matri);
				system("pause");
				system("cls");
		        op2=1;
			break;
		}
			case 3:{
				system("cls");
				printf("////////////////////////////////////////////////////\n");
				printf("----------------|PAGINA DE CADASTRO |----------------\n");
		    	printf("_____________________________________________________\n");
			 	printf("\nNOME: ");
			 	scanf(" %[^\n]s",&nome);
			 	printf("\nMATRICULA: ");
			 	scanf("%d",&matri);
			 	printf("\nNOTA: ");
			 	scanf("%f",&nota);
			 	system("cls");
			    lista=cadastra(lista,matri,nome,nota);
			    
			    if(lista){
				   printf("-------| CADASTRADO COM SUCESSO! |-----------------\n");
				}else{
				   printf("-------| NAO FOI POSSIVEL CADASTRAR |--------------\n");
			    }
			  	system("pause");  
				system("cls");
				op2=1;			
				break;
			}
		    case 4:{
		    	system("cls");
		    	printf("//////////////////////////////////////////////////////\n");
		    	printf("---------|PAGINA DE ALTERACAO DE CADASTRO |------------\n");
		    	printf("_______________________________________________________\n");
		    	printf("DIGITE A MATRICULA QUE SERA ALTERADA: ");
			 	scanf("%d",&matri);
			 	system("cls");
				edita(lista,matri);
				system("pause");
				system("cls");
				op2=1;
				break;
			}		
			case 5:{
				system("cls");
				printf("///////////////////////////////////////////////////////\n");
				printf("----------------|PAGINA DE REMOCAO DE CADASTRO |---------\n");
				printf("MATRICULA A SER EXCUIDA: ");
			 	scanf("%d",&matri);
			 	system("cls");
			 	lista = remover(lista,matri);
				system("pause");
				system("cls");
				op2=1;
				break;
			}	
			case 6:{
				op2=0;
				break;
			}
			default:{
				system("cls");
				printf("////////////////////////////////////////////////////////\n");
				printf("-------------------| OPCAO INVALIDA |--------------------\n");
				system("pause");
				system("cls");
				op2=1;
			}	
	}
}while(op2 != 0);

   system("cls");
   printf("///////////////////////////////////////////////////////////////////\n");
   printf("------------------------| FIM DO PROGRAMA |------------------------\n");
   printf("----------------| Desenvolvido por: Mauricio Franca |--------------\n");
   return 0;
}

