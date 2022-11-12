#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

struct signup { // struct signup
    char nome[50];
    int matricula;
    float nota;
    int frequencia;
    char turma;
};
void menu() { // menu function
    printf("\n[1]Cadastrar\t\t\t[7]Alunos por matricula\n[2]Remover\t\t\t[8]Alunos por nota\n[3]Pesquisar por nome\t\t[9]Maior e menor nota\n[4]Pesquisar por matricula\t[10]5 alunos com maiores e menores notas\n[5]Todos da turma\t\t[11]Alunos reprovados\n[6]Alunos por nome\t\t[12]Sair\n");
}

void insertionSort(float allGrades[], int *totalUsers) { //insertion sort
    int i, key, j;
    for (i = 1; i < *totalUsers; i++) {
        key = allGrades[i];
        j = i - 1;
        while (j >= 0 && allGrades[j] > key) {
            allGrades[j + 1] = allGrades[j];
            j = j - 1;
        }
        allGrades[j + 1] = key;
    }
}

int getUserNumberByRegistration(struct signup student[], int registration, int totalUsers) { //registration verificate with user number return


    int i;
    for (i = 0; i < totalUsers + 1 ; i++) {
        if (student[i].matricula == registration) {
            return i;//registration already exists
        }
    }
    return -1;//registration doesn't exist yet
}
void searchStudent(struct signup student[], char searchStudentName[], int *returnName, int *totalUsers) { //search username


    int i;
    int getName;
    for (i = 0; i < *totalUsers + 1; i++) {
        getName = strcmp(student[i].nome, searchStudentName);
        if (getName == 0) {
            *returnName = i;
        }
    }
}
void classSearch(struct signup student[], int allStudentsClass[], char *classChar, int *totalUsers, int *totalClass) {
    for (int i = 0; i < *totalUsers; i++) {
        if (*classChar == student[i].turma) {
            allStudentsClass[i] = i;
            *totalClass = *totalClass + 1;
        }
    }
}

int main() {
    //variables declaration
    int k = 2;

    struct signup student[k];
    int option, registration, searchClass;
    int totalUsers = -1;
    char removeStudent, removeAnswer;
    char searchStudentName[50];

    do {


        menu();
        printf("Sua escolha: ");
        scanf("%d", &option);

        if (option < 1 || option > 12) { //option validation

            printf("\nEscolha invalida\n");
        }

        if (option == 1) { //option 1

                if (totalUsers == SIZE - 1) { //free space verification
                    printf("Limite de alunos alcancado\n");
                }
                else {
                    printf("Matricula: ");
                    scanf("%d", &registration);
                    if (registration > 99999) {//registration validation
                        printf("Matr\nicula invalida\n");
                    }
                    if (getUserNumberByRegistration(student, registration, totalUsers) == -1) { //registration validaton
                        student[totalUsers + 1].matricula = registration; //assignment the registration

                        printf("Nome: ");
                        setbuf(stdin,NULL);
                        gets(student[totalUsers + 1].nome);

                        printf("Nota: ");
                        setbuf(stdin,NULL);
                        scanf("%f", &student[totalUsers + 1].nota);
                        if (student[totalUsers + 1].nota < 0 || student[totalUsers + 1].nota > 10) {
                            printf("\nNota invalida\n");
                        }

                        printf("Frequencia: ");
                        setbuf(stdin,NULL);
                        scanf("%d", &student[totalUsers + 1].frequencia);

                        printf("Turma: ");
                        setbuf(stdin,NULL);
                        scanf("%c", &student[totalUsers + 1].turma);
                        if (student[totalUsers + 1].turma == 'A' || student[totalUsers + 1].turma == 'B') {//class verification
                            printf("");
                        }
                        else {
                            printf("\nTurma invalida\n");
                        }

                        totalUsers++;

                    }
                    else {
                        printf("Matricula ja cadastrada\n");
                    }
                }
            }

        if (option == 2) { //option 2
                printf("Digite a matricula a ser removida: ");
                scanf("%d", &registration);

                if (getUserNumberByRegistration(student, registration, totalUsers) == -1) {
                    printf("\nAluno(a) nao cadastrado\n");
                }
                else {
                    printf("\nAluno(a) no sistema, tem certeza que deseja remover? (S/N)\nResposta: ");
                    setbuf(stdin,NULL);
                    scanf("%c", &removeAnswer);
                    if (removeAnswer == 'S' || removeAnswer == 's') {
                        for (int i = 0; i <= totalUsers; i++) {
                            for (int j = 0; j <= totalUsers; j++) {
                                student[i] = student[j + 1];
                            }
                        }
                        printf("Aluno(a) removido do sistema");
                        system("pause");
                    }
                }
        }

        if (option == 3) { //option 3


            int returnName;
            printf("\nPesquise o nome: ");
            setbuf(stdin,NULL);
            gets(searchStudentName);

            searchStudent(student, searchStudentName, &returnName, &totalUsers);

            printf("Nome %s\n", student[returnName].nome);
            printf("Matricula %d\n", student[returnName].matricula);
            printf("Nota %f\n", student[returnName].nota);
            printf("Frequencia %d\n", student[returnName].frequencia);
            printf("Turma %c\n", student[returnName].turma);
        }

        if (option == 4) { //option 4
            printf("Pesquisar matricula: ");
            scanf("%d", &registration);

            int getRegistration = getUserNumberByRegistration(student,registration,totalUsers);
            if (getRegistration == -1) {
                printf("\nAluno nao encontrado\n");
            }
            else {
                printf("\nNome: %s\n", student[totalUsers].nome);
                printf("Matricula: %d\n", student[totalUsers].matricula);
                printf("Nota: %f\n", student[totalUsers].nota);
                printf("Frequencia: %d\n", student[totalUsers].frequencia);
                printf("Turma: %c\n", student[totalUsers].turma);
            }
        }

        if (option == 5) { //option 5
            char classChar;
            int totalClass = 0;
            int allStudentsClass[totalUsers];
            printf("Turma: ");
            setbuf(stdin,NULL);
            scanf("%c", &classChar);
            if (totalUsers == -1) {
                printf("\nCadastre um aluno primeiro");
            }
            if (classChar == 'A' || classChar == 'B') {//class verification
                printf("");
            }
            else {
                printf("\nTurma invalida\n");
            }

            classSearch(student, allStudentsClass, &classChar, &totalUsers, &totalClass);

            for (int i = 0; i <= totalClass; i++) {
                printf("Nome %s\n", student[allStudentsClass[i]].nome);
                printf("Matricula %d\n", student[allStudentsClass[i]].matricula);
                printf("Nota %f\n", student[allStudentsClass[i]].nota);
                printf("Frequencia %d\n", student[allStudentsClass[i]].frequencia);
                printf("Turma %c\n", student[allStudentsClass[i]].turma);
            }
        }

        if (option == 6) { //option 6
            int contador = 0;
            for (int i = 0; i <= totalUsers; i++) {
                for (int j = i + 1; j <= totalUsers; j++) {
                    int retorno = strcmp(student[i].nome, student[j].nome);
                    if (retorno > 0) {
                        struct signup auxiliar = student[i];
                        student[i] = student[j];
                        student[j] = auxiliar;
                    }
                }
                contador = contador + 1;
            }
            for (int i = 0; i < contador; i++) {
                printf("Nome %s\n", student[i].nome);
                printf("Matricula %d\n", student[i].matricula);
                printf("Nota %f\n", student[i].nota);
                printf("Frequencia %d\n", student[i].frequencia);
                printf("Turma %c\n", student[i].turma);
            }
        }

        if (option == 7) { //option 7
            int contador = 0;

            while (contador <= totalUsers - 1) {
                for (int i = 0; i <= totalUsers - 1; i++) {
                    if (student[i].matricula > student[i+1].matricula) {
                        struct signup auxiliar = student[i];
                        student[i] = student[i+1];
                        student[i+1] = auxiliar;
                    }
                }
                contador = contador + 1;
            }

            for (int i = 0; i <= totalUsers ; i++) {
                printf("\n");
                printf("Nome %s\n", student[i].nome);
                printf("Matricula %d\n", student[i].matricula);
                printf("Nota %f\n", student[i].nota);
                printf("Frequencia %d\n", student[i].frequencia);
                printf("Turma %c\n", student[i].turma);
            }
        }

        if (option == 8) { //option 8

            for(int i = 0; i < totalUsers; i++) {
                for (int j = 0; j < totalUsers; j++) {
                    if (student[i].nota > student[j].nota) {
                        struct signup auxiliar = student[i];
                        student[i] = student[j];
                        student[j] = auxiliar;
                    }
                }
            }

            for (int i = 0; i < totalUsers + 1 ; i++) {
                printf("\n");
                printf("Nome %s\n", student[i].nome);
                printf("Matricula %d\n", student[i].matricula);
                printf("Nota %f\n", student[i].nota);
                printf("Frequencia %d\n", student[i].frequencia);
                printf("Turma %c\n", student[i].turma);
            }
        }

        if (option == 9) { //option 9

            float allGrades[totalUsers];
            for (int i = 0; i < totalUsers + 1; i++) { //all grades in one place
                allGrades[i] = student[i].nota;
            }

            insertionSort(allGrades, &totalUsers);

            for (int i = 0; i < totalUsers + 1; i++) {
                if (allGrades[0] == student[i].nota) {
                        printf("\n");
                        printf("Nome %s\n", student[i].nome);
                        printf("Matricula %d\n", student[i].matricula);
                        printf("Nota %f\n", student[i].nota);
                        printf("Frequencia %d\n", student[i].frequencia);
                        printf("Turma %c\n", student[i].turma);
                }
                if(allGrades[totalUsers - 1] == student[i].nota) {
                        printf("\n");
                        printf("Nome %s\n", student[i].nome);
                        printf("Matricula %d\n", student[i].matricula);
                        printf("Nota %f\n", student[i].nota);
                        printf("Frequencia %d\n", student[i].frequencia);
                        printf("Turma %c\n", student[i].turma);
                }
            }

        }

        if (option == 11) { //option 11
            struct signup aprovado[k];
            struct signup reprovado[k];
            int contadorAprovados = 0, contadorReprovados = 0;
            int opcao;
            for(int i = 0; i < totalUsers + 1; i++){
                for (int j = 0; j < totalUsers + 1; j++) {
                    if (student[i].nota >= 7) {
                        if (student[i].frequencia >= 75) {
                            aprovado[j] = student[i];
                        }else {
                            reprovado[j] = student[i];
                        }
                    }else {
                        reprovado[j] = student[i];
                    }
                }
            }

            do {
                printf("\nDESEJA VER OS [1]APROVADOS, [2]REPROVADOS OU [3]NENHUMA: ");
                scanf("%i", &opcao);

                if (opcao == 1) {
                    printf("\n------APROVADOS------\n");
                    for (int i = 0; i < totalUsers; i++) {
                        printf("\n");
                        printf("Nome %s\n", aprovado[i].nome);
                        printf("Matricula %d\n", aprovado[i].matricula);
                        printf("Nota %f\n", aprovado[i].nota);
                        printf("Frequencia %d\n", aprovado[i].frequencia);
                        printf("Turma %c\n", aprovado[i].turma);
                    }
                }
                printf("\n");
                if (opcao == 2) {
                    printf("\n------REPROVADOS------\n");
                    for (int i = 0; i < totalUsers; i++) {
                        printf("\n");
                        printf("Nome %s\n", reprovado[i].nome);
                        printf("Matricula %d\n", reprovado[i].matricula);
                        printf("Nota %f\n", reprovado[i].nota);
                        printf("Frequencia %d\n", reprovado[i].frequencia);
                        printf("Turma %c\n", reprovado[i].turma);
                    }
                }

                if (opcao < 1 || opcao > 2) {
                    printf("\nOPCAO INVALIDA");
                }
            }while(opcao != 3);
        }

    }while(option != 12);

    printf("\nPrograma finalizado\n");
    return 0;
}
