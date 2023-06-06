#ifndef __ALUNOS_H
#define __ALUNOS_H

typedef struct _alunos_ Alunos;

Alunos *colCriar(int maxItens);
int colInserir(Alunos *c, void *key);
void *colRetirar(Alunos *c, void *key, int (*cmp(void*,void*)));
void *colBuscar(Alunos *c, void *key, int (*cmp(void*, void*)));
int colDestruir(Alunos *c);
void *colgetFirst(Alunos *c);
void *colgetNext(Alunos *c);


#endif