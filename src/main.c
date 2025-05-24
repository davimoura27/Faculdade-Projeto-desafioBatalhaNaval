#include <stdio.h>

int main (){

    int index;

    char * nomesAlunos [3][3] = {
        {"Aluno 0", "PT:90", "MAT:90"},
        {"Aluno 1", "PT:60", "MAT:60"},
        {"Aluno 2", "PT:30", "MAT:90"}
    };

    printf("Digite 0 para aluno 0:\n");
    printf("Digite 1 para aluno 1:\n");
    printf("Digite 2 para aluno 2\n");
    
    scanf("%d", &index);

    printf("As notas do %s são:%s, %s",nomesAlunos[index][0], nomesAlunos[index][1], nomesAlunos[index][2]);
     
     return 0;
}