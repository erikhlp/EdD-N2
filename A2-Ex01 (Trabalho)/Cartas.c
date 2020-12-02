#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct Carta {
    char valor;
    char naipe[7];
};

struct Pilha {
	int topo;
	int capa;
	struct Carta *pElem;
};

void criar_pilha_de_cartas( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (struct Carta*) malloc (c * sizeof(struct Carta));
}
int possui_cartas ( struct Pilha *p ){

   if( p-> topo == -1 )
      return 1;
   else
      return 0;
}

int baralho_esta_cheio ( struct Pilha *p ){

	if (p->topo == p->capa - 1)
		return 1;
	else
		return 0;
}

void empilhar_cartas ( struct Pilha *p, struct Carta carta){

	p->topo++;
	p->pElem [p->topo] = carta;

}

char retorna_carta_do_topo ( struct Pilha *p ){

   struct Carta carta = p->pElem [p->topo];
   char naipe[7];
   strcpy(naipe, carta.naipe);
   char valor;
   strcpy(valor, carta.valor);
   return strcat(valor, naipe);


}

int main(){
	struct Pilha minhapilha;
	int capacidade = 52, op;
	char valor;

    struct Carta baralho[52];

    int i=1;
	for(i=1; i<14; i++) {
        struct Carta minhacarta;
        strcpy(minhacarta.naipe, "Espada");
        strcpy(minhacarta.valor, i);
        baralho[sizeof(baralho) + 1] = minhacarta;
	}
	for(i=1; i<14; i++) {
        struct Carta minhacarta;
        strcpy(minhacarta.naipe, "Copas");
        strcpy(minhacarta.valor, i);
        baralho[sizeof(baralho) + 1] = minhacarta;
	}
	for(i=1; i<14; i++) {
        struct Carta minhacarta;
        strcpy(minhacarta.naipe, "Paus");
        strcpy(minhacarta.valor, i);
        baralho[sizeof(baralho) + 1] = minhacarta;
	}
	for(i=1; i<14; i++) {
        struct Carta minhacarta;
        strcpy(minhacarta.naipe, "Ouro");
        strcpy(minhacarta.valor, i);
        baralho[sizeof(baralho) + 1] = minhacarta;
	}


	criar_pilha_de_cartas (&minhapilha, capacidade);

	while( 1 ){

		printf("\n1- empilhar_cartas (push)\n");
		printf("2- Mostrar carta no topo \n");
		printf("3- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);

		switch (op){

			case 1:

				if( baralho_esta_cheio( &minhapilha ) == 1 )
					printf("\nBaralho cheio! \n");
				else {
                    int j=0;
					for(j=0; j<52; j++) {
                        empilhar_cartas (&minhapilha, baralho[j]);
					}
				}
				break;

			case 2:
				if ( possui_cartas (&minhapilha) == 1 )
					printf( "\nPilha  de cartas vazia!\n" );
				else {
					valor = retorna_carta_do_topo (&minhapilha);
					printf ( "\nCarta no topo: %.1f\n", valor );
				}
				break;

			case 3:
				exit(0);

			default: printf( "\nOpção Inválida! \n" );
		}
	}

}
