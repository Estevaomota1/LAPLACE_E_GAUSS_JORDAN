#include <stdio.h>

#define MAX 10

// Função para calcular o determinante de uma matriz usando o método de Laplace
float determinante(float matriz[MAX][MAX], int n) {
    float det = 0;
    if (n == 1) {
        return matriz[0][0];
    } else if (n == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    for (int x = 0; x < n; x++) {
        float submatriz[MAX][MAX];
        int subi = 0; // índice para submatriz

        // Criando a submatriz
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != x) {
                    submatriz[subi][j < x ? j : j - 1] = matriz[i][j];
                }
            }
            subi++;
        }

        // Recursão para calcular o determinante da submatriz
        det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * determinante(submatriz, n - 1);
    }
    return det;
}

// Função para resolver o sistema de equações usando a regra de Cramer
void cramer(float matriz[MAX][MAX], int n) {
    float det = determinante(matriz, n);
    if (det == 0) {
        printf("O sistema não tem solução única.\n");
        return;
    }

    float x[MAX];
    for (int i = 0; i < n; i++) {
        float temp[MAX][MAX];
        // Criando a matriz temporária
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[j][k] = matriz[j][k];
            }
            temp[j][i] = matriz[j][n]; // Substitui a coluna da variável pela coluna de resultados
        }
        x[i] = determinante(temp, n) / det; // Calcula o valor da variável
    }

    // Exibindo os resultados
    printf("\nResultados:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i + 1, x[i]);
    }
}

int main() {
    int n;
    float matriz[MAX][MAX];

    // Lendo o número de equações
    printf("Digite o número de equações: ");
    scanf("%d", &n);

    // Lendo a matriz aumentada (coeficientes + resultados)
    printf("Digite os coeficientes da matriz (incluindo resultados):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("Matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    // Chamando a função que resolve usando a regra de Cramer
    cramer(matriz, n);

    return 0;
}
