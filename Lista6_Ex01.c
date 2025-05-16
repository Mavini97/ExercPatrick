//Lista 06

//Ex 01

#include <stdio.h>
#include <stdlib.h>

// Calcular a média do vetor
float calcular_media(int n, float *vet) {
    if (n <= 0 || vet == NULL) {
        return 0.0;
    }
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += vet[i];
    }
    return soma / n;
}

//Retornar elementos acima da média
float *acima_da_media(int n, float *vet, int *tam) {
    if (n <= 0 || vet == NULL || tam == NULL) {
        if (tam != NULL) {
            *tam = 0;
        }
        return NULL;
    }

    float media = calcular_media(n, vet);

    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] > media) {
            contador++;
        }
    }

    if (contador == 0) {
        *tam = 0;
        return NULL;
    }

    float *vetresposta = (float *)malloc(contador * sizeof(float));
    if (vetresposta == NULL) {
        *tam = 0;
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] > media) {
            vetresposta[j++] = vet[i];
        }
    }

    *tam = contador;
    return vetresposta;
}

int main() {
    int n;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    float *vet = (float *)malloc(n * sizeof(float));
    if (vet == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1;
    }

    printf("Digite os %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%f", &vet[i]);
    }

    int tam;
    float *resultado = acima_da_media(n, vet, &tam);

    if (resultado != NULL) {
        printf("\nElementos acima da média:\n");
        for (int i = 0; i < tam; i++) {
            printf("%.1f ", resultado[i]);
        }
        printf("\nTamanho do novo vetor: %d\n", tam);
        free(resultado);
    } else {
        printf("\nNenhum elemento acima da média ou erro na alocação.\n");
    }

    free(vet);
    return 0;
}
