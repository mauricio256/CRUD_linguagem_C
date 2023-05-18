
typedef struct no{
	int matri;
	char nome[60];
	float nota;
	struct no *proximo;
}No;

No *cadastra(No *lista,int matri,char nome[],float nota);
void exibe(No *lista);
void busca(No *lista,int matri);
void edita(No *lista,int matri);
No *remover(No *lista, int matri);


