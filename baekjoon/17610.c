#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int count;
  unsigned int *weights;
  unsigned int sum;
  bool *isPossible;
} Plumbs;

Plumbs plumbs;
bool **hasVisited;

void calculate(unsigned int current, unsigned int calculated) {
  if (hasVisited[current][calculated]) {
    return;
  }

  hasVisited[current][calculated] = true;
  plumbs.isPossible[calculated] = true;

  if (current >= plumbs.count) {
    return;
  }

  calculate(current + 1, calculated + plumbs.weights[current]);
  calculate(current + 1, calculated);
  calculate(current + 1, abs((int) (calculated - plumbs.weights[current])));
}

int main() {
  unsigned int impossibleCasesCount;
  unsigned int i;

  scanf("%u", &plumbs.count);
  
  plumbs.weights = (unsigned int *) calloc(plumbs.count, sizeof(unsigned int));
  hasVisited = (bool **) calloc(plumbs.count + 1, sizeof(bool *));

  plumbs.sum = 0;
  for (i = 0; i < plumbs.count; i++) {
    scanf("%u", &plumbs.weights[i]);

    plumbs.sum += plumbs.weights[i];
  }

  for (i = 0; i <= plumbs.count; i++) {
    hasVisited[i] = (bool *) calloc(plumbs.sum + 1, sizeof(bool));
  }

  plumbs.isPossible = (bool *) calloc(plumbs.sum + 1, sizeof(bool));

  calculate(0, 0);

  impossibleCasesCount = 0;
  for (i = 0; i <= plumbs.sum; i++) {
    if (!plumbs.isPossible[i]) {
      impossibleCasesCount++;
    }
  }

  printf("%u\n", impossibleCasesCount);

  free(plumbs.weights);

  for (i = 0; i <= plumbs.count; i++) {
    free(hasVisited[i]);
  }
  free(hasVisited);

  free(plumbs.isPossible);

  return 0;
}

