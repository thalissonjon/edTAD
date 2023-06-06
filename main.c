#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alunos.h"

#define true 1
#define false 0


typedef struct {
	char nome[20];
	int idade;
	float nota;
	} Aluno;

int cmp(void* elm,void* key){
    Aluno *pelm = (Aluno*)elm;
    Aluno *pkey = (Aluno*)key;
    if (pelm->idade == pkey->idade && pelm->nota == pkey->nota && strcmp(pelm->nome,pkey->nome)==0){
        return true;
    } else {
        return false;
    }
}

void main(void){

    int menuTurma;
    Alunos *c;
    Aluno a;
    int existeTurma = false;
    int quantAluno;

    do {
        printf("1. Criar uma turma\n");
        printf("2. Colocar um aluno na turma\n");
        printf("3. Expulsar aluno da turma\n");
        printf("4. Verificar se algum aluno existe na turma\n");
        printf("5. Listar os alunos da turma\n");
        printf("6. Desfazer a turma\n");
        printf("7. Sair do sistema\n");
	
        scanf("%d",&menuTurma);

        switch (menuTurma) {
			case 1:
                system("cls"); //so pra limpar deixar bonit
                if(existeTurma == false){
                    printf("Qual será a capacidade de alunos na turma?\t");
                    scanf("%d", &quantAluno);
                    c = colCriar(quantAluno);
                    if (c==NULL){ //sem espaço na memoria :(
                        exit(0);
                    }
                    existeTurma = true;
                } else {
                    printf("Turma já existente.\n");
                }
				break;
			case 2:
			    system("cls");
			    if(existeTurma == true){
                    printf("Insira o nome do aluno:\t");
                    scanf("%s",a.nome);
                    printf("Insira a idade do aluno:\t");
                    scanf("%d",&a.idade);
                    printf("Insira a nota do aluno:\t");
                    scanf("%f",&a.nota);

                    Aluno *pa;
                    pa = (Aluno*)malloc(sizeof(Aluno));
                    if(pa == NULL){ //sem espaço :c
                        exit(0);
                    }

                    strcpy(pa->nome, a.nome);
                    pa->idade = a.idade;
                    pa->nota = a.nota;

                    colInserir(c,(void*)pa);
                } else {
                    printf("Turma inexistente.\n");
                }

                break;
			case 3:
			    system("cls");
			    if(existeTurma == true){
                    Aluno *auxC3;
                    auxC3 = (Aluno*)malloc(sizeof(Aluno));
                    if(auxC3 == NULL){ //sem espaço
                    	printf ("sem espaço");
                        exit(0);
                    }
                    auxC3 = colgetFirst(c);
                    if (auxC3 == NULL){
                        printf("Nenhum aluno encontrado.\n");
                    } else {
                        int i = 1;
                        while (auxC3 != NULL){
                            printf("%d.Aluno\nNome: %s\n",i,auxC3->nome);
                            auxC3 = colgetNext(c);
                            i++;
                        }
                        printf("\n");

                        Aluno expulsarAluno;
                        printf("Insira o nome do aluno que será expulso:\t");
                        scanf("%s",expulsarAluno.nome);
					    printf("Insira a idade do aluno que será expulso:\t");
                        scanf("%d",&expulsarAluno.idade);
                       	printf("Insira a nota do aluno que será expulso:\t");
                        scanf("%f",&expulsarAluno.nota);
                        Aluno *pa3;
                        pa3 = (Aluno*)malloc(sizeof(Aluno));
                        if(pa3 == NULL){ //sem espaço
                            exit(0);
                        }

                        pa3 = colRetirar(c,(void*)&expulsarAluno,cmp);
                        if (pa3 == NULL){
                            printf("Aluno não foi encontrado no sistema!! ERRO.\n\n");
                        } else {
                            printf("\nAluno expulso da turma!\n");
                            printf("\n");
                        }
                    }

                } else {
                    printf("Turma inexistente.\n");
                }

				break;
			case 4:
			    system("cls");
			    if(existeTurma == true){

                    Aluno *auxC4;
                    auxC4 = (Aluno*)malloc(sizeof(Aluno));
                    if(auxC4 == NULL){ // sem espaço
                        exit(0);
                    }

                    auxC4 = colgetFirst(c);
                    if (auxC4 == NULL){
                        printf("Turma vazia.\n");
                    } 

                        Aluno consultarAluno;
                        printf("Insira o nome do aluno:\t");
                        scanf("%s",consultarAluno.nome);
						printf("Insira a idade do aluno:\t");
                        scanf("%d",&consultarAluno.idade);
                       	printf("Insira a nota do aluno:\t");
                        scanf("%f",&consultarAluno.nota);

                        Aluno *pa2;
                        pa2 = (Aluno*)malloc(sizeof(Aluno));
                        if(pa2 == NULL){ //sem espaço
                            exit(0);
                        }

                        pa2 = colBuscar(c,(void*)&consultarAluno,cmp);
                        if (pa2 == NULL){
                            printf("Aluno não encontrado nessa turma!\n");
                        } else {
                            printf("Nome: %s\nIdade: %d\nNota: %.2f\n",pa2->nome,pa2->idade,pa2->nota);
                        }
                    }
                else {
                    printf("Turma inexistente.\n");
                }

				break;
			case 5:
                system("cls");
                if(existeTurma == true){
                    Aluno *auxC;
                    auxC = (Aluno*)malloc(sizeof(Aluno));
                    if(auxC == NULL){//sem espaço
                        exit(0);
                    }

                    auxC = colgetFirst(c);
                    if (auxC == NULL){
                        printf("Turma vazia\n");
                    } else {
                        int i=1;
                        while (auxC != NULL){
                            printf("%d.Aluno\nNome: %s\nIdade: %d\nNota: %.2f\n",i,auxC->nome,auxC->idade,auxC->nota);
                            auxC = colgetNext(c);
                            i++;
                        }
                    }
                } else {
                    printf("Turma inexistente.\n");
                }

				break;
            case 6:
                system("cls");
                if(existeTurma == true){
                    Aluno *auxC2;
                    auxC2 = (Aluno*)malloc(sizeof(Aluno));
                    if(auxC2 == NULL){
                        exit(0);
                    }

                    auxC2 = colgetFirst(c);
                    if (auxC2 == NULL){
                        colDestruir(c);
                        existeTurma = false;
                        printf("Turma excluída\n");
                    } else {
                        printf("Não é possível destruir a turma. Ainda há alunos.\n");
                    }
                } else {
                    printf("Turma inexistente.\n");
                }

				break;
			case 7:
				break;
			default:
				printf("Entrada inválida.");
				break;
			}

    } while(menuTurma != 7);
    exit(0);
}