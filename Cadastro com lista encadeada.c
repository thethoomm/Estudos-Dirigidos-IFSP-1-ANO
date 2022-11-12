#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char nome[20];
    int matricula;
    float nota;
    float frequencia;
    char turma;
} Aluno;

typedef struct _node {
    Aluno aluno;
    struct _node *next;
} Node;

typedef struct _linked_list {
    Node *begin;
    Node *end;
} LinkedList;

LinkedList* CriarLista() {
    LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("\nErro");
        exit(1);
    }
    list->begin = NULL;
    list->end = NULL;

    return list;
}
int VerificarAluno(LinkedList *list, int *matricula) {
    Node *pointer;
    for (pointer = list->begin; pointer != NULL; pointer = pointer->next) {
        if (pointer->aluno.matricula == *matricula) {
            free(pointer);
            return 1;
        }
    }
    free(pointer);
    return 0;
}
void InserirAluno(LinkedList *list, char nome[], int *matricula, float *nota, float *frequencia, char *turma) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("\nErro");
        exit(1);
    }

    if (VerificarAluno(list, &matricula) == 1) {
        printf("\nALUNO JA EXITE");
        exit(1);
    }
    else {
        strcpy(node->aluno.nome, nome);
        node->aluno.matricula = *matricula;
        node->aluno.nota = *nota;
        node->aluno.frequencia = *frequencia;
        node->aluno.turma = *turma;


        node->next = list->begin;

        if(list->begin == NULL) {
            list->end = node;
        }

        list->begin = node;
    }
}
Node *PesquisarNome (LinkedList *list, char pesqNome[]) {

    Node *pointer;
    for (pointer = list->begin; pointer != NULL; pointer = pointer->next) {
        if (strcmp(pointer->aluno.nome, pesqNome) == 0) {
            return pointer;
        }
    }
    free(pointer);
    return -1;
}
Node *PesquisarMatricula(LinkedList *list, int *pesqMat) {

    Node *pointer;
    for (pointer = list->begin; pointer != NULL; pointer = pointer->next) {
        if (pointer->aluno.matricula == *pesqMat) {
            return pointer;
        }
    }
    free(pointer);
    return -1;
}
int RetirarAluno(LinkedList *list, int *aluno) {
    if(list == NULL) return 0;
    if(list->begin == NULL) return 0;

    Node *prev, *pos;

    for(pos = list->begin; pos != NULL; prev=pos, pos=pos->next) {
        if(pos->aluno.matricula == *aluno) {
            if(list->begin == list->end) {
                list->begin = NULL;
                list->end = NULL;
            }
            else {
                if(pos == list->begin) {
                    list->begin = pos->next;
                }
                else if(pos == list->end) {
                    list->end = prev;
                    prev->next = NULL;
                }
                else {
                    prev->next = pos->next;
                }
            }
            free(pos);
            return 1;

        }

    }
    return 0;
}
void mostraalunos(LinkedList *Lista,char Turma){
    if(Turma != 'A'){
        if(Turma != 'B'){
            printf("Turma nao encontrada\n");

        }
    }
   // else{
        if(Lista==NULL){
            printf("A lista nao foi criada.\n");
        }
        if(Lista->begin==NULL){
            printf("Nenhum aluno cadastrado.\n");
        }
        Node *NO;
        for(NO=Lista->begin;NO!=NULL;NO=NO->next){
            if(NO->aluno .turma==Turma){
                printf("----------------------\n");
                printf("NOME:%s\n",NO->aluno .nome);
                printf("MATRICULA:%d\n",NO->aluno .matricula);
                printf("NOTA:%.2f\n",NO->aluno .nota);
                printf("FREQUENCIA:%.2f\n",NO->aluno .frequencia);
                printf("TURMA: %c",NO->aluno .turma);
                printf("\n----------------------\n");
            if(NO->next==NULL){
                printf("Sem mais alunos\n");
            }
            else{
                printf("\n\n");
            }
            }
        }
    //}
}
int ordena(LinkedList *Lista){
    Node *NO,*n1, *fim = NULL;
    Aluno aux;

    for(NO = Lista->begin;NO!= NULL;NO=NO->next){
        for(n1=Lista->begin;n1->next != NULL ;n1=n1->next){
                    if(strcmp(n1->aluno .nome,n1->next->aluno .nome)>0){
                    aux = n1->aluno;
                    n1->aluno = n1->next->aluno;
                    n1->next->aluno = aux;
                    }
        }
    }
    return 1;


}
void maiormenor(LinkedList *Lista){
    Aluno maior, menor,empM,empm;
    maior .nota = 0;
    menor  .nota = 0;
    empM .nota =0;
    empm .nota = 0;
    Node *NO;
    int cont = 0;
    for(NO = Lista->begin;NO!= NULL;NO = NO -> next){
        if(maior .nota==0){
            maior = NO->aluno;
        }
        if(menor .nota==0){
            menor = NO->aluno;
        }
        if(cont>0){
         if(maior .nota==NO->aluno .nota){
                empM = NO->aluno;
            }
        if(menor .nota==NO->aluno .nota){
                empm=NO->aluno;
            }

        }
        cont++;
        if(NO->aluno .nota > maior .nota){
            maior = NO->aluno;

        }
        if(NO->aluno .nota < menor .nota){
            menor = NO->aluno;

        }

    }


            printf("Maior nota:\n");
            printf("---------------------\n");
            printf("%s\n",maior .nome);
            printf("%d\n",maior .matricula);
            printf("%.2f\n",maior .nota);
            printf("%.2f\n",maior .frequencia);
            printf("%c\n",maior .turma);
            printf("\n---------------------\n");
            printf("Menor nota:\n");
            printf("---------------------\n");
            printf("%s\n",menor .nome);
            printf("%d\n",menor .matricula);
            printf("%.2f\n",menor .nota);
            printf("%.2f\n",menor .frequencia);
            printf("%c\n",menor .turma);
            printf("---------------------\n");
            if(maior .nota == empM .nota){
                printf("Notas empatadas:\n");
                printf("Emapate com a maior:\n");
                printf("---------------------\n");
                printf("%s\n",empM .nome);
                printf("%d\n",empM .matricula);
                printf("%.2f\n",empM .nota);
                printf("%.2f\n",empM .frequencia);
                printf("%c\n",empM .turma);
                printf("---------------------\n");}
                if( menor .nota == empm .nota){
                printf("Notas empatadas:\n");
                printf("Empate com a menor:\n");
                printf("---------------------\n");
                printf("%s\n",empm .nome);
                printf("%d\n",empm .matricula);
                printf("%.2f\n",empm .nota);
                printf("%.2f\n",empm .frequencia);
                printf("%c\n",empm .turma);
                printf("---------------------\n");}


}



int main() {
    LinkedList *list = CriarLista();
    Aluno aluno;
    int escolha;
    int erro = 0;
    do {
        printf("\n***********************************\n");
        printf("****    SISTEMA DE CADASTRO    ****\n");
        printf("****                           ****\n");
        printf("**** Criado por Pedro e Thomas ****\n");
        printf("**** IFSP-CMP                  ****\n");
        printf("***********************************");
        printf("\n**    1. CADASTRAR ALUNO         **");
        printf("\n**    2. REMOVER ALUNO           **");
        printf("\n**    3. PESQUISAR NOME          **");
        printf("\n**    4. PESQUISAR MATRICULA     **");
        printf("\n**    5. MOSTRAR ALUNOS DA TURMA **");
        printf("\n**    6. ORDENADOS POR NOME      **");
        printf("\n**    7. MAIOR E MENOR NOTA      **");
        printf("\n**    8. SAIR                    **\n");
        printf("***********************************\n");
        printf("Escolha: ");
        scanf("%i", &escolha);

        if (escolha == 1) {
            system("cls");

            printf("\nNOME: ");
            setbuf(stdin, NULL);
            gets(aluno.nome);

            do {
                erro = 0;
                system("cls");

                printf("\nNOME: %s", aluno.nome);

                printf("\nMATRICULA: ");
                setbuf(stdin, NULL);
                scanf("%i", &aluno.matricula);
                if (aluno.matricula < 0 || aluno.matricula > 99999){
                    printf("\nMATRICULA INVALIDA\nDIGITE OUTRA\n");
                    erro = -1;
                    system("pause");
                } else {
                    if (VerificarAluno(list, &aluno.matricula) == 1) {
                        printf("\nMATRICULA JA EXISTE\nDIGITE OUTRA\n");
                        erro = -1;
                        system("pause");
                    }
                }
            }while(erro == -1);
            do {
                erro = 0;
                system("cls");

                printf("\nNOME: %s", aluno.nome);
                printf("\nMATRICULA: %i", aluno.matricula);

                printf("\nNOTA: ");
                scanf("%f", &aluno.nota);
                if (aluno.nota < 0 || aluno.nota > 10) {
                    printf("\nNOTA INVALIDA\nDIGITE OUTRA\n");
                    erro = -1;
                    system("pause");
                }
            }while(erro == -1);
            do {
                erro = 0;
                system("cls");

                printf("\nNOME: %s", aluno.nome);
                printf("\nMATRICULA: %i", aluno.matricula);
                printf("\nNOTA: %.2f", aluno.nota);

                printf("\nFREQUENCIA: ");
                scanf("%f", &aluno.frequencia);
                if (aluno.frequencia < 0 || aluno.frequencia > 100) {
                    printf("\nFREQUENCIA INVALIDA\nDIGITE OUTRA\n");
                    erro = -1;
                    system("pause");
                }
            }while(erro == -1);
            do {
                erro = 0;
                system("cls");

                printf("\nNOME: %s", aluno.nome);
                printf("\nMATRICULA: %i", aluno.matricula);
                printf("\nNOTA: %.2f", aluno.nota);
                printf("\nFREQUENCIA: %.2f%%", aluno.frequencia);

                printf("\nTURMA: ");
                setbuf(stdin, NULL);
                scanf("%c", &aluno.turma);
                if (aluno.turma == 'A' || aluno.turma == 'B') {
                    InserirAluno(list, aluno.nome, &aluno.matricula, &aluno.nota, &aluno.frequencia, &aluno.turma);
                }
                else {
                    printf("\nTURMA INVALIDA\nDIGITE OUTRA\n");
                    erro = -1;
                    system("pause");
                }
            }while(erro == -1);
        }
        if (escolha == 2) {
            do {
                int alunoRemovido;
                printf("\nREMOVER ALUNO(MATRICULA): ");
                scanf("%i", &alunoRemovido);

                if (RetirarAluno(list, &alunoRemovido) == 1) {
                    printf("\nALUNO REMOVIDO COM SUCESSO");
                }
                else {
                    printf("\nMATRICULA INVALIDA\nDIGITE OUTRA\n");
                    erro = -1;
                    system("pause");
                }
            }while(erro == -1);
        }
        if (escolha == 3) {

            system("cls");

            char pesqNome[20];
            printf("\nPESQUISAR POR NOME: ");
            setbuf(stdin, NULL);
            gets(pesqNome);

            if (PesquisarNome(list, &pesqNome) == -1) {
                printf("\nNOME INEXISTENTE");
            }
            else {

                Node *pointer = PesquisarNome(list, &pesqNome);

                printf("\nNOME: %s", pointer->aluno.nome);
                printf("\nMATRICULA: %i", pointer->aluno.matricula);
                printf("\nNOTA: %.2f", pointer->aluno.nota);
                printf("\nFREQUENCIA: %i", pointer->aluno.frequencia);
                printf("\nTURMA: %c\n", pointer->aluno.turma);

                system("pause");
            }

        }
        if (escolha == 4) {
            system("cls");

            int pesqMat;
            printf("\nPESQUISAR POR MATRICULA: ");
            scanf("%i", &pesqMat);

            if(PesquisarMatricula(list, &pesqMat) == -1) {
                printf("\nMATRICULA INEXISTENTE");
            }
            else {
                Node *pointer = PesquisarMatricula(list, &pesqMat);

                printf("\nNOME: %s", pointer->aluno.nome);
                printf("\nMATRICULA: %i", pointer->aluno.matricula);
                printf("\nNOTA: %.2f", pointer->aluno.nota);
                printf("\nFREQUENCIA: %i", pointer->aluno.frequencia);
                printf("\nTURMA: %c\n", pointer->aluno.turma);

                system("pause");
            }
        }
        if (escolha == 5) {
            system("cls");
            char turma;
            printf("Qual turma voce quer ver?(A ou B)\n");
            scanf("%s", &turma);
            mostraalunos(list,turma);
            system("pause");
            system("cls");

        }
        if (escolha == 6) {
            system("cls");
            int d;
            char turma[1];
            Node *percorre;
            d = ordena(list);
            printf("Ordem alfabetica:\n");
            if(d==1){
                for(percorre = list->begin;percorre != NULL;percorre = percorre->next){
                    printf("---------------------\n");
                    printf("%s\n",percorre->aluno .nome);
                    printf("%d\n",percorre->aluno .matricula);
                    printf("%.2f\n",percorre->aluno .nota);
                    printf("%.2f\n",percorre->aluno .frequencia);
                    printf("%c\n",percorre->aluno .turma);
                    printf("---------------------\n");

                 }
            }
            ordena(list);
            system("pause");
            system("cls");

        }
        if (escolha == 7) {
            system("cls");
            maiormenor(list);
            system("pause");
            system("cls");

        }
    }while(escolha != 8 );
}
