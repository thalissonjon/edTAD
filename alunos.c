#include <stdlib.h>
#include "alunos.h"

#define true 1
#define false 0

typedef struct _alunos_ {
  int numItens;
  int maxItens;
  int curItem;
  void **item;
} Alunos;


Alunos *colCriar(int maxItens){ 
	Alunos *c;
	if(maxItens>0){
		c = (Alunos*)malloc(sizeof(Alunos));
		if(c!=NULL){
			c->item = (void**)malloc(sizeof(void*)*maxItens);
			if(c->item!=NULL){
				c->numItens = 0;
				c->maxItens = maxItens;
				return c;
			}
			free (c); //nao tiver espaço
		}
		return NULL;
	}
}

int colInserir(Alunos *c, void *key){
  if(c!=NULL){ //se a colecao existir
    if(c->item!=NULL){ //se existir e houver algum elemento
      if(c->numItens < c->maxItens){ //
        c->item[c->numItens] = key; //preencher a posição numItens com um novo item
        c->numItens++; //+1 item na colecao
        return true;
      }
    }
  }
  return false;
}



void *colBuscar(Alunos *c,void *key,int (*cmp(void*, void*))){
  int i = 0;
  if(c!=NULL){
    if(c->item!=NULL){
      if(c->numItens>0){
        while(cmp(c->item[i],key)!=true && i<c->numItens-1){
          i++;
        }
        if(cmp(c->item[i],key)!=true){
          return c->item[i];
        }
      }
    }
    return NULL;
  }
}

void *colRetirar(Alunos *c, void *key, int (*cmp(void*,void*))){
	int i = 0;
	void *aux;
	if(c!=NULL){
		if(c->item!=NULL){
			if(c->numItens > 0){
				while(cmp(c->item[i],key)!=true && i<c->numItens-1){
					i++;
				}
				if(cmp(c->item[i],key)==true){
					aux = c->item[i];
					while(i<c->numItens){
						c->item[i] = c->item[i+1];
						i++;
					}
					c->numItens--;
					return aux;
				}
			}
		}
	}
	return NULL;
}

int colDestruir(Alunos *c){
  if (c==NULL || c->item==NULL){ //nao existir colecao ou sem itens
    return false;
  }
  free(c->item);
  free(c);
  return true;
}

void *colgetFirst(Alunos *c){
	if(c!=NULL){
		if(c->item!=NULL){
			if(c->numItens > 0){
				c->curItem = 0; //current item
				return c->item[0];
			}
		}
	}
	return NULL;
}

void *colgetNext(Alunos *c){
	if(c!=NULL){
		if(c->item!=NULL){
			if(c->numItens > 0){
				c->curItem++;
				if(c->curItem < c->numItens){
					return c->item[c->curItem];
				}
			}
		}
	}
	return NULL;
}