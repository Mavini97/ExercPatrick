#include <stdio.h>
#include <stdlib.h>

int *aprovados(int n, int *mat, float *notas, int *tam) {
    int contador = 0;

    // Contar aprovados
    for (int i = 0; i < n; i++) {
        if (notas[i] >= 5.0) {
            contador++;
        }
    }
    if (contador == 0) {
        *tam = 0;
        return NULL;
    }

    // Alocação dinâmica do vetor de matrículas
    int *mat_aprovados = (int *)malloc(contador * sizeof(int));
    if (mat_aprovados == NULL) {
        *tam = 0;
        return NULL;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] >= 5.0) {
            mat_aprovados[j++] = mat[i];
        }
    }
    *tam = contador;
    return mat_aprovados;
}
int main() {
    int n;
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    int *matrizes = (int *)malloc(n * sizeof(int));
    float *notas = (float *)malloc(n * sizeof(float));
    if (matrizes == NULL || notas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    printf("Digite as matrículas e as notas dos alunos:\n");
    for (int i = 0; i < n; i++) {
        printf("Aluno %d - Matrícula: ", i + 1);
        scanf("%d", &matrizes[i]);
        printf("Aluno %d - Nota: ", i + 1);
        scanf("%f", &notas[i]);
    }
    int tam = 0;
    int *mat_aprovados = aprovados(n, matrizes, notas, &tam);
    if (mat_aprovados != NULL) {
        printf("Matrículas dos alunos aprovados:\n");
        for (int i = 0; i < tam; i++) {
            printf("%d\n", mat_aprovados[i]);
        }
        free(mat_aprovados);
    } else {
        printf("Não há alunos aprovados.\n");
    }
    free(matrizes);
    free(notas);
    return 0;
}

