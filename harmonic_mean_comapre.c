#include <stdio.h>

/*
  Calculate the harmonic mean of an array
  https://pt.wikipedia.org/wiki/M%C3%A9dia_harm%C3%B4nica

  Known problem: in some cases, even though the harmonic means are equal, there
  will be a slight difference in the calculation of the harmonic mean for the
  different arrays.
*/

float harmonic_mean(int x[], int tamanho) {
    float divisor = 0;

    for (int i = 0; i < tamanho; i++) {
        divisor += (1.0 / (x[i]));
    }

    return tamanho / divisor;
}

/*
  @return  0 | 1 | -1 | -2

   0: equal harmonic means
   1: x harmonic mean greater than y harmonic mean
  -1: y harmonic mean greater than x harmonic mean
  -2: error if some of the array indexes has a value of 0
*/
int compare_harmonic_means(int x[], int y[], int tamanho) {
    float mediaX;
    float mediaY;

    for (int i = 0; i < tamanho; i++) {
        if (x[i] == 0 || y[i] == 0) {
            return -2;
        }
    }

    mediaX = harmonic_mean(x, tamanho);
    mediaY = harmonic_mean(y, tamanho);

    if (mediaX == mediaY) {
        return 0;
    } else if (mediaX > mediaY) {
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char const *argv[]) {
    int w[3] = {5, 9, 1};
    int x[3] = {0, 2, 4};
    int y[3] = {1, 5, 7};
    int z[3] = {5, 1, 7};

    // Should return -2
    printf("%d\n", compare_harmonic_means(x, y, 3));
    // Should return -1
    printf("%d\n", compare_harmonic_means(y, w, 3));
    // Should return -0
    printf("%d\n", compare_harmonic_means(y, z, 3));
    // Should return 1
    printf("%d\n", compare_harmonic_means(w, y, 3));

    return 0;
}
