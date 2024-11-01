#include <stdio.h>

#define MAX 10 // Definindo o tamanho máximo da matriz

void gaussJordan(float matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Tornar o elemento diagonal igual a 1
        float pivot = matrix[i][i];
        for (int j = 0; j < n + 1; j++) {
            matrix[i][j] /= pivot;
        }

        // Tornar os elementos acima e abaixo do pivô iguais a 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j < n + 1; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int n;
    float matrix[MAX][MAX];

    // Lendo o número de equações
    printf("Digite o número de equações: ");
    scanf("%d", &n);

    // Lendo a matriz aumentada (coeficientes + resultados)
    printf("Digite os coeficientes da matriz (incluindo resultados):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Aplicando o método de Gauss-Jordan
    gaussJordan(matrix, n);

    // Exibindo os resultados
    printf("\nResultados:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}
