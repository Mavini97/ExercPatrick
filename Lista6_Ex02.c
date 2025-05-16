#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compactar(char *s) {
  if (s == NULL) {
    return NULL;
  }

  int start = 0, end = strlen(s) - 1;

  while (s[start] == ' ' && start <= end) {
    start++;
  }

  while (s[end] == ' ' && end >= start) {
    end--;
  }

  if (start > end) {
    return NULL;
  }

  int len = end - start + 1;

  char *new_str = (char *)malloc((len + 1) * sizeof(char));
  if (new_str == NULL) {
    return NULL;
  }

  for (int i = 0; i < len; i++) {
    new_str[i] = s[start + i];
  }

  new_str[len] = '\0';

  return new_str;
}

int main() {
  char *s = (char *)malloc(100 * sizeof(char));

  if (s == NULL) {
    printf("Erro ao alocar memória para a string.\n");
    return 1;
  }

  printf("Digite os caracteres (apenas letras e espaços): ");
  scanf("%99[^\n]", s);

  char *compactada = compactar(s);

  if (compactada != NULL) {
    printf("Sequência compactada: '%s'\n", compactada);
    free(compactada);
  } else {
    printf("Não foi possível alocar a nova string ou a string estava vazia.\n");
  }

  free(s);
  return 0;
}
